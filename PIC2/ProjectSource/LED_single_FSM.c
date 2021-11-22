/****************************************************************************
 Module
   TemplateFSM.c

 Revision
   1.0.1

 Description
   This is a template file for implementing flat state machines under the
   Gen2 Events and Services Framework.

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 01/15/12 11:12 jec      revisions for Gen2 framework
 11/07/11 11:26 jec      made the queue static
 10/30/11 17:59 jec      fixed references to CurrentEvent in RunTemplateSM()
 10/23/11 18:20 jec      began conversion from SMTemplate.c (02/20/07 rev)
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "LED_single_FSM.h"
#include "../HALs/PIC32_SPI_HAL.h"
#include "../HALs/DM_Display.h"
#include "dbprintf.h"
#include "ES_DeferRecall.h"
#include "terminal.h"
//#include "ES_Port.h"

/*----------------------------- Module Defines ----------------------------*/

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match htat of enum in header file
static LED_single_State_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;
static ES_Event_t DeferralQueue[10];

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitTemplateFSM

 Parameters
     uint8_t : the priorty of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, sets up the initial transition and does any
     other required initialization for this state machine
 Notes

 Author
     J. Edward Carryer, 10/23/11, 18:55
****************************************************************************/
bool InitLED_single_FSM(uint8_t Priority)
{
  ES_Event_t ThisEvent;

  MyPriority = Priority;
  // put us into the Initial PseudoState
  CurrentState = InitPState_LED;
  // post the initial transition event
  clrScrn();
  ThisEvent.EventType = ES_INIT;
    SPISetup_DisableSPI(SPI_SPI1);
    SPISetup_BasicConfig(SPI_SPI1);
    SPISetup_SetLeader(SPI_SPI1,SPI_SMP_MID);
    SPISetup_SetBitTime(SPI_SPI1,10000);//100kHz
    SPISetup_MapSSOutput(SPI_SPI1,SPI_RPA0);
    SPISetup_MapSDOutput(SPI_SPI1,SPI_RPA1);
    SPISetup_SetClockIdleState(SPI_SPI1,SPI_CLK_LO);
    SPISetup_SetActiveEdge(SPI_SPI1,SPI_FIRST_EDGE);
    SPISetup_SetXferWidth(SPI_SPI1,SPI_16BIT);
    SPISetEnhancedBuffer(SPI_SPI1,true);
    SPISetup_EnableSPI(SPI_SPI1);
    while(!DM_TakeInitDisplayStep()){};
  if (ES_PostToService(MyPriority, ThisEvent) == true)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/****************************************************************************
 Function
     PostTemplateFSM

 Parameters
     EF_Event_t ThisEvent , the event to post to the queue

 Returns
     boolean False if the Enqueue operation failed, True otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     J. Edward Carryer, 10/23/11, 19:25
****************************************************************************/
bool PostLED_single_FSM(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunTemplateFSM

 Parameters
   ES_Event_t : the event to process

 Returns
   ES_Event_t, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
   add your description here
 Notes
   uses nested switch/case to implement the machine.
 Author
   J. Edward Carryer, 01/15/12, 15:23
****************************************************************************/
ES_Event_t RunLED_single_FSM(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

  switch (CurrentState)
  {
    case InitPState_LED:        // If current state is initial Psedudo State
    {
      if (ThisEvent.EventType == ES_INIT)    // only respond to ES_Init
      {
        // this is where you would put any actions associated with the
        // transition from the initial pseudo-state into the actual
        // initial state
        DM_ClearDisplayBuffer();
        // now put the machine into the actual initial state
        CurrentState = ReadyState_LED;
      }
    }
    break;

    case ReadyState_LED:        // If current state is state one
    {
        switch (ThisEvent.EventType)
        {
            case ES_NEWCHAR:
            {
                DB_printf("char: %d\r\n",ThisEvent.EventParam);
                DM_ScrollDisplayBuffer(4);
                DM_AddChar2DisplayBuffer(ThisEvent.EventParam);
                ES_Event_t newEvent;
                newEvent.EventType = ES_STARTPRINT;
                PostLED_single_FSM(newEvent);
                CurrentState = WriteState_LED;
            }
            break;
            case ES_DIGIT:  //If event is event one
            {   // Execute action function for state one : event one
              //Decide what the next state will be
                DM_ScrollDisplayBuffer(7);
                DB_printf("digit: %d\r\n",ThisEvent.EventParam);
                if(ThisEvent.EventParam == 0)
                {
                    DM_AddFilledSection();
                }else
                {
                    DM_AddChar2DisplayBuffer(ThisEvent.EventParam + '0');
                }
                DM_ScrollDisplayBuffer(1);
                if(ThisEvent.EventParam == 0){DM_AddFirstCol();}
            }
            break;
            case ES_STARTPRINT:
            {
                PostLED_single_FSM(ThisEvent);
                CurrentState = WriteState_LED;
            }  
            break;
            // repeat cases as required for relevant events
            default:
              ;
        }  // end switch on CurrentEvent
    }
    break;
    case WriteState_LED:        // If current state is state one
    {
      
      switch (ThisEvent.EventType)
      {
        case ES_STARTPRINT:  //If event is event one

        {   // Execute action function for state one : event one
          //Decide what the next state will be
//            DB_printf("Writing Line\r\n");
            if(!DM_TakeDisplayUpdateStep()){
                PostLED_single_FSM(ThisEvent);
            }else{
//                DB_printf("wrote Line\r\n");
                CurrentState = ReadyState_LED;
            }
        }
        break;
        // repeat cases as required for relevant events
        default:
          ;
      }  // end switch on CurrentEvent
    }
    break;
    // repeat state pattern as required for other states
    default:
      ;
  }                                   // end switch on Current State
  return ReturnEvent;
}

/****************************************************************************
 Function
     QueryTemplateSM

 Parameters
     None

 Returns
     TemplateState_t The current state of the Template state machine

 Description
     returns the current state of the Template state machine
 Notes

 Author
     J. Edward Carryer, 10/23/11, 19:21
****************************************************************************/
LED_single_State_t QueryLED_FSM(void)
{
  return CurrentState;
}

/***************************************************************************
 private functions
 ***************************************************************************/


/****************************************************************************
 Module
   PIC2ButtonFSM.c

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
#include "../ProjectHeaders/PIC2ButtonFSM.h"
#include "../HALs/PIC32PortHAL.h"
#include "dbprintf.h"
#include "ES_Events.h"
#include <time.h>
#include "ES_Port.h"
#include "terminal.h"
#include <string.h>

/*----------------------------- Module Defines ----------------------------*/

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match htat of enum in header file
static PIC2Button_FSM_State_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;
/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitPIC2ButtonFSM

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
bool InitPIC2ButtonFSM(uint8_t Priority)
{
  ES_Event_t ThisEvent;
  MyPriority = Priority;
  // put us into the Initial PseudoState
  CurrentState = InitPState;
  // post the initial transition event
  ThisEvent.EventType = ES_INIT;
  PortSetup_ConfigureDigitalInputs(_Port_B,_Pin_8);
  PortSetup_ConfigurePullUps(_Port_B,_Pin_8);
  PortSetup_ConfigureDigitalInputs(_Port_B,_Pin_9);
  PortSetup_ConfigurePullUps(_Port_B,_Pin_9);
  PortSetup_ConfigureDigitalInputs(_Port_B,_Pin_10);
  PortSetup_ConfigurePullUps(_Port_B,_Pin_10);
  PortSetup_ConfigureDigitalInputs(_Port_B,_Pin_11);
  PortSetup_ConfigurePullUps(_Port_B,_Pin_11);
  PortSetup_ConfigureDigitalOutputs(_Port_B,_Pin_4);

//  clrScrn();
  clrScrn();
  puts("Starting Test Harness for \r");
  DB_printf("the 2nd Generation Events & Services Framework V2.4\r\n");
//  DB_printf( "compiled at %s on %s\n", __TIME__, __DATE__);
//  DB_printf( "\n\r\n");
//  DB_printf( "Press any key to post key-stroke events to Service 0\n\r");
//  DB_printf( "Press 'd' to test event deferral \n\r");
//  DB_printf( "Press 'r' to test event recall \n\r");
//  DB_printf( "Press 'p' to test posting from an interrupt \n\r");
//  time_t toc; 
//  time(&toc);
//  srand((int)toc);
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
bool PostPIC2ButtonFSM(ES_Event_t ThisEvent)
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
const char printStr[255] = "NEXT STAGE!";
const char failStr[255] = "STAGE FAILED!";
const uint8_t printLen = strlen(printStr);
const uint8_t failLen = strlen(failStr);
#define ONE_SEC 1000

void sendToDisPlay(uint8_t* digits)
{
    
    for(uint8_t i = 0; i < NUM_BTNS; i++)
    {
        ES_Event_t newEvent;
        newEvent.EventType = ES_DIGIT;
        newEvent.EventParam = digits[i];
        PostLED_single_FSM(newEvent);
//        DB_printf("%d",digits[i]);
    }
//    DB_printf("\r\n");
    ES_Event_t newEvent;
    newEvent.EventType = ES_STARTPRINT;
    PostLED_single_FSM(newEvent);
//    ES_Event_t vent;
//    vent.EventType = ES_START;
//    CurrentState = AddIngredientsWaitState;
//    PostPIC2ButtonFSM(vent);
}

ES_Event_t RunPIC2ButtonFSM(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  static uint8_t remainPresses[NUM_BTNS];
  static uint8_t reqPress[NUM_BTNS];
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  static uint8_t printIdx = 0;
  switch (CurrentState)
  {
    case InitPState:        // If current state is initial Psedudo State
    {
        DB_printf("initpstate\r\n");
        if (ThisEvent.EventType == ES_INIT)    // only respond to ES_Init
        {
            CurrentState = AddIngredientsWaitState;
//            CurrentState = AddingState;
            ThisEvent.EventType = ES_RESET;
//            ThisEvent.EventType = ES_START;
            PostPIC2ButtonFSM(ThisEvent);
            DM_ClearDisplayBuffer();
            while(!DM_TakeDisplayUpdateStep()){}
        }
    }
    break;
    case AddIngredientsWaitState:        // If current state is state one
    {
        DB_printf("AddIngredientsWaitState\r\n");
        switch (ThisEvent.EventType)
        {
            case ES_START:
            {
                DB_printf("Generating Random Numbers\r\n");
                LED_ENABLE = 1;
                int start_t;
                int min_n = 2;
                int max_n = 6;
                for(uint8_t i = 0; i < NUM_BTNS; i++){
                    start_t = rand();
                    reqPress[i] = (uint8_t)(min_n + ((start_t)%(max_n+1-min_n)));
                    remainPresses[i] = reqPress[i];
//                    DB_printf("%d\r\n",reqPress[i]);
                }
                CurrentState = AddingState;
                sendToDisPlay(&remainPresses[0]);
                PostPIC2ButtonFSM(ThisEvent);
            }
            break;
            case ES_RESET:
            {
                LED_ENABLE = 0;
                DB_printf("RESET!\r\n");
//                for(uint8_t i = 0; i < NUM_BTNS; i++){
//                    start_t = rand();
//                    reqPress[i] = (uint8_t)(min_n + ((start_t)%(max_n+1-min_n)));
//                    remainPresses[i] = reqPress[i];
////                    DB_printf("%d\r\n",reqPress[i]);
//                }
//                CurrentState = InitPState;
//                ThisEvent.EventType = ES_RESET;
//                PostPIC2ButtonFSM(ThisEvent);
            }
            break;
            case ES_GAMETIMEOUT:{
                DB_printf("Game Timeout\r\n");
                ES_Event_t newEvent; 
                newEvent.EventType = ES_FAILURE;
                PostPIC2ButtonFSM(newEvent);
                CurrentState = FailureState;
            }
            break;
            default:
                ;
        }
    }
    break;
    case AddingState:
    {
//        sendToDisPlay(&remainPresses[0]);
        DB_printf("Adding State\r\n");
        switch(ThisEvent.EventType)
        {
            case ES_FALL:
            {
                if(remainPresses[ThisEvent.EventParam] == 0){
                    CurrentState = FailureState;
                    DB_printf("Pressed Too Many Times!\r\n");
                    ThisEvent.EventType = ES_FAILURE;
                    PostPIC2ButtonFSM(ThisEvent);
                    break;
                }else{
                    remainPresses[ThisEvent.EventParam]--;
                }
                if(remainPresses[0]==0 && remainPresses[1]==0 && remainPresses[2]==0 && remainPresses[3]==0){
                    CurrentState = SuccessState;
                    ThisEvent.EventType = ES_SUCCESS;
                    PostPIC2ButtonFSM(ThisEvent);
                }else{
                    sendToDisPlay(&remainPresses[0]);
                }
            }
            break;
            case ES_RESET:
            {
                LED_ENABLE = 0;
                CurrentState = AddIngredientsWaitState;
                PostPIC2ButtonFSM(ThisEvent);
                ES_Event_t postEvent;
                postEvent.EventType = P2P_STOP_TRANSMIT;
                PostP2PComm(postEvent);
                DM_ClearDisplayBuffer();
                while(!DM_TakeDisplayUpdateStep()){}
            }
            default:
                ;
            
        }
        
    }
    break;
    case FailureState:
    {
        switch(ThisEvent.EventType)
        {
            case ES_FAILURE:
            {
                DM_ClearDisplayBuffer();
                DB_printf("FAIL!\r\n");
                ES_Timer_InitTimer(BTN_TIMER, ONE_SEC/3);
                printIdx = 0;
                ES_Event_t postEvent;
                postEvent.EventType = P2P_START_TRANSMIT;
                postEvent.EventParam = ES_FAILURE;
                PostP2PComm(postEvent);
                LED_ENABLE = 0;
            }           
            break;
            case ES_TIMEOUT:
            {
                if(failLen > printIdx){
                    ES_Event_t newEvent;
                    newEvent.EventType = ES_NEWCHAR;
                    newEvent.EventParam = failStr[printIdx];
                    PostLED_single_FSM(newEvent);
                    printIdx++;
                    ES_Timer_InitTimer(BTN_TIMER, ONE_SEC/3);
                }
                else{
                    ReturnEvent.EventType = ES_NO_EVENT;
                    ES_Timer_InitTimer(BTN_TIMER, ONE_SEC*2);
                    printIdx = 0;
                    DM_ClearDisplayBuffer();
                }
            }
            break;
            case ES_RESET:
            {
                CurrentState = AddIngredientsWaitState;
                PostPIC2ButtonFSM(ThisEvent);
                ES_Event_t postEvent;
                postEvent.EventType = P2P_STOP_TRANSMIT;
                PostP2PComm(postEvent);
                DM_ClearDisplayBuffer();
                while(!DM_TakeDisplayUpdateStep()){}
            }
            break;
            default:
                ;
            }
    }
    break;
    case SuccessState:
    {
        switch(ThisEvent.EventType)
        {
            case ES_SUCCESS:
            {
                DB_printf("Suuuccess!\r\n");
                ES_Timer_InitTimer(BTN_TIMER, ONE_SEC/3);
                DM_ClearDisplayBuffer();
                printIdx = 0;
                ES_Event_t postEvent;
                postEvent.EventType = P2P_START_TRANSMIT;
                postEvent.EventParam = ES_SUCCESS;
                PostP2PComm(postEvent);
                LED_ENABLE = 0;
            }           
            break;
            case ES_TIMEOUT:
            {
                if(printLen > printIdx){
                    ES_Event_t newEvent;
                    newEvent.EventType = ES_NEWCHAR;
                    newEvent.EventParam = printStr[printIdx];
                    PostLED_single_FSM(newEvent);
                    printIdx++;
                    ES_Timer_InitTimer(BTN_TIMER, ONE_SEC/3);
                }
                else{
                    ReturnEvent.EventType = ES_NO_EVENT;
                    ES_Timer_InitTimer(BTN_TIMER, ONE_SEC*2);
                    printIdx = 0;
                    DM_ClearDisplayBuffer();
                }
            }
            break;
            case ES_RESET:
            {
                CurrentState = AddIngredientsWaitState;
                PostPIC2ButtonFSM(ThisEvent);
                ES_Event_t postEvent;
                postEvent.EventType = P2P_STOP_TRANSMIT;
                PostP2PComm(postEvent);
                DM_ClearDisplayBuffer();
                while(!DM_TakeDisplayUpdateStep()){}
            }
            break;
            default:
                ;
        }
    }
    break;
    default:
        ;
    }// end switch on Current State
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
PIC2Button_FSM_State_t QueryPIC2ButtonFSM(void)
{
  return CurrentState;
}

/***************************************************************************
 private functions
 ***************************************************************************/


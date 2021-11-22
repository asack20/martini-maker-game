/****************************************************************************
 Module
   DisplayFSM.c

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
#include "DisplayFSM.h"
#include "ES_DeferRecall.h"

/*----------------------------- Module Defines ----------------------------*/
#define NUM_COLS_IN_FONT 4
#define DEBUG_PRINT 0 // T/F to enable debug prints
/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/
bool InitializeSPI(void);
/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match htat of enum in header file
static DisplayState_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;
// add a deferral queue for up to 3 pending deferrals +1 to allow for overhead
static ES_Event_t DeferralQueue[3 + 1];

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitDisplayFSM

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
bool InitDisplayFSM(uint8_t Priority)
{
  ES_Event_t ThisEvent;
  puts("Initializing DisplayFSM\n\r");
  MyPriority = Priority;
  // initialize deferral queue for testing Deferal function
  ES_InitDeferralQueueWith(DeferralQueue, ARRAY_SIZE(DeferralQueue));
  // put us into the Initial PseudoState
  CurrentState = InitPState;
  // post the initial transition event
  ThisEvent.EventType = ES_INIT;
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
     PostDisplayFSM

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
bool PostDisplayFSM(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunDisplayFSM

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
ES_Event_t RunDisplayFSM(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  ES_Event_t PostEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  
  //DB_printf( "RunDisplayFSM: State %d Event %d \n\r", CurrentState, ThisEvent.EventType);
  switch (CurrentState)
  {
    case InitPState:        // If current state is initial Psedudo State
    {
      if (ThisEvent.EventType == ES_INIT)    // only respond to ES_Init
      {
        if (true == InitializeSPI()) //Initialize SPI for display
        {
            //If successful Switch state and write another ES_INIT event
            PostEvent.EventType = ES_INIT;
            PostDisplayFSM(PostEvent);
            CurrentState = InitializeDisplayState; 
        }           
        else // SPI failed to initialize, throw error
        {
            puts("DisplayFSM: ERROR: Failed to Initialize SPI.\n\r");
            ReturnEvent.EventType = ES_ERROR;
        }  
      }
    }
    break;

    case InitializeDisplayState: 
    {
      if (ThisEvent.EventType == ES_INIT)    // only respond to ES_Init
      {
          if (false == DM_TakeInitDisplayStep()) // Take a display step
          {
            //if display init not complete, post another event
            PostEvent.EventType = ES_INIT;
            PostDisplayFSM(PostEvent);
          }
          else // display init done
          {
              CurrentState = ReadyState; //move to ready state 
          }
      }
    }
    break;
    
    case ReadyState:        // If current state is state one
    {
      if (ThisEvent.EventType == ES_ADD_CHAR) // There is new char to scroll
      {
        DM_ScrollDisplayBuffer(NUM_COLS_IN_FONT); // scroll 1 char
        DM_AddChar2DisplayBuffer(ThisEvent.EventParam); // add char to buffer
        
        CurrentState = ScrollingState; // move to scrolling state
        PostEvent.EventType = ES_UPDATE_DISPLAY; //create event to start scroll
        PostDisplayFSM(PostEvent);
#if DEBUG_PRINT
        DB_printf( "DisplayFSM: Writing ->%c<- \n\r", (char)ThisEvent.EventParam);
#endif
      }
    }
    break;
    
    case ScrollingState:        // If current state is state one
    {
      if (ThisEvent.EventType == ES_UPDATE_DISPLAY)
      {
          if (false == DM_TakeDisplayUpdateStep()) // Take a display step
          {
            //if display update not complete, post another event
            PostEvent.EventType = ES_UPDATE_DISPLAY;
            PostDisplayFSM(PostEvent);
          }
          else // display update done 
          {
              //Recall any events in queue
              ES_RecallEvents(MyPriority, DeferralQueue); 
              CurrentState = ReadyState; //move to ready state 
#if DEBUG_PRINT 
              puts("DisplayFSM: Display has been scrolled\r\n");
#endif
          }
      }
      else if (ThisEvent.EventType == ES_ADD_CHAR)// defer add char events
      {
          ES_DeferEvent(DeferralQueue, ThisEvent);
#if DEBUG_PRINT 
          DB_printf( "DisplayFSM: Deferring adding char ->%c<- \n\r", (char)ThisEvent.EventParam);
#endif          
      }
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
     QueryDisplaySM

 Parameters
     None

 Returns
     DisplayState_t The current state of the Display state machine

 Description
     returns the current state of the Display state machine
 Notes

 Author
     J. Edward Carryer, 10/23/11, 19:21
****************************************************************************/
DisplayState_t QueryDisplayFSM(void)
{
  return CurrentState;
}

/***************************************************************************
 private functions
 ***************************************************************************/
/****************************************************************************
 Function
 InitializeSPi

 Parameters
     None

 Returns
     ReturnVal; True if SPI was initialized successfully, Else: false

 Description
 Initializes SPI to parameters required for the display
 * SPI_SMP_MID
 * 100 kHz clock
 * SS on A0
 * SDO on A1
 * Clock Idle Low
 * Read 1st edge
 * 16bit transfers
 
****************************************************************************/
bool InitializeSPI(void)
{
    bool ReturnVal = true;
    //Configure SPI connection
    ReturnVal &= SPISetup_BasicConfig(SPI_SPI1);
    ReturnVal &= SPISetup_SetLeader(SPI_SPI1, SPI_SMP_MID);
    ReturnVal &= SPISetup_SetBitTime(SPI_SPI1, 10000); //10,000 ns = 100 kHZ
    ReturnVal &= SPISetup_MapSSOutput(SPI_SPI1, SPI_RPA0); // make A0 SS
    ReturnVal &= SPISetup_MapSDOutput(SPI_SPI1, SPI_RPA1); // make A1 SDO
    ReturnVal &= SPISetup_SetClockIdleState(SPI_SPI1, SPI_CLK_LO); // clock is idle low
    ReturnVal &= SPISetup_SetActiveEdge(SPI_SPI1, SPI_FIRST_EDGE); // read on 1st edge 
    ReturnVal &= SPISetup_SetXferWidth(SPI_SPI1, SPI_16BIT); //16 bit messages
    ReturnVal &= SPISetEnhancedBuffer(SPI_SPI1, true); //enable ENHBUF

    //After everything set up, enable spi
    ReturnVal &= SPISetup_EnableSPI(SPI_SPI1);
    
    return ReturnVal;
}

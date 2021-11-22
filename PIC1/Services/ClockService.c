/****************************************************************************
 Module
   ClockService.c

 Revision
   1.0.1

 Description
   This is the service to demonstrate the Servo library

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/30/21 09:58 jec      started work based on TestHarnessService0
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
// Hardware
#include <xc.h>

// Event & Services Framework
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "ES_DeferRecall.h"
#include "ES_Port.h"
#include "terminal.h"
#include "dbprintf.h"

// PWM Lib
#include "../HALs/PWM_PIC32.h"

// This module
#include "ClockService.h"
//#include "ServoTest.h"
#include "GameMain.h"


/*----------------------------- Module Defines ----------------------------*/
// these times assume a 1.000mS/tick timing
#define ONE_SEC 1000
#define HALF_SEC (ONE_SEC / 2)
#define TWO_SEC (ONE_SEC * 2)
#define FIVE_SEC (ONE_SEC * 5)
#define TEN_MS (10)
#define TWENTY_FIVE_MS (25)
#define FIFTY_MS (50)

#define TIME_STEP TWENTY_FIVE_MS

#define CLOCK_DURATION 60 // make clock 60 seconds
#define CLOCK_TICK_LEN 1 // update once per second

// TICS_PER_MS assumes a 20MHz PBClk /8 = 2.5MHz clock rate
#define TICS_PER_MS 2500

// these are extents of servo motion
#define FULL_CW ((uint16_t)(0.45*TICS_PER_MS))
#define FULL_CCW ((uint16_t)(2.33*TICS_PER_MS))
#define MID_POINT (FULL_CW+((FULL_CCW-FULL_CW)/2))

// these are related to how fast we move how far to move each update
#define TICKS_PER_STEP ((FULL_CCW-FULL_CW)/(CLOCK_DURATION * CLOCK_TICK_LEN))

#define CLOCK_CNL 3 // Use pwm channel 3
#define CLOCK_PIN PWM_RPB9 //Servo on RB9 (Pin 18)
#define CLOCK_START_POS FULL_CCW // Start fully ccw
#define CLOCK_END_POS FULL_CW //end fully cw

#define CLOCK_TMR _Timer3_ // Use PWM timer 3
#define CLOCK_FREQ 50 // 50 HZ
#define NUM_PWM 5 // Configure All PWM Channels?

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
*/

/*---------------------------- Module Variables ---------------------------*/
// with the introduction of Gen2, we need a module level Priority variable
static uint8_t MyPriority;
static uint16_t CurrentTick;
static uint32_t CurrentPosition; 
static const uint16_t MAX_TICKS = CLOCK_DURATION * CLOCK_TICK_LEN;
/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitClockService

 Parameters
     uint8_t : the priorty of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Initializes service, PWM hardware for servo, and moves clock back to start
 Notes

 Author
    
****************************************************************************/
bool InitClockService(uint8_t Priority)
{
    puts("Initializing Clock Service\r");
    ES_Event_t ThisEvent;
    bool ReturnVal = true; // assume that everything will be OK
    
    MyPriority = Priority;
    
    // initialize module variables
    CurrentTick = 0;
    CurrentPosition = CLOCK_START_POS;

    /********************************************
     Initialization sequence for timers to do servo drive
     *******************************************/

    if(!PWMSetup_BasicConfig(NUM_PWM)) // config channels
    {
        ReturnVal = false;
    }else if(!PWMSetup_SetFreqOnTimer(CLOCK_FREQ, CLOCK_TMR))  // set timer freq
    {
        ReturnVal = false;    
    }else if(!PWMSetup_AssignChannelToTimer(CLOCK_CNL, CLOCK_TMR)) 
    {
        ReturnVal = false;    
    }else if(!PWMSetup_MapChannelToOutputPin(CLOCK_CNL, CLOCK_PIN))
    {
        ReturnVal = false;    
    }else  
    {
      // no else clause
    }

    // post the initial transition event
    ThisEvent.EventType = RESET_CLOCK;
    if (!ES_PostToService(MyPriority, ThisEvent))
    {
        ReturnVal = false;
    }
    else
    {
      // no else clause
    }
    return ReturnVal;
}

/****************************************************************************
 Function
     PostClockService

 Parameters
     ES_Event ThisEvent ,the event to post to the queue

 Returns
     bool false if the Enqueue operation failed, true otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     
****************************************************************************/
bool PostClockService(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunClockService

 Parameters
   ES_Event : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
 Responds to Open/CloseClock events to move servo
 Notes

 Author

****************************************************************************/
ES_Event_t RunClockService(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    ES_Event_t PostEvent;
    
    switch (ThisEvent.EventType)
    {
        case RESET_CLOCK:
        {
            puts("ClockService: Reset Clock\r");
            //Stop timer if it's running
            ES_Timer_StopTimer(CLOCK_TIMER);
            //Move servo to start pos
            if(!PWMOperate_SetPulseWidthOnChannel(CLOCK_START_POS,CLOCK_CNL))
            {
                ReturnEvent.EventType = ES_ERROR;    
            }
            // Reset variables
            CurrentTick = 0;
            CurrentPosition = CLOCK_START_POS;
        }
        break;
        case START_CLOCK:   
        {
            puts("ClockService: Start Clock\r");
            // init timer for one time step
            ES_Timer_InitTimer(CLOCK_TIMER, CLOCK_TICK_LEN*ONE_SEC);
            // Reset variables to make sure they are correct
            CurrentTick = 0;
            CurrentPosition = CLOCK_START_POS;
        }
        break;
        case PAUSE_CLOCK:
        {
            puts("ClockService: Pause Clock\r");
            //stop timer so clock won't progress
            ES_Timer_StopTimer(CLOCK_TIMER);
        }
        break;
        case ES_TIMEOUT: // progress clock each time step
        {
            CurrentTick++;
            // - because clockwise is negative
            CurrentPosition -= TICKS_PER_STEP;
            //Move servo to next pos
            if(!PWMOperate_SetPulseWidthOnChannel(CurrentPosition,CLOCK_CNL))
            {
                ReturnEvent.EventType = ES_ERROR;    
            }
            
            // if end of clock time reached
            if (CurrentTick >= MAX_TICKS)
            {
                //Post ClockTimeout Event
                //NOTE: Change which service it posts to
                PostEvent.EventType = CLOCK_TIMEOUT;
                PostGameMain(PostEvent);
            }
            else // continue clock
            {
                // init a new 1 tick timer
                ES_Timer_InitTimer(CLOCK_TIMER, CLOCK_TICK_LEN*ONE_SEC);
            }
            
        }
        break;    
        default:
        {}
        break;
  }

  return ReturnEvent;
}

/***************************************************************************
 private functions
 ***************************************************************************/

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/


/****************************************************************************
 Module
   DoorService.c

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
#include "DoorService.h"


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

// TICS_PER_MS assumes a 20MHz PBClk /8 = 2.5MHz clock rate
#define TICS_PER_MS 2500

// these are extents of servo motion
#define FULL_CW ((uint16_t)(0.5*TICS_PER_MS))
#define FULL_CCW ((uint16_t)(2.35*TICS_PER_MS))
#define MID_POINT (FULL_CW+((FULL_CCW-FULL_CW)/2))

// these are related to how fast we move. full range of motion in 100 steps
#define TICKS_PER_STEP ((FULL_CCW-FULL_CW)/100)

#define DOOR_CNL 4 // Use pwm channel 4
#define DOOR_PIN PWM_RPB13 //Servo on RB13 (Pin 24)
#define FULL_OPEN 5700 //Open is counter-Clockwise
#define FULL_CLOSE 2900 //close is clockwise

#define DOOR_TMR _Timer3_ // Use PWM timer 3
#define DOOR_FREQ 50 // 50 HZ
#define NUM_PWM 5 // Configure All PWM Channels?
/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
*/

/*---------------------------- Module Variables ---------------------------*/
// with the introduction of Gen2, we need a module level Priority variable
static uint8_t MyPriority;

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitDoorService

 Parameters
     uint8_t : the priorty of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, and does any
     other required initialization for this service
 Notes

 Author
    
****************************************************************************/
bool InitDoorService(uint8_t Priority)
{
    puts("Initializing Door Service\r");
    ES_Event_t ThisEvent;
    bool ReturnVal = true; // assume that everything will be OK
    
    MyPriority = Priority;

    /********************************************
     Initialization sequence for timers to do servo drive
     *******************************************/

    if(!PWMSetup_BasicConfig(NUM_PWM)) // config channels
    {
        ReturnVal = false;
    }else if(!PWMSetup_SetFreqOnTimer(DOOR_FREQ, DOOR_TMR))  // set timer freq
    {
        ReturnVal = false;    
    }else if(!PWMSetup_AssignChannelToTimer(DOOR_CNL, DOOR_TMR)) 
    {
        ReturnVal = false;    
    }else if(!PWMSetup_MapChannelToOutputPin(DOOR_CNL, DOOR_PIN))
    {
        ReturnVal = false;    
    }else  
    {
      // no else clause
    }

    // post the initial transition event
    ThisEvent.EventType = CLOSE_DOOR;
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
     PostDoorService

 Parameters
     ES_Event ThisEvent ,the event to post to the queue

 Returns
     bool false if the Enqueue operation failed, true otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     
****************************************************************************/
bool PostDoorService(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunDoorService

 Parameters
   ES_Event : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
 Responds to Open/CloseDoor events to move servo
 Notes

 Author

****************************************************************************/
ES_Event_t RunDoorService(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  
  switch (ThisEvent.EventType)
  {
    case OPEN_DOOR:
    {
        puts("DoorService: Opening Door\r");
        // Set servo to open and create return error if it fails
        if(!PWMOperate_SetPulseWidthOnChannel(FULL_OPEN,DOOR_CNL))
        {
            ReturnEvent.EventType = ES_ERROR;    
        }
    }
    break;
    case CLOSE_DOOR:   // implement motion
    {
        puts("DoorService: Closing Door\r");
        // Set servo to close and create return error if it fails
        if(!PWMOperate_SetPulseWidthOnChannel(FULL_CLOSE,DOOR_CNL))
        {
            ReturnEvent.EventType = ES_ERROR;    
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


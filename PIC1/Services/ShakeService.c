/****************************************************************************
 Module
   ShakeService.c

 Revision
   1.0.1

 Description
 * This is the file for the ShakeService State Machine, which controls the 
 * shake stage of the game. 
 * 

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
#include "ShakeService.h"
#include "HapticService.h"
#include "../HALs/PIC32_AD_Lib.h"
#include "../HALS/PIC32PortHAL.h"
#include "../PourService/AnalogChecker.h"
#include "GameMain.h"

/*----------------------------- Module Defines ----------------------------*/

#define REQUIRED_SHAKES 7 // Number of shakes required by service

#define SHORT_PULSE 50 // (ms) haptic pulse time after up/down event
#define LONG_PULSE 750 //(ms) haptic pulse time after SHAKE_SUCCESS

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match htat of enum in header file
static ShakeState_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;

static uint16_t ShakeCount;

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitShakeService

 Parameters
     uint8_t : the priorty of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, sets up the initial transition and does any
     other required initialization for this state machine
 Notes

 Author
 * Andrew Sack
****************************************************************************/
bool InitShakeService(uint8_t Priority)
{
    printf("Initializing Shake Service \n\r");

    MyPriority = Priority;
    // put us into the Ready State
    CurrentState = ShakeReadyState;

    if (false == InitDistanceSensor())
    {
        printf("Failed to Initialize Distance Sensor Event Checker \r\n");
        return false;
    }
    
    return true;
}

/****************************************************************************
 Function
     PostShakeService

 Parameters
     ES_Event_t ThisEvent , the event to post to the queue

 Returns
     boolean False if the Enqueue operation failed, True otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
 * Andrew Sack
****************************************************************************/
bool PostShakeService(ES_Event_t ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunShakeService

 Parameters
   ES_Event_t : the event to process

 Returns
   ES_Event_t, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
 * Responds to ShakeEventChecker and counts number of shakes. Posts Success 
 * event to Game main and controls haptic motor
 Notes
   uses nested switch/case to implement the machine.
 Author
 * Andrew Sack
****************************************************************************/
ES_Event_t RunShakeService(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ES_Event_t PostEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    switch (CurrentState)
    {
        case ShakeReadyState: // service is idle
        {
            if(START_SHAKE == ThisEvent.EventType)
            {
                printf("ShakeService: Starting Shake Detection \n\r");
                // Reset LastDistanceVal and Shake Count to Initial vals
                ReadInitialDistance();
                ShakeCount = 0; 
                
                // Multi Pulse Haptic at START to draw attn to stage
                PostEvent.EventType = MULTI_PULSE_HAPTIC;
                PostEvent.EventParam = SHORT_PULSE;
                PostHapticService(PostEvent);
                
                CurrentState = ShakeUpState;
            }
        }
        break;
        case ShakeUpState: // shaker currently moving up towards up threshold
        {
            if(RESET_SHAKE == ThisEvent.EventType)
            {
                //Post SHAKE_FAILURE event to GameMain (need to change)
                PostEvent.EventType = SHAKE_FAILURE;
                //Post to GameMain and TestShakeService
                PostShakeDistList(PostEvent);
                
                //stop shake detection and return to idle
                // Reset Service by going back to ShakeReadyState
                CurrentState = ShakeReadyState;
                printf("ShakeService: RESET_SHAKE received \n\r");
            }
            else if (SHAKE_TOP == ThisEvent.EventType)
            {
                //printf("ShakeService: SHAKE_TOP received going to ShakeDownState\n\r");
                // Reached Upper Limit, moving down now
                CurrentState = ShakeDownState;
                // Pulse Haptic motor briefly
                PostEvent.EventType = PULSE_HAPTIC;
                PostEvent.EventParam = SHORT_PULSE;
                PostHapticService(PostEvent);
            }
        }
        break;
        case ShakeDownState: // shaker currently moving down towards down thresh
        {
            if(RESET_SHAKE == ThisEvent.EventType)
            {
                //Post SHAKE_FAILURE event to GameMain
                PostEvent.EventType = SHAKE_FAILURE;
                //Post to GameMain and TestShakeService
                PostShakeDistList(PostEvent);
                
                //stop shake detection and return to idle
                //Reset Service by going back to ShakeReadyState
                CurrentState = ShakeReadyState;
                printf("ShakeService: RESET_SHAKE received \n\r");
            }
            else if (SHAKE_BOTTOM == ThisEvent.EventType)
            {
                //printf("ShakeService: SHAKE_Bottom received going to ShakeDownState\n\r");
                // Reached Bottom Limit
                // Did full shake, so increment counter
                ShakeCount++;
                printf("ShakeService: Completed %u shakes\n\r", ShakeCount);
                
                // did required number of shakes
                if (ShakeCount >= REQUIRED_SHAKES)
                {
                    // MULTI Pulse Haptic at SUCCESS
                    PostEvent.EventType = MULTI_PULSE_HAPTIC;
                    PostEvent.EventParam = SHORT_PULSE;
                    PostHapticService(PostEvent);
                
                    
                    //Post SHAKE_SUCCESS event to GameMain and end shake counting
                    PostEvent.EventType = SHAKE_SUCCESS;
                    //Post to GameMain and TestShakeService
                    PostShakeDistList(PostEvent);
                    
                    // move back to ready state
                    CurrentState = ShakeReadyState;
                }
                else // haven't reached required shakes
                {
                    //move back to up state
                    CurrentState = ShakeUpState;
                    // Pulse Haptic motor briefly
                    PostEvent.EventType = PULSE_HAPTIC;
                    PostEvent.EventParam = SHORT_PULSE;
                    PostHapticService(PostEvent);
                }
            }
        }
        break;
        default:
          ;
    }                                   // end switch on Current State
    return ReturnEvent;
}

/****************************************************************************
 Function
     QueryShakeService

 Parameters
     None

 Returns
     ShakeState_t The current state of the Shake state machine

 Description
     returns the current state of the Shake state machine
 Notes

 Author
 * Andrew Sack
****************************************************************************/
ShakeState_t QueryShakeService(void)
{
    return CurrentState;
}



/***************************************************************************
 private functions
 ***************************************************************************/


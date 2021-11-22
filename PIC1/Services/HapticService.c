/****************************************************************************
 Module
   HapticService.c

 Revision
   1.0.1

 Description
   This is a template file for implementing a simple service under the
   Gen2 Events and Services Framework.

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 01/16/12 09:58 jec      began conversion from HapticFSM.c
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "HapticService.h"
#include "../HALs/PIC32PortHAL.h"

/*----------------------------- Module Defines ----------------------------*/
#define HAPTIC_PORT _Port_B
#define HAPTIC_PIN _Pin_8 // Hardware pin 17
#define HAPTIC_LAT LATBbits.LATB8
/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
*/

/*---------------------------- Module Variables ---------------------------*/
// with the introduction of Gen2, we need a module level Priority variable
static uint8_t MyPriority;
static uint16_t PulseTime;
static uint16_t PulseQuantity;

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitHapticService

 Parameters
     uint8_t : the priority of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Configures Digital Output to control motor and initializes service
 Notes

 Author
     
****************************************************************************/
bool InitHapticService(uint8_t Priority)
{
    printf("Initializing HapticService\n\r");
    ES_Event_t ThisEvent;
    
    // initialize variables
    PulseTime = 0;
    PulseQuantity = 0;
    
    MyPriority = Priority;
    
    //Configure pin as digital output and give error if it fails
    if (false == PortSetup_ConfigureDigitalOutputs(HAPTIC_PORT, HAPTIC_PIN))
    {
        printf("Failed to configure digital output for haptic motor\n\r");
        return false;
    }
    
    // post stop event to ensure motor is off
    ThisEvent.EventType = STOP_HAPTIC;
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
     PostHapticService

 Parameters
     EF_Event_t ThisEvent ,the event to post to the queue

 Returns
     bool false if the Enqueue operation failed, true otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     
****************************************************************************/
bool PostHapticService(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunHapticService

 Parameters
   ES_Event_t : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
   Responds to events to turn the haptic motor on and off
 Notes

 Author
   
****************************************************************************/
ES_Event_t RunHapticService(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    switch (ThisEvent.EventType)
    {
        case START_HAPTIC:
        {
            HAPTIC_LAT = 1; // turn on motor
        }
        break;
        case STOP_HAPTIC:
        {
            HAPTIC_LAT = 0; // turn off motor
        }
        break;
        case PULSE_HAPTIC:
        {
            PulseTime = ThisEvent.EventParam;
            PulseQuantity = 1; // pulse once
            
            HAPTIC_LAT = 1; // turn on motor
            //Init timer for time specified in event param
            ES_Timer_InitTimer(HAPTIC_TIMER, PulseTime);
        }
        break;
        case MULTI_PULSE_HAPTIC:
            PulseTime = ThisEvent.EventParam;
            PulseQuantity = 9; // pulse three times
            
            HAPTIC_LAT = 1; // turn on motor
            //Init timer for time specified in event param
            ES_Timer_InitTimer(HAPTIC_TIMER, PulseTime);
        case ES_TIMEOUT:
        {
            PulseQuantity--; // 1 pulse complete
            
            if ((PulseQuantity % 2) == 0) // If quantity is even
            {
                HAPTIC_LAT = 0; // turn off motor
            }
            else // quantity odd
            {
                HAPTIC_LAT = 1; // turn on motor
            }
            
            if (PulseQuantity > 0) // pulses left
            {
                // start another timer
                ES_Timer_InitTimer(HAPTIC_TIMER, PulseTime);
            }   
        }
        break;
        default:
        {}
    }
    return ReturnEvent;
}

/***************************************************************************
 private functions
 ***************************************************************************/

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/


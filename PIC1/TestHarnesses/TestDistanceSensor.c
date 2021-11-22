/****************************************************************************
 Module
   TestDistanceSensor.c

 Revision
   1.0.1

 Description
   This is a template file for implementing a simple service under the
   Gen2 Events and Services Framework.

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 01/16/12 09:58 jec      began conversion from TemplateFSM.c
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "TestDistanceSensor.h"
#include "../HALs/PIC32PortHAL.h"
#include "../HALs/PIC32_AD_Lib.h"
#include "../PourService/AnalogChecker.h"

/*----------------------------- Module Defines ----------------------------*/
#define WAIT_TIME 100 //ms


/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
*/

/*---------------------------- Module Variables ---------------------------*/
// with the introduction of Gen2, we need a module level Priority variable
static uint8_t MyPriority;
static uint32_t ConversionResults[2];
/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitTestDistanceSensor

 Parameters
     uint8_t : the priorty of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, and does any
     other required initialization for this service
 Notes

 Author
     J. Edward Carryer, 01/16/12, 10:00
****************************************************************************/
bool InitTestDistanceSensor(uint8_t Priority)
{
    printf("---------------------------------------------------------\n\r");
    printf("Initializing Test Distance Sensor\n\r");
    printf( "Press 'z' to read single Distance value \n\r");
    printf( "Press 'x' to start continuous Distance value reading \n\r");
    printf( "Press 'c' to stop continuous Distance value reading\n\r");
    ES_Event_t ThisEvent;

    MyPriority = Priority;

    InitADC();
    return true;
}

/****************************************************************************
 Function
     PostTestDistanceSensor

 Parameters
     EF_Event_t ThisEvent ,the event to post to the queue

 Returns
     bool false if the Enqueue operation failed, true otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     J. Edward Carryer, 10/23/11, 19:25
****************************************************************************/
bool PostTestDistanceSensor(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunTestDistanceSensor

 Parameters
   ES_Event_t : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
   add your description here
 Notes

 Author
   J. Edward Carryer, 01/15/12, 15:23
****************************************************************************/
ES_Event_t RunTestDistanceSensor(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    ES_Event_t PostEvent;
  
    switch (ThisEvent.EventType)
    {
        case ES_NEW_KEY:
        {
            /*
            printf("\n\rES_NEW_KEY received with -> %c <- in TestDistanceSensor\r\n",
            (char)ThisEvent.EventParam);
            */
            switch (ThisEvent.EventParam)
            {
                case 'z':
                {
                    printf("TestDistanceSensor: Checking single value\r\n");
                    checkDistanceValue();
                }
                break;
                case 'x':
                {
                    printf("TestDistanceSensor: Starting Continuous Read\r\n");
                    ES_Timer_InitTimer(DISTANCE_TIMER, WAIT_TIME);
                }
                break;
                case 'c':
                {
                    printf("TestDistanceSensor: Stopping Continuous Read\r\n");
                    ES_Timer_StopTimer(DISTANCE_TIMER);
                }
                break;
                default:
                  ;
            }
        }
        break;
        case ES_TIMEOUT:
        {
            // check value and start a new timer
            checkDistanceValue();
            ES_Timer_InitTimer(DISTANCE_TIMER, WAIT_TIME);
        }
        break;
        case DISTANCE_VALUE:
        {
            printf("TestDistanceSensor: value = %u\r\n", ThisEvent.EventParam);
        }
        break;
        default:
        ;
    }
    return ReturnEvent;
}



/***************************************************************************
 private functions
 ***************************************************************************/

bool checkDistanceValue(void)
{
    printf("Checking Distance\r\n");
    ES_Event_t PostEvent;
    ADC_MultiRead(ConversionResults);
    uint32_t CurrentVal = ConversionResults[1];
    
    PostEvent.EventType = DISTANCE_VALUE;
    PostEvent.EventParam = (uint16_t) CurrentVal;
    PostTestDistanceSensor(PostEvent);
    
    return true;
    
}

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/


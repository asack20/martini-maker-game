/****************************************************************************
 Module
   TestShakeService.c

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
#include "TestShakeService.h"
#include "../HALs/PIC32PortHAL.h"
#include "../Services/HapticService.h"
#include "../Services/ShakeService.h"
#include "../PourService/PourService.h"
#include "../Services/AddIngredientsHelperService.h"

/*----------------------------- Module Defines ----------------------------*/


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
     InitTestShakeService

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
bool InitTestShakeService(uint8_t Priority)
{
    printf("---------------------------------------------------------\n\r");
    printf("Initializing Stages Test Harness \n\r");
    
    printf( "Press 'a' to START_ADD_INGREDIENTS \n\r");
    printf( "Press 's' to RESET_ADD_INGREDIENTS \n\r");
    
    printf( "Press 'd' to START_SHAKE \n\r");
    printf( "Press 'f' to RESET_SHAKE \n\r");
    
    printf( "Press 'g' to START_POUR \n\r");
    printf( "Press 'h' to RESET_POUR \n\r");
    
    printf( "Press 'v' to Start Haptic Motor \n\r");
    printf( "Press 'b' to Stop Haptic Motor\n\r");
    printf( "Press 'n' to Pulse Haptic Motor for 0.25 sec \n\r");
    printf( "Press 'm' to Pulse Haptic Motor for 0.5 sec \n\r");
    printf( "Press ',' to Pulse Haptic Motor for 1 sec \n\r");
    printf( "Press '.' to Pulse Haptic Motor for 2 sec \n\r");
    ES_Event_t ThisEvent;

    MyPriority = Priority;

    return true;
}

/****************************************************************************
 Function
     PostTestShakeService

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
bool PostTestShakeService(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunTestShakeService

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
ES_Event_t RunTestShakeService(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    ES_Event_t PostEvent;
  
    switch (ThisEvent.EventType)
    {
        case ES_NEW_KEY:
        {
            /*
            printf("\n\rES_NEW_KEY received with -> %c <- in TestShakeService\r\n",
            (char)ThisEvent.EventParam);
            */
            switch (ThisEvent.EventParam)
            {
                case 'a':
                {
                    printf("Test Stages: Sending START_ADD_INGREDIENTS to AddIngredientsHelper\r\n");
                    PostEvent.EventType = START_ADD_INGREDIENTS;
                    printf("[NEED TO POST] START_ADD_INGREDIENTS to AddIngredientsHelper\r\n");
                    PostAddIngredientsHelperService(PostEvent);
                }
                break;
                case 's':
                {
                    printf("Test Stages: Sending RESET_ADD_INGREDIENTS to AddIngredientsHelper\r\n");
                    PostEvent.EventType = RESET_ADD_INGREDIENTS;
                    printf("[NEED TO POST] RESET_ADD_INGREDIENTS to AddIngredientsHelper\r\n");
                    PostAddIngredientsHelperService(PostEvent);
                }
                break;
                case 'd':
                {
                    printf("Test Stages: Sending START_SHAKE to ShakeService\r\n");
                    PostEvent.EventType = START_SHAKE;
                    PostShakeService(PostEvent);
                }
                break;
                case 'f':
                {
                    printf("Test Stages: Sending RESET_SHAKE to ShakeService\r\n");
                    PostEvent.EventType = RESET_SHAKE;
                    PostShakeService(PostEvent);
                }
                break;
                case 'g':
                {
                    printf("Test Stages: Sending START_POUR to PourService\r\n");
                    PostEvent.EventType = START_POUR;
                    PostPourService(PostEvent);
                }
                break;
                case 'h':
                {
                    printf("Test Stages: Sending RESET_POUR to PourService\r\n");
                    PostEvent.EventType = RESET_POUR;
                    PostPourService(PostEvent);
                }
                break;
                
                case 'v':
                {
                    printf("TestShakeService: Starting Haptic Motor\r\n");
                    PostEvent.EventType = START_HAPTIC;
                    PostHapticService(PostEvent);
                }
                break;
                case 'b':
                {
                    printf("TestShakeService: Stopping Haptic Motor\r\n");
                    PostEvent.EventType = STOP_HAPTIC;
                    PostHapticService(PostEvent);
                }
                break;
                case 'n':
                {
                    printf("TestShakeService: Pulsing Haptic Motor for 0.25 sec\r\n");
                    PostEvent.EventType = PULSE_HAPTIC;
                    PostEvent.EventParam = 250;
                    PostHapticService(PostEvent);
                }
                break;
                case 'm':
                {
                    printf("TestShakeService: Pulsing Haptic Motor for 0.5 sec\r\n");
                    PostEvent.EventType = PULSE_HAPTIC;
                    PostEvent.EventParam = 500;
                    PostHapticService(PostEvent);
                }
                break;
                case ',':
                {
                    printf("TestShakeService: Pulsing Haptic Motor for 1 sec\r\n");
                    PostEvent.EventType = PULSE_HAPTIC;
                    PostEvent.EventParam = 1000;
                    PostHapticService(PostEvent);
                }
                break;
                case '.':
                {
                    printf("TestShakeService: Pulsing Haptic Motor for 2 sec\r\n");
                    PostEvent.EventType = PULSE_HAPTIC;
                    PostEvent.EventParam = 2000;
                    PostHapticService(PostEvent);
                }
                break;
                default:
                  ;
            }
        }
        break; 
        case SHAKE_SUCCESS:
        {
            printf("TestShakeService: Received SHAKE_SUCCESS event from ShakeService\r\n");
        }
        break;
        case SHAKE_FAILURE:
        {
            printf("TestShakeService: Received SHAKE_FAILURE event from ShakeService\r\n");
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

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/


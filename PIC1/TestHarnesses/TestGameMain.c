/****************************************************************************
 Module
   TestGameMain.c

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
#include "TestGameMain.h"
#include "../Services/GameMain.h"

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
     InitTestGameMain

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
bool InitTestGameMain(uint8_t Priority)
{
    printf("\n\n---------------------------------------------------------\n\r");
    printf("Initializing Test GameMain \n\r");
    
    printf( "Press 'q' to post RESET_GAME\n\r");
    printf( "Press 'w' to post START_BUTTON_PRESSED\n\r");
    printf( "Press 'e' to post CLOCK_TIMEOUT \n\r");

    printf( "Press 'r' to post ADD_INGREDIENTS_SUCCESS \n\r");
    printf( "Press 't' to post ADD_INGREDIENTS_FAILURE \n\r");
    
    printf( "Press 'y' to post SHAKE_SUCCESS \n\r");
    printf( "Press 'u' to post SHAKE_FAILURE \n\r");
    
    printf( "Press 'i' to post POUR_SUCCESS \n\r");
    printf( "Press 'o' to post POUR_FAILURE \n\r");

    MyPriority = Priority;

    return true;
}

/****************************************************************************
 Function
     PostTestGameMain

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
bool PostTestGameMain(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunTestGameMain

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
ES_Event_t RunTestGameMain(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    ES_Event_t PostEvent;
  
    switch (ThisEvent.EventType)
    {
        case ES_NEW_KEY:
        {
            /*
            printf("\n\rES_NEW_KEY received with -> %c <- in TestGameMain\r\n",
            (char)ThisEvent.EventParam);
            */
            switch (ThisEvent.EventParam)
            {
                case 'q':
                {
                    printf("TestGameMain: Posting RESET_GAME to GameMain\r\n");
                    PostEvent.EventType = RESET_GAME;
                    PostGameMain(PostEvent);
                }
                break;
                case 'w':
                {
                    printf("TestGameMain: Posting START_BUTTON_PRESSED to GameMain\r\n");
                    PostEvent.EventType = START_BUTTON_PRESSED;
                    PostGameMain(PostEvent);
                }
                break;
                case 'e':
                {
                    printf("TestGameMain: Posting CLOCK_TIMEOUT to GameMain\r\n");
                    PostEvent.EventType = CLOCK_TIMEOUT;
                    PostGameMain(PostEvent);
                }
                break;
                case 'r':
                {
                    printf("TestGameMain: Posting ADD_INGREDIENTS_SUCCESS to GameMain\r\n");
                    PostEvent.EventType = ADD_INGREDIENTS_SUCCESS;
                    PostGameMain(PostEvent);
                }
                break;
                case 't':
                {
                    printf("TestGameMain: Posting ADD_INGREDIENTS_FAILURE to GameMain\r\n");
                    PostEvent.EventType = ADD_INGREDIENTS_FAILURE;
                    PostGameMain(PostEvent);
                }
                break;
                case 'y':
                {
                    printf("TestGameMain: Posting SHAKE_SUCCESS to GameMain\r\n");
                    PostEvent.EventType = SHAKE_SUCCESS;
                    PostGameMain(PostEvent);
                }
                break;
                case 'u':
                {
                    printf("TestGameMain: Posting SHAKE_FAILURE to GameMain\r\n");
                    PostEvent.EventType = SHAKE_FAILURE;
                    PostGameMain(PostEvent);
                }
                break;
                case 'i':
                {
                    printf("TestGameMain: Posting POUR_SUCCESS to GameMain\r\n");
                    PostEvent.EventType = POUR_SUCCESS;
                    PostGameMain(PostEvent);
                }
                break;
                case 'o':
                {
                    printf("TestGameMain: Posting POUR_FAILURE to GameMain\r\n");
                    PostEvent.EventType = POUR_FAILURE;
                    PostGameMain(PostEvent);
                }
                break;
                
                default:
                  ;
            }
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


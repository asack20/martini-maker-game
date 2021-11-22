/****************************************************************************
 Module
   AddIngredientsHelperService.c

 Revision
   1.0.1

 Description
 * This is a helper services that maps events for AddIngredients to the commands
 * required to send to PIC2 via P2P comm

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 01/16/12 09:58 jec      began conversion from AddIngredientsHelperFSM.c
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "AddIngredientsHelperService.h"
#include "GameMain.h"
#include "P2PComm.h"

/*----------------------------- Module Defines ----------------------------*/
//P2P comm pulse times (in ms) that map to each event
#define START_TIME 15
#define RESET_TIME 35
#define SUCCESS_TIME 15
#define FAILURE_TIME 35
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
     InitAddIngredientsHelperService

 Parameters
     uint8_t : the priority of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
 Sets Priority for AddIngredientsHelperSerrvice
 
 Notes

 Author
 Andrew Sack
****************************************************************************/
bool InitAddIngredientsHelperService(uint8_t Priority)
{
    printf("Initializing AddIngredientsHelperService\n\r");

    MyPriority = Priority;
    
    return true;
}

/****************************************************************************
 Function
     PostAddIngredientsHelperService

 Parameters
     EF_Event_t ThisEvent ,the event to post to the queue

 Returns
     bool false if the Enqueue operation failed, true otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     
****************************************************************************/
bool PostAddIngredientsHelperService(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunAddIngredientsHelperService

 Parameters
   ES_Event_t : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
 Maps GameMain events to P2PComm signals and vice versa
 Notes

 Author
   
****************************************************************************/
ES_Event_t RunAddIngredientsHelperService(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    ES_Event_t PostEvent;

    switch (ThisEvent.EventType)
    {
        case START_ADD_INGREDIENTS: // from GameMain to P2PComm
        {
            printf("AddIngredientsHelper: START_ADD_INGREDIENTS received\n\r");
            //Need to Stop transmit before changing pulse
            PostEvent.EventType = P2P_STOP_TRANSMIT;
            PostP2PComm(PostEvent);
            
            // Post P2P_START_TRANSMIT event of correct length for START event
            PostEvent.EventType = P2P_START_TRANSMIT;
            PostEvent.EventParam = START_TIME;
            PostP2PComm(PostEvent);
        }
        break;
        case RESET_ADD_INGREDIENTS: // from GameMain to P2PComm
        {
            printf("AddIngredientsHelper: RESET_ADD_INGREDIENTS received\n\r");
            //Need to Stop transmit before changing pulse
            PostEvent.EventType = P2P_STOP_TRANSMIT;
            PostP2PComm(PostEvent);
            
            // Post P2P_START_TRANSMIT event of correct length for RESET event
            PostEvent.EventType = P2P_START_TRANSMIT;
            PostEvent.EventParam = RESET_TIME;
            PostP2PComm(PostEvent);
        }
        break;
        case P2P_SIGNAL_RECEIVED: // from P2PComm to GameMain
        {
            // stop transmitting whenever an event is received back
            //PostEvent.EventType = P2P_STOP_TRANSMIT;
            //PostP2PComm(PostEvent);
            
            if (SUCCESS_TIME == ThisEvent.EventParam)
            {
                //ADD_INGREDIENTS_SUCCESS event received
                //Post it to GameMain
                PostEvent.EventType = ADD_INGREDIENTS_SUCCESS;
                PostGameMain(PostEvent);
            }
            else if (FAILURE_TIME == ThisEvent.EventParam)
            {
                //ADD_INGREDIENTS_FAILURE event received
                //Post it to GameMain
                PostEvent.EventType = ADD_INGREDIENTS_FAILURE;
                PostGameMain(PostEvent);
            }
            else
            {
                printf("AddIngredientsHelper: Received unknown event of length %u from P2PComm",
                        ThisEvent.EventParam);
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


/****************************************************************************
 Module
   TestP2PService.c

 Revision
   1.0.1

 Description
   This is a template file for implementing a simple service under the
   Gen2 Events and Services Framework.

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 01/16/12 09:58 jec      began conversion from TestP2PFSM.c
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "TestP2PService.h"

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
     InitTestP2PService

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
bool InitTestP2PService(uint8_t Priority)
{
  ES_Event_t ThisEvent;

  MyPriority = Priority;
  
  printf("---------------------------------------------------------\n\r");
  puts("Initializing TestP2PService\r");
  printf( "Press '6' to StartTransmit with length 15 ms (START_ADD_INGREDIENTS)\n\r");
  printf( "Press '7' to StartTransmit with length 35 ms (RESET_ADD_INGREDIENTS)\n\r");
  printf( "Press '8' to StartTransmit 1 pulse length 15 ms (START_ADD_INGREDIENTS)\n\r");
  printf( "Press '9' to StartTransmit 1 pulse length 35 ms (RESET_ADD_INGREDIENTS)\n\r");
  printf( "Press '0' to StopTransmit \n\r");
  
  return true;
}

/****************************************************************************
 Function
     PostTestP2PService

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
bool PostTestP2PService(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunTestP2PService

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
ES_Event_t RunTestP2PService(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  ES_Event_t PostEvent;
  
  switch (ThisEvent.EventType)
  {
      case P2P_SIGNAL_RECEIVED:
      {
          printf("TestP2PService: Received Signal with length = %u\r\n", ThisEvent.EventParam);
      }
      break;
      case ES_NEW_KEY:
      {
          switch (ThisEvent.EventParam)
          {
              case '0':
              {
                  puts("TestP2PService: StoppingTransmit\r");
                  PostEvent.EventType = P2P_STOP_TRANSMIT;
                  PostP2PComm(PostEvent);
              }
              break;
              case '6':
              {
                  PostEvent.EventType = P2P_START_TRANSMIT;
                  PostEvent.EventParam = 15;
                  PostP2PComm(PostEvent);
                  puts("TestP2PService: StartingTransmit Len = 15 ms (START_ADD_INGREDIENTS)\r");
              }
              break;
              case '7':
              {
                  PostEvent.EventType = P2P_START_TRANSMIT;
                  PostEvent.EventParam = 35;
                  PostP2PComm(PostEvent);
                  puts("TestP2PService: StartingTransmit Len = 35 ms (RESET_ADD_INGREDIENTS)\r");
              }
              break;
              
              case '8':
              {
                  PostEvent.EventType = P2P_START_TRANSMIT;
                  PostEvent.EventParam = 15;
                  PostP2PComm(PostEvent);
                  // Timer to auto stop the transmit
                  ES_Timer_InitTimer(TESTP2P_TIMER, 2*15);
                  puts("TestP2PService: Starting SINGLE Transmit Len = 15 ms (START_ADD_INGREDIENTS)\r");
              }
              break;
              case '9':
              {
                  PostEvent.EventType = P2P_START_TRANSMIT;
                  PostEvent.EventParam = 35;
                  PostP2PComm(PostEvent);
                  // Timer to auto stop the transmit
                  ES_Timer_InitTimer(TESTP2P_TIMER, 2*35);
                  puts("TestP2PService: Starting SINGLE Transmit Len = 35 ms (RESET_ADD_INGREDIENTS)\r");
              }
              break;
              
              default:
                ;
          }
      }
      break;
      case ES_TIMEOUT:
      {
          puts("TestP2PService: Stopping SINGLE Transmit after timeout\r");
          PostEvent.EventType = P2P_STOP_TRANSMIT;
          PostP2PComm(PostEvent);
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


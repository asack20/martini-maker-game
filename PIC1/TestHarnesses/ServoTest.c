/****************************************************************************
 Module
   ServoTest.c

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
#include "ServoTest.h"

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
     InitServoTest

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
bool InitServoTest(uint8_t Priority)
{
    ES_Event_t ThisEvent;

    MyPriority = Priority;
    
    printf("---------------------------------------------------------\n\r");
    puts("Initializing ServoTest\r");
    printf( "Press '1' to open Servo Door \n\r");
    printf( "Press '2' to close Servo Door \n\r");
    printf( "Press '3' to Reset Clock \n\r");
    printf( "Press '4' to Start Clock \n\r");
    printf( "Press '5' to Pause Clock \n\r");

    return true;
}

/****************************************************************************
 Function
     PostServoTest

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
bool PostServoTest(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunServoTest

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
ES_Event_t RunServoTest(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  ES_Event_t PostEvent;
  
  switch (ThisEvent.EventType)
  {
      case ES_NEW_KEY:
      {
          /*
          printf("\n\rES_NEW_KEY received with -> %c <- in ServoTest\r\n",
          (char)ThisEvent.EventParam);
          */
          switch (ThisEvent.EventParam)
          {
              case '1':
              {
                  PostEvent.EventType = OPEN_DOOR;
                  PostDoorService(PostEvent);
              }
              break;
              case '2':
              {
                    PostEvent.EventType = CLOSE_DOOR;
                    PostDoorService(PostEvent);
              }
              break;
              case '3':
              {
                    PostEvent.EventType = RESET_CLOCK;
                    PostClockService(PostEvent);
              }
              break;
              case '4':
              {
                    PostEvent.EventType = START_CLOCK;
                    PostClockService(PostEvent);
              }
              break;
              case '5':
              {
                    PostEvent.EventType = PAUSE_CLOCK;
                    PostClockService(PostEvent);
              }
              break;
              default:
                ;
          }
      }
      break;
      case CLOCK_TIMEOUT:
          puts("ServoTest: Received ClockTimeout Event\r");
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


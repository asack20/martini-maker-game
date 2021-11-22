/****************************************************************************
 Module
   PrintService.c

 Revision
   1.0.1

 Description
   This is a template file for implementing a simple service under the
   Gen2 Events and Services Framework.

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 01/16/12 09:58 jec      began conversion from PrintFSM.c
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "PrintService.h"

/*----------------------------- Module Defines ----------------------------*/
#define ONE_SEC 1000
#define HALF_SEC (ONE_SEC / 2)
#define QTR_SEC (ONE_SEC / 4)
/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
*/

/*---------------------------- Module Variables ---------------------------*/
// with the introduction of Gen2, we need a module level Priority variable
static uint8_t MyPriority;
static char Message[] = "ME218a TA's are really awesome people and generous graders!";
static uint8_t msg_index = 0;
const uint8_t msg_sz = sizeof(Message)/sizeof(Message[0]) - 1;// avoid null char

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitPrintService

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
bool InitPrintService(uint8_t Priority)
{
  ES_Event_t ThisEvent;

  MyPriority = Priority;
  puts("Initializing PrintService:\r");
  puts("\tType ->s<- to restart message printing.\n\r");
  // post the initial transition event
  ThisEvent.EventType = ES_INIT;
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
     PostPrintService

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
bool PostPrintService(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunPrintService

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
ES_Event_t RunPrintService(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  ES_Event_t PostEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  switch (ThisEvent.EventType)
  {
    case ES_INIT: 
    {
      msg_index = 0; // reset message index
      ES_Timer_InitTimer(PRINTSERVICE_TIMER, QTR_SEC); // start timer
      puts("PrintService: ES_INIT received. Starting Message Scroll\r\n");
    }
    break;
    case ES_TIMEOUT:   // scroll 1 char
    {
      DB_printf("PrintService: ES_TIMEOUT received from Timer %d\r\n",
          ThisEvent.EventParam);
      
      // Post Add_Char event of next char to Display FSM
      PostEvent.EventType = ES_ADD_CHAR;
      PostEvent.EventParam = (uint16_t) Message[msg_index];
      PostDisplayFSM(PostEvent);
      
      if (msg_index < msg_sz - 1 ) // message not over
      {
          msg_index++; //move to next char
          //restart timer to scroll another character
          ES_Timer_InitTimer(PRINTSERVICE_TIMER, QTR_SEC);
      }
      else // done writing message
      {
          puts("PrintService: Message Complete\r\n");
      }
      
    }
    break;
 
    case ES_NEW_KEY:   // announce
    {
      if ('s' == ThisEvent.EventParam) // Restart command
      {
          puts("PrintService: ->s<- received. Restarting message.\r\n");
          // call init event on this service to restart
          DM_ClearDisplayBuffer(); // clear display buffer so msg starts fresh
          PostEvent.EventType = ES_INIT;
          PostPrintService(PostEvent);
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


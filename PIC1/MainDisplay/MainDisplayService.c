/****************************************************************************
 Module
   Service.c

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
#include "MainDisplayService.h"

/*----------------------------- Module Defines ----------------------------*/
#define ONE_SEC 1000
#define HALF_SEC (ONE_SEC / 2)
#define QTR_SEC (ONE_SEC / 4)
#define FIFTH_SEC (ONE_SEC / 5)
#define CHAR_TIME FIFTH_SEC // time to pause between scrolling characters
/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
*/

/*---------------------------- Module Variables ---------------------------*/
// with the introduction of Gen2, we need a module level Priority variable
static uint8_t MyPriority;

/* Message Indexes
 * 0 = Welcome 
 * 1 = Add Ingredients Start 
 * 2 = Shake Start 
 * 3 = Add Ingredients Failed
 * 4 = Clock Fail
 * 5 = Pour Start 
 * 6 = Shake Failed 
 * 7 = Game Win
 * 8 = Pour Failed
 */
static char Messages[][44] = {"Welcome Agent! Press Start to Begin    ", 
                            "Press Buttons to Add Ingredients    ",
                            "Shake the Shaker    ",
                            "Wrong Number of Ingredients! You Lose    ",
                            "Time's Up! You Lose    ",
                            "Twist to Pour the Martini    ",
                            "Failed Shaking. Way to be an Afshan    ",
                            "Excellent Work Agent! Enjoy your drink!    ",
                            "Martini Overflow Error. You Lose    "
                            };
static uint8_t Message_Lengths[] = {39, 36, 20, 41, 23, 29, 39, 43, 36};
static uint8_t msg_index = 0;
static uint8_t msg_size; //length of current message
static uint8_t WhichMessage; // which message in Messages array to use

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitMainDisplayService

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
bool InitMainDisplayService(uint8_t Priority)
{
    ES_Event_t ThisEvent;

    MyPriority = Priority;
    printf("Initializing Main Display Service\r\n");
    printf( "Press '\' to scroll test message\n\r");

    // post the initial transition event
    ThisEvent.EventType = CLEAR_MAIN_DISPLAY;
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
     PostMainDisplayService

 Parameters
     EF_Event_t ThisEvent ,the event to post to the queue

 Returns
     bool false if the Enqueue operation failed, true otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author

****************************************************************************/
bool PostMainDisplayService(ES_Event_t ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunMainDisplayService

 Parameters
   ES_Event_t : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
   add your description here
 Notes

 Author

****************************************************************************/
ES_Event_t RunMainDisplayService(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ES_Event_t PostEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    switch (ThisEvent.EventType)
    {
        case CLEAR_MAIN_DISPLAY: // Make display blank and stop scrolling
        {
            msg_index = 0; // reset message index
            DM_ClearDisplayBuffer(); // clear display buffer so msg starts fresh
            PostEvent.EventType = ES_ADD_CHAR;
            PostEvent.EventParam = ' '; // Add a space, so nothing is added
            PostDisplayFSM(PostEvent);
            printf("MainDisplayService: Clearing Display\r\n");
            
            // stop timer so scrolling stops
            ES_Timer_StopTimer(MAINDISPLAY_TIMER);
        }
        break;
        // Display message specified by EventParam statically
        case PRINT_MAIN_DISPLAY:
        {
            
        }
        break;
        // Scroll message specified by EventParam continuously
        case SCROLL_MAIN_DISPLAY:
        {
            // Save which message to display
            WhichMessage = ThisEvent.EventParam;
            // Select correct message length
            msg_size = Message_Lengths[WhichMessage];
            /*
            msg_size = sizeof(Messages[WhichMessage])/
                    sizeof(Messages[WhichMessage][0]) - 1;// avoid null char
            */
            
            printf("MainDisplayService: Starting to scroll message #%u\r\n", 
                    WhichMessage);
            
            msg_index = 0;
            DM_ClearDisplayBuffer(); // clear display buffer so msg starts fresh
            PostEvent.EventType = ES_INIT;
            PostMainDisplayService(PostEvent);
            
            ES_Timer_InitTimer(MAINDISPLAY_TIMER, CHAR_TIME);// start timer
            
        }
        break;

        case ES_TIMEOUT:   // scroll 1 char
        {
            /*
            printf("MainDisplayService: ES_TIMEOUT received from Timer %d\r\n",
                ThisEvent.EventParam);
            */
            // Post Add_Char event of next char to Display FSM
            PostEvent.EventType = ES_ADD_CHAR;
            PostEvent.EventParam = (uint16_t) Messages[WhichMessage][msg_index];
            PostDisplayFSM(PostEvent);
            
            if (msg_index < msg_size - 1 ) // message not over
            {
                msg_index++; //move to next char
                //restart timer to scroll another character
                ES_Timer_InitTimer(MAINDISPLAY_TIMER, CHAR_TIME);
            }
            else // done writing message
            {
                msg_index = 0; // go  back to beginning
                //restart timer to scroll another character
                ES_Timer_InitTimer(MAINDISPLAY_TIMER, CHAR_TIME);
                //puts("MainDisplayService: Message Complete. Restarting\r\n");
            }

        }
        break;

        case ES_NEW_KEY: 
        {
            if ('/' == ThisEvent.EventParam) // test case
            {
                puts("MainDisplayService: ->s<- received. Scrooling message #1\r\n");
               
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 1;
                PostMainDisplayService(PostEvent);
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


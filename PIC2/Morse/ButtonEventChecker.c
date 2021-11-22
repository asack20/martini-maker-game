/****************************************************************************
 Module
   ButtonEventChecker.c

 Revision
   1.0.1

 Description
   This is the sample for writing event checkers along with the event
   checkers used in the basic framework test harness.

 Notes
   Note the use of static variables in sample event checker to detect
   ONLY transitions.

 History
 When           Who     What/Why
 -------------- ---     --------
 08/06/13 13:36 jec     initial version
****************************************************************************/

// this will pull in the symbolic definitions for events, which we will want
// to post in response to detecting events
#include "ES_Configure.h"
// This gets us the prototype for ES_PostAll
#include "ES_Framework.h"
// this will get us the structure definition for events, which we will need
// in order to post events in response to detecting events
#include "ES_Events.h"
// if you want to use distribution lists then you need those function
// definitions too.
#include "ES_PostList.h"
// This include will pull in all of the headers from the service modules
// providing the prototypes for all of the post functions
#include "ES_ServiceHeaders.h"
// this test harness for the framework references the serial routines that
// are defined in ES_Port.c
#include "ES_Port.h"
// include our own prototypes to insure consistency between header &
// actual functions definition
#include "ButtonEventChecker.h"

/*----------------------------- Module Defines ----------------------------*/
#define BUTTON_PORT _Port_B
#define BUTTON_PIN _Pin_3
#define BUTTON_VAL PORTBbits.RB3
/*---------------------------- Module Variables ---------------------------*/
static bool LastButtonState;

/*------------------------------ Module Code ------------------------------*/

/****************************************************************************
Function
 * InitButtonStatus
Parameters
 * None
Returns
 * None
Description
 * Configure digital input for button and Set LastButtonState to initial value
Notes

Author
Andrew Sack
****************************************************************************/
void InitButtonStatus(void)
{
    puts("Initializing Button Event Checker\n\r");
    //Initialize digital input for calibrate button
    PortSetup_ConfigureDigitalInputs(BUTTON_PORT, BUTTON_PIN);
    //Set LastButtonState to value read from button pin
    LastButtonState = (bool) BUTTON_VAL;
}

/****************************************************************************
Function
 * CheckButtonEvents
Parameters
 * None
Returns
 * True if an event posted
Description
 * Checks if button state changed and, if yes, posts event to MorseElements 
 * with button change type
Notes

Author
Andrew Sack
****************************************************************************/
bool CheckButtonEvents(void)
{
    bool ReturnVal = false;
    bool CurrentButtonState;
    ES_Event_t PostEvent;
    
    // Set CurrentButtonState to state read from port pin
    CurrentButtonState = (bool) BUTTON_VAL;
    // If the CurrentButtonState is different from the LastButtonState
    if (CurrentButtonState != LastButtonState)
    {
        ReturnVal = true;
        if (1 == CurrentButtonState) //Button is pressed
        {
            //puts("ButtonEventChecker: ButtonDown Event\n\r");
            // PostEvent ButtonDown to MorseElements queue
            PostEvent.EventType = ButtonDown;
            ES_PostList00(PostEvent); 
        }
        else // button is Released
        {
            //puts("ButtonEventChecker: ButtonUp Event\n\r");
            // PostEvent ButtonUp to MorseElements queue
            PostEvent.EventType = ButtonUp;
            PostMorseElements(PostEvent);
        }
    }
    LastButtonState = CurrentButtonState;
    return ReturnVal;
}


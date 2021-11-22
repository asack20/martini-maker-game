/****************************************************************************
 Module
   StartButtonService.c

 Revision
   1.0.1

 Description
   This is the service to demonstrate the Servo library

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/30/21 09:58 jec      started work based on TestHarnessService0
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
// Hardware
#include <xc.h>

// Event & Services Framework
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "ES_Port.h"

// PWM Lib
#include "../HALs/PIC32PortHAL.h"

// This module
#include "StartButtonService.h"
#include "GameMain.h"


/*----------------------------- Module Defines ----------------------------*/
#define START_BUTTON_PORT _Port_A //Physical pin 12
#define START_BUTTON_PIN _Pin_4
#define START_BUTTON_VAL PORTAbits.RA4

#define START_LED_PORT _Port_B //Physical pin 14 (5v tolerant)
#define START_LED_PIN _Pin_5
#define START_LED_LAT LATBbits.LATB5


/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
*/

/*---------------------------- Module Variables ---------------------------*/
// with the introduction of Gen2, we need a module level Priority variable
static uint8_t MyPriority;
static bool LastButtonState;

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitStartButtonService

 Parameters
     uint8_t : the priorty of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, and 
     Initializes pins for start button input and LED
 Notes

 Author
    
****************************************************************************/
bool InitStartButtonService(uint8_t Priority)
{
    puts("Initializing StartButtonService\r");
    ES_Event_t ThisEvent;
    bool ReturnVal = true; // assume that everything will be OK
    
    MyPriority = Priority;
    
    //call InitStartButtonStatus() to configure button pin
    InitStartButtonStatus();
    
    //Configure pin for LED as digital output
    PortSetup_ConfigureDigitalOutputs(START_LED_PORT, START_LED_PIN);
    
    // turn off LED on initialization
    ThisEvent.EventType = DISABLE_START_LED;
    if (!ES_PostToService(MyPriority, ThisEvent))
    {
        ReturnVal = false;
    }
    else
    {
      // no else clause
    }
    return ReturnVal;
}

/****************************************************************************
 Function
     PostStartButtonService

 Parameters
     ES_Event ThisEvent ,the event to post to the queue

 Returns
     bool false if the Enqueue operation failed, true otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     
****************************************************************************/
bool PostStartButtonService(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunStartButtonService

 Parameters
   ES_Event : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
 Switch statement to respond to ENABLE_START_LED and DISABLE_START_LED events 
 and toggle light accordingly
 Notes

 Author

****************************************************************************/
ES_Event_t RunStartButtonService(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  
  switch (ThisEvent.EventType)
  {
    case ENABLE_START_LED: //turn led on
    {
        puts("StartButtonService: Turning on Start Button LED\r");
        //Set lat register to 1 to turn on
        START_LED_LAT = 1;
    }
    break;
    case DISABLE_START_LED:   // turn led off
    {
        puts("StartButtonService: Turning off Start Button LED\r");
        //Set lat register to 0 to turn off
        START_LED_LAT = 0;
    }
    break;
    
    default:
    {}
    break;
  }

  return ReturnEvent;
}

/****************************************************************************
Function
 * InitStartButtonStatus
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
void InitStartButtonStatus(void)
{
    printf("Initializing Start Button Event Checker\n\r");
    //Initialize digital input for start button
    PortSetup_ConfigureDigitalInputs(START_BUTTON_PORT, START_BUTTON_PIN);
    //configure internal pull up resistor
    PortSetup_ConfigurePullUps(START_BUTTON_PORT, START_BUTTON_PIN);
    //Set LastButtonState to value read from button pin
    LastButtonState = (bool) START_BUTTON_VAL;
}

/****************************************************************************
Function
 * CheckStartButtonEvents
Parameters
 * None
Returns
 * True if an event posted
Description
 * Checks if button state changed from unpressed to pressed and, if yes,
 * posts event to GameMain.
Notes

Author
Andrew Sack
****************************************************************************/
bool CheckStartButtonEvents(void)
{
    bool ReturnVal = false;
    bool CurrentButtonState;
    ES_Event_t PostEvent;
    
    // Set CurrentButtonState to state read from port pin
    CurrentButtonState = (bool) START_BUTTON_VAL;
    // If the CurrentButtonState is different from the LastButtonState
    if (CurrentButtonState != LastButtonState)
    {  
        if (0 == CurrentButtonState) //Button is pressed
        {
            printf("CheckStartButtonEvents: Button press detected\r\n");
            ReturnVal = true;
            PostEvent.EventType = START_BUTTON_PRESSED;
            PostGameMain(PostEvent); 
            
        }
    }
    LastButtonState = CurrentButtonState;
    return ReturnVal;
}


/***************************************************************************
 private functions
 ***************************************************************************/

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/


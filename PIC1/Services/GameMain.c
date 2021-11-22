/****************************************************************************
 Module
   GameMain.c

 Revision
   1.0.1

 Description
 * This is the file for the GameMain State Machine, which controls the 
 * shake stage of the game. 
 * 

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 01/15/12 11:12 jec      revisions for Gen2 framework
 11/07/11 11:26 jec      made the queue static
 10/30/11 17:59 jec      fixed references to CurrentEvent in RunTemplateSM()
 10/23/11 18:20 jec      began conversion from SMTemplate.c (02/20/07 rev)
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "GameMain.h"
#include "../TestHarnesses/TestGameMain.h"
// Other Services
#include "ClockService.h"
#include "DoorService.h"
#include "ShakeService.h"
#include "HapticService.h"
#include "StartButtonService.h"
#include "../PourService/PourService.h"
#include "AddIngredientsHelperService.h"
#include "P2PComm.h"
#include "../MainDisplay/MainDisplayService.h"

/*----------------------------- Module Defines ----------------------------*/
#define ONE_SEC 1000
#define END_STATE_TIME 15*ONE_SEC // time to show end UI

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match htat of enum in header file
static GameState_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitGameMain

 Parameters
     uint8_t : the priorty of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, sets up the initial transition and does any
     other required initialization for this state machine
 Notes

 Author
 * Andrew Sack
****************************************************************************/
bool InitGameMain(uint8_t Priority)
{
    printf("Initializing GameMain FSM \n\r");

    MyPriority = Priority;
    
    // put us into the GameInit State
    CurrentState = GameInitState;
    
    // post the initial transition event
    ES_Event_t ThisEvent;
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
     PostGameMain

 Parameters
     ES_Event_t ThisEvent , the event to post to the queue

 Returns
     boolean False if the Enqueue operation failed, True otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
 * Andrew Sack
****************************************************************************/
bool PostGameMain(ES_Event_t ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunGameMain

 Parameters
   ES_Event_t : the event to process

 Returns
   ES_Event_t, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
 * Main State machine that progresses through stages of game and controls all
 * other services
 Notes
   uses nested switch/case to implement the machine.
 Author
 * Andrew Sack
****************************************************************************/
ES_Event_t RunGameMain(ES_Event_t ThisEvent)
{
    ES_Event_t ReturnEvent;
    ES_Event_t PostEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    switch (CurrentState)
    {
        case GameInitState:
        {
            if(ES_INIT == ThisEvent.EventType)
            {
                printf("---------------------------------------------------------\n\r");
                printf("GameMain: Initializing Game. Post RESET events for all services\r\n");
                
                //NEED TO ADD
                // Post Reset commands
                // Check everything is OK
                //Post Reset events to all required services
                
                //RESET_CLOCK
                PostEvent.EventType = RESET_CLOCK;
                PostClockService(PostEvent);
                
                //RESET_ADD_INGREDIENTS
                PostEvent.EventType = RESET_ADD_INGREDIENTS;
                PostAddIngredientsHelperService(PostEvent);
                //RESET_SHAKE
                PostEvent.EventType = RESET_SHAKE;
                PostShakeService(PostEvent);
                //RESET_POUR
                PostEvent.EventType = RESET_POUR;
                PostPourService(PostEvent);
                // Re-Init Pour Display
                PostEvent.EventType = ES_INIT;
                PostPourService(PostEvent);
                //CLOSE_DOOR
                PostEvent.EventType = CLOSE_DOOR;
                PostDoorService(PostEvent);
                
                //STOP_HAPTIC
                PostEvent.EventType = STOP_HAPTIC;
                PostHapticService(PostEvent);
                
                //DISABLE_START_LED
                PostEvent.EventType = DISABLE_START_LED;
                PostStartButtonService(PostEvent);
                
                /*
                 * DON't want this so it will transmit reset continuously
                //P2P_STOP_TRANSMIT
                PostEvent.EventType = P2P_STOP_TRANSMIT;
                PostP2PComm(PostEvent);
                */ 
                //Clear All displays
                PostEvent.EventType = CLEAR_MAIN_DISPLAY;
                PostMainDisplayService(PostEvent);
                
                // Post GAME_INIT_COMPLETE event to this service
                PostEvent.EventType = GAME_INIT_COMPLETE;
                PostGameMain(PostEvent);
                CurrentState = WelcomeState;   
            }
        }
        break;
        case WelcomeState:
        {
            if(GAME_INIT_COMPLETE == ThisEvent.EventType)
            {
                printf("---------------------------------------------------------\n\r");
                printf("GameMain: Game Init Complete. In welcome state\r\n");
                //Turn on Start Button LED
                PostEvent.EventType = ENABLE_START_LED;
                PostStartButtonService(PostEvent);
                //Main Display Scroll Welcome Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 0;
                PostMainDisplayService(PostEvent);
            }
            else if (START_BUTTON_PRESSED == ThisEvent.EventType)
            {
                printf("GameMain: Start Button Pressed. Starting AddIngredients Stage\r\n");

                //Main Display Add Ingredients Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 1;
                PostMainDisplayService(PostEvent);
                
                //turn off start button led
                PostEvent.EventType = DISABLE_START_LED;
                PostStartButtonService(PostEvent);
                
                //Post START_ADD_INGREDIENTS event to AddIngredientsHelper service
                PostEvent.EventType = START_ADD_INGREDIENTS;
                PostAddIngredientsHelperService(PostEvent);
                
                //Start Game Clock
                PostEvent.EventType = START_CLOCK;
                PostClockService(PostEvent);
                
                //Kick start the pour display
                PostEvent.EventType = RESET_POUR;
                PostPourService(PostEvent);
                
                //Set CurrentState to AddIngredientsState
                CurrentState = AddIngredientsState;    
            }
            else if (RESET_GAME == ThisEvent.EventType)
            {
                printf("GameMain: RESET_GAME received. Going to GameInitState and resetting all services\r\n");
                // Go to GameInitState
                CurrentState = GameInitState;
                //Post an ES_INIT Event
                PostEvent.EventType = ES_INIT;
                PostGameMain(PostEvent);
            }
        }
        break;
        case AddIngredientsState:
        {
            if(ADD_INGREDIENTS_SUCCESS == ThisEvent.EventType)
            {
                printf("GameMain: Add Ingredients Success. Starting Shake Stage\r\n");
                
                PostEvent.EventType = START_SHAKE;
                PostShakeService(PostEvent);
                
                //Main Display Shake Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 2;
                PostMainDisplayService(PostEvent);
                
                CurrentState = ShakeState;
            }
            else if(ADD_INGREDIENTS_FAILURE == ThisEvent.EventType)
            {
                printf("GameMain: Add Ingredients Failed. Going to Game Failure State\r\n");
                
                PostEvent.EventType = GAME_SHOW_FAILURE;
                PostGameMain(PostEvent);
                CurrentState = GameFailureState;
                
                //Main Display Add Ingredients Failed Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 3;
                PostMainDisplayService(PostEvent);
            }
            else if(CLOCK_TIMEOUT == ThisEvent.EventType)
            {
                printf("GameMain: Clock ran out of time in Add Ingredients State. Going to Game Failure State\r\n");
                
                //Main Display Clock Failed Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 4;
                PostMainDisplayService(PostEvent);
                
                //RESET_ADD_INGREDIENTS when timeout during it running
                PostEvent.EventType = RESET_ADD_INGREDIENTS;
                PostAddIngredientsHelperService(PostEvent);
                
                PostEvent.EventType = GAME_SHOW_FAILURE;
                PostGameMain(PostEvent);
                CurrentState = GameFailureState;
            }
            else if (RESET_GAME == ThisEvent.EventType)
            {
                printf("GameMain: RESET_GAME received. Going to GameInitState and resetting all services\r\n");
                // Go to GameInitState
                CurrentState = GameInitState;
                //Post an ES_INIT Event
                PostEvent.EventType = ES_INIT;
                PostGameMain(PostEvent);
            }
        }
        break;
        case ShakeState:
        {
            if(SHAKE_SUCCESS == ThisEvent.EventType)
            {
                printf("GameMain: Shake Success. Starting Pour Stage\r\n");
                PostEvent.EventType = START_POUR;
                PostPourService(PostEvent);
                printf("GameMain: NEED TO POST START_POUR\r\n");
                
                //Main Display Pour Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 5;
                PostMainDisplayService(PostEvent);
                
                CurrentState = PourState;
            }
            else if(SHAKE_FAILURE == ThisEvent.EventType)
            {
                printf("GameMain: Shake Failed. Going to Game Failure State\r\n");
                
                PostEvent.EventType = GAME_SHOW_FAILURE;
                PostGameMain(PostEvent);
                CurrentState = GameFailureState;
                
                //Main Display Shake Failed Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 6;
                PostMainDisplayService(PostEvent);
            }
            else if(CLOCK_TIMEOUT == ThisEvent.EventType)
            {
                printf("GameMain: Clock ran out of time in Shake State. Going to Game Failure State\r\n");
                
                PostEvent.EventType = GAME_SHOW_FAILURE;
                PostGameMain(PostEvent);
                CurrentState = GameFailureState;
                
                //RESET_SHAKE when timeout while its running
                PostEvent.EventType = RESET_SHAKE;
                PostShakeService(PostEvent);
                
                //Main Display Clock Failed Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 4;
                PostMainDisplayService(PostEvent);
            }
            else if (RESET_GAME == ThisEvent.EventType)
            {
                printf("GameMain: RESET_GAME received. Going to GameInitState and resetting all services\r\n");
                // Go to GameInitState
                CurrentState = GameInitState;
                //Post an ES_INIT Event
                PostEvent.EventType = ES_INIT;
                PostGameMain(PostEvent);
            }
        }
        break;
        case PourState:
        {
            if(POUR_SUCCESS == ThisEvent.EventType)
            {
                printf("GameMain: Pour Success. Game Won\r\n");
                
                PostEvent.EventType = GAME_SHOW_SUCCESS;
                PostGameMain(PostEvent);
                
                //Main Display Game Win Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 7;
                PostMainDisplayService(PostEvent);

                CurrentState = GameSuccessState;
            }
            else if(POUR_FAILURE == ThisEvent.EventType)
            {
                printf("GameMain: POUR Failed. Going to Game Failure State\r\n");
                
                PostEvent.EventType = GAME_SHOW_FAILURE;
                PostGameMain(PostEvent);
                CurrentState = GameFailureState;
                
                //Main Display Pour Failed Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 8;
                PostMainDisplayService(PostEvent);
            }
            else if(CLOCK_TIMEOUT == ThisEvent.EventType)
            {
                printf("GameMain: Clock ran out of time in Pour State. Going to Game Failure State\r\n");
                
                PostEvent.EventType = GAME_SHOW_FAILURE;
                PostGameMain(PostEvent);
                CurrentState = GameFailureState;
                
                //RESET_POUR when timeout while its running
                PostEvent.EventType = RESET_POUR;
                PostPourService(PostEvent);
                
                //Main Display Clock Failed Message
                PostEvent.EventType = SCROLL_MAIN_DISPLAY;
                PostEvent.EventParam = 4;
                PostMainDisplayService(PostEvent);
            }
            else if (RESET_GAME == ThisEvent.EventType)
            {
                printf("GameMain: RESET_GAME received. Going to GameInitState and resetting all services\r\n");
                // Go to GameInitState
                CurrentState = GameInitState;
                //Post an ES_INIT Event
                PostEvent.EventType = ES_INIT;
                PostGameMain(PostEvent);
            }
        }
        break;
        case GameSuccessState:
        {
            if(GAME_SHOW_SUCCESS == ThisEvent.EventType)
            {
                printf("GameMain: Game was won. Show Success UI. Open Door\r\n");
                ES_Timer_InitTimer(GAME_TIMER, END_STATE_TIME);
                
                //Open Door
                PostEvent.EventType = OPEN_DOOR;
                PostDoorService(PostEvent);
                
                //Pause Clock
                PostEvent.EventType = PAUSE_CLOCK;
                PostClockService(PostEvent);
            }
            else if (ES_TIMEOUT == ThisEvent.EventType)
            {
                printf("GameMain: End state finished. Resetting game\r\n");
                CurrentState = GameInitState;
                PostEvent.EventType = ES_INIT;
                PostGameMain(PostEvent);
            }
            else if (RESET_GAME == ThisEvent.EventType)
            {
                printf("GameMain: RESET_GAME received. Going to GameInitState and resetting all services\r\n");
                // Go to GameInitState
                CurrentState = GameInitState;
                //Post an ES_INIT Event
                PostEvent.EventType = ES_INIT;
                PostGameMain(PostEvent);
            }
        }
        break;
        case GameFailureState:
        {
            if(GAME_SHOW_FAILURE == ThisEvent.EventType)
            {
                printf("GameMain: Game was failed. Show failure UI\r\n");
                ES_Timer_InitTimer(GAME_TIMER, END_STATE_TIME);
                
                //Pause Clock
                PostEvent.EventType = PAUSE_CLOCK;
                PostClockService(PostEvent);
            }
            else if (ES_TIMEOUT == ThisEvent.EventType)
            {
                printf("GameMain: End state finished. Resetting game\r\n");
                CurrentState = GameInitState;
                PostEvent.EventType = ES_INIT;
                PostGameMain(PostEvent);
            }
            else if (RESET_GAME == ThisEvent.EventType)
            {
                printf("GameMain: RESET_GAME received. Going to GameInitState and resetting all services\r\n");
                // Go to GameInitState
                CurrentState = GameInitState;
                //Post an ES_INIT Event
                PostEvent.EventType = ES_INIT;
                PostGameMain(PostEvent);
            }
        }
        break;
        default:
          ;
    }                                   // end switch on Current State
    return ReturnEvent;
}

/****************************************************************************
 Function
     QueryGameMain

 Parameters
     None

 Returns
     GameState_t The current state of the GameMain state machine

 Description
     returns the current state of the GameMain state machine
 Notes

 Author
 * Andrew Sack
****************************************************************************/
GameState_t QueryGameMain(void)
{
    return CurrentState;
}


/***************************************************************************
 private functions
 ***************************************************************************/


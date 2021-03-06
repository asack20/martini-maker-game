/****************************************************************************
 Module
     ES_Configure.h
 Description
     This file contains macro definitions that are edited by the user to
     adapt the Events and Services framework to a particular application.
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 12/19/16 20:19  jec     removed EVENT_CHECK_HEADER definition. This goes with
                         the V2.3 move to a single wrapper for event checking
                         headers
  10/11/15 18:00 jec     added new event type ES_SHORT_TIMEOUT
  10/21/13 20:54 jec     lots of added entries to bring the number of timers
                         and services up to 16 each
 08/06/13 14:10 jec      removed PostKeyFunc stuff since we are moving that
                         functionality out of the framework and putting it
                         explicitly into the event checking functions
 01/15/12 10:03 jec      started coding
*****************************************************************************/

#ifndef ES_CONFIGURE_H
#define ES_CONFIGURE_H

/****************************************************************************/
// The maximum number of services sets an upper bound on the number of
// services that the framework will handle. Reasonable values are 8 and 16
// corresponding to an 8-bit(uint8_t) and 16-bit(uint16_t) Ready variable size
#define MAX_NUM_SERVICES 16

/****************************************************************************/
// This macro determines that nuber of services that are *actually* used in
// a particular application. It will vary in value from 1 to MAX_NUM_SERVICES
#define NUM_SERVICES 16

/****************************************************************************/
// These are the definitions for Service 0, the lowest priority service.
// Every Events and Services application must have a Service 0. Further
// services are added in numeric sequence (1,2,3,...) with increasing
// priorities
// the header file with the public function prototypes
#define SERV_0_HEADER "../Services/GameMain.h"
// the name of the Init function
#define SERV_0_INIT InitGameMain
// the name of the run function
#define SERV_0_RUN RunGameMain
// How big should this services Queue be?
#define SERV_0_QUEUE_SIZE 3

/****************************************************************************/
// The following sections are used to define the parameters for each of the
// services. You only need to fill out as many as the number of services
// defined by NUM_SERVICES
/****************************************************************************/
// These are the definitions for Service 1
#if NUM_SERVICES > 1
// the header file with the public function prototypes
#define SERV_1_HEADER "../TestHarnesses/TestGameMain.h"
// the name of the Init function
#define SERV_1_INIT InitTestGameMain
// the name of the run function
#define SERV_1_RUN RunTestGameMain
// How big should this services Queue be?
#define SERV_1_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 2
#if NUM_SERVICES > 2
// the header file with the public function prototypes
#define SERV_2_HEADER "../Services/ClockService.h"
// the name of the Init function
#define SERV_2_INIT InitClockService
// the name of the run function
#define SERV_2_RUN RunClockService
// How big should this services Queue be?
#define SERV_2_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 3
#if NUM_SERVICES > 3
// the header file with the public function prototypes
#define SERV_3_HEADER "../Services/DoorService.h"
// the name of the Init function
#define SERV_3_INIT InitDoorService
// the name of the run function
#define SERV_3_RUN RunDoorService
// How big should this services Queue be?
#define SERV_3_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 4
#if NUM_SERVICES > 4
// the header file with the public function prototypes
#define SERV_4_HEADER "../Services/ShakeService.h"
// the name of the Init function
#define SERV_4_INIT InitShakeService
// the name of the run function
#define SERV_4_RUN RunShakeService
// How big should this services Queue be?
#define SERV_4_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 5
#if NUM_SERVICES > 5
// the header file with the public function prototypes
#define SERV_5_HEADER "../Services/HapticService.h"
// the name of the Init function
#define SERV_5_INIT InitHapticService
// the name of the run function
#define SERV_5_RUN RunHapticService
// How big should this services Queue be?
#define SERV_5_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 6
#if NUM_SERVICES > 6
// the header file with the public function prototypes
#define SERV_6_HEADER "../TestHarnesses/TestDistanceSensor.h"
// the name of the Init function
#define SERV_6_INIT InitTestDistanceSensor
// the name of the run function
#define SERV_6_RUN RunTestDistanceSensor
// How big should this services Queue be?
#define SERV_6_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 7
#if NUM_SERVICES > 7
// the header file with the public function prototypes
#define SERV_7_HEADER "../TestHarnesses/TestShakeService.h"
// the name of the Init function
#define SERV_7_INIT InitTestShakeService
// the name of the run function
#define SERV_7_RUN RunTestShakeService
// How big should this services Queue be?
#define SERV_7_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 8
#if NUM_SERVICES > 8
// the header file with the public function prototypes
#define SERV_8_HEADER "../TestHarnesses/ServoTest.h"
// the name of the Init function
#define SERV_8_INIT InitServoTest
// the name of the run function
#define SERV_8_RUN RunServoTest
// How big should this services Queue be?
#define SERV_8_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 9
#if NUM_SERVICES > 9
// the header file with the public function prototypes
#define SERV_9_HEADER "../Services/StartButtonService.h"
// the name of the Init function
#define SERV_9_INIT InitStartButtonService
// the name of the run function
#define SERV_9_RUN RunStartButtonService
// How big should this services Queue be?
#define SERV_9_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 10
#if NUM_SERVICES > 10
// the header file with the public function prototypes
#define SERV_10_HEADER "../PourService/PourService.h"
// the name of the Init function
#define SERV_10_INIT InitPourService
// the name of the run function
#define SERV_10_RUN RunPourService
// How big should this services Queue be?
#define SERV_10_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 11
#if NUM_SERVICES > 11
// the header file with the public function prototypes
#define SERV_11_HEADER "../Services/P2PComm.h"
// the name of the Init function
#define SERV_11_INIT InitP2PComm
// the name of the run function
#define SERV_11_RUN RunP2PTransmit
// How big should this services Queue be?
#define SERV_11_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 12
#if NUM_SERVICES > 12
// the header file with the public function prototypes
#define SERV_12_HEADER "../Services/AddIngredientsHelperService.h"
// the name of the Init function
#define SERV_12_INIT InitAddIngredientsHelperService
// the name of the run function
#define SERV_12_RUN RunAddIngredientsHelperService
// How big should this services Queue be?
#define SERV_12_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 13
#if NUM_SERVICES > 13
// the header file with the public function prototypes
#define SERV_13_HEADER "../TestHarnesses/TestP2PService.h"
// the name of the Init function
#define SERV_13_INIT InitTestP2PService
// the name of the run function
#define SERV_13_RUN RunTestP2PService
// How big should this services Queue be?
#define SERV_13_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 14
#if NUM_SERVICES > 14
// the header file with the public function prototypes
#define SERV_14_HEADER "../MainDisplay/DisplayFSM.h"
// the name of the Init function
#define SERV_14_INIT InitDisplayFSM
// the name of the run function
#define SERV_14_RUN RunDisplayFSM
// How big should this services Queue be?
#define SERV_14_QUEUE_SIZE 3
#endif

/****************************************************************************/
// These are the definitions for Service 15
#if NUM_SERVICES > 15
// the header file with the public function prototypes
#define SERV_15_HEADER "../MainDisplay/MainDisplayService.h"//"../MainDisplay/PrintService.h"
// the name of the Init function
#define SERV_15_INIT InitMainDisplayService//InitPrintService
// the name of the run function
#define SERV_15_RUN RunMainDisplayService//RunPrintService
// How big should this services Queue be?
#define SERV_15_QUEUE_SIZE 3
#endif

/****************************************************************************/
// Name/define the events of interest
// Universal events occupy the lowest entries, followed by user-defined events
typedef enum
{
    ES_NO_EVENT = 0,
    ES_ERROR,                 /* used to indicate an error from the service */
    ES_INIT,                  /* used to transition from initial pseudo-state */
    ES_TIMEOUT,               /* signals that the timer has expired */
    ES_SHORT_TIMEOUT,         /* signals that a short timer has expired */
    /* User-defined events start here */
    ES_NEW_KEY,               /* signals a new key received from terminal */
    /*MainDisplay Events*/
    ES_ADD_CHAR,
    ES_UPDATE_DISPLAY,
    PRINT_MAIN_DISPLAY,
    SCROLL_MAIN_DISPLAY,
    CLEAR_MAIN_DISPLAY,
    /*GameMain Events*/
    GAME_INIT_COMPLETE,
    RESET_GAME,
    GAME_TIMEOUT,
    GAME_SHOW_SUCCESS,
    GAME_SHOW_FAILURE,       
    /*PourService Events*/
    START_POUR,
    RESET_POUR,
    POUR_SUCCESS,
    POUR_FAILURE,
    POUR_DELTA_DETECT,                // Detected change in analog in
    POUR_UPDATE_DISPLAY,          // Update Display to match buffer
    /*ShakeService Events*/
    DISTANCE_VALUE,
    START_SHAKE,
    RESET_SHAKE,
    SHAKE_SUCCESS,
    SHAKE_FAILURE,
    SHAKE_TOP,
    SHAKE_BOTTOM,
    /*AddIngredients Events*/
    START_ADD_INGREDIENTS,
    RESET_ADD_INGREDIENTS,
    ADD_INGREDIENTS_SUCCESS,
    ADD_INGREDIENTS_FAILURE,
    /*ClockService Events*/
    START_CLOCK,
    PAUSE_CLOCK,
    RESET_CLOCK,
    CLOCK_TIMEOUT,
    /*DoorService Events*/
    OPEN_DOOR,
    CLOSE_DOOR,
    /*HapticService Events*/
    START_HAPTIC,
    STOP_HAPTIC,
    PULSE_HAPTIC,
    MULTI_PULSE_HAPTIC,
    /*StartButtonService Events*/
    START_BUTTON_PRESSED,
    ENABLE_START_LED,
    DISABLE_START_LED,
    /*P2PComm Events*/
    P2P_SIGNAL_RECEIVED,
    P2P_START_TRANSMIT,
    P2P_STOP_TRANSMIT

}ES_EventType_t;

/****************************************************************************/
// These are the definitions for the Distribution lists. Each definition
// should be a comma separated list of post functions to indicate which
// services are on that distribution list.
#define NUM_DIST_LISTS 2
#if NUM_DIST_LISTS > 0
#define DIST_LIST0 PostGameMain, PostTestShakeService
#endif
#if NUM_DIST_LISTS > 1
#define DIST_LIST1 PostAddIngredientsHelperService
#endif
#if NUM_DIST_LISTS > 2
#define DIST_LIST2 PostTemplateFSM
#endif
#if NUM_DIST_LISTS > 3
#define DIST_LIST3 PostTemplateFSM
#endif
#if NUM_DIST_LISTS > 4
#define DIST_LIST4 PostTemplateFSM
#endif
#if NUM_DIST_LISTS > 5
#define DIST_LIST5 PostTemplateFSM
#endif
#if NUM_DIST_LISTS > 6
#define DIST_LIST6 PostTemplateFSM
#endif
#if NUM_DIST_LISTS > 7
#define DIST_LIST7 PostTemplateFSM
#endif

// This is a rename of the PostList function
#define PostShakeDistList ES_PostList00
#define PostP2PCommDistList ES_PostList01

/****************************************************************************/
// This is the list of event checking functions
#define EVENT_CHECK_LIST Check4Keystroke, CheckShakeEvents, CheckStartButtonEvents, CheckPour, CheckP2PReceiveEvents

/****************************************************************************/
// These are the definitions for the post functions to be executed when the
// corresponding timer expires. All 16 must be defined. If you are not using
// a timer, then you should use TIMER_UNUSED
// Unlike services, any combination of timers may be used and there is no
// priority in servicing them
#define TIMER_UNUSED ((pPostFunc)0)
#define TIMER0_RESP_FUNC PostGameMain
#define TIMER1_RESP_FUNC PostClockService
#define TIMER2_RESP_FUNC PostPourService
#define TIMER3_RESP_FUNC PostP2PComm
#define TIMER4_RESP_FUNC PostTestP2PService
#define TIMER5_RESP_FUNC PostMainDisplayService
#define TIMER6_RESP_FUNC TIMER_UNUSED//PostPrintService
#define TIMER7_RESP_FUNC PostTestDistanceSensor
#define TIMER8_RESP_FUNC PostHapticService
#define TIMER9_RESP_FUNC TIMER_UNUSED
#define TIMER10_RESP_FUNC TIMER_UNUSED
#define TIMER11_RESP_FUNC TIMER_UNUSED
#define TIMER12_RESP_FUNC TIMER_UNUSED
#define TIMER13_RESP_FUNC TIMER_UNUSED
#define TIMER14_RESP_FUNC TIMER_UNUSED
#define TIMER15_RESP_FUNC TIMER_UNUSED

/****************************************************************************/
// Give the timer numbers symbolc names to make it easier to move them
// to different timers if the need arises. Keep these definitions close to the
// definitions for the response functions to make it easier to check that
// the timer number matches where the timer event will be routed
// These symbolic names should be changed to be relevant to your application

#define GAME_TIMER 0
#define CLOCK_TIMER 1
#define POURTIMER 2
#define P2PTransmit_TIMER 3
#define TESTP2P_TIMER 4
#define MAINDISPLAY_TIMER 5
#define PRINTSERVICE_TIMER 6
#define HAPTIC_TIMER 8
#define DISTANCE_TIMER 7

#endif /* ES_CONFIGURE_H */

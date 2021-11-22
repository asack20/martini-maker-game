/****************************************************************************
 Module
   AnalogChecker.c

 Revision
   1.0.1

 Description
   This is the analog event checker

 Notes
   Note the use of static variables in sample event checker to detect
   ONLY transitions.

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
// actual functionsdefinition
#include "AnalogChecker.h"

#include "PourService.h"
#include "../HALs/PIC32PortHAL.h"
#include "../HALs/PIC32_AD_Lib.h"
#include "../FrameworkHeaders/bitdefs.h"
#include "../Services/GameMain.h"
#include "../Services/ShakeService.h"

// This is the event checking function sample. It is not intended to be
// included in the module. It is only here as a sample to guide you in writing
// your own event checkers
/****************************************************************************
****************************************************************************/
#define UP_DIST_THRESH 350 // Upper threshold for shake distance sensor (NOTE: lower number is further away)
#define DOWN_DIST_THRESH 750 // Lower threshold for shake distance sensor

//Distance Sensor Pin Configuration
#define DISTANCE_PORT _Port_B
#define DISTANCE_PIN _Pin_3 //Hardware Pin 7
#define DISTANCE_AN BIT5HI
#define DISTANCE_ADC_IDX 1 // Index in Analog results array that contains data for distance

//Potentiometer Pin Configuration
#define POT_PORT _Port_B
#define POT_PIN _Pin_2
#define POT_AN BIT4HI
#define POT_ADC_IDX 0

#define STABILITY_GOAL 50000

// Distance Sensor
static uint32_t ConversionResults[2];
static uint16_t LastDistanceVal;


// Potentiometer
static uint16_t LastVal;
static uint32_t DisplayVal;
static uint32_t Stability;
static uint32_t Sensitivity = 128000;
static bool Done;

/****************************************************************************
 Function
 * InitADC

 Parameters
     None

 Returns
 * void

 Description
 Initializes ADC Library
 
 Notes

 Author
 * Andrew Sack
****************************************************************************/
void InitADC(void)
{
    ADC_ConfigAutoScan((DISTANCE_AN | POT_AN), 2);
}

void InitPourStatus(void)
{
    PortSetup_ConfigureAnalogInputs(POT_PORT, POT_PIN);
    InitADC();
    //LastVal = 16;
    LastVal = 0;
    DisplayVal = 0;
    Stability = 0;
    Done = false;
    printf("Analog Checker INITIALIZED\r\n");
    return;
}

void ResetPourStatus(void)
{
    LastVal = 0;
    DisplayVal = 0;
    Stability = 0;
    Done = false;
    return;
}

/*
bool CheckPour(void)
{
    bool ReturnVal = false;
    uint32_t CurrentVal;
    uint32_t *pCurrentVal = &CurrentVal;

    ADC_MultiRead(pCurrentVal);
    CurrentVal = CurrentVal/32 + 1;
    
    uint16_t CurrentVal16 = CurrentVal;

    //for(int j = 0; j < 100000; j++);

    if(CurrentVal16 < 33 && CurrentVal16 >= 0){
        if(CurrentVal16 != LastVal){
            LastVal = CurrentVal16;
            ES_Event_t ThisEvent;
            ThisEvent.EventType   = DELTA_DETECT;
            ThisEvent.EventParam = CurrentVal16;
            //printf("%u \n\r", ThisEvent.EventParam);
            PostPourService(ThisEvent);
        }
    }
    
    
    return ReturnVal;
}
*/

bool CheckPour(void)
{
    bool ReturnVal = false;
    uint32_t CurrentVal;
    //uint32_t *pCurrentVal = &CurrentVal;

    ADC_MultiRead(ConversionResults);
    CurrentVal = ConversionResults[POT_ADC_IDX];
    CurrentVal = CurrentVal/32 + 1;
    //printf("%u \n\r", CurrentVal);

    //for(int j = 0; j < 100000; j++);
    if(CurrentVal <= 4){
        if(DisplayVal < 4){
            DisplayVal = 0;
        }else {
            DisplayVal -= 4;
        }
        Stability = 0;
    }else if(CurrentVal > 4 && CurrentVal <= 8){
        if(DisplayVal < 2){
            DisplayVal = 0;
        }else {
            DisplayVal -= 2;
        }
        Stability = 0;
    }else if(CurrentVal > 8 && CurrentVal <= 12){
        if(DisplayVal < 1){
            DisplayVal = 0;
        }else {
            DisplayVal -= 1;
        }
        Stability = 0;
    }else if(CurrentVal > 12 && CurrentVal <= 18){
        Stability +=1;
    }else if(CurrentVal > 18 && CurrentVal <= 22){
        if(DisplayVal > Sensitivity-1){
            DisplayVal = Sensitivity;
        }else {
            DisplayVal += 1;
        }
        Stability = 0;
    }else if(CurrentVal > 22 && CurrentVal <= 26){
         if(DisplayVal > Sensitivity-2){
            DisplayVal = Sensitivity;
        }else {
            DisplayVal += 2;
        }
        Stability = 0;
    }else if(CurrentVal > 26){
        if(DisplayVal > Sensitivity-4){
            DisplayVal = Sensitivity;
        }else {
            DisplayVal += 4;
        }
        Stability = 0;
    }
    
    uint16_t SendVal = DisplayVal/4000;
    if(LastVal != SendVal){
        LastVal = SendVal;
        ReturnVal = true;
        //printf("%u \n\r", DisplayVal);
        ES_Event_t ThisEvent;
        ThisEvent.EventType = POUR_DELTA_DETECT;
        ThisEvent.EventParam = SendVal;
        PostPourService(ThisEvent);
    }else if(LastVal >= 22 && LastVal <= 24 && Stability>STABILITY_GOAL && Done == false){
        printf("\r\nSuccess\r\n");
        Stability = 0;
        Done = true;
        ES_Event_t ThisEvent;
        ThisEvent.EventType = POUR_SUCCESS;
        PostGameMain(ThisEvent);
        PostPourService(ThisEvent);
    }
    return ReturnVal;
}

/****************************************************************************
 Function
 * InitDistanceSensor

 Parameters
     None

 Returns
 True if event checker initializes successfully

 Description
 Configures pin and ADC library for distance sensor
 
 Notes

 Author
 * Andrew Sack
****************************************************************************/
bool InitDistanceSensor(void)
{
    printf("Initializing Shake Distance Event Checker\r\n");

    //Configure pin as analog input and give error if it fails
    if (false == PortSetup_ConfigureAnalogInputs(DISTANCE_PORT, DISTANCE_PIN))
    {
        printf("Failed to configure Analog Input for Distance Sensor\n\r");
        return false;
    }
    // Configure A/D library for pin
    InitADC();

    return true;
    
}
/****************************************************************************
 Function
 * ReadInitialDistance

 Parameters
     None

 Returns
 void

 Description
 Reads distance sensor for 1st time and saves val to LastDistanceVal
 
 Notes
 * This is split from InitDistanceSensor to allow time after ADC_ConfigAutoScan
 * and it to be called again when START_SHAKE event received
 Author
 * Andrew Sack
****************************************************************************/
void ReadInitialDistance(void)
{
    printf("Reading Initial Distance\r\n");

    //Read Distance Sensor and store initial val in LastDistanceVal
    ADC_MultiRead(ConversionResults);
    LastDistanceVal = (uint16_t) ConversionResults[DISTANCE_ADC_IDX];
    printf("Initial Distance Val is %u\r\n", LastDistanceVal);
}
/****************************************************************************
 Function
 * CheckShakeEvents

 Parameters
     None

 Returns
 True if ShakeTop or ShakeBottom event was detected

 Description
 * Reads distance sensor value and posts event if it crosses over top or bottom 
 * threshold
 
 Notes

 Author
 * Andrew Sack
****************************************************************************/
bool CheckShakeEvents(void)
{
    // if in idle, immediately return false and don't run event checker
    if (ShakeReadyState == QueryShakeService())
        return false;
    
    bool ReturnVal = false;
    ES_Event_t PostEvent;
    
    //Read Distance Sensor and store in CurrentDistanceVal
    ADC_MultiRead(ConversionResults);
    uint16_t CurrentDistanceVal = (uint16_t) ConversionResults[DISTANCE_ADC_IDX];
    
    // Note: Up is a smaller reading on sensor, so logic may seem backwards
    // If shaker was below the upper limit
    if (LastDistanceVal > UP_DIST_THRESH )  
    {
        // shaker crosses over the upper limit
        if (CurrentDistanceVal <= UP_DIST_THRESH) 
        {
            //printf("CheckShakeEvents: Detected SHAKE_TOP\r\n");
            ReturnVal = true;
            // post a SHAKE_TOP Event to ShakeService
            PostEvent.EventType = SHAKE_TOP;
            PostEvent.EventParam = CurrentDistanceVal;
            PostShakeService(PostEvent);
        }
    }
    // if shaker was above the bottom limit
    // NOTE: Important that this is if and not else if
    if (LastDistanceVal < DOWN_DIST_THRESH)  
    {
        // shaker crosses below the lower limit
        if (CurrentDistanceVal >= DOWN_DIST_THRESH) 
        {
            //printf("CheckShakeEvents: Detected SHAKE_BOTTOM\r\n");
            ReturnVal = true;
            // post a SHAKE_BOTTOM Event to ShakeService
            PostEvent.EventType = SHAKE_BOTTOM;
            PostEvent.EventParam = CurrentDistanceVal;
            PostShakeService(PostEvent);
        }
    }
    
    // update last val
    LastDistanceVal = CurrentDistanceVal;
    
    return ReturnVal;
    
}
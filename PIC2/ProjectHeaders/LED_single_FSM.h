/****************************************************************************

  Header file for template Flat Sate Machine
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef FSM_LED_H
#define FSM_LED_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum
{
  InitPState_LED, ReadyState_LED, WriteState_LED
}LED_single_State_t;

// Public Function Prototypes

bool InitLED_single_FSM(uint8_t Priority);
bool PostLED_single_FSM(ES_Event_t ThisEvent);
ES_Event_t RunLED_single_FSM(ES_Event_t ThisEvent);
LED_single_State_t QueryLED_FSM(void);

#endif /* FSMTemplate_H */


/****************************************************************************

  Header file for Display Flat Sate Machine
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef FSMDisplay_H
#define FSMDisplay_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
//#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum
{
  InitPState, InitializeDisplayState, ReadyState, ScrollingState
}DisplayState_t;

// Public Function Prototypes

bool InitDisplayFSM(uint8_t Priority);
bool PostDisplayFSM(ES_Event_t ThisEvent);
ES_Event_t RunDisplayFSM(ES_Event_t ThisEvent);
DisplayState_t QueryDisplaySM(void);

#endif /* FSMDisplay_H */


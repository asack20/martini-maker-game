/****************************************************************************

  Header file for template Flat Sate Machine
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef ShakeService_H
#define ShakeService_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum
{
  ShakeReadyState, ShakeUpState, ShakeDownState
}ShakeState_t;

// Public Function Prototypes

bool InitShakeService(uint8_t Priority);
bool PostShakeService(ES_Event_t ThisEvent);
ES_Event_t RunShakeService(ES_Event_t ThisEvent);
ShakeState_t QueryShakeService(void);




#endif /* ShakeService_H */


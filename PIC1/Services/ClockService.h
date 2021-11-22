/****************************************************************************

  Header file for Servo ClockService
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef ClockService_H
#define ClockService_H

#include <stdint.h>
#include <stdbool.h>

#include "ES_Events.h"
#include "ES_Port.h"                // needed for definition of REENTRANT
// Public Function Prototypes

bool InitClockService(uint8_t Priority);
bool PostClockService(ES_Event_t ThisEvent);
ES_Event_t RunClockService(ES_Event_t ThisEvent);

#endif /* ClockService_H */


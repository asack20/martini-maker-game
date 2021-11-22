/****************************************************************************

  Header file for Servo DoorService
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef DoorService_H
#define DoorService_H

#include <stdint.h>
#include <stdbool.h>

#include "ES_Events.h"
#include "ES_Port.h"                // needed for definition of REENTRANT
// Public Function Prototypes

bool InitDoorService(uint8_t Priority);
bool PostDoorService(ES_Event_t ThisEvent);
ES_Event_t RunDoorService(ES_Event_t ThisEvent);

#endif /* DoorService_H */


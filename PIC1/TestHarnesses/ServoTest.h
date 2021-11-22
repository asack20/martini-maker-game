/****************************************************************************

  Header file for template service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef ServoTest_H
#define ServoTest_H

#include "ES_Types.h"
#include "../Services/DoorService.h"
#include "../Services/ClockService.h"

// Public Function Prototypes

bool InitServoTest(uint8_t Priority);
bool PostServoTest(ES_Event_t ThisEvent);
ES_Event_t RunServoTest(ES_Event_t ThisEvent);

#endif /* ServoTest_H */


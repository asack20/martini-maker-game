/****************************************************************************

  Header file for template service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestDistanceSensor_H
#define TestDistanceSensor_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestDistanceSensor(uint8_t Priority);
bool PostTestDistanceSensor(ES_Event_t ThisEvent);
ES_Event_t RunTestDistanceSensor(ES_Event_t ThisEvent);
bool checkDistanceValue(void);

#endif /* TestDistanceSensor_H */


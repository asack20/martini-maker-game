/****************************************************************************

  Header file for template service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestShakeService_H
#define TestShakeService_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestShakeService(uint8_t Priority);
bool PostTestShakeService(ES_Event_t ThisEvent);
ES_Event_t RunTestShakeService(ES_Event_t ThisEvent);

#endif /* TestShakeService_H */


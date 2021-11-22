/****************************************************************************

  Header file for template service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef TestGameMain_H
#define TestGameMain_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitTestGameMain(uint8_t Priority);
bool PostTestGameMain(ES_Event_t ThisEvent);
ES_Event_t RunTestGameMain(ES_Event_t ThisEvent);

#endif /* TestGameMain_H */


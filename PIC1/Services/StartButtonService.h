/****************************************************************************

  Header file for StartButtonService
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef StartButtonService_H
#define StartButtonService_H

#include <stdint.h>
#include <stdbool.h>

#include "ES_Events.h"
#include "ES_Port.h"                // needed for definition of REENTRANT
// Public Function Prototypes

bool InitStartButtonService(uint8_t Priority);
bool PostStartButtonService(ES_Event_t ThisEvent);
ES_Event_t RunStartButtonService(ES_Event_t ThisEvent);
void InitStartButtonStatus(void);
bool CheckStartButtonEvents(void);

#endif /* StartButtonService_H */


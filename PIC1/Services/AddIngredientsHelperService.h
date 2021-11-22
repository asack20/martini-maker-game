/****************************************************************************

  Header file for AddIngredientsHelper service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef ServAddIngredientsHelper_H
#define ServAddIngredientsHelper_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitAddIngredientsHelperService(uint8_t Priority);
bool PostAddIngredientsHelperService(ES_Event_t ThisEvent);
ES_Event_t RunAddIngredientsHelperService(ES_Event_t ThisEvent);

#endif /* ServAddIngredientsHelper_H */


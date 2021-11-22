/****************************************************************************

  Header file for MainDisplay service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef ServMainDisplay_H
#define ServMainDisplay_H

#include "ES_Types.h"
#include "../HALs/DM_Display.h"
#include "DisplayFSM.h"

// Public Function Prototypes

bool InitMainDisplayService(uint8_t Priority);
bool PostMainDisplayService(ES_Event_t ThisEvent);
ES_Event_t RunMainDisplayService(ES_Event_t ThisEvent);

#endif /* ServMainDisplay_H */


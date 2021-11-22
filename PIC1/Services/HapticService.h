/****************************************************************************

  Header file for Haptic Motor service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef ServHaptic_H
#define ServHaptic_H

#include "ES_Types.h"

// Public Function Prototypes

bool InitHapticService(uint8_t Priority);
bool PostHapticService(ES_Event_t ThisEvent);
ES_Event_t RunHapticService(ES_Event_t ThisEvent);

#endif /* ServHaptic_H */


/****************************************************************************

  Header file for template service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef ServTestP2P_H
#define ServTestP2P_H

#include "ES_Types.h"
#include "../Services/P2PComm.h"

// Public Function Prototypes

bool InitTestP2PService(uint8_t Priority);
bool PostTestP2PService(ES_Event_t ThisEvent);
ES_Event_t RunTestP2PService(ES_Event_t ThisEvent);

#endif /* ServTestP2P_H */


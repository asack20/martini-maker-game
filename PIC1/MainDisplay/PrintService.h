/****************************************************************************

  Header file for Print service
  based on the Gen 2 Events and Services Framework

 ****************************************************************************/

#ifndef ServPrint_H
#define ServPrint_H

#include "ES_Types.h"
#include "../HALs/DM_Display.h"
#include "DisplayFSM.h"

// Public Function Prototypes

bool InitPrintService(uint8_t Priority);
bool PostPrintService(ES_Event_t ThisEvent);
ES_Event_t RunPrintService(ES_Event_t ThisEvent);

#endif /* ServPrint_H */


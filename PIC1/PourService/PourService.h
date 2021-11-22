/****************************************************************************

  Header file for Display Flat Sate Machine
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef POURSERVICE_H
#define POURSERVICE_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */
#include "../HALs/PIC32_SPI_HAL.h" // SPI HAL
#include "../HALs/DM_Display_2.h" // Display HAL
#include "terminal.h"
#include "dbprintf.h"

// typedefs for the states
// State definitions for use with the query function
typedef enum
{
  InitPourPseudoState, InitializePourState, PourReadyState, PourScrollingState, PourResetState
}PourState_t;

// Public Function Prototypes

bool InitPourService(uint8_t Priority);
bool PostPourService(ES_Event_t ThisEvent);
ES_Event_t RunPourService(ES_Event_t ThisEvent);
PourState_t QueryPourService(void);
bool CheckPot(void);

#endif /* POURSERVICE_H */


/****************************************************************************

  Header file for Pic 2 Pic communication Flat Sate Machine
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef FSMP2PComm_H
#define FSMP2PComm_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum
{
  P2P_TransmitIdle, P2P_SendingLo, P2P_SendingHi
}P2PCommState_t;

// Public Function Prototypes

bool InitP2PComm(uint8_t Priority);
bool PostP2PComm(ES_Event_t ThisEvent);
ES_Event_t RunP2PTransmit(ES_Event_t ThisEvent);
bool CheckP2PReceiveEvents(void);
P2PCommState_t QueryP2PComm(void);

#endif /* FSMP2PComm_H */


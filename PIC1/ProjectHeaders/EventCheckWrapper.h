/****************************************************************************
 Module
     ES_EventCheckWrapper.h
 Description
     This is a wrapper header file for all of the header files that include
     prototypes for event checking functions.
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 12/19/16 20:12 jec      Started coding
*****************************************************************************/

#ifndef ES_EventCheckWrapper_H
#define ES_EventCheckWrapper_H

// This is the header for the event checkers for the template project
#include "EventCheckers.h"
#include "../Services/StartButtonService.h" // For CheckStartButtonEvents
#include "../PourService/AnalogChecker.h" // For CheckPour and CheckShakeEvents
#include "../Services/P2PComm.h" //For CheckP2PReceiveEvents

// Here you would #include the header files for any other modules that
// contained event checking functions

#endif  // ES_EventCheckWrapper_H

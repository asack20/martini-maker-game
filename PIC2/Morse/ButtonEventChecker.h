/****************************************************************************
 Module
     ButtonEventChecker.h
 Description
     header file for the event checking functions
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/18/15 11:50 jec      added #include for stdint & stdbool
 08/06/13 14:37 jec      started coding
*****************************************************************************/

#ifndef ButtonEventChecker_H
#define ButtonEventChecker_H

// the common headers for C99 types
#include <stdint.h>
#include <stdbool.h>
#include "ES_Configure.h"
#include "HALs/PIC32PortHAL.h"

// prototypes for event checkers
void InitButtonStatus(void);
bool CheckButtonEvents(void);

#endif /* ButtonEventChecker_H */

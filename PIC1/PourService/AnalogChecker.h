/****************************************************************************
 Module
     AnalogChecker.h
 Description
     header file for the event checking functions
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/18/15 11:50 jec      added #include for stdint & stdbool
 08/06/13 14:37 jec      started coding
*****************************************************************************/

#ifndef AnalogChecker_H
#define AnalogChecker_H

// the common headers for C99 types
#include <stdint.h>
#include <stdbool.h>

// prototypes for event checkers

void InitADC(void);

void InitPourStatus(void);
void ResetPourStatus(void);
bool CheckPour(void);

bool InitDistanceSensor(void);
void ReadInitialDistance(void);
bool CheckShakeEvents(void);

#endif /* AnalogChecker_H */

/****************************************************************************
 Module
     EventCheckers.h
 Description
     header file for the event checking functions
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/18/15 11:50 jec      added #include for stdint & stdbool
 08/06/13 14:37 jec      started coding
*****************************************************************************/

#ifndef EventCheckers_H
#define EventCheckers_H

// the common headers for C99 types
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    Waiting, DebounceFall, DebounceRise
}debounce_state_t;

// prototypes for event checkers

//bool Check4Keystroke(void);
bool Check4Btns(void);
bool CheckP2PReceiveEvents(void);
#endif /* EventCheckers_H */

/****************************************************************************

  Header file for template Flat Sate Machine
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef GameMain_H
#define GameMain_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum
{
  GameInitState, WelcomeState, AddIngredientsState, ShakeState, PourState,
          GameSuccessState, GameFailureState
}GameState_t;

// Public Function Prototypes

bool InitGameMain(uint8_t Priority);
bool PostGameMain(ES_Event_t ThisEvent);
ES_Event_t RunGameMain(ES_Event_t ThisEvent);
GameState_t QueryGameMain(void);

#endif /* GameMain_H */


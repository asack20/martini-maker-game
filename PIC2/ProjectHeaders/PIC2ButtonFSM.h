/****************************************************************************

  Header file for template Flat Sate Machine
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef SPI2_Button_FSM_H
#define SPI2_Button_FSM_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum
{
  InitPState, AddIngredientsWaitState,AddingState,SuccessState, FailureState
}PIC2Button_FSM_State_t;

// Public Function Prototypes

#define VODKA_BTN PORTBbits.RB8
#define GIN_BTN PORTBbits.RB9
#define ICE_BTN PORTBbits.RB10
#define OLIVE_BTN PORTBbits.RB11
#define LED_ENABLE PORTBbits.RB4

#define NUM_BTNS   4
bool InitPIC2ButtonFSM(uint8_t Priority);
bool PostPIC2ButtonFSM(ES_Event_t ThisEvent);
ES_Event_t RunPIC2ButtonFSM(ES_Event_t ThisEvent);
PIC2Button_FSM_State_t QueryPIC2ButtonFSM(void);
void sendToDisPlay(uint8_t* digits);

#endif /* FSMTemplate_H */


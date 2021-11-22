/****************************************************************************
 Module
   P2PComm.c

 Revision
   1.0.1

 Description
FSM that manages pic-to-pic communication. State machine manages sending signals
and receive event checkers are also included in the module. 
Runs on both pics


****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "P2PComm.h"
#include "../HALs/PIC32PortHAL.h"

/*----------------------------- Module Defines ----------------------------*/
#define RECEIVE_PORT _Port_B
#define RECEIVE_PIN _Pin_11
#define RECEIVE_VAL PORTBbits.RB11
#define TRANSMIT_PORT _Port_B
#define TRANSMIT_PIN _Pin_10
#define TRANSMIT_VAL LATBbits.LATB10

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match that of enum in header file
static P2PCommState_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;

static uint8_t TransmitLength;
static uint8_t ValidReceiveLengths[] = {15, 35, 55, 75};
const uint8_t SZ_VALIDRECEIVE = sizeof(ValidReceiveLengths)/sizeof(ValidReceiveLengths[0]);

static const uint8_t RECEIVE_ERROR = 5;

static bool LastReceiveState;
static uint16_t ReceiveRisingTime;

/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitP2PComm

 Parameters
     uint8_t : the priority of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Initializes Service and hardware for Pic2Pic Communication
 Notes

 Author
     J. Edward Carryer, 10/23/11, 18:55
****************************************************************************/
bool InitP2PComm(uint8_t Priority)
{
    puts("Initializing P2PComm\r");
    ES_Event_t ThisEvent;

    MyPriority = Priority;
    // put us into the Initial State
    CurrentState = P2P_TransmitIdle;
    
    //Initialize the input line to receive signal
    //Return false if configure fails
    if(false == PortSetup_ConfigureDigitalInputs(RECEIVE_PORT, RECEIVE_PIN))
    {
        puts("Error: P2PComm failed to Configure Receive Pin\n\r");
        return false; 
    }
    //Sample port line and use it to initialize the LastReceiveState variable
    LastReceiveState = (bool) RECEIVE_VAL;
    ReceiveRisingTime = 0; // init to 0
    
    //Initialize the transmit as a digital output
    //Return false if configure fails
    if(false == PortSetup_ConfigureDigitalOutputs(TRANSMIT_PORT, TRANSMIT_PIN))
    {
        puts("Error: P2PComm failed to Configure Transmit Pin\n\r");
        return false; 
    }
    // Initialize output to lo
    TRANSMIT_VAL = 0;
    
    return true;

}

/****************************************************************************
 Function
     PostP2PComm

 Parameters
     EF_Event_t ThisEvent , the event to post to the queue

 Returns
     boolean False if the Enqueue operation failed, True otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
     J. Edward Carryer, 10/23/11, 19:25
****************************************************************************/
bool PostP2PComm(ES_Event_t ThisEvent)
{
  return ES_PostToService(MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunP2PTransmit

 Parameters
   ES_Event_t : the event to process

 Returns
   ES_Event_t, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
   State machine for transmitting signals for P2P communication
 Notes
   uses nested switch/case to implement the machine.
 Author
   J. Edward Carryer, 01/15/12, 15:23
****************************************************************************/
ES_Event_t RunP2PTransmit(ES_Event_t ThisEvent)
{
  ES_Event_t ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

  switch (CurrentState)
  {
    case P2P_TransmitIdle:        // If current state is idle
    {
        if (ThisEvent.EventType == P2P_START_TRANSMIT)
        {
            //Prep to start transmission
            TransmitLength = ThisEvent.EventParam;
            CurrentState = P2P_SendingLo;
            ES_Timer_InitTimer(P2PTransmit_TIMER, TransmitLength);
            printf("P2PComm: Starting Transmit with length = %u\r\n", TransmitLength);
        }
    }
    break;

    case P2P_SendingLo: // signal currently low
    {
        if (ThisEvent.EventType == ES_TIMEOUT)
        {
            //After timeout switch to Hi
            CurrentState = P2P_SendingHi;
            TRANSMIT_VAL = 1; // set pin hi
            ES_Timer_InitTimer(P2PTransmit_TIMER, TransmitLength);
        }
        else if (ThisEvent.EventType == P2P_STOP_TRANSMIT)
        {
            //Return to idle state to stop
            CurrentState = P2P_TransmitIdle;
            puts("P2PComm: Stopping Transmit\r");
        }
    }
    break;
    case P2P_SendingHi:      // signal currently hi
    {
        if (ThisEvent.EventType == ES_TIMEOUT)
        {
            //After timeout switch to LO
            CurrentState = P2P_SendingLo;
            TRANSMIT_VAL = 0; // set pin lo
            ES_Timer_InitTimer(P2PTransmit_TIMER, TransmitLength);
        }
        else if (ThisEvent.EventType == P2P_STOP_TRANSMIT)
        {
            TRANSMIT_VAL = 0; // set pin lo before stopping
            //Return to idle state to stop
            CurrentState = P2P_TransmitIdle;
            puts("P2PComm: Stopping Transmit\r");
        }
    }
    break;
    default:
      ;
  }                                   // end switch on Current State
  return ReturnEvent;
}

/****************************************************************************
 Function
     QueryP2PComm

 Parameters
     None

 Returns
     P2PCommState_t The current state of the P2PTransmit state machine

 Description
     returns the current state of the P2P Transmit state machine
 Notes

 Author
     J. Edward Carryer, 10/23/11, 19:21
****************************************************************************/
P2PCommState_t QueryP2PComm(void)
{
  return CurrentState;
}

/****************************************************************************
 Function
     CheckP2PReceiveEvents

 Parameters
     None

 Returns
     True if an event was posted

 Description
     Event Checker monitors receive pin and if a valid hi interval length is 
 * measured, it will post an event to the distribution list
 Notes

 Author
****************************************************************************/
bool CheckP2PReceiveEvents(void)
{
    bool ReturnVal = false;
    bool CurrentReceiveState;
    ES_Event_t PostEvent;
    uint16_t CurrentTime;
    uint16_t HiTime;
    uint8_t idx;
    
    // Get the CurrentReceiveState from the input line
    CurrentReceiveState = (bool) RECEIVE_VAL;
    
    // if state of receive pin has changed
    if (CurrentReceiveState != LastReceiveState)
    {
        
        CurrentTime = ES_Timer_GetTime(); // read current time
        if (1 == CurrentReceiveState) //Rising Edge
        {
            ReceiveRisingTime = CurrentTime; // update rising start time
        }
        else // falling edge
        {
            //Check if HiTime corresponds to a valid signal
            HiTime = CurrentTime - ReceiveRisingTime;
            
            // check each valid receive length
            for (idx = 0; idx < SZ_VALIDRECEIVE; idx++)
            {
                // HiTime within +- Receive_Error of the value
                if ((HiTime >= (ValidReceiveLengths[idx] - RECEIVE_ERROR)) &&
                       (HiTime <= (ValidReceiveLengths[idx] + RECEIVE_ERROR)) )
                {
                    // post event if it matches
                    ReturnVal = true; // will post event
                    PostEvent.EventType = P2P_SIGNAL_RECEIVED;
                    PostEvent.EventParam = ValidReceiveLengths[idx];
                    PostP2PCommDistList(PostEvent); // post to distro 
                    //printf("P2PComm: Received Message of length = %u\r\n", ValidReceiveLengths[idx]);
                    if (ValidReceiveLengths[idx] != HiTime) // not Exact
                    {
                        //printf("P2PComm: MISTMATCH!!! TRUE length = %u\r\n", HiTime);
                    }
                    
                    break; // quit loop
                }
                
                
            }
            if (ReturnVal == false) // message invalid
            {
                //printf("P2PComm: Received Invalid Message of length = %u\r\n", HiTime);
            }
            
        }
    }
    LastReceiveState = CurrentReceiveState; // update last state
    return ReturnVal;
}

/***************************************************************************
 private functions
 ***************************************************************************/


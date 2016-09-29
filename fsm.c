//****************************************************************************//
//  MSP430 state machine
//  fsm.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    Do not change code in here!!!
//
//  Generated with Excel Table
//  Date:  09/29/2016        Time:  09:52:58
//
//****************************************************************************//

#include <stdint.h>
#include <stdio.h>
#include "fsm.h"

//****************************************************************************//
// Global variables
//****************************************************************************//
uint8_t  ActState;

const FSM_STATE_TABLE StateTable [NR_STATES][NR_EVENTS] =
{
  FSM_menu_7, STATE_7, FSM_menu_1, STATE_1, FSM_menu_01, STATE_01, FSM_menu_0, STATE_0, FSM_menu_0, STATE_0,
  FSM_menu_0, STATE_0, FSM_menu_2, STATE_2, FSM_menu_11, STATE_11, FSM_menu_1, STATE_1, FSM_menu_1, STATE_1,
  FSM_menu_1, STATE_1, FSM_menu_3, STATE_3, FSM_menu_21, STATE_21, FSM_menu_2, STATE_2, FSM_menu_2, STATE_2,
  FSM_menu_2, STATE_2, FSM_menu_4, STATE_4, FSM_menu_31, STATE_31, FSM_menu_3, STATE_3, FSM_menu_3, STATE_3,
  FSM_menu_3, STATE_3, FSM_menu_5, STATE_5, FSM_menu_41, STATE_41, FSM_menu_4, STATE_4, FSM_menu_4, STATE_4,
  FSM_menu_4, STATE_4, FSM_menu_6, STATE_6, FSM_menu_51, STATE_51, FSM_menu_5, STATE_5, FSM_menu_5, STATE_5,
  FSM_menu_5, STATE_5, FSM_menu_7, STATE_7, FSM_menu_61, STATE_61, FSM_menu_6, STATE_6, FSM_menu_6, STATE_6,
  FSM_menu_6, STATE_6, FSM_menu_0, STATE_0, FSM_menu_71, STATE_71, FSM_menu_7, STATE_7, FSM_menu_7, STATE_7,
  FSM_menu_01, STATE_01, FSM_menu_01, STATE_01, FSM_menu_01, STATE_01, FSM_menu_01, STATE_01, FSM_menu_0, STATE_0,
  FSM_menu_11, STATE_11, FSM_menu_11, STATE_11, FSM_menu_11, STATE_11, FSM_menu_11, STATE_11, FSM_menu_1, STATE_1,
  FSM_menu_21, STATE_21, FSM_menu_21, STATE_21, FSM_menu_21, STATE_21, FSM_menu_21, STATE_21, FSM_menu_2, STATE_2,
  FSM_menu_31, STATE_31, FSM_menu_31, STATE_31, FSM_menu_31, STATE_31, FSM_menu_31, STATE_31, FSM_menu_3, STATE_3,
  FSM_menu_41, STATE_41, FSM_menu_41, STATE_41, FSM_menu_41, STATE_41, FSM_menu_41, STATE_41, FSM_menu_4, STATE_4,
  FSM_menu_51, STATE_51, FSM_menu_51, STATE_51, FSM_menu_51, STATE_51, FSM_menu_51, STATE_51, FSM_menu_5, STATE_5,
  FSM_menu_61, STATE_61, FSM_menu_61, STATE_61, FSM_menu_61, STATE_61, FSM_menu_61, STATE_61, FSM_menu_6, STATE_6,
  FSM_menu_71, STATE_71, FSM_menu_71, STATE_71, FSM_menu_71, STATE_71, FSM_menu_71, STATE_71, FSM_menu_7, STATE_7
};


//****************************************************************************//
// Initialize state machine
//****************************************************************************//
void FSM_Init (void)
{
  ActState = STATE_0;
}


//****************************************************************************//
// Event function "press_up"
//****************************************************************************//
void FSM_press_up (void)
{
  if (StateTable[ActState][PRESS_UP].ptrFunct != NULL)
    StateTable[ActState][PRESS_UP].ptrFunct();

  ActState = StateTable[ActState][PRESS_UP].NextState;
}


//****************************************************************************//
// Event function "press_down"
//****************************************************************************//
void FSM_press_down (void)
{
  if (StateTable[ActState][PRESS_DOWN].ptrFunct != NULL)
    StateTable[ActState][PRESS_DOWN].ptrFunct();

  ActState = StateTable[ActState][PRESS_DOWN].NextState;
}


//****************************************************************************//
// Event function "press_rigth"
//****************************************************************************//
void FSM_press_rigth (void)
{
  if (StateTable[ActState][PRESS_RIGTH].ptrFunct != NULL)
    StateTable[ActState][PRESS_RIGTH].ptrFunct();

  ActState = StateTable[ActState][PRESS_RIGTH].NextState;
}


//****************************************************************************//
// Event function "press_left"
//****************************************************************************//
void FSM_press_left (void)
{
  if (StateTable[ActState][PRESS_LEFT].ptrFunct != NULL)
    StateTable[ActState][PRESS_LEFT].ptrFunct();

  ActState = StateTable[ActState][PRESS_LEFT].NextState;
}


//****************************************************************************//
// Event function "press_ok"
//****************************************************************************//
void FSM_press_ok (void)
{
  if (StateTable[ActState][PRESS_OK].ptrFunct != NULL)
    StateTable[ActState][PRESS_OK].ptrFunct();

  ActState = StateTable[ActState][PRESS_OK].NextState;
}


//****************************************************************************//

//****************************************************************************//
//  MSP430 state machine
//  fsm.h
//
//  Describtion:
//    A simple state machine for the MSP430
//
//  Generated with Excel Table
//  Date:  09/26/2016        Time:  16:07:42
//
//****************************************************************************//

#ifndef FSM_H
#define FSM_H

#include <stdint.h>
#include <stdio.h>
#include "ssd1306.h"

//#include "screen_out.h"
extern	volatile	uint32_t	key_scan;
//extern char char_100;
//extern	char char_10;
//extern	char char_1;

//****************************************************************************//
// State table typedef
//****************************************************************************//
typedef struct
{
  void (*ptrFunct) (void);
  uint8_t NextState;
} FSM_STATE_TABLE;

extern uint8_t ActState;


#define NR_EVENTS 5
#define PRESS_UP  0
#define PRESS_DOWN  1
#define PRESS_RIGTH  2
#define PRESS_LEFT  3
#define PRESS_OK  4

#define NR_STATES 16
#define STATE_0  0
#define STATE_1  1
#define STATE_2  2
#define STATE_3  3
#define STATE_4  4
#define STATE_5  5
#define STATE_6  6
#define STATE_7  7
#define STATE_01  8
#define STATE_11  9
#define STATE_21  10
#define STATE_31  11
#define STATE_41  12
#define STATE_51  13
#define STATE_61  14
#define STATE_71  15


//****************************************************************************//
// Function prototypes
//****************************************************************************//
// Initialize state machine
void FSM_Init (void);

// Event function "press_up"
void FSM_press_up (void);

// Event function "press_down"
void FSM_press_down (void);

// Event function "press_rigth"
void FSM_press_rigth (void);

// Event function "press_left"
void FSM_press_left (void);

// Event function "press_ok"
void FSM_press_ok (void);

// Transition function "menu_7"
void FSM_menu_7 (void);

// Transition function "menu_1"
void FSM_menu_1 (void);

// Transition function "menu_01"
void FSM_menu_01 (void);

// Transition function "menu_0"
void FSM_menu_0 (void);

// Transition function "menu_2"
void FSM_menu_2 (void);

// Transition function "menu_11"
void FSM_menu_11 (void);

// Transition function "menu_3"
void FSM_menu_3 (void);

// Transition function "menu_21"
void FSM_menu_21 (void);

// Transition function "menu_4"
void FSM_menu_4 (void);

// Transition function "menu_31"
void FSM_menu_31 (void);

// Transition function "menu_5"
void FSM_menu_5 (void);

// Transition function "menu_41"
void FSM_menu_41 (void);

// Transition function "menu_6"
void FSM_menu_6 (void);

// Transition function "menu_51"
void FSM_menu_51 (void);

// Transition function "menu_61"
void FSM_menu_61 (void);

// Transition function "menu_71"
void FSM_menu_71 (void);


//****************************************************************************//

#endif /* FSM_H */

//****************************************************************************//

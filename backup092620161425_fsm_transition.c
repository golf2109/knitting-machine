//****************************************************************************//
//  MSP430 state machine
//  fsm_transition.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    You can add your own code in here!!!
//
//  Generated with Excel Table
//  Date:  09/26/2016        Time:  13:33:20
//
//****************************************************************************//

#include "fsm.h"

//****************************************************************************//
// Transition function "menu_5"
//****************************************************************************//
void FSM_menu_5 (void)
{
  // You can add your code here
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("menu 5",Font_11x18,Black, NoInversion);
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_1"
//****************************************************************************//
void FSM_menu_1 (void)
{
  // You can add your code here
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("menu 1",Font_11x18,Black, NoInversion);
  ssd1306_UpdateScreen();			
}


//****************************************************************************//
// Transition function "menu_0"
//****************************************************************************//
void FSM_menu_0 (void)
{
  // You can add your code here
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("menu 0",Font_11x18,Black, NoInversion);
  ssd1306_UpdateScreen();			
}


//****************************************************************************//
// Transition function "menu_2"
//****************************************************************************//
void FSM_menu_2 (void)
{
  // You can add your code here
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("menu 2",Font_11x18,Black, NoInversion);
  ssd1306_UpdateScreen();			
}


//****************************************************************************//
// Transition function "menu_3"
//****************************************************************************//
void FSM_menu_3 (void)
{
  // You can add your code here
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("menu 3",Font_11x18,Black, NoInversion);
  ssd1306_UpdateScreen();			
}


//****************************************************************************//
// Transition function "menu_4"
//****************************************************************************//
void FSM_menu_4 (void)
{
  // You can add your code here
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("menu 4",Font_11x18,Black, NoInversion);
  ssd1306_UpdateScreen();			
}


//****************************************************************************//

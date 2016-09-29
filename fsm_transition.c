//****************************************************************************//
//  MSP430 state machine
//  fsm_transition.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    You can add your own code in here!!!
//
//  Generated with Excel Table
//  Date:  09/26/2016        Time:  16:07:40
//
//****************************************************************************//

#include "fsm.h"
//#include "screen_out.h"
extern	void int_to_char (uint16_t in_value);
extern  void out_char_center(void);
extern	void out_char_pos(uint8_t pos);
extern	uint16_t prog_oborot;

extern	uint16_t cv_1[20];
extern	uint16_t cv_2[20];
extern	uint16_t cv_3[20];
extern	uint16_t cv_4[20];
extern	uint16_t pered_val[20];
extern	uint16_t zad_val[20];
extern	uint16_t stop_mass[20];

extern char char_100;
extern char char_10;
extern char char_1;
uint8_t menu_01_open = 0;
uint8_t menu_11_open = 0;
uint8_t menu_21_open = 0;
uint8_t menu_31_open = 0;
uint8_t menu_41_open = 0;
uint8_t menu_51_open = 0;
uint8_t menu_61_open = 0;
uint8_t menu_71_open = 0;

uint8_t	cursor_pos=0;
uint8_t	cursor_move=0;
//****************************************************************************//
// Transition function "menu_7"
//****************************************************************************//
void FSM_menu_7 (void)
{
  // You can add your code here
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();	
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("  STOP 7 ",Font_11x18,Black, NoInversion);
  ssd1306_SetCursor(1,20);
  ssd1306_WriteString("777 000 000",Font_11x18,Black, NoInversion);	
  ssd1306_SetCursor(1,40);
  ssd1306_WriteString("000 000 000",Font_11x18,Black, NoInversion);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_1"
//****************************************************************************//
void FSM_menu_1 (void)
{
  // You can add your code here
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();		
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString("  COLOR 1 ",Font_11x18,Black, NoInversion);
//  ssd1306_SetCursor(3,22);
//  ssd1306_WriteString("111 000 000 ",Font_11x18,Black, NoInversion);	
//  ssd1306_SetCursor(3,44);
//  ssd1306_WriteString("000 000 000",Font_11x18,Black, NoInversion);		
	int_to_char(cv_1[0]);
	out_char_pos(0);	
	int_to_char(cv_1[1]);
	out_char_pos(1);	
	int_to_char(cv_1[2]);
	out_char_pos(2);		
	int_to_char(cv_1[3]);
	out_char_pos(3);	
	int_to_char(cv_1[4]);
	out_char_pos(4);	
	int_to_char(cv_1[5]);
	out_char_pos(5);			
  ssd1306_UpdateScreen();	
	cursor_pos = 0;
	cursor_move = 0;		
}


//****************************************************************************//
// Transition function "menu_01"
//****************************************************************************//
void FSM_menu_01 (void)
{
  // You can add your code here
//	FSM_menu_0();
  ssd1306_DrawLine(50,48,80,48,Black);		
  ssd1306_DrawLine(50,49,80,49,Black);	
  ssd1306_UpdateScreen();		
	
		switch(key_scan)
		{
			case 1: //down
//			ssd1306_SetCursor(50,30);
			if(menu_01_open == 1)
			{
				prog_oborot--;if(prog_oborot == 0)prog_oborot = 999;
			}
				int_to_char(prog_oborot);
			out_char_center();
			break;
			
			case 2: //up
//			ssd1306_SetCursor(50,30);
			if(menu_01_open == 1)
			{			
				prog_oborot++;if(prog_oborot == 999)prog_oborot = 0;
			}
			int_to_char(prog_oborot);
			out_char_center();
			break;
			
			case 4: //rigth
				menu_01_open = 1;				
				FSM_press_rigth();
			break;
			
			case 8: //left
				menu_01_open = 0;					
				FSM_press_left();
			break;
			
			case 0x10: //ok
				menu_01_open = 0;		
				ssd1306_DrawLine(50,48,80,48,White);		
				ssd1306_DrawLine(50,49,80,49,White);	
				ssd1306_UpdateScreen();					
				FSM_press_ok();
			break;			
			
			default:
				break;				
		}				
}


//****************************************************************************//
// Transition function "menu_0"
//****************************************************************************//
void FSM_menu_0 (void)
{
  // You can add your code here
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();		
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString("   OBOROT  ",Font_11x18,Black, NoInversion);
	int_to_char(prog_oborot);
	out_char_center();			
}


//****************************************************************************//
// Transition function "menu_2"
//****************************************************************************//
void FSM_menu_2 (void)
{
  // You can add your code here
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();		
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("  COLOR 2 ",Font_11x18,Black, NoInversion);
  ssd1306_SetCursor(1,20);
  ssd1306_WriteString("222 000 000",Font_11x18,Black, NoInversion);	
  ssd1306_SetCursor(1,40);
  ssd1306_WriteString("000 000 000",Font_11x18,Black, NoInversion);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_11"
//****************************************************************************//
void FSM_menu_11 (void)
{
  // You can add your code here
//	FSM_menu_1();	
				if(cursor_pos <3)
				{
  ssd1306_DrawLine(3+cursor_pos*44,40,33+cursor_pos*44,40,Black);		
  ssd1306_DrawLine(3+cursor_pos*44,41,33+cursor_pos*44,41,Black);		
				}
				else
				{
  ssd1306_DrawLine(3+(cursor_pos-3)*44,61,33+(cursor_pos-3)*44,61,Black);		
  ssd1306_DrawLine(3+(cursor_pos-3)*44,62,33+(cursor_pos-3)*44,62,Black);					
				}
  ssd1306_UpdateScreen();		
	if(cursor_move == 0)cursor_pos=0;
		switch(key_scan)
		{
			case 1: //down
				if(menu_11_open == 1)
				{
					cv_1[0+cursor_pos]--;if(cv_1[0+cursor_pos] == 0)cv_1[0+cursor_pos] = 999;
				}
				int_to_char(cv_1[0+cursor_pos]);
				out_char_pos(cursor_pos);			
			break;
			
			case 2: //up
				if(menu_11_open == 1)
				{
					cv_1[0+cursor_pos]++;if(cv_1[0+cursor_pos] == 999)cv_1[0+cursor_pos] = 0;
				}
				int_to_char(cv_1[0+cursor_pos]);
				out_char_pos(cursor_pos);	
			break;
			
			case 4: //rigth
				menu_11_open = 1;			
				if(cursor_pos <3)
				{
					ssd1306_DrawLine(3+cursor_pos*44,40,33+cursor_pos*44,40,White);		
					ssd1306_DrawLine(3+cursor_pos*44,41,33+cursor_pos*44,41,White);			
				}
				else
				{
					ssd1306_DrawLine(3+(cursor_pos-3)*44,61,33+(cursor_pos-3)*44,61,White);		
					ssd1306_DrawLine(3+(cursor_pos-3)*44,62,33+(cursor_pos-3)*44,62,White);						
				}
				HAL_Delay(300);						
				if(cursor_move != 0)cursor_pos++;		
				if(cursor_pos > 5)cursor_pos = 0;
				cursor_move = 1;			
//				HAL_Delay(300);			
				FSM_press_rigth();
			break;
			
			case 8: //left
				if(cursor_pos <3)
				{
					ssd1306_DrawLine(3+cursor_pos*44,40,33+cursor_pos*44,40,White);		
					ssd1306_DrawLine(3+cursor_pos*44,41,33+cursor_pos*44,41,White);			
				}
				else
				{
					ssd1306_DrawLine(3+(cursor_pos-3)*44,61,33+(cursor_pos-3)*44,61,White);		
					ssd1306_DrawLine(3+(cursor_pos-3)*44,62,33+(cursor_pos-3)*44,62,White);						
				}			
				cursor_pos = 0;
				cursor_move = 0;			
				menu_11_open = 0;			
				FSM_press_left();
			break;

			case 0x10: //ok
				if(cursor_pos <3)
				{
					ssd1306_DrawLine(3+cursor_pos*44,40,33+cursor_pos*44,40,White);		
					ssd1306_DrawLine(3+cursor_pos*44,41,33+cursor_pos*44,41,White);			
				}
				else
				{
					ssd1306_DrawLine(3+cursor_pos*44,62,33+cursor_pos*44,62,White);		
					ssd1306_DrawLine(3+cursor_pos*44,63,33+cursor_pos*44,63,White);						
				}				
				cursor_pos = 0;			
				cursor_move = 0;			
				menu_11_open = 0;
//				ssd1306_DrawLine(1,38,30,38,White);		
//				ssd1306_DrawLine(1,39,30,39,White);				
//				ssd1306_UpdateScreen();					
				FSM_press_ok();
			break;				
			
			default:
				break;				
		}			
}

//****************************************************************************//
// Transition function "menu_3"
//****************************************************************************//
void FSM_menu_3 (void)
{
  // You can add your code here
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();		
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("  COLOR 3 ",Font_11x18,Black, NoInversion);
  ssd1306_SetCursor(1,20);
  ssd1306_WriteString("333 000 000",Font_11x18,Black, NoInversion);	
  ssd1306_SetCursor(1,40);
  ssd1306_WriteString("000 000 000",Font_11x18,Black, NoInversion);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_21"
//****************************************************************************//
void FSM_menu_21 (void)
{
  // You can add your code here
	FSM_menu_2();		
  ssd1306_DrawLine(1,38,10,38,Black);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_4"
//****************************************************************************//
void FSM_menu_4 (void)
{
  // You can add your code here
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();		
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString("  COLOR 4 ",Font_11x18,Black, NoInversion);
  ssd1306_SetCursor(1,20);
  ssd1306_WriteString("444 000 000",Font_11x18,Black, NoInversion);	
  ssd1306_SetCursor(1,40);
  ssd1306_WriteString("000 000 000",Font_11x18,Black, NoInversion);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_31"
//****************************************************************************//
void FSM_menu_31 (void)
{
  // You can add your code here
	FSM_menu_3();	
  ssd1306_DrawLine(1,38,10,38,Black);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_5"
//****************************************************************************//
void FSM_menu_5 (void)
{
  // You can add your code here
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();		
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString(" Pered val",Font_11x18,Black, NoInversion);
  ssd1306_SetCursor(1,20);
  ssd1306_WriteString("555 000 000",Font_11x18,Black, NoInversion);	
  ssd1306_SetCursor(1,40);
  ssd1306_WriteString("000 000 000",Font_11x18,Black, NoInversion);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_41"
//****************************************************************************//
void FSM_menu_41 (void)
{
  // You can add your code here
	FSM_menu_4();	
  ssd1306_DrawLine(1,38,10,38,Black);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_6"
//****************************************************************************//
void FSM_menu_6 (void)
{
  // You can add your code here
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();		
  ssd1306_SetCursor(1,3);
  ssd1306_WriteString(" Zadn val ",Font_11x18,Black, NoInversion);
  ssd1306_SetCursor(1,20);
  ssd1306_WriteString("666 000 000",Font_11x18,Black, NoInversion);	
  ssd1306_SetCursor(1,40);
  ssd1306_WriteString("000 000 000",Font_11x18,Black, NoInversion);		
  ssd1306_UpdateScreen();			
}


//****************************************************************************//
// Transition function "menu_51"
//****************************************************************************//
void FSM_menu_51 (void)
{
  // You can add your code here
	FSM_menu_5();	
  ssd1306_DrawLine(1,38,10,38,Black);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_61"
//****************************************************************************//
void FSM_menu_61 (void)
{
  // You can add your code here
	FSM_menu_6();	
  ssd1306_DrawLine(1,38,10,38,Black);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//
// Transition function "menu_71"
//****************************************************************************//
void FSM_menu_71 (void)
{
  // You can add your code here
	FSM_menu_7();	
  ssd1306_DrawLine(1,38,10,38,Black);		
  ssd1306_UpdateScreen();		
}


//****************************************************************************//

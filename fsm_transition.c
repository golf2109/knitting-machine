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
extern	void out_cursor_position(SSD1306_COLOR color);
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
  ssd1306_Fill(White);	
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString("  STOP 7 ",Font_11x18,Black, NoInversion);
	int_to_char(stop_mass[0]);
	out_char_pos(0);	
	int_to_char(stop_mass[1]);
	out_char_pos(1);	
	int_to_char(stop_mass[2]);
	out_char_pos(2);		
	int_to_char(stop_mass[3]);
	out_char_pos(3);	
	int_to_char(stop_mass[4]);
	out_char_pos(4);	
	int_to_char(stop_mass[5]);
	out_char_pos(5);			
  ssd1306_UpdateScreen();	
	cursor_pos = 0;
	cursor_move = 0;		
}


//****************************************************************************//
// Transition function "menu_1"
//****************************************************************************//
void FSM_menu_1 (void)
{
  ssd1306_Fill(White);	
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString("  COLOR 1 ",Font_11x18,Black, NoInversion);
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
  ssd1306_DrawLine(50,48,80,48,Black);		
  ssd1306_DrawLine(50,49,80,49,Black);	
  ssd1306_UpdateScreen();		
	
		switch(key_scan)
		{
			case 1: //down
			if(menu_01_open == 1)
			{
				prog_oborot--;if(prog_oborot == 0)prog_oborot = 999;
			}
				int_to_char(prog_oborot);
			out_char_center();
			break;
			
			case 2: //up
			if(menu_01_open == 1)
			{			
				prog_oborot++;if(prog_oborot == 999)prog_oborot = 0;
			}
			int_to_char(prog_oborot);
			out_char_center();
			break;
			
			case 4: //rigth
				menu_01_open = 1;				
			break;
			
			case 8: //left
				menu_01_open = 0;					
			break;
			
			case 0x10: //ok
				menu_01_open = 0;		
				ssd1306_DrawLine(50,48,80,48,White);		
				ssd1306_DrawLine(50,49,80,49,White);	
				ssd1306_UpdateScreen();					
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
  ssd1306_Fill(White);	
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
  ssd1306_Fill(White);	
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString("  COLOR 2 ",Font_11x18,Black, NoInversion);
	int_to_char(cv_2[0]);
	out_char_pos(0);	
	int_to_char(cv_2[1]);
	out_char_pos(1);	
	int_to_char(cv_2[2]);
	out_char_pos(2);		
	int_to_char(cv_2[3]);
	out_char_pos(3);	
	int_to_char(cv_2[4]);
	out_char_pos(4);	
	int_to_char(cv_2[5]);
	out_char_pos(5);			
  ssd1306_UpdateScreen();	
	cursor_pos = 0;
	cursor_move = 0;		
}


//****************************************************************************//
// Transition function "menu_11"
//****************************************************************************//
void FSM_menu_11 (void)
{
	if(cursor_move == 0)cursor_pos=0;	
			
	out_cursor_position(Black);		
  ssd1306_UpdateScreen();		

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
				out_cursor_position(White);				
				if(cursor_move != 0)cursor_pos++;	
				if(cursor_pos > 5)cursor_pos = 0;
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;
			
			case 8: //left	
				menu_11_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)
					{
						if(cursor_pos == 0) 
						{
							cursor_pos = 5;	
						}
						else
						{
							cursor_pos--;
						}
					}
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;

			case 0x10: //ok		
				out_cursor_position(White);			
				cursor_pos = 0;			
				cursor_move = 0;			
				menu_11_open = 0;
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
  ssd1306_Fill(White);	
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString("  COLOR 3 ",Font_11x18,Black, NoInversion);
	int_to_char(cv_3[0]);
	out_char_pos(0);	
	int_to_char(cv_3[1]);
	out_char_pos(1);	
	int_to_char(cv_3[2]);
	out_char_pos(2);		
	int_to_char(cv_3[3]);
	out_char_pos(3);	
	int_to_char(cv_3[4]);
	out_char_pos(4);	
	int_to_char(cv_3[5]);
	out_char_pos(5);			
  ssd1306_UpdateScreen();	
	cursor_pos = 0;
	cursor_move = 0;	
}


//****************************************************************************//
// Transition function "menu_21"
//****************************************************************************//
void FSM_menu_21 (void)
{
	if(cursor_move == 0)cursor_pos=0;	
			
	out_cursor_position(Black);		
  ssd1306_UpdateScreen();		

		switch(key_scan)
		{
			case 1: //down
				if(menu_21_open == 1)
				{
					cv_2[0+cursor_pos]--;if(cv_2[0+cursor_pos] == 0)cv_2[0+cursor_pos] = 999;
				}
				int_to_char(cv_2[0+cursor_pos]);
				out_char_pos(cursor_pos);			
			break;
			
			case 2: //up
				if(menu_21_open == 1)
				{
					cv_2[0+cursor_pos]++;if(cv_2[0+cursor_pos] == 999)cv_2[0+cursor_pos] = 0;
				}
				int_to_char(cv_2[0+cursor_pos]);
				out_char_pos(cursor_pos);	
			break;
			
			case 4: //rigth
				menu_21_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)cursor_pos++;	
				if(cursor_pos > 5)cursor_pos = 0;
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;
			
			case 8: //left	
				menu_21_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)
					{
						if(cursor_pos == 0) 
						{
							cursor_pos = 5;	
						}
						else
						{
							cursor_pos--;
						}
					}
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;

			case 0x10: //ok		
				out_cursor_position(White);			
				cursor_pos = 0;			
				cursor_move = 0;			
				menu_21_open = 0;
			break;				
			
			default:
				break;				
		}			
}


//****************************************************************************//
// Transition function "menu_4"
//****************************************************************************//
void FSM_menu_4 (void)
{
  ssd1306_Fill(White);	
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString("  COLOR 4 ",Font_11x18,Black, NoInversion);
	int_to_char(cv_4[0]);
	out_char_pos(0);	
	int_to_char(cv_4[1]);
	out_char_pos(1);	
	int_to_char(cv_4[2]);
	out_char_pos(2);		
	int_to_char(cv_4[3]);
	out_char_pos(3);	
	int_to_char(cv_4[4]);
	out_char_pos(4);	
	int_to_char(cv_4[5]);
	out_char_pos(5);			
  ssd1306_UpdateScreen();	
	cursor_pos = 0;
	cursor_move = 0;		
}


//****************************************************************************//
// Transition function "menu_31"
//****************************************************************************//
void FSM_menu_31 (void)
{
	if(cursor_move == 0)cursor_pos=0;	
			
	out_cursor_position(Black);		
  ssd1306_UpdateScreen();		

		switch(key_scan)
		{
			case 1: //down
				if(menu_31_open == 1)
				{
					cv_3[0+cursor_pos]--;if(cv_3[0+cursor_pos] == 0)cv_3[0+cursor_pos] = 999;
				}
				int_to_char(cv_3[0+cursor_pos]);
				out_char_pos(cursor_pos);			
			break;
			
			case 2: //up
				if(menu_31_open == 1)
				{
					cv_3[0+cursor_pos]++;if(cv_3[0+cursor_pos] == 999)cv_3[0+cursor_pos] = 0;
				}
				int_to_char(cv_3[0+cursor_pos]);
				out_char_pos(cursor_pos);	
			break;
			
			case 4: //rigth
				menu_31_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)cursor_pos++;	
				if(cursor_pos > 5)cursor_pos = 0;
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;
			
			case 8: //left	
				menu_31_open = 1;
				out_cursor_position(White);				
				if(cursor_move != 0)
					{
						if(cursor_pos == 0) 
						{
							cursor_pos = 5;	
						}
						else
						{
							cursor_pos--;
						}
					}
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;

			case 0x10: //ok		
				out_cursor_position(White);			
				cursor_pos = 0;			
				cursor_move = 0;			
				menu_31_open = 0;
			break;				
			
			default:
				break;				
		}			
}


//****************************************************************************//
// Transition function "menu_5"
//****************************************************************************//
void FSM_menu_5 (void)
{
  ssd1306_Fill(White);	
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString(" Pered val",Font_11x18,Black, NoInversion);
	int_to_char(pered_val[0]);
	out_char_pos(0);	
	int_to_char(pered_val[1]);
	out_char_pos(1);	
	int_to_char(pered_val[2]);
	out_char_pos(2);		
	int_to_char(pered_val[3]);
	out_char_pos(3);	
	int_to_char(pered_val[4]);
	out_char_pos(4);	
	int_to_char(pered_val[5]);
	out_char_pos(5);			
  ssd1306_UpdateScreen();	
	cursor_pos = 0;
	cursor_move = 0;		
}


//****************************************************************************//
// Transition function "menu_41"
//****************************************************************************//
void FSM_menu_41 (void)
{
	if(cursor_move == 0)cursor_pos=0;	
			
	out_cursor_position(Black);		
  ssd1306_UpdateScreen();		

		switch(key_scan)
		{
			case 1: //down
				if(menu_41_open == 1)
				{
					cv_4[0+cursor_pos]--;if(cv_4[0+cursor_pos] == 0)cv_4[0+cursor_pos] = 999;
				}
				int_to_char(cv_4[0+cursor_pos]);
				out_char_pos(cursor_pos);			
			break;
			
			case 2: //up
				if(menu_41_open == 1)
				{
					cv_4[0+cursor_pos]++;if(cv_4[0+cursor_pos] == 999)cv_4[0+cursor_pos] = 0;
				}
				int_to_char(cv_4[0+cursor_pos]);
				out_char_pos(cursor_pos);	
			break;
			
			case 4: //rigth
				menu_41_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)cursor_pos++;	
				if(cursor_pos > 5)cursor_pos = 0;
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;
			
			case 8: //left	
				menu_41_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)
					{
						if(cursor_pos == 0) 
						{
							cursor_pos = 5;	
						}
						else
						{
							cursor_pos--;
						}
					}
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;

			case 0x10: //ok		
				out_cursor_position(White);			
				cursor_pos = 0;			
				cursor_move = 0;			
				menu_41_open = 0;
			break;				
			
			default:
				break;				
		}			
}


//****************************************************************************//
// Transition function "menu_6"
//****************************************************************************//
void FSM_menu_6 (void)
{
  ssd1306_Fill(White);	
  ssd1306_SetCursor(3,3);
  ssd1306_WriteString(" Zadn val ",Font_11x18,Black, NoInversion);
	int_to_char(zad_val[0]);
	out_char_pos(0);	
	int_to_char(zad_val[1]);
	out_char_pos(1);	
	int_to_char(zad_val[2]);
	out_char_pos(2);		
	int_to_char(zad_val[3]);
	out_char_pos(3);	
	int_to_char(zad_val[4]);
	out_char_pos(4);	
	int_to_char(zad_val[5]);
	out_char_pos(5);			
  ssd1306_UpdateScreen();	
	cursor_pos = 0;
	cursor_move = 0;		
}


//****************************************************************************//
// Transition function "menu_51"
//****************************************************************************//
void FSM_menu_51 (void)
{
	if(cursor_move == 0)cursor_pos=0;	
			
	out_cursor_position(Black);		
  ssd1306_UpdateScreen();		

		switch(key_scan)
		{
			case 1: //down
				if(menu_51_open == 1)
				{
					pered_val[0+cursor_pos]--;if(pered_val[0+cursor_pos] == 0)pered_val[0+cursor_pos] = 999;
				}
				int_to_char(pered_val[0+cursor_pos]);
				out_char_pos(cursor_pos);			
			break;
			
			case 2: //up
				if(menu_51_open == 1)
				{
					pered_val[0+cursor_pos]++;if(pered_val[0+cursor_pos] == 999)pered_val[0+cursor_pos] = 0;
				}
				int_to_char(pered_val[0+cursor_pos]);
				out_char_pos(cursor_pos);	
			break;
			
			case 4: //rigth
				menu_51_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)cursor_pos++;	
				if(cursor_pos > 5)cursor_pos = 0;
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;
			
			case 8: //left	
				menu_51_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)
					{
						if(cursor_pos == 0) 
						{
							cursor_pos = 5;	
						}
						else
						{
							cursor_pos--;
						}
					}
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;

			case 0x10: //ok		
				out_cursor_position(White);			
				cursor_pos = 0;			
				cursor_move = 0;			
				menu_51_open = 0;
			break;				
			
			default:
				break;				
		}			
}


//****************************************************************************//
// Transition function "menu_61"
//****************************************************************************//
void FSM_menu_61 (void)
{
	if(cursor_move == 0)cursor_pos=0;	
			
	out_cursor_position(Black);		
  ssd1306_UpdateScreen();		

		switch(key_scan)
		{
			case 1: //down
				if(menu_61_open == 1)
				{
					zad_val[0+cursor_pos]--;if(zad_val[0+cursor_pos] == 0)zad_val[0+cursor_pos] = 999;
				}
				int_to_char(zad_val[0+cursor_pos]);
				out_char_pos(cursor_pos);			
			break;
			
			case 2: //up
				if(menu_61_open == 1)
				{
					zad_val[0+cursor_pos]++;if(zad_val[0+cursor_pos] == 999)zad_val[0+cursor_pos] = 0;
				}
				int_to_char(zad_val[0+cursor_pos]);
				out_char_pos(cursor_pos);	
			break;
			
			case 4: //rigth
				menu_61_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)cursor_pos++;	
				if(cursor_pos > 5)cursor_pos = 0;
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;
			
			case 8: //left	
				menu_61_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)
					{
						if(cursor_pos == 0) 
						{
							cursor_pos = 5;	
						}
						else
						{
							cursor_pos--;
						}
					}
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;

			case 0x10: //ok		
				out_cursor_position(White);			
				cursor_pos = 0;			
				cursor_move = 0;			
				menu_61_open = 0;
			break;				
			
			default:
				break;				
		}				
}


//****************************************************************************//
// Transition function "menu_71"
//****************************************************************************//
void FSM_menu_71 (void)
{
	if(cursor_move == 0)cursor_pos=0;	
			
	out_cursor_position(Black);		
  ssd1306_UpdateScreen();		

		switch(key_scan)
		{
			case 1: //down
				if(menu_71_open == 1)
				{
					stop_mass[0+cursor_pos]--;if(stop_mass[0+cursor_pos] == 0)stop_mass[0+cursor_pos] = 999;
				}
				int_to_char(stop_mass[0+cursor_pos]);
				out_char_pos(cursor_pos);			
			break;
			
			case 2: //up
				if(menu_71_open == 1)
				{
					stop_mass[0+cursor_pos]++;if(stop_mass[0+cursor_pos] == 999)stop_mass[0+cursor_pos] = 0;
				}
				int_to_char(stop_mass[0+cursor_pos]);
				out_char_pos(cursor_pos);	
			break;
			
			case 4: //rigth
				menu_71_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)cursor_pos++;	
				if(cursor_pos > 5)cursor_pos = 0;
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;
			
			case 8: //left	
				menu_71_open = 1;				
				out_cursor_position(White);				
				if(cursor_move != 0)
					{
						if(cursor_pos == 0) 
						{
							cursor_pos = 5;	
						}
						else
						{
							cursor_pos--;
						}
					}
				out_cursor_position(Black);			
				cursor_move = 1;			
				ssd1306_UpdateScreen();					
			break;

			case 0x10: //ok		
				out_cursor_position(White);			
				cursor_pos = 0;			
				cursor_move = 0;			
				menu_71_open = 0;
			break;				
			
			default:
				break;				
		}				
}


//****************************************************************************//

#include "screen_out.h"

uint8_t	del;
extern	uint8_t	cursor_pos;

void int_to_char (uint16_t in_value)
{
	uint8_t a100,a10,a1;
	if(in_value > 999)
	{
		in_value = 999;
	}
	a100 = in_value / 100;
	char_100 = a100 | 0x30;
	a10 = (in_value - 100*a100)/10;
	char_10 = a10 | 0x30;
	a1 = in_value - 100*a100 - 10*a10;
	char_1 = a1 | 0x30;
}

void out_char_center(void)
{
	ssd1306_SetCursor(50,30);
	ssd1306_WriteChar(char_100, Font_11x18,Black);
  ssd1306_SetCursor(60,30);	
	ssd1306_WriteChar(char_10, Font_11x18,Black);
  ssd1306_SetCursor(70,30);	
	ssd1306_WriteChar(char_1, Font_11x18,Black);					
  ssd1306_UpdateScreen();	
}

void out_char_pos(uint8_t pos)
{
	del=pos/3;
	if(pos < 3)
	{
			ssd1306_SetCursor(3+44*pos,22);	
			ssd1306_WriteChar(char_100, Font_11x18,Black);
			ssd1306_SetCursor(14+44*pos,22);	
			ssd1306_WriteChar(char_10, Font_11x18,Black);
			ssd1306_SetCursor(25+44*pos,22);	
			ssd1306_WriteChar(char_1, Font_11x18,Black);		
	}
	else
	{
			pos = pos-3;
			ssd1306_SetCursor(3+44*pos,43);	
			ssd1306_WriteChar(char_100, Font_11x18,Black);
			ssd1306_SetCursor(14+44*pos,43);	
			ssd1306_WriteChar(char_10, Font_11x18,Black);
			ssd1306_SetCursor(25+44*pos,43);	
			ssd1306_WriteChar(char_1, Font_11x18,Black);		
	}
  ssd1306_UpdateScreen();		
}

void out_cursor_position(SSD1306_COLOR color)
{
				if(cursor_pos <3)
				{
					ssd1306_DrawLine(3+cursor_pos*44,40,33+cursor_pos*44,40,color);		
					ssd1306_DrawLine(3+cursor_pos*44,41,33+cursor_pos*44,41,color);			
				}
				else
				{
					ssd1306_DrawLine(3+(cursor_pos-3)*44,61,33+(cursor_pos-3)*44,61,color);		
					ssd1306_DrawLine(3+(cursor_pos-3)*44,62,33+(cursor_pos-3)*44,62,color);						
				}		
}


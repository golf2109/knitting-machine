#ifndef SCREEN_OUT_H
#define SCREEN_OUT_H

#include "stm32f1xx_hal.h"
#include "ssd1306.h"
#include "fonts.h"
////extern FontDef Font_7x10;
////extern FontDef Font_11x18;
////extern FontDef Font_16x26;

extern	uint16_t prog_oborot;
extern	uint16_t cv_1[20];
extern	uint16_t cv_2[20];
extern	uint16_t cv_3[20];
extern	uint16_t cv_4[20];
extern	uint16_t pered_val[20];
extern	uint16_t zad_val[20];
extern	uint16_t stop_mass[20];

char char_100;
char char_10;
char char_1;

void int_to_char (uint16_t in_value);
void out_char_center(void);
void out_char_pos(uint8_t pos);
#endif

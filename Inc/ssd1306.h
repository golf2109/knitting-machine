#include "stm32f1xx_hal.h"
#include "fonts.h"

// This library for use with STM32 microcontrollers and uses the HAL i2c libraries.
// This library is designed to use a ssd1306 driven OLED display.
// To use should definitely below the defines are set correctly.
// As used I2C port and the size of the screen.
// The library uses two files (fonts.c / h), which describes three fonts.
// These fonts can be used as:
// - Font_7x10
// - Font_11x18
// - Font_16x26

#ifndef ssd1306
#define ssd1306

// I2c port name in main programs generated by CubeMX
#define SSD1306_I2C_PORT		hi2c1
// I2C address 
#define SSD1306_I2C_ADDR        0x78
// SSD1306 width in pixels
#define SSD1306_WIDTH           128
// SSD1306 LCD height in pixels
#define SSD1306_HEIGHT          64

// Enum for the colors of the Black and White screen
typedef enum {
	Black = 0x00, /*!< Black color, no pixel */
	White = 0x01  /*!< Pixel is set. Color depends on LCD */
} SSD1306_COLOR;

typedef enum {
	NoInversion = 0x00,
	Inversion	= 0x01
} SSD1306_INVERSION;

// Struct to track changes
typedef struct {
	uint16_t CurrentX;
	uint16_t CurrentY;
	uint8_t Inverted;
	uint8_t Initialized;
} SSD1306_t;

// The i2c port is in the main
extern I2C_HandleTypeDef SSD1306_I2C_PORT;
void ssd1306_WriteCommand(uint8_t command);
uint8_t ssd1306_Init(void);
void ssd1306_Fill(SSD1306_COLOR color);
void ssd1306_UpdateScreen(void);
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
void ssd1306_InversionPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color);
char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color, SSD1306_INVERSION inversion);	
void ssd1306_SetCursor(uint8_t x, uint8_t y);
void ssd1306_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, SSD1306_COLOR color);
void ssd1306_DrawRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, SSD1306_COLOR color);
void ssd1306_DrawFilledRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, SSD1306_COLOR color);

static void ssd1306_WriteCommand(uint8_t command);

#endif

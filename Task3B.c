//
// Smpl_LCD_DrawBmp : Draw different size of bitmap
//
// bmp2asm to convert into byte array
#include <stdio.h>	
#include <string.h>																										 
#include "NUC1xx.h"
#include "SYS.h"
#include "LCD.h"
#include "Scankey.h"

//bitmap 8x8
//Byte0......7
//    00011000 bit0 (LSB)
//    00100100
//    01000010
//    11111111
//    00011000
//    00011000
//    00011000
//    00000000 bit7 (MSB)
unsigned char bmp8x8[8] = {
	0x08,0x0C,0x0A,0x79,0x79,0x0A,0x0C,0x08};

//bitmap 16x8
//Byte0...............15
//    00000011,11000000, bit0 (LSB)
//    00001111,11110000,
//    00011111,11111000,
//    00110101,10101100,
//    01111111,01111110,
//    00111001,10011100,
//    00010000,00001000,
//    00000000,00000000, bit7 (MSB)


unsigned char bmp32x32[128] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x40,0x20,0x30,0x10,0x18,0x18,0x08,0x08,0xFF,0x08,0x08,0x18,0x18,0x30,0x30,0x60,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x80,0x80,0x80,0x80,0xF8,0x8E,0x81,0x81,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x81,0x87,0x9E,0xF8,0x80,0x80,0x80,
	0x01,0x01,0x01,0x01,0x0F,0x39,0xE1,0x81,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x81,0x61,0x3D,0x0F,0x00,0x01,0x01,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x02,0x06,0x04,0x0C,0x08,0x08,0x18,0xFF,0x08,0x08,0x08,0x0C,0x04,0x04,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char blank[32]={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int32_t main (void)
{
	char TEXT[16];
	int i;
	int8_t x,y;
	int8_t keyin=0;

	UNLOCKREG();
  DrvSYS_Open(50000000);
	LOCKREG();

	init_LCD();  
	clear_LCD();
	OpenKeyPad();

	print_Line(0,"  Press any");
	print_Line(1," 1 ~ 9 button");
	print_Line(2,"  To move");
	print_Line(3,"the crosshair");
	
	while(1) {
  keyin=ScanKey(); // Scan 3x3 keypad 
  switch(keyin){   // input 1~9 to select bitmap to draw
		case 1:	clear_LCD(); draw_Bmp32x32(0,0,FG_COLOR,BG_COLOR,bmp32x32); break;
		case 2:	clear_LCD(); draw_Bmp32x32(43,0,FG_COLOR,BG_COLOR,bmp32x32); break;
		case 3:	clear_LCD(); draw_Bmp32x32(96,0,FG_COLOR,BG_COLOR,bmp32x32); break;
		case 4:	clear_LCD(); draw_Bmp32x32(0,15,FG_COLOR,BG_COLOR,bmp32x32); break;
		case 5:	clear_LCD(); draw_Bmp32x32(43,15,FG_COLOR,BG_COLOR,bmp32x32); break;
		case 6:	clear_LCD(); draw_Bmp32x32(95,15,FG_COLOR,BG_COLOR,bmp32x32); break;
		case 7:	clear_LCD(); draw_Bmp32x32(0,30,FG_COLOR,BG_COLOR,bmp32x32); break;
		case 8:	clear_LCD(); draw_Bmp32x32(43,30,FG_COLOR,BG_COLOR,bmp32x32); break;
		case 9:	clear_LCD(); draw_Bmp32x32(95,30,FG_COLOR,BG_COLOR,bmp32x32); break;
		//default: clear_LCD(); draw_Bmp32x32(43,15,FG_COLOR,BG_COLOR,bmp32x32); break; // clear LCD when key is not pressed
		}
	}
}
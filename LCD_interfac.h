/*
 * LCD_config.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Magico
 */

#include "STD_TYPES.h"
#define  ROW0     0
#define  ROW1     1
#define  ROW2     2
#define  ROW3     3


#define  CHAR0     0
#define  CHAR1     1
#define  CHAR2     2
#define  CHAR3     3
#define  CHAR4     4
#define  CHAR5     5
#define  CHAR6     6
#define  CHAR7     7
#ifndef   LCD_INTERFACE_H_
#define   LCD_INTERFACE_H_
//intaite lcd
void HLCD_voidLcdIntiate(void);
//write char in lcd
void HLCD_voidLcdWriteChar(u8 data);
//CLEAR lcd
void HLCD_voidLcdClear(void);
//to write char
void HLCD_voidLcdcmd(u8 command);
//to write string
void HLCD_voidLcdWriteString(u8 *u8data,u8 u8copy_row,u8 u8copy_col);
//TO WRITE INTEGER NUMBER
void HLCD_voidLcdWriteIntiger(u32 u8data,u8 u8copy_row,u8 u8copy_col);
//TO DRAW
void HLCD_voidLcdDraw(u8 *u8data,u8 u8copy_char,u8 u8copy_row,u8 u8copy_col);
void HLCD_voidLcdSetAddress(u8 u8copy_row,u8 u8copy_col);
u8 LCD_u8WriteNum( f64 real_num );
#endif

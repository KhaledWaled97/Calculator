/*
 * LCD_config.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Magico
 */

#ifndef   LCD_PRIVATE_H_
#define   LCD_PRIVATE_H_
#define  RS    PORTA_ID,PIN3
#define  EN    PORTA_ID,PIN2
#define  D4    PORTB_ID,PIN0
#define  D5    PORTB_ID,PIN1
#define  D6    PORTB_ID,PIN2
#define  D7    PORTB_ID,PIN4

#define  CLEAR_LCD            0X01
#define  RETURN_HOME_LCD      0X02
#define  DISPLAY_OFF_LCD      0X08
#define  DISPLAY_ON_LCD       0X0C
#define  BIT4_MODE_LCD        0X28
#define  ENTRY_MODE_LCD       0X06
#define  FIRST_ROW            0X80
#define  SECOND_ROW           0XC0
#define  THIRD_ROW            0X94
#define  FOURTH_ROW           0XD4
#define  CGRAM_ADD            0X40



#endif

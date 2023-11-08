/*
 * LCD_config.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Magico
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"LCD_interfac.h"
#include"LCD_private.h"
#include"LCD_config.h"
#include<util/delay.h>
static u8 data_arr[32];
static u8 count_num;
static void voidDecodeDigit(u32 u32copy_data_to_write,u8 *data_arr)
 {   count_num=0;
 	 if(u32copy_data_to_write!=0)
 	 {
     for(u8 i=0;i<32;i++)                                        //for loop with didit long iteration
     {  if((u32copy_data_to_write%10==0)&&(u32copy_data_to_write/10==0))
    	 break;
         data_arr[i]=u32copy_data_to_write%10;                 //take the number by take the remander
         u32copy_data_to_write=u32copy_data_to_write/10;       //divide the orginal number to can take the next number
         count_num++;
     }
 	 }
 	 else{}
 }

//static void   _delay_ms(u32 copy_time_to_delay)
//{
//	u32 counter_percale =(copy_time_to_delay*8)-10;  //to prescale the number to be in microsecond
//	u32 count =0;
//	while(count<counter_percale)count++;
//}
//write data in the bus
static void voidWriteInBus(u8 data_or_cmd)
{
	DIO_voidSetPinValue(D4,GET_BIT(data_or_cmd,PIN4));
	DIO_voidSetPinValue(D5,GET_BIT(data_or_cmd,PIN5));
	DIO_voidSetPinValue(D6,GET_BIT(data_or_cmd,PIN6));
	DIO_voidSetPinValue(D7,GET_BIT(data_or_cmd,PIN7));


}
//write command in bus
void HLCD_voidLcdcmd(u8 command)
{    u8 copy_command_decoded =command;
	 voidWriteInBus(copy_command_decoded);
	 DIO_voidSetPinValue(RS,PIN_LOW);  //TO WRITE COMMAND
	 DIO_voidSetPinValue(EN,PIN_HIGH); //TO MAKE PULSE FROM HIGH TO LOW TO TAKE THE COMMAND FROM BUS
     _delay_ms(1);
     DIO_voidSetPinValue(EN,PIN_LOW);	//TO MAKE PULSE FROM HIGH TO LOW TO TAKE THE COMMAND FROM BUS
	 copy_command_decoded=(command<<4);
	 voidWriteInBus(copy_command_decoded);
	 DIO_voidSetPinValue(EN,PIN_HIGH); //TO MAKE PULSE FROM HIGH TO LOW TO TAKE THE COMMAND FROM BUS
     _delay_ms(1);
     DIO_voidSetPinValue(EN,PIN_LOW);	//TO MAKE PULSE FROM HIGH TO LOW TO TAKE THE COMMAND FROM BUS
     _delay_ms(2);
}
//intaite lcd
void HLCD_voidLcdIntiate(void)
{   _delay_ms(40);
	DIO_voidSetPinDirection(RS,PIN_OUTPUT);
	DIO_voidSetPinDirection(EN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D4,PIN_OUTPUT);
	DIO_voidSetPinDirection(D5,PIN_OUTPUT);
	DIO_voidSetPinDirection(D6,PIN_OUTPUT);
	DIO_voidSetPinDirection(D7,PIN_OUTPUT);
	HLCD_voidLcdcmd(RETURN_HOME_LCD);
	_delay_ms(15);
	HLCD_voidLcdcmd(BIT4_MODE_LCD);
	_delay_ms(2);
	HLCD_voidLcdcmd(DISPLAY_ON_LCD);
	_delay_ms(2);
	HLCD_voidLcdcmd(CLEAR_LCD);
	_delay_ms(15);
	HLCD_voidLcdcmd(ENTRY_MODE_LCD);
	_delay_ms(2);
}
//to set address that user sent
void HLCD_voidLcdSetAddress(u8 u8copy_row,u8 u8copy_col)
{
	switch(u8copy_row)
		{
		case ROW0:
			   HLCD_voidLcdcmd((FIRST_ROW+u8copy_col));
			   break;
		case ROW1:
				HLCD_voidLcdcmd((SECOND_ROW+u8copy_col));
				 break;
		case ROW2:
				HLCD_voidLcdcmd((THIRD_ROW+u8copy_col));
				 break;
		case ROW3:
				HLCD_voidLcdcmd((FOURTH_ROW+u8copy_col));
				 break;
		}
}
//write char in lcd
void HLCD_voidLcdWriteChar(u8 data)
{
	 u8 copy_data_decoded =data;
	 voidWriteInBus(copy_data_decoded);
	 DIO_voidSetPinValue(RS,PIN_HIGH);  //TO WRITE DATA
	 DIO_voidSetPinValue(EN,PIN_HIGH); //TO MAKE PULSE FROM HIGH TO LOW TO TAKE THE COMMAND FROM BUS
     _delay_ms(2);
     DIO_voidSetPinValue(EN,PIN_LOW);	//TO MAKE PULSE FROM HIGH TO LOW TO TAKE THE COMMAND FROM BUS
	 copy_data_decoded=(data<<4);
	 voidWriteInBus(copy_data_decoded);
	 DIO_voidSetPinValue(EN,PIN_HIGH); //TO MAKE PULSE FROM HIGH TO LOW TO TAKE THE COMMAND FROM BUS
     _delay_ms(2);
     DIO_voidSetPinValue(EN,PIN_LOW);	//TO MAKE PULSE FROM HIGH TO LOW TO TAKE THE COMMAND FROM BUS
     _delay_ms(2);
}
//void HLCD_voidLcdWriteCharWithPostion(u8 data,u8 u8copy_row,u8 u8copy_col)
//{
//
//}
//CLEAR lcd
void HLCD_voidLcdClear(void)
{
	HLCD_voidLcdcmd(CLEAR_LCD);
}


void HLCD_voidLcdWriteString(u8* u8data,u8 u8copy_row,u8 u8copy_col)
{   u8 counter= u8copy_row*20+u8copy_col;
 	u8 * copy_of_data=u8data;
	HLCD_voidLcdSetAddress(u8copy_row,u8copy_col);
	_delay_us(40);
	while((*copy_of_data)!='\0')
	{
		HLCD_voidLcdWriteChar(*copy_of_data);
		copy_of_data++;
		counter++;
		if(counter==20)
		{HLCD_voidLcdcmd(0xC0);_delay_us(40);}
		else if(counter==40)
				{HLCD_voidLcdcmd(0x94);_delay_us(40);}
		else if(counter==60)
				{HLCD_voidLcdcmd(0xD4);_delay_us(40);}
		else if(counter==80)
						{HLCD_voidLcdcmd(0x80);_delay_us(40);}
	}

}
void HLCD_voidLcdWriteIntiger(u32 u32data,u8 u8copy_row,u8 u8copy_col)
{   u8 counter=0;
	voidDecodeDigit(u32data,data_arr);
	_delay_us(40);
    if(u8copy_col<=20)
    {
	 counter= u8copy_row*20+u8copy_col;
	 HLCD_voidLcdSetAddress(u8copy_row,u8copy_col);}
     if( count_num!=0){
		for(s8 i=count_num-1;i>=0;i--)
		{
			HLCD_voidLcdWriteChar(data_arr[i]+48);
			counter++;
			if(counter==20)
			{HLCD_voidLcdcmd(FIRST_ROW);_delay_ms(40);}
			else if(counter==40)
					{HLCD_voidLcdcmd(SECOND_ROW);_delay_ms(40);}
			else if(counter==60)
					{HLCD_voidLcdcmd(THIRD_ROW);_delay_ms(40);}
			else if(counter==80)
							{HLCD_voidLcdcmd(0x80);_delay_ms(40);}

		}}
     else  HLCD_voidLcdWriteChar(48);
		count_num=0;
}
//write in CGRAM
 static void HLCD_voidLcdWriteCGRAM(u8* u8data,u8 u8copy_char)
{
HLCD_voidLcdcmd(CGRAM_ADD+(u8copy_char*8));
for(u8 i=0;i<8;i++)
{
HLCD_voidLcdWriteChar(u8data[i]);
}

}
//TO DRAW
void HLCD_voidLcdDraw(u8* u8data,u8 u8copy_char,u8 u8copy_row,u8 u8copy_col)
{
  HLCD_voidLcdWriteCGRAM(u8data,u8copy_char);
  HLCD_voidLcdSetAddress(u8copy_row,u8copy_col);
  HLCD_voidLcdWriteChar(u8copy_char);
  HLCD_voidLcdcmd(FIRST_ROW);
}

u8 LCD_u8WriteNum( f64 real_num )
{
	s32 int_num, int_num_cpy = 1;	// integer part
	u8 ch;
	u8 signFlag = FALSE;
	u32 dec_num;				// decimal part
	u8 dec_places = 3;			// number of decimal places in dec_num
	u8 r = 0;					// rounded place
	u8 count = 0;				// written chars

	signFlag = ( real_num < 0)? TRUE : FALSE;		// detect minus sign
	real_num *= (f64) (signFlag)? -1.0 : 1.0 ;			// absolute value
	int_num = (s32) real_num;						// store integer part
	real_num -= (f32) int_num;							// delete integer part from real_num

	// store decimal part:
	while( dec_places-- > 0 )
	{ real_num *= 10.0 ; }
	dec_num = (u32) real_num;
	real_num -= (s32) real_num;
	real_num *= 10.0;
	r = (u8) real_num;
	dec_num += (r >= 5)? 1 : 0;

	if( signFlag )
	{
		HLCD_voidLcdWriteChar( '-' );
		count++;
	}

	if( !int_num )
	{
		HLCD_voidLcdWriteChar( '0' );
		count++;
	}
	// storing the integer part reversed:
	while( int_num != 0 )
	{
		int_num_cpy *= 10;
		int_num_cpy += int_num % 10;
		int_num /= 10;
	}
	// displaying the integer part:
	while( int_num_cpy != 1 )
	{
		ch = int_num_cpy % 10 + '0';
		HLCD_voidLcdWriteChar( ch );
		count++;
		int_num_cpy /= 10;
	}
	// displaying the decimal part:
	if( dec_num )
	{
		u32 dec_num_cpy = 0;
		while( dec_num != 0 )
		{
			dec_num_cpy *= 10;
			dec_num_cpy += dec_num % 10;
			dec_num /= 10;
		}
		HLCD_voidLcdWriteChar( '.' );
		count++;
		while( dec_num_cpy != 0 )
		{
			ch = dec_num_cpy % 10 + '0';
			HLCD_voidLcdWriteChar( ch );
			count++;
			dec_num_cpy /= 10;
		}
	}
	return count;
}


/*
 * main.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Khaled Waled
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LCD_interfac.h"
#include "keypad_interface.h"



#include <util/delay.h>
#include <avr/io.h>

#define TRUE	1
#define FALSE 	0


#define RESET_CALC do{\
	operand_index = operator_index = 0;\
	operand_arr[0] = operand_arr[1] = operand_arr[2] = operand_arr[3] = operand_arr[4] = 0.0;\
	operators[0] = operators[1] = operators[2] = operators[3] = operators[4] = 0;\
	opdLast = signFlag = FALSE;\
	divByZero = resultExist = resultRequest = FALSE;\
	cursor = 1;\
	HLCD_voidLcdcmd( 0x01 );\
	} while(0)

int main( void )
{
	HLCD_voidLcdIntiate();
	HKEY_voidKeybadIntiate();

	enum operators { ADD = 1, SUB, MUL, DIV };

	f64 operand_arr[5] = {0.0};
	u8 operators[5] = {0};		// operators ( +, -, *, / ) array
	u8 operand_index = 0;
	u8 operator_index = 0;
	f64 result = 0.0;

	/* Flags */
	u8 signFlag = FALSE;			// raised when minus sign is entered (but not a subtract operator)
	u8 opdLast = FALSE;				// raised if the last entered is an operand
	u8 divByZero = FALSE; 			// raised when attempt to divide by zero
	u8 resultExist = FALSE;			// raised when there is a result on LCD
	u8 resultRequest = FALSE;		// raised when equals sign is entered

	u8 cursor = 1;			// cursor in line 1

	while( 1 )
	{
		u8 sym;					// symbol button
		u8 btn;
		for( btn = 0; btn <= 15; btn++ )
		{
			if( kpad_u8GetBtnStatus( btn ) == PRESSED )
			{
				sym = kpad_u8GetBtnSym( btn );
				if( resultExist )
				{
					if( sym == '+' || sym == '-' || sym == '*' || sym == '/' )
					{
						RESET_CALC;
						operand_arr[operand_index] = result;
						cursor += LCD_u8WriteNum( result );
						opdLast = TRUE;
					}
					else if( sym >= '0' && sym <= '9' )
					{
						RESET_CALC;
					}
				}

				switch( sym )
				{
					case 'c':
						RESET_CALC;
						continue;
						break;

					case '0'...'9':
						operand_arr[operand_index] *= 10.0;
						operand_arr[operand_index] += (f64) ( (signFlag)? -1.0 : 1.0 ) * (sym - '0');
						opdLast = TRUE;
						break;

					case '+':
						if( opdLast )
						{
							operators[operator_index++] = ADD;
							operand_index++;
							opdLast = FALSE;
						}
						else
						{ opdLast = TRUE; }
						break;
					case '-':
						if( opdLast )
						{
							operators[operator_index++] = SUB;
							operand_index++;
							opdLast = FALSE;
						}
						else
						{
							signFlag = TRUE;
							opdLast = TRUE;
						}
						break;
					case '*':
						if( opdLast )
						{
							operators[operator_index++] = MUL;
							operand_index++;
							opdLast = FALSE;
						}
						else
						{
							operators[operator_index-1] = MUL;
							HLCD_voidLcdSetAddress( 1, --cursor );
						}
						break;
					case '/':
						if( opdLast )
						{
							operators[operator_index++] = DIV;
							operand_index++;
							opdLast = FALSE;
						}
						else
						{
							operators[operator_index-1] = DIV;
							HLCD_voidLcdSetAddress( 1, --cursor );
						}
						break;

					case '=':
						// calculate the result:
						result = operand_arr[0];			// initial value
						u8 i;
						for( i = 0; i <= operator_index; i++ )
						{
							switch( operators[i] )
							{
								case ADD:
									result += operand_arr[i+1];
									break;
								case SUB:
									result -= operand_arr[i+1];
									break;
								case MUL:
									result *= operand_arr[i+1];
									break;
								case DIV:
									if( operand_arr[i+1] == 0 )// if division by zero:
									{
										divByZero = TRUE;
									}
									else
									{
										result /= operand_arr[i+1];
									}
									break;
								default:
									break;
							}
						}
						resultExist = TRUE;
						resultRequest = TRUE;
						break;
					default:
						break;
				}


				signFlag = ( !opdLast )? FALSE : signFlag ;// reset signFlag if operand is entered


				HLCD_voidLcdWriteChar( sym );// display symbol on LCD
				cursor++;

				if( resultRequest )
				{


					if( divByZero )
					{
						HLCD_voidLcdWriteString( (u8 *) "err: Div by 0!",2, 1 );
					}
					else if( !opdLast )
					{
						HLCD_voidLcdWriteString( (u8 *) "err: operand missing!",2, 1 );
					}
					else
					{
						LCD_u8WriteNum( result );
					}

					resultRequest = FALSE;
				}


				while( kpad_u8GetBtnStatus( btn ) == PRESSED ) { }// wait until key is un-pressed:
			}
		}
	}
	return 0;
}

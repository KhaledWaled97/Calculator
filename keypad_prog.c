/*
 * keypad_prog.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Magico
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "keypad_config.h"
#include "keypad_interface.h"
#include "keypad_private.h"
#include "DIO_interface.h"
#include "LCD_interfac.h"
#include <util/delay.h>

void HKEY_voidKeybadIntiate( void )
{
	/* Rows as input resistors */
	DIO_voidSetPinDirection( ROW1_PORT, ROW1_PIN, PIN_INPUT ); // input
	DIO_voidSetPinValue( ROW1_PORT, ROW1_PIN, PIN_LOW );
	DIO_voidSetPinDirection( ROW2_PORT, ROW2_PIN, PIN_INPUT ); // input
	DIO_voidSetPinValue( ROW2_PORT, ROW2_PIN, PIN_LOW );
	DIO_voidSetPinDirection( ROW3_PORT, ROW3_PIN, PIN_INPUT ); // input
	DIO_voidSetPinValue( ROW3_PORT, ROW3_PIN, PIN_LOW );
	DIO_voidSetPinDirection( ROW4_PORT, ROW4_PIN, PIN_INPUT ); // input
	DIO_voidSetPinValue( ROW4_PORT, ROW4_PIN, PIN_LOW );

	/* Columns as output */
	DIO_voidSetPinDirection( COL1_PORT, COL1_PIN, PIN_OUTPUT );
	DIO_voidSetPinDirection( COL2_PORT, COL2_PIN, PIN_OUTPUT );
	DIO_voidSetPinDirection( COL3_PORT, COL3_PIN, PIN_OUTPUT );
	DIO_voidSetPinDirection( COL4_PORT, COL4_PIN, PIN_OUTPUT );
}

u8 kpad_u8GetBtnStatus( u8 btn )
{
	// map row and column:
	u8 row = btn / 4;
	u8 col = btn % 4;

	u8 realRow[] = { ROW1_PIN, ROW2_PIN, ROW3_PIN, ROW4_PIN };
	u8 realCol[] = { COL1_PIN, COL2_PIN, COL3_PIN, COL4_PIN };
	u8 value = UNPRESSED, status = UNPRESSED;

	// all columns HIGH
	DIO_voidSetPinValue( COL1_PORT, COL1_PIN, PIN_HIGH );
	DIO_voidSetPinValue( COL2_PORT, COL2_PIN, PIN_HIGH );
	DIO_voidSetPinValue( COL3_PORT, COL3_PIN, PIN_HIGH );
	DIO_voidSetPinValue( COL4_PORT, COL4_PIN, PIN_HIGH );

	// button column LOW
	DIO_voidSetPinValue( COL1_PORT, realCol[col], PIN_LOW );

	// button row check:
	value = DIO_u8GetPinValue( ROW1_PORT, realRow[row] );
	if( value == PRESSED )
	{
		_delay_ms( 20 );	// for bouncing
		// read again:
		value = DIO_u8GetPinValue( ROW1_PORT, realRow[row] );
		if( value == PRESSED )
		{ status = PRESSED; }
	}
	return status;
}

// returns symbol (ASCII) of a given button
u8 kpad_u8GetBtnSym( u8 btn )
{
	switch( btn )
	{
	case BTN0:
		return '0';
		break;
	case BTN1:
		return '1';
		break;
	case BTN2:
		return '2';
		break;
	case BTN3:
		return '3';
		break;
	case BTN4:
		return '4';
		break;
	case BTN5:
		return '5';
		break;
	case BTN6:
		return '6';
		break;
	case BTN7:
		return '7';
		break;
	case BTN8:
		return '8';
		break;
	case BTN9:
		return '9';
		break;
	case BTN_EQU:
		return '=';
		break;
	case BTN_CLR:
		return 'c';
		break;
	case BTN_PLS:
		return '+';
		break;
	case BTN_MIN:
		return '-';
		break;
	case BTN_MUL:
		return '*';
		break;
	case BTN_DIV:
		return '/';
		break;
	}
	return 0;
}

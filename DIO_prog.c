#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"



void DIO_voidSetPortDirection (u8 Copy_u8PortID , u8 Copy_u8PortDir )
{
	if (Copy_u8PortID<=3)
	{
		switch(Copy_u8PortID)
		{
			case PORTA_ID : DDRA_REG =Copy_u8PortDir ;break;
			case PORTB_ID : DDRB_REG =Copy_u8PortDir ;break;
			case PORTC_ID : DDRC_REG =Copy_u8PortDir ;break;
			case PORTD_ID : DDRD_REG =Copy_u8PortDir ;break;
			default :
				break;
		}
	}
}
void DIO_voidSetPortValue (u8 Copy_u8PortID , u8 Copy_u8PortVal )
{
	if (Copy_u8PortID<=3 )
	{
		switch(Copy_u8PortID)
		{
			case PORTA_ID : PORTA_REG =Copy_u8PortVal ;break;
			case PORTB_ID : PORTB_REG =Copy_u8PortVal ;break;
			case PORTC_ID : PORTC_REG =Copy_u8PortVal ;break;
			case PORTD_ID : PORTD_REG =Copy_u8PortVal ;break;
			default :
				break;
		}
	}
}

void DIO_voidSetPinDirection (u8 Copy_u8PortID ,u8 Copy_u8PinID, u8 Copy_u8PinDir )
{
	if (Copy_u8PinID<=7 )
	{
		if (PIN_OUTPUT ==Copy_u8PinDir)
		{
			switch(Copy_u8PortID)
	        {
				case PORTA_ID :SET_BIT(DDRA_REG,Copy_u8PinID);break;
				case PORTB_ID :SET_BIT(DDRB_REG,Copy_u8PinID);break;
				case PORTC_ID :SET_BIT(DDRC_REG,Copy_u8PinID);break;
				case PORTD_ID :SET_BIT(DDRD_REG,Copy_u8PinID);break;
				default :
					break;
			}
		}
		else if (PIN_INPUT ==Copy_u8PinDir)
		{
			switch(Copy_u8PortID)
			{
				case PORTA_ID :CLR_BIT(DDRA_REG,Copy_u8PinID);break;
				case PORTB_ID :CLR_BIT(DDRB_REG,Copy_u8PinID);break;
				case PORTC_ID :CLR_BIT(DDRC_REG,Copy_u8PinID);break;
				case PORTD_ID :CLR_BIT(DDRD_REG,Copy_u8PinID);break;
				default :
					break;
			}
		}
		else
		{

		}
	}
}
void DIO_voidSetPinValue (u8 Copy_u8PortID ,u8 Copy_u8PinID, u8 Copy_u8PinVal ){
	if (Copy_u8PinID<=7 )
	{
		if (PIN_HIGH ==Copy_u8PinVal)
		{
			switch(Copy_u8PortID)
			{
			case PORTA_ID :SET_BIT(PORTA_REG,Copy_u8PinID);break;
			case PORTB_ID :SET_BIT(PORTB_REG,Copy_u8PinID);break;
			case PORTC_ID :SET_BIT(PORTC_REG,Copy_u8PinID);break;
			case PORTD_ID :SET_BIT(PORTD_REG,Copy_u8PinID);break;
			default :
				break;
			}
		}
		else if (PIN_LOW ==Copy_u8PinVal)
		{
			switch(Copy_u8PortID)
			{
				case PORTA_ID :CLR_BIT(PORTA_REG,Copy_u8PinID);break;
				case PORTB_ID :CLR_BIT(PORTB_REG,Copy_u8PinID);break;
				case PORTC_ID :CLR_BIT(PORTC_REG,Copy_u8PinID);break;
				case PORTD_ID :CLR_BIT(PORTD_REG,Copy_u8PinID);break;
				default :
					break;
			}
		}
		else
		{

		}
	}
}

u8 DIO_u8GetPinValue (u8 Copy_u8PortID ,u8 Copy_u8PinID ){
	u8 value ;
	if (Copy_u8PinID<=7 )
	{
		switch(Copy_u8PortID)
		{
		case PORTA_ID : value =GET_BIT(PINA_REG ,Copy_u8PinID); break;
		case PORTB_ID : value =GET_BIT(PINB_REG ,Copy_u8PinID); break;
		case PORTC_ID : value =GET_BIT(PINC_REG ,Copy_u8PinID); break;
		case PORTD_ID : value =GET_BIT(PIND_REG ,Copy_u8PinID); break;
		default :
			break;
		}
	}

	return value;
}

void DIO_voidTogglePin (u8 Copy_u8PortID ,u8 Copy_u8PinID){

	if (Copy_u8PinID<=7 )
	{
		switch(Copy_u8PortID)
		{
			case PORTA_ID :TOG_BIT(PORTA_REG ,Copy_u8PinID); break;
			case PORTB_ID :TOG_BIT(PORTB_REG ,Copy_u8PinID); break;
			case PORTC_ID :TOG_BIT(PORTC_REG ,Copy_u8PinID); break;
			case PORTD_ID :TOG_BIT(PORTD_REG ,Copy_u8PinID); break;
			default :
				break;
		}
	}
}

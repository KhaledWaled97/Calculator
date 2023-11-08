#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
#include "STD_TYPES.h"

/**********PORT ID macros**********/
#define PORTA_ID            (u8)(0x00)
#define PORTB_ID            (u8)(0x01)
#define PORTC_ID            (u8)(0x02)
#define PORTD_ID            (u8)(0x03)

/**********PIN ID macros**********/
#define PIN0                (u8)(0x00)
#define PIN1                (u8)(0x01)
#define PIN2                (u8)(0x02)
#define PIN3                (u8)(0x03)
#define PIN4                (u8)(0x04)
#define PIN5                (u8)(0x05)
#define PIN6                (u8)(0x06)
#define PIN7                (u8)(0x07)

/**********Directions macros**********/

#define PIN_OUTPUT               (u8)(0x01)
#define PIN_INPUT                (u8)(0x00)

#define PIN_HIGH                 (u8)(0x01)
#define PIN_LOW                  (u8)(0x00)

#define ALL_PORT_OUTPUT          (u8)(0xFF)
#define ALL_PORT_INPUT           (u8)(0x00)

#define ALL_PORT_HIGH            (u8)(0xFF)
#define ALL_PORT_LOW             (u8)(0x00)



/**********Functions Prototype**********/

void DIO_voidSetPortDirection (u8 Copy_u8PortID , u8 Copy_u8PortDir );
void DIO_voidSetPortValue (u8 Copy_u8PortID , u8 Copy_u8PortVal );

void DIO_voidSetPinDirection (u8 Copy_u8PortID ,u8 Copy_u8PinID, u8 Copy_u8PinDir );
void DIO_voidSetPinValue (u8 Copy_u8PortID ,u8 Copy_u8PinID, u8 Copy_u8PinVal );

u8 DIO_u8GetPinValue (u8 Copy_u8PortID ,u8 Copy_u8PinID );

void DIO_voidTogglePin (u8 Copy_u8PortID ,u8 Copy_u8PinID);


#endif

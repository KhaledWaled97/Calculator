#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*********************PORTA registers***********************************/
#define PORTA_REG       (*(volatile u8*)(0x3B)) // Low / High
#define DDRA_REG        (*(volatile u8*)(0x3A)) // Direction I/O
#define PINA_REG        (*(volatile u8*)(0x39)) // Read Pin

/*********************PORTB registers***********************************/
#define PORTB_REG       (*(volatile u8*)(0x38))
#define DDRB_REG        (*(volatile u8*)(0x37))
#define PINB_REG        (*(volatile u8*)(0x36))

/*********************PORTC registers***********************************/
#define PORTC_REG       (*(volatile u8*)(0x35))
#define DDRC_REG        (*(volatile u8*)(0x34))
#define PINC_REG        (*(volatile u8*)(0x33))

/*********************PORTD registers***********************************/
#define PORTD_REG       (*(volatile u8*)(0x32))
#define DDRD_REG        (*(volatile u8*)(0x31))
#define PIND_REG        (*(volatile u8*)(0x30))


#endif //DIO_PRIVATE_H

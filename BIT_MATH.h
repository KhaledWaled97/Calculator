#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT_NO)       VAR|=(1<<BIT_NO)
#define CLR_BIT(VAR,BIT_NO)       VAR &=~(1<<BIT_NO)
#define GET_BIT(VAR,BIT_NO)       ((VAR>>BIT_NO)&0x01)
#define TOG_BIT(VAR,BIT_NO)       (VAR) ^= (1<<BIT_NO)

#define SET_PORT(VAR,PORT)       ( (VAR)=(PORT))

enum{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
};
#endif

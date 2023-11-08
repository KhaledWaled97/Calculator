/*
 * keypad_config.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Magico
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
/*that confige to choise THE COLOR OF LED YOU WANT TO USE:
												  SW1_PIN
                                                  SW2_PIN
												  SW3_PIN
												  SW4_PIN
			      										  */
#define ROW1_PORT            PORTC_ID
#define ROW1_PIN             PIN5
#define ROW2_PORT            PORTC_ID
#define ROW2_PIN             PIN4
#define ROW3_PORT            PORTC_ID
#define ROW3_PIN             PIN3
#define ROW4_PORT            PORTC_ID
#define ROW4_PIN             PIN2
#define COL1_PORT            PORTD_ID
#define COL1_PIN             PIN7
#define COL2_PORT            PORTD_ID
#define COL2_PIN             PIN6
#define COL3_PORT            PORTD_ID
#define COL3_PIN             PIN5
#define COL4_PORT            PORTD_ID
#define COL4_PIN             PIN3

#define BTN0	13
#define BTN1	8
#define BTN2	9
#define BTN3	10
#define BTN4	4
#define BTN5	5
#define BTN6	6
#define BTN7	0
#define BTN8	1
#define BTN9	2
#define BTN_CLR	12
#define BTN_EQU	14
#define BTN_PLS	15
#define BTN_MIN	11
#define BTN_MUL	7
#define BTN_DIV	3

#define   ARR_ROW_PORT    {ROW1_PORT,ROW2_PORT,ROW3_PORT,ROW4_PORT}
#define   ARR_ROW_PIN     {ROW1_PIN,ROW2_PIN,ROW3_PIN,ROW4_PIN}

#define   ARR_COL_PORT    {COL1_PORT,COL2_PORT,COL3_PORT,COL4_PORT}
#define   ARR_COL_PIN     {COL1_PIN,COL2_PIN,COL3_PIN,COL4_PIN}


#endif /* KEYPAD_CONFIG_H_ */

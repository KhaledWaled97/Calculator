/*
 * keypad_interface.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Magico
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define PRESSED		0
#define UNPRESSED	1

void HKEY_voidKeybadIntiate( void );
u8 kpad_u8GetBtnStatus( u8 btn );
u8 kpad_u8GetBtnSym( u8 btn );

#endif /* KEYPAD_INTERFACE_H_ */

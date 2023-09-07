 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the keypad driver
 *
 * Author: Mohamed Ezzat &Editing BY :ABDELRAHMAN MAGDY
 *
 * created date : 8/10/2022
 *
 * Version : v1.0.1
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*******************************************************************************
 *                                Inclusions                                  *
 *******************************************************************************/

#include"typedef.h"

/*******************************************************************************
 *                         	    Definitions                                    *
 *******************************************************************************/
#define STANDARD_KEYPAD
/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                   4
#define KEYPAD_NUM_ROWS                   4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                PORT_B
#define KEYPAD_FIRST_ROW_PIN_ID           PIN_4

#define KEYPAD_COL_PORT_ID                PORT_D
#define KEYPAD_FIRST_COL_PIN_ID           PIN_2

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOW
#define KEYPAD_BUTTON_RELEASED           HIGH


/*******************************************************************************
 *                         FUNCTIONS Prototypes                                *
 *******************************************************************************/
/*
 * Description :
 * Get the Keypad pressed button
 */
uint_8 KEYPAD_getPressedKey(void);
#endif /* KEYPAD_H_ */

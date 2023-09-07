 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the keypad driver
 *
 * Author: Mohamed Ezzat &Editing BY :ABDELRAHMAN MAGDY
 *
 * Created on: Oct 8, 2022
 *
 * Version : v1.0.1
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include"common_macros.h"
#include<avr/io.h>
#include <GPIO_Enums_func.h>
#include"keypad.h"

/*******************************************************************************/

/*******************************************************************************
 *                      		   FUNCTIONS                                   *
 *******************************************************************************/
/*
 * Description :
 * Get the Keypad pressed button
 */
uint_8 KEYPAD_getPressedKey(void)
{
	uint_8 row,col;
	GPIO_setpindirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID,INPUT);
	GPIO_setpindirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+1,INPUT);
	GPIO_setpindirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+2,INPUT);
	GPIO_setpindirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+3,INPUT);

	GPIO_setpindirection(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID,INPUT);
	GPIO_setpindirection(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+1,INPUT);
	GPIO_setpindirection(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+2,INPUT);
#if (KEYPAD_NUM_COLS==4)
	GPIO_setpindirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+3,INPUT);
#endif

	while(1)
	{
		for(row=0;row<KEYPAD_NUM_ROWS;row++)
		{
			GPIO_setpindirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+row,OUTPUT);
			GPIO_writepin(KEYPAD_ROW_PORT_ID, KEYPAD_FIRST_ROW_PIN_ID+row, KEYPAD_BUTTON_PRESSED);

			for(col=0;col<KEYPAD_NUM_COLS;col++)
			{
				if(GPIO_readpin(KEYPAD_COL_PORT_ID,KEYPAD_FIRST_COL_PIN_ID+col) == KEYPAD_BUTTON_PRESSED)
				{
					#if (KEYPAD_NUM_COLS == 3)

					#ifdef STANDARD_KEYPAD
						return ((row*KEYPAD_NUM_COLS)+col+1);
					#else
						return KEYPAD_4x3_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#endif

					#elif (KEYPAD_NUM_COLS == 4)

					#ifdef STANDARD_KEYPAD
						return ((row*KEYPAD_NUM_COLS)+col+1);
					#else
						return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#endif
					#endif

				}
			}
			GPIO_setpindirection(KEYPAD_ROW_PORT_ID,KEYPAD_FIRST_ROW_PIN_ID+row,INPUT);
		}
	}
}


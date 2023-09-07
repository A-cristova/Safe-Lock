/*
 *  File Name :APP.c
 *  Des: File include functions
 *  Created on: Sep 5, 2023
 *  Author: ABDELRAHMAN MAGDY
 */
#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "lcd.h"
#include "red_led.h"
#include "green_led.h"
#include "typedef.h"
#include "app.h"

/*Default Password */
static uint_8 pass_word[]={1,9,1,7};

static void menu_screen();                     //function to display menu screen
static void open_safe_screen();                //function to display open safe screen
static void true_pass_screen();                //function to display true password screen
static void change_pass_screen();              //function to display change password screen
static void change_pass();                     //function to change password
static void wrong_pass_screen(uint_8 num);     //function to display wrong password screen
static void ThiefAlert();                      //function to display thief Alert


void App_init()
{
	LCD_init();
	RED_LED_init();
	GRN_LED_init();
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
void App_Welcome_screen()
{
	LCD_clearScreen();
	LCD_displayString("HELLO...ABDO");
	_delay_ms(1000);
	menu_screen();
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void menu_screen()
{
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"1)Open Safe");
	LCD_displayStringRowColumn(1,0,"2)Change Pass");
	uint_8 presskey = KEYPAD_getPressedKey();

	switch (presskey)
	{
	    case 1: _delay_ms(1000);
	    	    open_safe_screen();
	    break;
	    case 2: _delay_ms(1000);
	            change_pass_screen();
	    break;
	    default:
		LCD_clearScreen();
		LCD_displayStringRowColumn(0,0,"Wrong Input");
		LCD_displayStringRowColumn(1,0,"System Reset");
		_delay_ms(1500);
		App_Welcome_screen();
	}
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void open_safe_screen()
{
	uint_8 user_press [4];
	pass_state state = wrong_password;
    for (uint_8 i=0; i<3 && state==wrong_password; i++)
    {
    	LCD_clearScreen();
    	LCD_displayStringRowColumn(0,0,"Enter Pass");
    	LCD_moveCursor(1,0);
        for(uint_8 j=0; j<4; j++)
        {
        	   user_press [j]=KEYPAD_getPressedKey();
        	   _delay_ms(1000);
        	   LCD_displayCharacter("*");
        }
        state=true_password;
        for(uint_8 j=0; j<4; j++)
        {
        	   if(user_press[j]!=pass_word[j] )
        	   {
        		     wrong_pass_screen(3- i);
        		     state =wrong_password;
                     break;
        	   }
        }
    }
	if(state == true_password)
	{
		_delay_ms(500);
		true_pass_screen();
		menu_screen();
	}
	else
	{
		_delay_ms(500);
		ThiefAlert();
		menu_screen();
	}
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void true_pass_screen()
{
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"True Pass !!");
	GRN_LED_on();
	_delay_ms(3000);
	GRN_LED_off();
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void change_pass_screen()
{
	uint_8 user_press [4];
	pass_state state =wrong_password;
    for (uint_8 i=0; i<3 && state==wrong_password; i++)
    {
    	LCD_clearScreen();
    	LCD_displayStringRowColumn(0,0,"Enter Old Pass");
    	LCD_moveCursor(1,0);
        for(uint_8 j=0; j<4; j++)
        {
        	user_press [j]=KEYPAD_getPressedKey();
        	_delay_ms(1000);
        	LCD_displayCharacter("*");
        }
        state=true_password;
        for(uint_8 j=0; j<4; j++)
        {
        	   if(user_press[j]!=pass_word[j] )
        	   {
        		     wrong_pass_screen(3- i);
        		     state =wrong_password;
                     break;
        	   }
        }
    }
	if(state == true_password)
	{
		_delay_ms(500);
		change_pass();
		menu_screen();
	}
	else
	{
		_delay_ms(500);
		ThiefAlert();
		menu_screen();
	}
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void change_pass()
{
	LCD_clearScreen();
	LCD_displayString("Enter New Pass");
	LCD_moveCursor(1, 0);

	for(uint_8 j=0;j<4;j++)
	{
		pass_word[j] = KEYPAD_getPressedKey();
		_delay_ms(1000);
		LCD_displayCharacter('*');
	}
	_delay_ms(500);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"Pass Updated");
	LCD_displayStringRowColumn(1,0,"Successfully !!");
	_delay_ms(1500);
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void wrong_pass_screen(uint_8 num)
{
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"Wrong Pass");
	LCD_displayStringRowColumn(1,0,"Tries Left -");
	LCD_integerToString(num);
	RED_LED_on();
	_delay_ms(2000);
	RED_LED_off();
}
//**************************************************************************************************
//**************************************************************************************************
//**************************************************************************************************
static void ThiefAlert()
{
	LCD_clearScreen();
	LCD_displayString("Thief Alert !!");
	RED_LED_on();
	_delay_ms(5000);
	RED_LED_off();
	App_Welcome_screen();
}

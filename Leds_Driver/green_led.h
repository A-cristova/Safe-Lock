/******************************************************************************
 *
 * Module: GRN LED
 *
 * File Name: green_led.h
 *
 * Description: header file for the green led driver
 *
 * Author: Mohamed Ezzat &Editing BY :ABDELRAHMAN MAGDY
 *
 * Created on: April 24, 2023
 *
 * Version : v1.0.1
 *
 *******************************************************************************/
#ifndef GRN_LED_H
#define GRN_LED_H

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define GRN_LED_PIN  PIN_1
#define GRN_LED_PORT PORT_C

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * A function to initialize the GRN_LED
 */
void GRN_LED_init(void);

/*
 * Description :
 * A function to turn on the GRN_LED
 */
void GRN_LED_on(void);

/*
 * Description :
 * A function to turn off the GRN_LED
 */
void GRN_LED_off(void);

#endif /* RED_LED_H */

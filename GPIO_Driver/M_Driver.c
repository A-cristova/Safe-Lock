/*
 *  File Name : main_Driver.c
 *  GPIO DRIVER
 *  Created on: Aug 31, 2023
 *  Author: ABDELRAHMAN MAGDY
 */
#include<avr/io.h>
#include <GPIO_Enums_func.h>
#include "Typedef.h"
//#include "DIO_func.h"
#include "common_macros.h"

void GPIO_setpindirection ( DIO_port_name port, DIO_pin_name pin, DIO_pin_direction direction) //function to Set The Direction to pin
{
	switch(port)
	{
	      case PORT_A : if(direction==INPUT)
	                    {
		                      CLEAR_BIT(DDRA,pin);
	                    }
	                    else if(direction==OUTPUT)
	                    {
	    	                  SET_BIT(DDRA,pin);
	                    }
	      break;
	      case PORT_B : if(direction==INPUT)
	                    {
		                      CLEAR_BIT(DDRB,pin);
	                    }
	                    else if(direction==OUTPUT)
	                    {
	    	                  SET_BIT(DDRB,pin);
	                    }
	      break;
	      case PORT_C : if(direction==INPUT)
	                    {
		                      CLEAR_BIT(DDRC,pin);
	                    }
	                    else if(direction==OUTPUT)
	                    {
	    	                  SET_BIT(DDRC,pin);
	                    }
	      break;
	      case PORT_D : if(direction==INPUT)
	                    {
		                      CLEAR_BIT(DDRD,pin);
	                    }
	                    else if(direction==OUTPUT)
	                    {
	    	                  SET_BIT(DDRD,pin);
	                    }
	      break;
	      default :
	      break;
	}
}

void GPIO_writepin (DIO_port_name port, DIO_pin_name pin, DIO_pin_output_value value) //function to write the output value to pin
{
    switch(port)
    {
          case PORT_A : if(value==LOW)
                        {
	                          CLEAR_BIT(PORTA,pin);
                        }
                        else if(value==HIGH)
                        {
  	                          SET_BIT(PORTA,pin);
                        }
          break;
          case PORT_B : if(value==LOW)
                        {
	                          CLEAR_BIT(PORTB,pin);
                        }
                        else if(value==HIGH)
                        {
  	                          SET_BIT(PORTB,pin);
                        }
          break;
          case PORT_C : if(value==LOW)
                        {
	                          CLEAR_BIT(PORTC,pin);
                        }
                        else if(value==HIGH)
                        {
  	                          SET_BIT(PORTC,pin);
                        }
          break;
          case PORT_D : if(value==LOW)
                        {
	                          CLEAR_BIT(PORTD,pin);
                        }
                        else if(value==HIGH)
                        {
  	                          SET_BIT(PORTD,pin);
                        }
          break;
          default :
          break;
    }
}

uint_8 GPIO_readpin (DIO_port_name port, DIO_pin_name pin)  //function to Read the input value to pin
{
	uint_8 localreading =0x00;
	switch(port)
	{
	      case PORT_A :
	    	            localreading = GET_BIT(PINA,pin);
	      break;
	      case PORT_B :
	    	            localreading = GET_BIT(PINB,pin);
	      break;
	      case PORT_C :
	    	            localreading = GET_BIT(PINC,pin);
	      break;
	      case PORT_D :
	    	            localreading = GET_BIT(PIND,pin);
	      break;
          default :
          break;
	}
	return localreading;
}

void GPIO_setportdirection ( DIO_port_name port, uint_8 direction) //function to Set The Direction to port
{
	switch(port)
	{
	      case PORT_A : if (direction==INPUT_PORT)
	                    {
	    	                  DDRA=0x00;
	                    }
	                    else if (direction==OUTPUT_PORT)
	                    {
	    	                  DDRA=0xFF;
	                    }
	      break;
	      case PORT_B : if (direction==INPUT_PORT)
	                    {
	    	                  DDRB=0x00;
	                    }
	                    else if (direction==OUTPUT_PORT)
	                    {
	    	                  DDRB=0xFF;
	                    }
	      break;
	      case PORT_C : if (direction==INPUT_PORT)
	                    {
	    	                  DDRC=0x00;
	                    }
	                    else if (direction==OUTPUT_PORT)
	                    {
	    	                  DDRC=0xFF;
	                    }
	      break;
	      case PORT_D : if (direction==INPUT_PORT)
	                    {
	    	                  DDRD=0x00;
	                    }
	                    else if (direction==OUTPUT_PORT)
	                    {
	    	                  DDRD=0xFF;
	                    }
	      break;
	      default :
	      break;
	}
}

void GPIO_writeport (DIO_port_name port, DIO_port_output_value value) //function to write the output value to port
{
    switch(port)
    {
          case PORT_A : if(value==LOW_PORT)
                        {
        	                  PORTA =0x00;
                        }
                        else if(value ==HIGH_PORT)
                        {
        	                  PORTA =0xFF;
                        }
          break;
          case PORT_B : if(value==LOW_PORT)
                        {
        	                  PORTB =0x00;
                        }
                        else if(value ==HIGH_PORT)
                        {
        	                  PORTB =0xFF;
                        }
          break;
          case PORT_C : if(value==LOW_PORT)
                        {
        	                  PORTC =0x00;
                        }
                        else if(value ==HIGH_PORT)
                        {
        	                  PORTC =0xFF;
                        }
          break;
          case PORT_D : if(value==LOW_PORT)
                        {
        	                  PORTD =0x00;
                        }
                        else if(value ==HIGH_PORT)
                        {
        	                  PORTD =0xFF;
                        }
          break;
          default :
          break;
    }
}

uint_8 GPIO_readport (DIO_port_name port) //function to Read the input value to port
{
	uint_8 localreading=0x00;
	switch(port)
	{
	      case PORT_A :
	    	            localreading =PINA;
	      break;
	      case PORT_B :
	    	            localreading =PINB;
	      break;
	      case PORT_C :
	    	            localreading =PINC;
	      break;
	      case PORT_D :
	    	            localreading =PIND;
	      break;
	      default :
	      break;
	}
	return localreading ;
}

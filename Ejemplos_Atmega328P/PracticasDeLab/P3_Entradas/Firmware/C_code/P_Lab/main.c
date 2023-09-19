/*************************************************************************
 *   Copyright (C) 2022 by Jesús Daniel                                  *
 *   jesus.garzacmn@uanl.edu.mx                                          *
 *   Attribution-NonCommercial-ShareAlike 3.0 (CC-BY-NC-SA 3.0)           *
 *   https://creativecommons.org/licenses/by-nc-sa/3.0/                  *
 *                                                                       * 
 *   Example 1 - Lab Practice #3 - Microcontrollers Lab                   *
 *   Device: Arduino Nano ATmega328P                                    *
 *   Language: C                                                        *
 *   Revision: 1.0                                                       *
 *                                                                       *
 *   Date: 05/09/22                                                      *
 ************************************************************************/

// ------- Preamble -------- //

//-- Libraries
#include <avr/io.h> // Include AVR I/O libraries
#define F_CPU 16000000UL // 16 MHz internal crystal speed
#include <util/delay.h> /* Functions for time delays */

//-- Constants

//-- Labels
//- Inputs
#define SWITCHES PIND
#define SW0 PIND2
#define SW1 PIND3
#define SW2 PIND4
#define SW3 PIND5

//- Outputs
#define LEDS PORTB
#define LED0 PORTB2
#define LED1 PORTB3
#define LED2 PORTB4
#define LED3 PORTB5

//-- Global Variables

//-- Functions()
//-- Function Declarations()
void initPorts(void); // Function to initialize ports

// ------- MAIN -------- //
int main(void)
{
// -------- Inits --------- //	
	//-- Initialization of functions()
	initPorts(); // Goes to initialization above
	
	//-- Local program variables
	
// ------ Event loop ------ //
    while (1) 
		{
		//- Read a single pull up input
		//- Bitwise AND (&)
		//- 0bXXXXXXXX & 0b00000100
		//- Logic not (!)
			if (!(SWITCHES & 0b00000100))
			{  //OR mask to set a bit
				LEDS |=  (1<<LED0); // Turn on the LED
			} 
			else
			{  //AND mask to clear a bit
				LEDS &= ~(1<<LED0); // Turn off the LED
			}
		//- Read a single pull down input
		//- Bitwise AND (&)
			if (SWITCHES & (1<<SW2))
			{  //OR mask to set a bit
				LEDS |=  (1<<LED0); // Turn on the LED
			}
			else
			{  //AND mask to clear a bit
				LEDS &= ~(1<<LED0); // Turn off the LED
			}
			//- Read two or more pull-up input
			//- Logical AND
			//- SW0 && SW1
			if ((!(SWITCHES & _BV(SW0))) && (!(SWITCHES & _BV(SW1))))
			{
				LEDS |=  _BV(LED1); // AND
				LEDS &= ~_BV(LED2); // NAND
			}
			else
			{
				LEDS &= ~_BV(LED1); // AND
				LEDS |=  _BV(LED2); // NAND
			}
		
    } // END infinite loop
	
}// END MAIN

//**********************************************************************
// Function Definitions
//**********************************************************************

//**********************************************************************
// initializePorts: Initialize input and output ports
//**********************************************************************
void initPorts(void)
{
	//-- Inputs
	DDRD  &= ~(_BV(SW0) | _BV(SW1) | _BV(SW2) | _BV(SW3));
	//- Pull-up enabled
	PORTD |=  (_BV(SW0) | _BV(SW1));
	//- Pull-up disabled
	PORTD &= ~(_BV(SW2) | _BV(SW3));	
	//-- Outputs
	DDRB  |=  (_BV(LED0) | _BV(LED1) | _BV(LED2) | _BV(LED3));
	//- Turn off
	PORTB &= ~(_BV(LED0) | _BV(LED1) | _BV(LED2) | _BV(LED3));
}//end_initPorts

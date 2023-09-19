/*************************************************************************
 *   Copyright (C) 2022 by Jesús Camarena                                *
 *   jesus.garzacmn@uanl.edu.mx                                          *
 *   Attribution-NonCommercial-ShareAlike 3.0 (CC-BY-NC-SA 3.0)           *
 *   https://creativecommons.org/licenses/by-nc-sa/3.0/                  *
 *                                                                       * 
 *   Example 1 - Lab Practice #2 - Microcontrollers Lab                   *
 *   Device: ATmega328P                                                 *
 *   Language: C                                                        *
 *   Revision: 1.0                                                       *
 *                                                                       *
 *   Date: 03/08/22                                                      *
 ************************************************************************/

// ------- Preamble -------- //

// Libraries
#include <avr/io.h> // Include AVR I/O libraries
#define F_CPU 1000000UL // 1 MHz internal crystal speed for ATmega328P
//#define F_CPU 16000000UL // 16 MHz external crystal speed for Arduino Nano or Uno
#include <util/delay.h> // Include delay functions

// Constants
#define DELAY_LEDS 500 // Define a delay time of 500ms as a constant

// Pin Definitions
#define LED_BAR_DDR  DDRD // Direction register for LED bar
#define LED_BAR_PORT PORTD // Port register for LED bar

#define LEDS_DDR  DDRB // Direction register for individual LEDs
#define LEDS_PORT PORTB // Port register for individual LEDs

#define LED_0 PORTB0 // Individual LED 0
#define LED_1 PORTB1 // Individual LED 1
#define LED_2 PORTB2 // Individual LED 2
#define LED_3 PORTB3 // Individual LED 3
#define LED_4 PORTB4 // Individual LED 4

// Function Declarations
void initPorts(void);
void initLEDBar(void);

// ------- MAIN -------- //

int main(void)
{
    // Initialization
    initLEDBar();
    initPorts();

    // Event Loop
    while (1) 
    {
        // Example 1 - LED Bar
        LED_BAR_PORT = 0b11111111; // Turn on all LEDs in the bar
        _delay_ms(1000);     // Delay
        LED_BAR_PORT = 0b00000000; // Turn off all LEDs in the bar
        _delay_ms(1000);     // Delay

        // Example 2 - Individual LEDs
        LEDS_PORT = 0b00000001; // Only turn on LED 0
        _delay_ms(DELAY_LEDS); // Delay
        LEDS_PORT = (1 << 1); // Only turn on LED 1
        _delay_ms(DELAY_LEDS); // Delay
        LEDS_PORT = (1 << LED_2); // Only turn on LED 2
        _delay_ms(DELAY_LEDS); // Delay
        LEDS_PORT = (1 << LED_3); // Only turn on LED 3
        _delay_ms(DELAY_LEDS); // Delay
        LEDS_PORT = (1 << LED_4); // Only turn on LED 4
        _delay_ms(DELAY_LEDS); // Delay
    }
}

// Function Definitions
//***********************************************************************
//* Name:  initPorts
//* Description: Function to initialize ports
//* Declaration: void initPorts(void)
//* Call: initPorts();
//* Return: void
//* Arguments: void
//***********************************************************************

void initPorts(void)
{
    // Set individual LED pins as outputs
				//76543210
    LEDS_DDR  = 0b00011111; // Bit 4..0 are Outputs
    // Initialize individual LED ports to low (off) state
    LEDS_PORT = 0b00000000; // Initial value
}//end_initPorts

void initLEDBar(void)
{
    // Set LED bar pins as outputs
	//-- LED Bar    //76543210
	 LED_BAR_DDR =  0b11111111; // All bits are outputs
    // Initialize LED bar to low (off) state
     LED_BAR_PORT = 0b00000000;
}

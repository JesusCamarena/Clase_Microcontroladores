//" �No copies y pegues el c�digo, anal�zalo e inspirate en el! "
/*************************************************************************
 *   Copyright (C) 2022 by JesusCamarena                                *
 *   jesus.garzacmn@uanl.edu.mx                                          *
 *   Attribution-NonCommercial-ShareAlike 3.0(CC-BY-NC-SA 3.0)           *
 *   https://creativecommons.org/licenses/by-nc-sa/3.0/                  *
 *                                                                       * 
 *   Nombre:                                                             *
 *   Dispositivo:                                                        *
 *   Lenguaje: C                                                         *
 *   Rev: 1.0                                                            *
 *                                                                       *
 *                                                     Fecha: 02/03/23   *
 ************************************************************************/
// ------- Preamble -------- //
//-- Bibliotecas
#include <avr/io.h> //se incluyen las bibioletcas de E/S del AVR
#define F_CPU 16000000UL //16 Mhz velocidad del cristal externo
#include <util/delay.h> /* Funciones para retardos de tiempo */

//--Etiquetas
//-Inputs
#define BTN_DDRX  DDRD
#define BTN_PORTX PORTD
#define BTN_PINX  PIND
#define BTN_0     PORTD4
#define BTN_1     PORTD3

//-Outputs
#define LED_DDRX  DDRB
#define LED_PORTX PORTB
#define LED_PINX  PINB
#define LED_0     PORTB4
#define LED_1     PORTB3


//-- Funciones()
//-- Prototipos de Funciones()
void ports_init(void);

// ------- MAIN -------- //
int main(void)
{
// -------- Inits --------- //	
    ports_init();//llama a la funcion
	
// ------ Event loop ------ //
    while (1) 
    {
	//0b00000001 = 0b00000001
//0bXXXXXXXX & 0b00000001 = 0b0000000X
//0bXXXXXXX0 & 0b00000001 = 0b00000000
//0bXXXXXXX1 & 0b00000001 = 0b00000001
		if(BTN_PINX & 0b00010000)
		{
			LED_PORTX |= 0b00010000;//Enciendo LED_0
		}
		else
		{
			LED_PORTX &= ~(1<<LED_0);//Apago LED_0
		}
		if(BTN_PINX & (1<<BTN_1))//BTN_1 es uno
		{
			LED_PORTX |= (1<<LED_1);
		}
		else
		{
			LED_PORTX &= ~(1<<LED_1);
		}
    }//Fin_while
}//Fin_main

void ports_init(void)
{
//--Definir Entradas y Salidas
//-Inputs
	BTN_DDRX &= ~(1<<BTN_0);// solo PORTD4 es una entrada
	BTN_DDRX &= ~(1<<BTN_1);// solo PORTD4 es una entrada
	
//-Outputs
	LED_DDRX |=  (1<<LED_0);// solo PORTB4 es una salida
	LED_DDRX |=  (1<<LED_1);// solo PORTB4 es una salida
	
//--Init Entradas y Salidas
//-Inputs
	BTN_PORTX &= ~(1<<BTN_0);//Pull-down
	BTN_PORTX &= ~(1<<BTN_1);//Pull-down

//-Outputs
	LED_PORTX &= ~(1<<LED_0);//Output Low (Sink)
	LED_PORTX &= ~(1<<LED_1);//Output Low (Sink)
}
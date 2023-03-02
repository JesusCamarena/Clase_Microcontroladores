//" ¡No copies y pegues el código, analízalo e inspirate en el! "
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

//--Macros
//-Inputs
//BTN_0
#define BTN_0_PRESS BTN_PINX & (1<<BTN_0)

//BTN_1
#define BTN_1_PRESS BTN_PINX & (1<<BTN_1)


//-Outputs
//LED_0
#define LED_0_ON  LED_PORTX |=  (1<<LED_0)
#define LED_0_OFF LED_PORTX &= ~(1<<LED_0)
//LED_1
#define LED_1_ON  LED_PORTX |=  (1<<LED_1)
#define LED_1_OFF LED_PORTX &= ~(1<<LED_1)

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
	   //0bXXXXXXXX	& 0b00001000
	   //0b0000X000	& 0b00001000
	   //0b00000000	& 0b00001000 = 0
	  //0b00000100	& 0b00001000 = 1
		if(!(BTN_0_PRESS)&&!(BTN_1_PRESS))
		{
			LED_0_ON;
			LED_1_ON;
		}
			else if (!(BTN_0_PRESS)&&(BTN_1_PRESS))
			{
				LED_0_ON;
				LED_1_OFF;
			}
				else if ((BTN_0_PRESS)&&!(BTN_1_PRESS))
				{
					LED_0_OFF;
					LED_1_ON;
				}
					else
					{
						LED_0_OFF;
						LED_1_OFF;
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
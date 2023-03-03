//" ¡No copies y pegues el código, analízalo e inspirate en el! "
/*************************************************************************
 *   Copyright (C) 2022 by JesusCamarena                                 *
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
 //0b00000100 = 0b00000100
		PORTB = PIND;
    }
}

void ports_init(void)
{
//--Definir Entradas y Salidas
//-Inputs (colocar 0)
	DDRD  = DDRD & ~(1<<PORTD4);// solo PORTD4 es una entrada
	DDRD &= ~(1<<PORTD3);// solo PORTD3 es una entrada
	
//-Outputs (colocar 1)
	DDRB  = DDRB |  (1<<PORTB4);// solo PORTB4 es una salida
	DDRB |=  (1<<PORTB3);// solo PORTB4 es una salida
	
//--Init Entradas y Salidas
//-Inputs
	PORTD &= ~(1<<PORTD4);//Pull-down
	PORTD |=  (1<<PORTD3);//Pull-up

//-Outputs
	PORTB &= ~(1<<PORTB4);//Output Low (Sink)
	PORTB &= ~(1<<PORTB3);//Output Low (Sink)
}
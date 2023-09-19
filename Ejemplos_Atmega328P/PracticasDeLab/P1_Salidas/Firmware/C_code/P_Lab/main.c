//" ¡No copies y pegues el código, analízalo e inspirate en el! "

/*************************************************************************
 *   Copyright (C) 2022 by Jesús Daniel                                  *
 *   jesus.garzacmn@uanl.edu.mx                                          *
 *   Attribution-NonCommercial-ShareAlike 3.0(CC-BY-NC-SA 3.0)           *
 *   https://creativecommons.org/licenses/by-nc-sa/3.0/                  *
 *                                                                       * 
 *   Ejemplo práctica N° 1 - Lab. Microcontroladores                     *
 *   Dispositivo: atmega328p                                             *
 *   Lenguaje C                                                          *
 *   Rev: 1.0                                                            *
 *   Licencia:                                                           *
 *                                                     Fecha: 22/07/22   *
 ************************************************************************/

//comentario corto
/*comentario largo
 */
//Bibliotecas
#include <avr/io.h> //bibliotecas internas del atmega328p
#define F_CPU 1000000UL //1 Mhz velocidad del cristal interno

/*16 Mhz velocidad del cristal externo para el arduino nano o uno*/
//#define F_CPU 16000000UL

//Se ejecuta una vez
int main(void)
{
	//DDRX son de entrada o salida
	//-DDRD = 0b00000001;// dato en bin "PD0 es una salida"
	//-DDRD = 1;         // dato en dec "PD0 es una salida"
	//-DDRD = 0x01;      // dato en hex "PD0 es una salida"
	
	        //76543210
	DDRD  = 0b11111111; // Todo el PORTD  es salida
	DDRC  = 0b00000001; // Solo el PORTC0 es una salida

	//PORTX estan en alto o en bajo
	PORTD = 0b00000100;// dato en bin "PD2" esta en alto en modo source
	PORTC = 0x00;      // dato en hex "PC0" esta en alto en modo sink"

	//Se ejecuta infinitamente
	while (1) // for(;;) bucle infinito
	{

	} //Fin bucle while
} //Fin main
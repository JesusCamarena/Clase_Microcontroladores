/*
 * Ej2HolaMundo.c
 *
 * Created: 09/02/2023 10:52:05 a. m.
 * Author : jdgar
 */ 
//comentario corto
//atmega328p
/*
	Comentario largo
*/
//--Bibliotecas
#include <avr/io.h> //I/O del AVR



int main(void)//setup 
{           //76543210
	DDRB  = 0b00100000; //Declara como salida
	PORTB = 0x00;// Enciende
	        //76543210
	DDRC  = 0b00000100;
	PORTC = 0x00;
	
    while (1) //bucle infinito (loop)
    {
		
    }
}


/*
 * Ej2HolaMundo.c
 *
 * Created: 09/02/2023 10:52:05 a. m.
 * Author : jdgar
 */ 

//comentario corto
//atmega328p
/*
	Comentario largooooooo
*/

//--Bibliotecas
#include <avr/io.h> //I/O del AVR

//-----------------Main---------------------//
int main(void)//se ejecuta una vez (setup)
{           
//DDRX =  Registro de 8 bits donde se declara si es una entrada o salida
//0b =  dato en binario
			//76543210 numero de los bits del registro
	DDRB  = 0b00100000; //PORTB5 se declara como salida
	
//PORTX =  Registro de 8 bits donde se declara si esta encendido o apagado
//0b =  dato en binario
	PORTB = 0b00100000; //PORTB5 se enciende
	
            //76543210
	DDRC  = 0b00000100; //PORTC2 se declara como salida
	PORTC = 0b00000100; //PORTC2 se enciende
//-----------------while---------------------//	
    while (1) //bucle infinito (loop)
    {
		
    }//Fin_while
}//Fin_main


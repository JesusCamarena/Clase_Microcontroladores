//" ¡No copies y pegues el código, analízalo e inspirate en el! "

/*************************************************************************
 *   Copyright (C) 2022 by Jesús Daniel                                  *
 *   jesus.garzacmn@uanl.edu.mx                                          *
 *   Attribution-NonCommercial-ShareAlike 3.0(CC-BY-NC-SA 3.0)           *
 *   https://creativecommons.org/licenses/by-nc-sa/3.0/                  *
 *                                                                       * 
 *   Ejemplo práctica N° 0 - Lab. Microcontroladores                     *
 *   Dispositivo: atmega328p                                             *
 *   Lenguaje C                                                          *
 *   Rev: 1.0                                                            *
 *   Licencia:                                                           *
 *                                                     Fecha: 22/07/22   *
 ************************************************************************/

//comentario corto
/*comentario largoooooo

 */
//atmega328p

//--Bibliotecas
#include <avr/io.h> //I/O del AVR
#define F_CPU 1000000UL //1 Mhz velocidad del cristal interno

//-----------------Main---------------------//
int main(void)//se ejecuta una vez (setup)
{           
//DDRX =  Registro interno de 8 bits donde se declara si es una entrada o salida
//0b =  dato en binario
	        //76543210 numero de los bits del registro
	DDRB  = 0b00100000; //PORTB5 se declara como salida
	
//PORTX =  Registro de interno 8 bits donde se declara si está encendido o apagado
//0b =  dato en binario
	        //76543210 numero de los bits del registro
	PORTB = 0b00100000; //PORTB5 se enciende
	
//-----------------while---------------------//	
    while (1) //bucle infinito (loop)
    {
		  //do nothing()
    }//Fin_while	
}//Fin_main
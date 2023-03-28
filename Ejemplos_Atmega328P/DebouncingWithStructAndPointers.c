#include <avr/io.h>
#define F_CPU 1000000UL

#define SWITCH PIND
#define SW_0 PIND0
#define SW_1 PIND1

#define LEDS PORTB
#define LED0 PORTB0

void init_ports(void);

typedef struct Boton Boton;

struct Boton
{
	volatile uint8_t * puerto;
	int pin;
	int estadoAnterior;
	int estadoActual;
	
};

int debounce(Boton *btn);

int main(void)
{
	init_ports();
	
	int counter1 = 0;
	int counter2 = 0;
	
	Boton btn1;
	btn1.puerto	= &SWITCH;
	btn1.pin	= SW_0;


	Boton btn2;
	btn2.puerto	= &SWITCH;
	btn2.pin	= SW_1;
	
	while (1)
	{
		if ( debounce(&btn1) )
		{
			counter1++;
		}


		if ( debounce(&btn2) )
		{
			counter2++;
		}		
		
		if ( counter1 == 2 && counter2 == 2 )
		{
			LEDS |=  ( _BV(LED0) );
		}

	}
}

void init_ports(void)
{

	DDRD   &= ~( _BV(SW_0) );
	PORTD |=   ( _BV(SW_0) );
	
	DDRB |=  ( _BV(LED0) );
	LEDS &= ~( _BV(LED0) );

}


int debounce(Boton *btn)
{
	(*btn).estadoAnterior = (*btn).estadoActual;
	
	if ( (*btn).puerto == &PIND ) (*btn).estadoActual = bit_is_clear(PIND, (*btn).pin);
		else if ( (*btn).puerto == &PINB ) (*btn).estadoActual = bit_is_clear(PINB, (*btn).pin);
			else if ( (*btn).puerto == &PINC ) (*btn).estadoActual = bit_is_clear(PINC, (*btn).pin);
	

	if ( (*btn).estadoAnterior == 0 && (*btn).estadoActual == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

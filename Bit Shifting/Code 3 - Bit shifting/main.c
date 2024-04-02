/*
 * code 2 Digital IO.c
 *
 * Created: 4/2/2024 4:34:19 PM
 * Author : kosala
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define Button_1 PD1
#define Button_2 PD2

volatile uint8_t continuous_mode_active = 0;

void Continuous_mode()
{
	continuous_mode_active = 1; 

	while (!(PINB & (1 << 7)))
	{
		PORTB = PORTB * 2;
		_delay_ms(500);

		if (PINB & (1 << 7))
		{
			PORTB = 0x01;
			_delay_ms(500);
		}

		if (!(PIND & (1 << Button_2)))
		{
			continuous_mode_active = 0; 
			PORTB = 0x00; 
			return;
		}
	}

	continuous_mode_active = 0; 
}

int main(void)
{
	DDRB = 0xFF;
	PORTD |= (1 << Button_1) | (1 << Button_2);

	while (1)
	{
		if (!(PIND & (1 << Button_1)))
		{
			PORTB |= (1 << 0);
			_delay_ms(500);
			Continuous_mode();
		}

		if (!(PIND & (1 << Button_2)))
		{
			PORTB = 0x00; 
		}
	}
}

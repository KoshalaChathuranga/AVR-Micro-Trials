/*
 * code 2 Digital IO.c
 *
 * Created: 4/2/2024 4:34:19 PM
 * Author : kosala
 */ 

#include <avr/io.h> 

int main(void)
{
	DDRB = 0x01; // Set PB0 as output
	PORTB = 0x02; // Set initial state of PB1 (enable the internal pull-up resistor)
	
	while (1) // Infinite loop
	{
		if (!(PINB & 0x02)) // Check if PB1 (button) is pressed
		{
			PORTB |= 0x01; // Turn on PB0 (LED) if button is pressed
		}
		else
		{
			PORTB &= 0xFE; // Turn off PB0 (LED) if button is not pressed
		}
	}
}

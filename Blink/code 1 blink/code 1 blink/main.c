/*
 * code 1 blink.c
 *
 * Created: 4/2/2024 3:02:48 PM
 * Author : kosala
 */ 

#define F_CPU 1000000UL 

#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	DDRB = 0xff; // Set PORTB as output
	
    while (1) 
    {
			PORTB= 0x00; // Set PORTB output to sink (low)
			_delay_ms(500); // delay of 500 ms
			PORTB= 0xff; // Set PORTB output to source (high)
			_delay_ms(500);
    }
}
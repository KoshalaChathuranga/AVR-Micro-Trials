#define F_CPU 16000000L  // Adjust the clock frequency for Arduino Uno

#include <avr/io.h>
#include <util/delay.h>  // Correct library name for delay functions

int main(void)
{
  DDRB |= (1 << DDB5);  // Set pin 13 (PB5) as output
  PORTB &= ~(1 << PORTB5);  // Set pin 13 low initially

  while(1){
    PORTB |= (1 << PORTB5);  // Set pin 13 high
    _delay_ms(1000);
    PORTB &= ~(1 << PORTB5);  // Set pin 13 low
    _delay_ms(200);
  }
  return 0;
}

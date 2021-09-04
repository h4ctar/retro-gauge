#include <avr/io.h>     // This contains the definitions of the terms used
#include <util/delay.h> // This contains the definition of delay function

void main()
{
    DDRD = 0b00000100;  // Port D2 (Pin 4 in the ATmega) made output
    PORTD = 0b00000000; // Turn LED off

    while (1)
    {
        PORTD = 0b00000100; //Turn LED on
        _delay_ms(1000);    // delay of 200 millisecond
        PORTD = 0b00000000; //Turn LED off
        _delay_ms(1000);    // delay of 200 millisecond
    }
}

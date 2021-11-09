#define __AVR_ATmega328P__

#include <avr/io.h>
#include <util/delay.h>

#define MOT_PORT PORTD
#define MOT_PORT_DDR DDRD

#define MOT_PIN_1 0b00000001
#define MOT_PIN_2 0b00000010
#define MOT_PIN_3 0b00000100
#define MOT_PIN_4 0b00001000

#define MOT_PATTERN_1 0b00000111
#define MOT_PATTERN_2 0b00011100
#define MOT_PATTERN_3 0b00011100
#define MOT_PATTERN_4 0b00110001

#define DELAY 1

void stepMotor(unsigned char bit)
{
    if ((MOT_PATTERN_1 >> bit) & 1)
        MOT_PORT |= MOT_PIN_1;
    else
        MOT_PORT &= ~MOT_PIN_1;

    if ((MOT_PATTERN_2 >> bit) & 1)
        MOT_PORT |= MOT_PIN_2;
    else
        MOT_PORT &= ~MOT_PIN_2;

    if ((MOT_PATTERN_3 >> bit) & 1)
        MOT_PORT |= MOT_PIN_3;
    else
        MOT_PORT &= ~MOT_PIN_3;

    if ((MOT_PATTERN_4 >> bit) & 1)
        MOT_PORT |= MOT_PIN_4;
    else
        MOT_PORT &= ~MOT_PIN_4;
}

void main()
{
    MOT_PORT_DDR |= MOT_PIN_1;
    MOT_PORT_DDR |= MOT_PIN_2;
    MOT_PORT_DDR |= MOT_PIN_3;
    MOT_PORT_DDR |= MOT_PIN_4;

    while (1)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int i = 0; i < 6; i++)
            {
                stepMotor(i);
                _delay_ms(DELAY);
            }
        }

        for (int j = 0; j < 100; j++)
        {
            for (int i = 5; i >= 0; i--)
            {
                stepMotor(i);
                _delay_ms(DELAY);
            }
        }
    }
}

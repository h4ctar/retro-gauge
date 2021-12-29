#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

int main() {
    Lcd lcd = { &PORTB, &DDRB, 0b00100000, 0b00010000, 0b00001000 };
    initLcd(&lcd);

    int count = 0;
    while (1) {
        // writeString(&lcd, " Hello  ");
        writeInteger(&lcd, count++);
        _delay_us(100000);
    }

    return 0;
}


#include "analog.h"

#include <avr/io.h>
#include <stdint.h>

void initAnalog() {
    // Select Vref=AVcc
    ADMUX |= (1 << REFS0);

    // Set prescaller to 128 and enable ADC  
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
}

uint32_t readAnalog(uint8_t channel) {
    // Select ADC channel with safety mask
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); 

    // Single conversion mode
    ADCSRA |= (1 << ADSC);

    // Wait until ADC conversion is complete
    while (ADCSRA & (1 << ADSC));

    return ADC;
}


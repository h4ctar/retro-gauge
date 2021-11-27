#include <avr/io.h>
#include <util/delay.h>
#include <util/atomic.h>

#include "neopixel.h"

/*
 This is an example of how simple driving a Neopixel can be
 This code is optimized for understandability and changability rather than raw speed
 More info at http://wp.josh.com/2014/05/11/ws2812-neopixels-made-easy/
 https://wp.josh.com/2014/05/13/ws2812-neopixels-are-not-so-finicky-once-you-get-to-know-them/
*/

#define PIXEL_PORT PORTD // Port of the pin the pixels are connected to
#define PIXEL_DDR DDRD   // Port of the pin the pixels are connected to
#define PIXEL_BIT 0      // Bit of the pin the pixels are connected to

// These are the timing constraints taken mostly from the WS2812 datasheets
// These are chosen to be conservative and avoid problems rather than for maximum throughput

#define T1H 900 // Width of a 1 bit in ns
#define T1L 600 // Width of a 1 bit in ns

#define T0H 400 // Width of a 0 bit in ns
#define T0L 900 // Width of a 0 bit in ns

// Older pixels would reliabily reset with a 6us delay, but some newer (>2019) ones
// need 250us. This is set to the longer delay here to make sure things work, but if
// you want to get maximum refresh speed, you can try decreasing this until your pixels
// start to flicker.

#define RES 250000 // Width of the low gap between bits to cause a frame to latch

// Here are some convience defines for using nanoseconds specs to generate actual CPU delays

#define NS_PER_SEC (1000000000L) // Note that this has to be SIGNED since we want to be able to check for negative values of derivatives

#define CYCLES_PER_SEC (F_CPU)

#define NS_PER_CYCLE (NS_PER_SEC / CYCLES_PER_SEC)

#define NS_TO_CYCLES(n) ((n) / NS_PER_CYCLE)

void sendByte(unsigned char byte);
void sendBit(unsigned char bit);

void pixelSetup()
{
    // Make the pixel pin an output
    PIXEL_DDR |= 1 << PIXEL_BIT;
}

void sendPixels(long pixels[], int size)
{
    // Disable interrupts
    cli();

    for (int i = 0; i < size; i++)
    {
        // Neopixel wants colors in green then red then blue order
        sendByte(pixels[i] >> 8 & 0xFF);
        sendByte(pixels[i] >> 16 & 0xFF);
        sendByte(pixels[i] & 0xFF);
    }

    // Show
    _delay_us((RES / 1000UL) + 1);

    // Enable interrupts
    sei();
}

inline void sendByte(unsigned char byte)
{
    for (int i = 7; i >= 0; i--)
    {
        sendBit(byte & (1 << i));
    }
}

inline void sendBit(unsigned char bitVal)
{
    if (bitVal)
    { // 0 bit

        asm volatile(
            "sbi %[port], %[bit] \n\t" // Set the output bit
            ".rept %[onCycles] \n\t"   // Execute NOPs to delay exactly the specified number of cycles
            "nop \n\t"
            ".endr \n\t"
            "cbi %[port], %[bit] \n\t" // Clear the output bit
            ".rept %[offCycles] \n\t"  // Execute NOPs to delay exactly the specified number of cycles
            "nop \n\t"
            ".endr \n\t" ::
                [port] "I"(_SFR_IO_ADDR(PIXEL_PORT)),
            [bit] "I"(PIXEL_BIT),
            [onCycles] "I"(NS_TO_CYCLES(T1H) - 2), // 1-bit width less overhead  for the actual bit setting, note that this delay could be longer and everything would still work
            [offCycles] "I"(NS_TO_CYCLES(T1L) - 2) // Minimum interbit delay. Note that we probably don't need this at all since the loop overhead will be enough, but here for correctness

        );
    }
    else
    { // 1 bit

        // **************************************************************************
        // This line is really the only tight goldilocks timing in the whole program!
        // **************************************************************************

        asm volatile(
            "sbi %[port], %[bit] \n\t" // Set the output bit
            ".rept %[onCycles] \n\t"   // Now timing actually matters. The 0-bit must be long enough to be detected but not too long or it will be a 1-bit
            "nop \n\t"                 // Execute NOPs to delay exactly the specified number of cycles
            ".endr \n\t"
            "cbi %[port], %[bit] \n\t" // Clear the output bit
            ".rept %[offCycles] \n\t"  // Execute NOPs to delay exactly the specified number of cycles
            "nop \n\t"
            ".endr \n\t" ::
                [port] "I"(_SFR_IO_ADDR(PIXEL_PORT)),
            [bit] "I"(PIXEL_BIT),
            [onCycles] "I"(NS_TO_CYCLES(T0H) - 2),
            [offCycles] "I"(NS_TO_CYCLES(T0L) - 2)

        );
    }

    // Note that the inter-bit gap can be as long as you want as long as it doesn't exceed the 5us reset timeout (which is A long time)
    // Here I have been generous and not tried to squeeze the gap tight but instead erred on the side of lots of extra time.
    // This has thenice side effect of avoid glitches on very long strings becuase
}

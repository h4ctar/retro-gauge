#define __AVR_ATmega328P__

#include <avr/io.h>
#include <util/delay.h>

#define LCD_PORT PORTB
#define LCD_PORT_DDR DDRB
#define CS_PIN 0b00001000
#define WR_PIN 0b00010000
#define DATA_PIN 0b00100000

#define T_CLK 5 // the clock time in micro seconds

// Modes
#define COMMAND_MODE 0b0100 // 1 0 0
#define DATA_MODE 0b0101    // 1 0 1

// Commands
#define BIAS 0b00101001 // 0010-10X1-X - 1/3 BIAS, 4 commons \
                        //  101001
#define SYS_DIS 0b00000000
#define RC_256K 0b00011000 // 0001-10XX-X - System clock source, on-chip RC oscillator
#define WDT_DIS 0b00000101 // 0000-0101-X - Disable WDT time-out flag output
#define WDT_EN 0b00000111
#define SYS_EN 0b000000001  // 0000-0001-X - Turn on system oscillator
#define LCD_ON 0b000000011  // 0000-0011-X - Turn on LCD bias generator
#define LCD_OFF 0b000000010 // 0000-0010-X - Turn off LCD bias generator

#define RCOSC 0b00011000

// The segments that are lit up for each character
// The bit to segment mapping is CA,F,E,D,I,J,K,L,A,B,C,DP,H,G,N,M
// unsigned short font[] = {
//     0b0111000011100000,
// };

// unsigned char addressMapping[8][4] = {
//     {5, 3, 9, 7},
//     {1, 0, 13, 11},
//     {0, 0, 17, 15},
//     {0, 0, 21, 19},
//     {0, 0, 25, 23},
//     {0, 0, 29, 27},
//     {0, 0, 31, 29},
//     {0, 0, 0, 0},
// };

void writeCommand(unsigned char command);
void writeData(unsigned char address, unsigned char data);
void writeBits(unsigned char bits, unsigned char numberOfBits);
void writeBit(unsigned char bit);

void main()
{
    LCD_PORT_DDR |= CS_PIN;
    LCD_PORT_DDR |= WR_PIN;
    LCD_PORT_DDR |= DATA_PIN;

    writeCommand(SYS_EN);
    writeCommand(RCOSC);
    writeCommand(BIAS);
    writeCommand(LCD_ON);

    // Configure
    // writeCommand(BIAS);
    // writeCommand(RC_256K);
    // writeCommand(SYS_DIS);
    // writeCommand(WDT_DIS);
    // writeCommand(WDT_EN);
    // writeCommand(SYS_EN);
    // writeCommand(LCD_ON);

    // writeCommand(LCD_OFF);

    while (1)
    {
        for (unsigned char i = 0; i < 16; i++)
        {
            writeData(i, 0);
        }
        _delay_us(1000);
    }

    // for (unsigned char i = 0; i < 8; i++)
    // {
    //     for (unsigned char j = 0; j < 4; j++)
    //     {
    //         unsigned char address = addressMapping[i][j];
    //         unsigned char data = (0b0000111000000111 >> (j * 4)) & 0b1111;
    //         // 0b0000111000000111

    //         //0b0000000000001110
    //         writeData(address, data);
    //     }
    // }
}

void writeCommand(unsigned char command)
{
    LCD_PORT &= ~CS_PIN;
    writeBits(COMMAND_MODE, 3);
    writeBits(command, 8);
    writeBit(0);
    LCD_PORT |= CS_PIN;
}

void writeData(unsigned char address, unsigned char data)
{
    LCD_PORT &= ~CS_PIN;
    writeBits(DATA_MODE, 3);
    writeBits(address, 6);
    writeBits(data, 4);
    LCD_PORT |= CS_PIN;
}

void writeBits(unsigned char bits, unsigned char numberOfBits)
{
    for (int i = numberOfBits - 1; i >= 0; i--)
    {
        writeBit(bits & (1 << i));
    }
}

void writeBit(unsigned char bit)
{
    LCD_PORT &= ~WR_PIN;
    _delay_us(T_CLK);
    if (bit)
    {
        LCD_PORT |= DATA_PIN;
    }
    else
    {
        LCD_PORT &= ~DATA_PIN;
    }
    LCD_PORT |= WR_PIN;
    _delay_us(T_CLK);
}

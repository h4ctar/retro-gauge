OBJS=main.o motor.o neopixel.o
CFLAGS=-Wall -std=gnu99 -Os -mmcu=atmega328p -DF_CPU=16000000 -D__AVR_ATmega328P__
CC=avr-gcc

PROGRAMMER=usbtiny
MCU=atmega328p
LFUSE=0b11111111
HFUSE=0b11010110
EFUSE=0b11111101

main.hex: ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

clean:
	rm -f *.o *.hex

burn: main.hex
	avrdude -c ${PROGRAMMER} -p ${MCU} -Uflash:w:main.hex

fuses:
	avrdude –c ${PROGRAMMER} -p ${MCU} -v -U lfuse:w:${LFUSE}:m
	avrdude –c ${PROGRAMMER} -p ${MCU} -v -U hfuse:w:${HFUSE}:m
	avrdude –c ${PROGRAMMER} -p ${MCU} -v -U efuse:w:${EFUSE}:m

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<

OBJS=main.o timer.o analog.o led.o lcd.o motor.o speedo.o indicators.o battery.o twi.o rtc.o clock.o button.o eeprom.o

PROGRAMMER=usbtiny
ARCH=avr
MCU=atmega328p
LFUSE=0b11111111
HFUSE=0b11010110
EFUSE=0b11111101

CC=clang
CFLAGS=-Wall -Wno-unknown-attributes --target=${ARCH} -mmcu=${MCU} -O -isystem /usr/avr/include -DF_CPU=16000000 -D__AVR_ATmega328P__ -D__DELAY_BACKWARD_COMPATIBLE__

main.hex: ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

clean:
	rm -f *.o *.hex

burn: main.hex
	avrdude -c ${PROGRAMMER} -p ${MCU} -Uflash:w:main.hex

fuses:
	avrdude -c ${PROGRAMMER} -p ${MCU} -v -U lfuse:w:${LFUSE}:m
	avrdude -c ${PROGRAMMER} -p ${MCU} -v -U hfuse:w:${HFUSE}:m
	avrdude -c ${PROGRAMMER} -p ${MCU} -v -U efuse:w:${EFUSE}:m

.c.o:
	${CC} ${CFLAGS} ${INCLUDES}-c $<


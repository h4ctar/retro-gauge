# Motorcycle Tacho

## Introduction

This is an open source motorcycle tacho project with the following features:

- Analog tachometer
- Digital speedometer
- Odometer
- Trip meter
- Battery voltage
- Standard indicators (turn signals, oil pressure, neutral and high beam)
- Clock

It is housed in a classic round casing, with a retro looking 8 digit starburst LCD.

The toolchain is all open source; the PCB's are designed with KiCad and the case is designed in FreeCAD.

![Assembly](./images/assembly.jpg)

## System Design

The system design is simple, the only interesting decision is that the indicators all go via the microcontroller, this lets us do fun things with the indicators (test them when powered on or reuse the oil pressure indicator for other warnings).

![System Design](./images/system-design.png)

## Microcontroller

An ATmega328P-PU microcontroller will be used to process all the inputs, and drive the outputs.

Here are all the required inputs and outputs:

| Function        | Type           | Number of pins    |
| --------------- | -------------- | ----------------- |
| Tacho           | Digital input  | 1                 |
| Speedo          | Digital input  | 1                 |
| Oil pressure    | Digital input  | 1                 |
| Turn signals    | Digital input  | 1                 |
| Neutral         | Digital input  | 1                 |
| High beam       | Digital input  | 1                 |
| Mode button     | Digital input  | 1                 |
| Battery voltage | Analog input   | 1                 |
| Stepper motor   | Digital output | 4 (could be 3)    |
| RBG LEDs        | Digital output | 1                 |
| LCD             | Digital output | 3                 |
| ISP             | Digital IO     | 3 (can be shared) |
| Real time clock | Digital IO     | 2                 |

For a total of 18 digital IOs and one analog input, the ATmega328P-PU has more than enough at 23 programmable IO lines.

The ATmega328P-PU also has 1024 bytes of EEPROM which can be used to store the configuration, trip and odometer values.

An external 16 MHz crystal will be used to run the ATmega328P-PU at it's fastest clock speed.

The microcontroller will be programmed with an in-circuit serial programmer (ICSP).
A bootloader doesnt need to be burned when using ICSP.

The low byte fuses configure the clock:

| Bit | Name   | Description                                | Value |
| --- | ------ | ------------------------------------------ | ----- |
| 7   | CKDIV8 | When set, divides the clock speed by 8     | 1     |
| 6   | CKOUT  | When set, the clock pulse is output on PB0 | 1     |
| 5   | SUT1   | Sets start up delay time                   | 1     |
| 4   | SUT0   |                                            | 1     |
| 3   | CKSEL3 | Sets the clock source                      | 1     |
| 2   | CKSEL2 |                                            | 1     |
| 1   | CKSEL1 |                                            | 1     |
| 0   | CKSEL0 |                                            | 1     |

The high byte fuses:

| Bit | Name     | Description                               | Value |
| --- | -------- | ----------------------------------------- | ----- |
| 7   | RSTDISBL | External reset disable                    | 1     |
| 6   | DWEN     | Debug wire enable                         | 1     |
| 5   | SPIEN    | Enable serial programming                 | 0     |
| 4   | WDTON    | Watchdog timer always on                  | 1     |
| 3   | EESAVE   | Preserve EEPROM memory through chip erase | 0     |
| 2   | EBOOTSZ1 | Sets the bootloder size memory            | 1     |
| 1   | EBOOTSZ0 |                                           | 1     |
| 0   | BOOTRST  | Select the reset vector                   | 0     |

The extended fuses:

| Bit | Name      | Description                       | Value |
| --- | --------- | --------------------------------- | ----- |
| 7   |           | Not used                          | 1     |
| 6   |           |                                   | 1     |
| 5   |           |                                   | 1     |
| 4   |           |                                   | 1     |
| 3   |           |                                   | 1     |
| 2   | BODLEVEL2 | Sets the brown-out detector level | 1     |
| 1   | BODLEVEL1 |                                   | 0     |
| 0   | BODLEVEL0 |                                   | 1     |

There is a simple Makefile that compiles and links the code and has targets to burn the fuses and the code.

## Power Supply

A linear voltage regulator will be used to convert the bikes rough 14V down to a smooth 5V for the rest of the system.
A smoothing capacitor is added on the bikes side to help smooth out the input before it gets to the regulator.

![Power Supply](./images/power-supply.png)

## Indicator Lights

There are indicator lights for low oil pressure, neutral, high beam and turn signals.

The oil pressure and neutral sensors are simple switches to ground.
So these will be directly connected to digital input pins.
I'm not sure if the internal pull ups will be good enough so there will be provision on the PCB for external pull up resistors.

![Neutral](./images/neutral.png)

The highbeam and turn signals indicators should light up when they see 12V.
We'll use an optocoupler to give some extra protection.

![Turn Signals](./images/turn-signals.png)

```
Diode forward voltage: 0.715V
Photodiode forward voltage: 1.3V
Photodiode forward current: 10mA
R1 = (14V - 0.715V - 1.3V) / 10mA = 1200 ohm ~= 1k ohm
```

```
CTR: 50%
Output current: 50% of 10mA = 5mA
Output voltage: 4V
R2 = (5V - 4V) / 5mA = 200 ohm
```

## Tachometer

## Speedometer

## Real Time Clock

A PCF8563T RTC module will be used to keep the time for the clock.
It will have a coin cell to keep the clock ticking when the key is off.

![RTC](./images/rtc.png)

## LCD

The VIM-878-DP-FC-S-LV LCD display will be used.
It is a transflective LCD so works well in both bright sunlight and at night with a backlight.
It is an 8 character 14 (plus 2) segment "starburst" display.
It has a total of (14 + 2) \* 8 = 128 segments and uses 4 backplanes.

The HT1621B will be used to drive the LCD.
There are some existing Arduino libraries to interface with it.
It can drive 32 segments by 4 commons which is exactly what is required to drive the selected LCD.

The wiring of the driver to the display is optimised for the PCB layout.

![LCD Segment Names](./images/14seg.png)

This table has the LCD segments from the datasheet and what memory address they are according to the PCB layout:

| LCD Pin | COM0 | COM1 | COM2 | COM3 | Memory address |
| ------- | ---- | ---- | ---- | ---- | -------------- |
| 1       | 1D   | 1E   | 1F   | CA1  | 31             |
| 2       | 1L   | 1K   | 1J   | 1I   | 30             |
| 3       | 2D   | 2E   | 2F   | CA2  | 29             |
| 4       | 2L   | 2K   | 2J   | 2I   | 27             |
| 5       | 3D   | 3E   | 3F   | CA3  | 28             |
| 6       | 3L   | 3K   | 3J   | 3I   | 26             |
| 7       | 4D   | 4E   | 4F   | CA4  | 25             |
| 8       | 4L   | 4K   | 4J   | 4I   | 24             |
| 9       | 5D   | 5E   | 5F   | CA5  | 23             |
| 10      | 5L   | 5K   | 5J   | 5I   | 22             |
| 11      | 6D   | 6E   | 6F   | CA6  | 21             |
| 12      | 6L   | 6K   | 6J   | 6I   | 20             |
| 13      | 7D   | 7E   | 7F   | CA7  | 19             |
| 14      | 7L   | 7K   | 7J   | 7I   | 18             |
| 15      | 8D   | 8E   | 8F   | CA8  | 17             |
| 16      | 8L   | 8K   | 8J   | 8I   | 16             |
| 17      | COM0 |      |      |      |                |
| 18      |      | COM1 |      |      |                |
| 19      |      |      | COM2 |      |                |
| 20      |      |      |      | COM3 |                |
| 21      | DP8  | 8C   | 8B   | 8A   | 15             |
| 22      | 8M   | 8N   | 8G   | 8H   | 14             |
| 23      | DP7  | 7C   | 7B   | 7A   | 13             |
| 24      | 7M   | 7N   | 7G   | 7H   | 12             |
| 25      | DP6  | 6C   | 6B   | 6A   | 11             |
| 26      | 6M   | 6N   | 6G   | 6H   | 10             |
| 27      | DP5  | 5C   | 5B   | 5A   | 9              |
| 28      | 5M   | 5N   | 5G   | 5H   | 8              |
| 29      | DP4  | 4C   | 4B   | 4A   | 7              |
| 30      | 4M   | 4N   | 4G   | 4H   | 6              |
| 31      | DP3  | 3C   | 3B   | 3A   | 5              |
| 32      | 3M   | 3N   | 3G   | 3H   | 4              |
| 33      | DP2  | 2C   | 2B   | 2A   | 3              |
| 34      | 2M   | 2N   | 2G   | 2H   | 2              |
| 35      | DP1  | 1C   | 1B   | 1A   | 1              |
| 36      | 1M   | 1N   | 1G   | 1H   | 0              |

From this table we can see that each digit is powered by 4 LCD pins that map to 4 memory addresses.
For example digit 1 is LCD pins 35, 1, 2 and 36, which map to memory address' 1, 31, 30 and 0.

The font maps ASCII characters to the segments in order CA,F,E,D,I,J,K,L,A,B,C,DP,H,G,N,M.
The segments are in this order so the nibbles match the memory layout of the driver.

The address mapping maps digits to the 4 memory addresses that the font nibbles should be written to.

| Digit | Address'   |
| ----- | ---------- |
| 1     |  1,31,30, 0|
| 2     |  3,29,27, 2|
| 3     |  5,28,26, 4|
| 4     |  7,25,24, 6|
| 5     |  9,23,22, 8|
| 6     | 11,21,20,10|
| 7     | 13,19,18,12|
| 8     | 15,17,16,14|

This font table and address mapping should be enough to display text on the LCD.

## Stepper motor

The X27.168 stepper motor will be used, it is designed for gauges and can be directly driven from a microcontroller.

People on the internet say that clamping diodes are required, so they will be added.

![Motor](./images/motor.png)

The X25 datasheet shows the required pattern to step the motor.

![Step Pattern](./images/stepper-pattern.png)

## PCB Design

There are three PCBs: the main board, the sensor board and the face board.
The boards are stacked using standoffs and are connected together with 2.54mm stacking header pins.

The main board has the microcontroller, stepper motor, LCD, real time clock and indicators.
The sensor board has the power supply and the signal conditioning.
The face board is the dial face and has transparent icons for the indicators.

![Main PCB](./images/pcb-main.jpg)

## Case Design

The case is 3D printed out of ASA.

![Case](./images/case.png)

## EEPROM

The ODO, trip and configuration will be stored in EEPROM.

EEPROM has like 100,000 writes before it wears out, so in order to be able to store the ODO and trip we will need to be able to rotate to new address'.
To do this we will have a table at the start of the EEPROM that stores the address of each value and if the EEPROM gets corrupt we will find a new place to store it and update the table.

| Address | Size | Description            |
| ------- | ---- | ---------------------- |
| 0       | 8    | ODO Address            |
| 1       | 8    | Trip Address           |
| 2       | 8    | Wheel diameter         |
| 15      | 8    | Next available address |
| 16      | 32   | ODO value              |
| 20      | 32   | Trip value             |


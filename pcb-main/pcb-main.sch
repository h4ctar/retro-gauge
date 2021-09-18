EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Motor:Stepper_Motor_bipolar M?
U 1 1 612E09E8
P 9550 1900
AR Path="/612034C5/612E09E8" Ref="M?"  Part="1" 
AR Path="/612E09E8" Ref="M1"  Part="1" 
F 0 "M1" H 9738 2024 50  0000 L CNN
F 1 "Stepper_Motor" H 9738 1933 50  0000 L CNN
F 2 "footprints:Stepper Motor" H 9560 1890 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 9560 1890 50  0001 C CNN
	1    9550 1900
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4001 D?
U 1 1 612E09EE
P 8550 2250
AR Path="/612034C5/612E09EE" Ref="D?"  Part="1" 
AR Path="/612E09EE" Ref="D2"  Part="1" 
F 0 "D2" H 8550 2467 50  0000 C CNN
F 1 "1N4001" H 8550 2376 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8550 2075 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 8550 2250 50  0001 C CNN
	1    8550 2250
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4001 D?
U 1 1 612E09F4
P 8950 2250
AR Path="/612034C5/612E09F4" Ref="D?"  Part="1" 
AR Path="/612E09F4" Ref="D4"  Part="1" 
F 0 "D4" H 8950 2467 50  0000 C CNN
F 1 "1N4001" H 8950 2376 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8950 2075 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 8950 2250 50  0001 C CNN
	1    8950 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	8950 2000 9250 2000
Wire Wire Line
	8550 1800 9250 1800
$Comp
L Diode:1N4001 D?
U 1 1 612E09FE
P 8550 1200
AR Path="/612034C5/612E09FE" Ref="D?"  Part="1" 
AR Path="/612E09FE" Ref="D1"  Part="1" 
F 0 "D1" H 8550 1417 50  0000 C CNN
F 1 "1N4001" H 8550 1326 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8550 1025 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 8550 1200 50  0001 C CNN
	1    8550 1200
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4001 D?
U 1 1 612E0A04
P 8950 1200
AR Path="/612034C5/612E0A04" Ref="D?"  Part="1" 
AR Path="/612E0A04" Ref="D3"  Part="1" 
F 0 "D3" H 8950 1417 50  0000 C CNN
F 1 "1N4001" H 8950 1326 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8950 1025 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 8950 1200 50  0001 C CNN
	1    8950 1200
	0    1    1    0   
$EndComp
Connection ~ 8950 2000
Connection ~ 8550 1800
$Comp
L Diode:1N4001 D?
U 1 1 612E0A0C
P 10350 2250
AR Path="/612034C5/612E0A0C" Ref="D?"  Part="1" 
AR Path="/612E0A0C" Ref="D6"  Part="1" 
F 0 "D6" H 10350 2467 50  0000 C CNN
F 1 "1N4001" H 10350 2376 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10350 2075 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 10350 2250 50  0001 C CNN
	1    10350 2250
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4001 D?
U 1 1 612E0A12
P 10350 1200
AR Path="/612034C5/612E0A12" Ref="D?"  Part="1" 
AR Path="/612E0A12" Ref="D5"  Part="1" 
F 0 "D5" H 10350 1417 50  0000 C CNN
F 1 "1N4001" H 10350 1326 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10350 1025 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 10350 1200 50  0001 C CNN
	1    10350 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	9650 1600 9650 1550
$Comp
L Diode:1N4001 D?
U 1 1 612E0A1B
P 10750 1200
AR Path="/612034C5/612E0A1B" Ref="D?"  Part="1" 
AR Path="/612E0A1B" Ref="D7"  Part="1" 
F 0 "D7" H 10750 1417 50  0000 C CNN
F 1 "1N4001" H 10750 1326 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10750 1025 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 10750 1200 50  0001 C CNN
	1    10750 1200
	0    1    1    0   
$EndComp
$Comp
L Diode:1N4001 D?
U 1 1 612E0A21
P 10750 2250
AR Path="/612034C5/612E0A21" Ref="D?"  Part="1" 
AR Path="/612E0A21" Ref="D8"  Part="1" 
F 0 "D8" H 10750 2467 50  0000 C CNN
F 1 "1N4001" H 10750 2376 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10750 2075 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 10750 2250 50  0001 C CNN
	1    10750 2250
	0    1    1    0   
$EndComp
Connection ~ 10350 1550
$Comp
L power:GND #PWR?
U 1 1 612E0A4A
P 8550 2600
AR Path="/612034C5/612E0A4A" Ref="#PWR?"  Part="1" 
AR Path="/612E0A4A" Ref="#PWR0101"  Part="1" 
F 0 "#PWR0101" H 8550 2350 50  0001 C CNN
F 1 "GND" H 8555 2427 50  0000 C CNN
F 2 "" H 8550 2600 50  0001 C CNN
F 3 "" H 8550 2600 50  0001 C CNN
	1    8550 2600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 612E0A50
P 8550 850
AR Path="/612034C5/612E0A50" Ref="#PWR?"  Part="1" 
AR Path="/612E0A50" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 8550 700 50  0001 C CNN
F 1 "+5V" H 8565 1023 50  0000 C CNN
F 2 "" H 8550 850 50  0001 C CNN
F 3 "" H 8550 850 50  0001 C CNN
	1    8550 850 
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U?
U 1 1 612E398C
P 2050 2600
AR Path="/612034A3/612E398C" Ref="U?"  Part="1" 
AR Path="/612E398C" Ref="U1"  Part="1" 
F 0 "U1" H 2000 1750 50  0000 C CNN
F 1 "ATmega328P-AU" H 2000 1600 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 2050 2600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 2050 2600 50  0001 C CNN
	1    2050 2600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 612E3992
P 2150 900
AR Path="/612034A3/612E3992" Ref="#PWR?"  Part="1" 
AR Path="/612E3992" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 2150 750 50  0001 C CNN
F 1 "+5V" H 2165 1073 50  0000 C CNN
F 2 "" H 2150 900 50  0001 C CNN
F 3 "" H 2150 900 50  0001 C CNN
	1    2150 900 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 612E399D
P 4400 1050
AR Path="/612034A3/612E399D" Ref="#PWR?"  Part="1" 
AR Path="/612E399D" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 4400 900 50  0001 C CNN
F 1 "+5V" H 4415 1223 50  0000 C CNN
F 2 "" H 4400 1050 50  0001 C CNN
F 3 "" H 4400 1050 50  0001 C CNN
	1    4400 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 612E39A4
P 4400 2150
AR Path="/612034A3/612E39A4" Ref="#PWR?"  Part="1" 
AR Path="/612E39A4" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 4400 1900 50  0001 C CNN
F 1 "GND" H 4405 1977 50  0000 C CNN
F 2 "" H 4400 2150 50  0001 C CNN
F 3 "" H 4400 2150 50  0001 C CNN
	1    4400 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector:AVR-ISP-6 J?
U 1 1 612E39AB
P 4500 1650
AR Path="/612034A3/612E39AB" Ref="J?"  Part="1" 
AR Path="/612E39AB" Ref="J1"  Part="1" 
F 0 "J1" H 4171 1746 50  0000 R CNN
F 1 "AVR-ISP-6" H 4171 1655 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 4250 1700 50  0001 C CNN
F 3 " ~" H 3225 1100 50  0001 C CNN
	1    4500 1650
	1    0    0    -1  
$EndComp
Text Label 4900 1550 0    50   ~ 0
PB3
Text Label 4900 1450 0    50   ~ 0
PB4
Text Label 4900 1650 0    50   ~ 0
PB5
Text Label 4900 1750 0    50   ~ 0
RESET
Text Label 3400 2900 0    50   ~ 0
RESET
$Comp
L symbols:HT1621B U2
U 1 1 612E981B
P 1650 6050
F 0 "U2" H 1650 7215 50  0000 C CNN
F 1 "HT1621B" H 1650 7124 50  0000 C CNN
F 2 "footprints:HT1621B" H 1650 6050 50  0001 C CNN
F 3 "" H 1650 6050 50  0001 C CNN
	1    1650 6050
	1    0    0    -1  
$EndComp
$Comp
L symbols:VIM878 U3
U 1 1 612E9821
P 3850 6250
F 0 "U3" H 3875 7325 50  0000 C CNN
F 1 "VIM878" H 3875 7234 50  0000 C CNN
F 2 "footprints:VIM878" H 3850 6150 50  0001 C CNN
F 3 "" H 3850 6150 50  0001 C CNN
	1    3850 6250
	1    0    0    -1  
$EndComp
Text Label 2250 5150 0    50   ~ 0
SEG8
Text Label 2250 5250 0    50   ~ 0
SEG9
Text Label 2250 5350 0    50   ~ 0
SEG10
Text Label 2250 5450 0    50   ~ 0
SEG11
Text Label 2250 5550 0    50   ~ 0
SEG12
Text Label 2250 5650 0    50   ~ 0
SEG13
Text Label 2250 5750 0    50   ~ 0
SEG14
Text Label 2250 5850 0    50   ~ 0
SEG15
Text Label 2250 5950 0    50   ~ 0
SEG16
Text Label 2250 6050 0    50   ~ 0
SEG17
Text Label 2250 6150 0    50   ~ 0
SEG18
Text Label 2250 6250 0    50   ~ 0
SEG19
Text Label 2250 6350 0    50   ~ 0
SEG20
Text Label 2250 6450 0    50   ~ 0
SEG21
Text Label 2250 6550 0    50   ~ 0
SEG22
Text Label 2250 6650 0    50   ~ 0
SEG23
Text Label 2250 6750 0    50   ~ 0
SEG24
Text Label 2250 6850 0    50   ~ 0
SEG25
Text Label 2250 6950 0    50   ~ 0
SEG26
Text Label 2250 7050 0    50   ~ 0
SEG27
Text Label 2250 7150 0    50   ~ 0
SEG28
Text Label 2250 7250 0    50   ~ 0
SEG29
Text Label 2250 7350 0    50   ~ 0
SEG30
Text Label 2250 7450 0    50   ~ 0
SEG31
Text Label 1050 5150 2    50   ~ 0
SEG7
Text Label 1050 5250 2    50   ~ 0
SEG6
Text Label 1050 5350 2    50   ~ 0
SEG5
Text Label 1050 5450 2    50   ~ 0
SEG4
Text Label 1050 5550 2    50   ~ 0
SEG3
Text Label 1050 5650 2    50   ~ 0
SEG2
Text Label 1050 5750 2    50   ~ 0
SEG1
Text Label 1050 5850 2    50   ~ 0
SEG0
Text Label 3300 5400 2    50   ~ 0
SEG8
Text Label 3300 5500 2    50   ~ 0
SEG9
Text Label 3300 5600 2    50   ~ 0
SEG10
Text Label 3300 5700 2    50   ~ 0
SEG11
Text Label 3300 5800 2    50   ~ 0
SEG12
Text Label 3300 5900 2    50   ~ 0
SEG13
Text Label 3300 6000 2    50   ~ 0
SEG14
Text Label 3300 6100 2    50   ~ 0
SEG15
Text Label 3300 6200 2    50   ~ 0
SEG7
Text Label 3300 6300 2    50   ~ 0
SEG6
Text Label 3300 6400 2    50   ~ 0
SEG5
Text Label 3300 6500 2    50   ~ 0
SEG4
Text Label 3300 6600 2    50   ~ 0
SEG3
Text Label 3300 6700 2    50   ~ 0
SEG2
Text Label 3300 6800 2    50   ~ 0
SEG1
Text Label 3300 6900 2    50   ~ 0
SEG0
Text Label 4450 5400 0    50   ~ 0
SEG16
Text Label 4450 5500 0    50   ~ 0
SEG17
Text Label 4450 5600 0    50   ~ 0
SEG18
Text Label 4450 5700 0    50   ~ 0
SEG19
Text Label 4450 5800 0    50   ~ 0
SEG20
Text Label 4450 5900 0    50   ~ 0
SEG21
Text Label 4450 6000 0    50   ~ 0
SEG22
Text Label 4450 6100 0    50   ~ 0
SEG23
Text Label 4450 6200 0    50   ~ 0
SEG24
Text Label 4450 6300 0    50   ~ 0
SEG25
Text Label 4450 6400 0    50   ~ 0
SEG26
Text Label 4450 6500 0    50   ~ 0
SEG27
Text Label 4450 6600 0    50   ~ 0
SEG28
Text Label 4450 6700 0    50   ~ 0
SEG29
Text Label 4450 6800 0    50   ~ 0
SEG30
Text Label 4450 6900 0    50   ~ 0
SEG31
Text Label 1050 7150 2    50   ~ 0
COM0
Text Label 1050 7250 2    50   ~ 0
COM1
Text Label 1050 7350 2    50   ~ 0
COM2
Text Label 1050 7450 2    50   ~ 0
COM3
Text Label 3300 7000 2    50   ~ 0
COM0
Text Label 3300 7100 2    50   ~ 0
COM1
Text Label 4450 7000 0    50   ~ 0
COM2
Text Label 4450 7100 0    50   ~ 0
COM3
$Comp
L power:GND #PWR0108
U 1 1 612E9872
P 950 6350
F 0 "#PWR0108" H 950 6100 50  0001 C CNN
F 1 "GND" H 955 6177 50  0000 C CNN
F 2 "" H 950 6350 50  0001 C CNN
F 3 "" H 950 6350 50  0001 C CNN
	1    950  6350
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 612E987D
P 600 6550
F 0 "#PWR0109" H 600 6400 50  0001 C CNN
F 1 "+5V" H 615 6723 50  0000 C CNN
F 2 "" H 600 6550 50  0001 C CNN
F 3 "" H 600 6550 50  0001 C CNN
	1    600  6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 1100 2050 1000
Wire Wire Line
	2050 1000 2150 1000
Wire Wire Line
	2150 1000 2150 1100
Wire Wire Line
	2150 900  2150 1000
Connection ~ 2150 1000
Wire Wire Line
	4400 1050 4400 1150
Wire Wire Line
	4400 2050 4400 2150
$Comp
L Device:LED D11
U 1 1 6133090E
P 5250 6100
F 0 "D11" V 5289 5982 50  0000 R CNN
F 1 "BACKLIGHT" V 5198 5982 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5250 6100 50  0001 C CNN
F 3 "~" H 5250 6100 50  0001 C CNN
	1    5250 6100
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D14
U 1 1 613312D0
P 5800 6100
F 0 "D14" V 5839 5982 50  0000 R CNN
F 1 "BACKLIGHT" V 5748 5982 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5800 6100 50  0001 C CNN
F 3 "~" H 5800 6100 50  0001 C CNN
	1    5800 6100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 6133ED63
P 5250 6500
F 0 "R3" H 5320 6546 50  0000 L CNN
F 1 "R" H 5320 6455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 6500 50  0001 C CNN
F 3 "~" H 5250 6500 50  0001 C CNN
	1    5250 6500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 6134082C
P 5800 6500
F 0 "R6" H 5870 6546 50  0000 L CNN
F 1 "R" H 5870 6455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5730 6500 50  0001 C CNN
F 3 "~" H 5800 6500 50  0001 C CNN
	1    5800 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 6250 5250 6350
Wire Wire Line
	5250 6650 5250 6750
Wire Wire Line
	5250 6750 5800 6750
Wire Wire Line
	5800 6750 5800 6650
Wire Wire Line
	5250 5950 5250 5850
Wire Wire Line
	5250 5850 5800 5850
Wire Wire Line
	5800 5850 5800 5950
Wire Wire Line
	5800 6250 5800 6350
$Comp
L power:GND #PWR0110
U 1 1 6134852F
P 5250 6850
F 0 "#PWR0110" H 5250 6600 50  0001 C CNN
F 1 "GND" H 5255 6677 50  0000 C CNN
F 2 "" H 5250 6850 50  0001 C CNN
F 3 "" H 5250 6850 50  0001 C CNN
	1    5250 6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 6850 5250 6750
Connection ~ 5250 6750
Wire Wire Line
	5250 5750 5250 5850
Connection ~ 5250 5850
Text Notes 5250 5500 0    50   ~ 0
LCD Backlight
Wire Wire Line
	10350 2400 10350 2500
Wire Wire Line
	10350 2500 10750 2500
Wire Wire Line
	10750 2500 10750 2400
Wire Wire Line
	8950 2500 8950 2400
Wire Wire Line
	8950 2500 8550 2500
Wire Wire Line
	8550 2500 8550 2400
Wire Wire Line
	8550 2600 8550 2500
Connection ~ 8550 2500
Wire Wire Line
	8550 1800 8450 1800
Wire Wire Line
	8950 2000 8450 2000
Wire Wire Line
	10350 1550 10850 1550
Wire Wire Line
	8950 2000 8950 2100
Wire Wire Line
	8550 2100 8550 1800
Wire Wire Line
	10350 1550 10350 2100
Wire Wire Line
	9650 1550 10350 1550
Wire Wire Line
	10350 2500 8950 2500
Connection ~ 10350 2500
Connection ~ 8950 2500
Wire Wire Line
	9450 1600 9450 1450
Wire Wire Line
	9450 1450 10750 1450
Wire Wire Line
	10350 1550 10350 1350
Wire Wire Line
	10750 2100 10750 1450
Connection ~ 10750 1450
Wire Wire Line
	10750 1450 10850 1450
Wire Wire Line
	10750 1350 10750 1450
Wire Wire Line
	8950 1350 8950 2000
Wire Wire Line
	8550 1800 8550 1350
Wire Wire Line
	10750 1050 10750 950 
Wire Wire Line
	10750 950  10350 950 
Wire Wire Line
	10350 950  10350 1050
Wire Wire Line
	10350 950  8950 950 
Wire Wire Line
	8950 950  8950 1050
Connection ~ 10350 950 
Wire Wire Line
	8950 950  8550 950 
Wire Wire Line
	8550 950  8550 1050
Connection ~ 8950 950 
Wire Wire Line
	8550 950  8550 850 
Connection ~ 8550 950 
Text Label 10850 1450 0    50   ~ 0
MOT_1
Text Label 10850 1550 0    50   ~ 0
MOT_2
Text Label 8450 1800 2    50   ~ 0
MOT_3
Text Label 8450 2000 2    50   ~ 0
MOT_4
Text Label 2650 2400 0    50   ~ 0
MOT_1
Text Label 2650 2500 0    50   ~ 0
MOT_4
Text Label 2650 2600 0    50   ~ 0
MOT_3
Text Label 2650 2300 0    50   ~ 0
MOT_2
Wire Wire Line
	1050 6350 950  6350
Wire Wire Line
	950  6650 1050 6650
Wire Wire Line
	1050 6750 950  6750
Wire Wire Line
	950  6750 950  6650
Connection ~ 950  6650
$Comp
L power:+5V #PWR?
U 1 1 613D3197
P 3250 2400
AR Path="/612034A3/613D3197" Ref="#PWR?"  Part="1" 
AR Path="/613D3197" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 3250 2250 50  0001 C CNN
F 1 "+5V" H 3265 2573 50  0000 C CNN
F 2 "" H 3250 2400 50  0001 C CNN
F 3 "" H 3250 2400 50  0001 C CNN
	1    3250 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 613D3AC3
P 3250 2650
F 0 "R7" H 3180 2604 50  0000 R CNN
F 1 "10k" H 3180 2695 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 3180 2650 50  0001 C CNN
F 3 "~" H 3250 2650 50  0001 C CNN
	1    3250 2650
	-1   0    0    1   
$EndComp
Wire Wire Line
	3400 2900 3250 2900
Wire Wire Line
	3250 2800 3250 2900
Connection ~ 3250 2900
Wire Wire Line
	3250 2900 2650 2900
Wire Wire Line
	3250 2500 3250 2400
Text Label 2650 1900 0    50   ~ 0
PB5
Text Label 2650 1800 0    50   ~ 0
PB4
Text Label 2650 1700 0    50   ~ 0
PB3
Text Label 1050 5950 2    50   ~ 0
PB3
Text Label 1050 6150 2    50   ~ 0
PB4
Text Label 1050 6250 2    50   ~ 0
PB5
Text Label 5250 5750 0    50   ~ 0
BACKLIGHT_LED
Text Notes 2650 4900 0    50   ~ 0
LCD
Text Notes 4700 1050 0    50   ~ 0
ISP
Wire Wire Line
	1450 1400 1350 1400
Wire Wire Line
	1350 1400 1350 1000
Wire Wire Line
	1350 1000 2050 1000
Connection ~ 2050 1000
Text Label 2650 1400 0    50   ~ 0
PB0
Text Label 2650 3400 0    50   ~ 0
PD3
Text Label 2650 3300 0    50   ~ 0
PD2
$Comp
L Device:Crystal Y1
U 1 1 6149BB4A
P 4400 3550
F 0 "Y1" H 4400 3818 50  0000 C CNN
F 1 "Crystal" H 4400 3727 50  0000 C CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 4400 3550 50  0001 C CNN
F 3 "~" H 4400 3550 50  0001 C CNN
	1    4400 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 614A1171
P 4150 3800
F 0 "C2" H 4265 3846 50  0000 L CNN
F 1 "C" H 4265 3755 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4188 3650 50  0001 C CNN
F 3 "~" H 4150 3800 50  0001 C CNN
	1    4150 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 614A1B8D
P 4650 3800
F 0 "C3" H 4765 3846 50  0000 L CNN
F 1 "C" H 4765 3755 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 4688 3650 50  0001 C CNN
F 3 "~" H 4650 3800 50  0001 C CNN
	1    4650 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 4050 4650 3950
Wire Wire Line
	4250 3550 4150 3550
Wire Wire Line
	4150 3550 4150 3650
Wire Wire Line
	4650 3550 4650 3650
Wire Wire Line
	4150 3950 4150 4050
Wire Wire Line
	4650 4050 4150 4050
Connection ~ 4150 4050
Wire Wire Line
	4150 4050 4150 4150
Wire Wire Line
	4650 3550 4550 3550
$Comp
L power:GND #PWR?
U 1 1 614B5C47
P 4150 4150
AR Path="/612034C5/614B5C47" Ref="#PWR?"  Part="1" 
AR Path="/614B5C47" Ref="#PWR0111"  Part="1" 
F 0 "#PWR0111" H 4150 3900 50  0001 C CNN
F 1 "GND" H 4155 3977 50  0000 C CNN
F 2 "" H 4150 4150 50  0001 C CNN
F 3 "" H 4150 4150 50  0001 C CNN
	1    4150 4150
	1    0    0    -1  
$EndComp
Text Label 2650 2000 0    50   ~ 0
XTAL1
Text Label 2650 2100 0    50   ~ 0
XTAL2
Text Label 4150 3450 2    50   ~ 0
XTAL1
Text Label 4650 3450 0    50   ~ 0
XTAL2
Wire Wire Line
	4150 3450 4150 3550
Connection ~ 4150 3550
Wire Wire Line
	4650 3450 4650 3550
Connection ~ 4650 3550
$Comp
L Device:C C1
U 1 1 614BF38E
P 1100 1150
F 0 "C1" H 1215 1196 50  0000 L CNN
F 1 "C" H 1215 1105 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 1138 1000 50  0001 C CNN
F 3 "~" H 1100 1150 50  0001 C CNN
	1    1100 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1000 1100 1000
Connection ~ 1350 1000
$Comp
L power:GND #PWR?
U 1 1 614C2394
P 1100 1300
AR Path="/612034A3/614C2394" Ref="#PWR?"  Part="1" 
AR Path="/614C2394" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 1100 1050 50  0001 C CNN
F 1 "GND" H 1105 1127 50  0000 C CNN
F 2 "" H 1100 1300 50  0001 C CNN
F 3 "" H 1100 1300 50  0001 C CNN
	1    1100 1300
	1    0    0    -1  
$EndComp
Text Label 2650 3500 0    50   ~ 0
PD4
Text Label 2650 3200 0    50   ~ 0
PD1
Text Label 2650 3600 0    50   ~ 0
PD5
Text Label 2650 3700 0    50   ~ 0
PD6
Text Label 2650 3800 0    50   ~ 0
PD7
Text Label 1450 1600 2    50   ~ 0
ADC6
Text Label 1450 1700 2    50   ~ 0
ADC7
Text Label 7150 3800 0    50   ~ 0
PB0
Text Label 6650 3600 2    50   ~ 0
PD3
Text Label 6650 3800 2    50   ~ 0
PD2
Text Label 6650 3400 2    50   ~ 0
PD4
Text Label 7150 3900 0    50   ~ 0
PD1
Text Label 6650 3500 2    50   ~ 0
PD5
Text Label 6650 3700 2    50   ~ 0
PD6
Text Label 6650 3900 2    50   ~ 0
PD7
Text Label 7150 3400 0    50   ~ 0
ADC6
Text Label 7150 3600 0    50   ~ 0
ADC7
$Comp
L power:+5V #PWR?
U 1 1 614D3041
P 7400 3700
AR Path="/612034A3/614D3041" Ref="#PWR?"  Part="1" 
AR Path="/614D3041" Ref="#PWR0116"  Part="1" 
F 0 "#PWR0116" H 7400 3550 50  0001 C CNN
F 1 "+5V" H 7415 3873 50  0000 C CNN
F 2 "" H 7400 3700 50  0001 C CNN
F 3 "" H 7400 3700 50  0001 C CNN
	1    7400 3700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 614D9B38
P 7400 3500
AR Path="/612034C5/614D9B38" Ref="#PWR?"  Part="1" 
AR Path="/614D9B38" Ref="#PWR0117"  Part="1" 
F 0 "#PWR0117" H 7400 3250 50  0001 C CNN
F 1 "GND" H 7405 3327 50  0000 C CNN
F 2 "" H 7400 3500 50  0001 C CNN
F 3 "" H 7400 3500 50  0001 C CNN
	1    7400 3500
	0    -1   -1   0   
$EndComp
Text Notes 4450 3200 2    50   ~ 0
Clock
$Comp
L Connector_Generic:Conn_02x06_Counter_Clockwise J2
U 1 1 615DA54A
P 6850 3600
F 0 "J2" H 6900 4017 50  0000 C CNN
F 1 "Conn_02x06_Counter_Clockwise" H 6900 3926 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x06_P2.54mm_Vertical_SMD" H 6850 3600 50  0001 C CNN
F 3 "~" H 6850 3600 50  0001 C CNN
	1    6850 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61669FD1
P 2050 4100
AR Path="/612034C5/61669FD1" Ref="#PWR?"  Part="1" 
AR Path="/61669FD1" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 2050 3850 50  0001 C CNN
F 1 "GND" H 2055 3927 50  0000 C CNN
F 2 "" H 2050 4100 50  0001 C CNN
F 3 "" H 2050 4100 50  0001 C CNN
	1    2050 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 6167E0BA
P 600 6900
F 0 "C4" H 715 6946 50  0000 L CNN
F 1 "C" H 715 6855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 638 6750 50  0001 C CNN
F 3 "~" H 600 6900 50  0001 C CNN
	1    600  6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	600  6750 600  6650
Wire Wire Line
	600  6650 950  6650
Connection ~ 600  6650
Wire Wire Line
	600  6650 600  6550
$Comp
L power:GND #PWR0107
U 1 1 61685286
P 600 7150
F 0 "#PWR0107" H 600 6900 50  0001 C CNN
F 1 "GND" H 605 6977 50  0000 C CNN
F 2 "" H 600 7150 50  0001 C CNN
F 3 "" H 600 7150 50  0001 C CNN
	1    600  7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	600  7150 600  7050
Wire Wire Line
	7150 3500 7400 3500
Wire Wire Line
	7150 3700 7400 3700
Text Label 2650 2700 0    50   ~ 0
BACKLIGHT_LED
$Comp
L Connector_Generic:Conn_02x02_Counter_Clockwise J3
U 1 1 61409762
P 6850 2100
F 0 "J3" H 6900 2317 50  0000 C CNN
F 1 "Conn_02x02_Counter_Clockwise" H 6900 2226 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical_SMD" H 6850 2100 50  0001 C CNN
F 3 "~" H 6850 2100 50  0001 C CNN
	1    6850 2100
	1    0    0    -1  
$EndComp
Text Label 2650 3100 0    50   ~ 0
PD0
Text Label 7250 2200 0    50   ~ 0
PD0
$Comp
L power:+5V #PWR0112
U 1 1 6140FFCF
P 6550 2100
F 0 "#PWR0112" H 6550 1950 50  0001 C CNN
F 1 "+5V" V 6565 2228 50  0000 L CNN
F 2 "" H 6550 2100 50  0001 C CNN
F 3 "" H 6550 2100 50  0001 C CNN
	1    6550 2100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 614106F8
P 6550 2300
F 0 "#PWR0113" H 6550 2050 50  0001 C CNN
F 1 "GND" H 6555 2127 50  0000 C CNN
F 2 "" H 6550 2300 50  0001 C CNN
F 3 "" H 6550 2300 50  0001 C CNN
	1    6550 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 2200 7150 2200
Wire Wire Line
	6650 2100 6550 2100
Wire Wire Line
	6550 2300 6550 2200
Wire Wire Line
	6550 2200 6650 2200
Text Notes 1150 4750 0    50   ~ 0
TODO: change the footprint
$Comp
L Switch:SW_Push SW?
U 1 1 615419CF
P 4000 2900
F 0 "SW?" H 4000 3185 50  0000 C CNN
F 1 "SW_Push" H 4000 3094 50  0000 C CNN
F 2 "" H 4000 3100 50  0001 C CNN
F 3 "~" H 4000 3100 50  0001 C CNN
	1    4000 2900
	1    0    0    -1  
$EndComp
$EndSCHEMATC

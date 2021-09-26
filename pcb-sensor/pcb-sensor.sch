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
L Connector_Generic:Conn_02x06_Counter_Clockwise J1
U 1 1 613D87D0
P 2150 1900
F 0 "J1" H 2200 2317 50  0000 C CNN
F 1 "Conn_02x06_Counter_Clockwise" H 2200 2226 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x06_P2.54mm_Vertical_SMD" H 2150 1900 50  0001 C CNN
F 3 "~" H 2150 1900 50  0001 C CNN
	1    2150 1900
	1    0    0    -1  
$EndComp
Text Label 1850 1700 2    50   ~ 0
PD4
Text Label 1850 1800 2    50   ~ 0
PD5
Text Label 1850 1900 2    50   ~ 0
PD3
Text Label 1850 2000 2    50   ~ 0
PD6
Text Label 1850 2100 2    50   ~ 0
PD2
Text Label 1850 2200 2    50   ~ 0
PD7
Text Label 2550 1700 0    50   ~ 0
ADC6
Text Label 2550 1900 0    50   ~ 0
ADC7
Text Label 2550 2100 0    50   ~ 0
PB0
Text Label 2550 2200 0    50   ~ 0
PD1
Wire Wire Line
	2450 1800 2700 1800
Wire Wire Line
	2450 2000 2700 2000
$Comp
L power:GND #PWR0101
U 1 1 613DAC0F
P 2700 1800
F 0 "#PWR0101" H 2700 1550 50  0001 C CNN
F 1 "GND" V 2705 1672 50  0000 R CNN
F 2 "" H 2700 1800 50  0001 C CNN
F 3 "" H 2700 1800 50  0001 C CNN
	1    2700 1800
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 613DB4E3
P 2700 2000
F 0 "#PWR0102" H 2700 1850 50  0001 C CNN
F 1 "+5V" V 2715 2128 50  0000 L CNN
F 2 "" H 2700 2000 50  0001 C CNN
F 3 "" H 2700 2000 50  0001 C CNN
	1    2700 2000
	0    1    1    0   
$EndComp
Text Label 2250 3500 0    50   ~ 0
COIL
Text Label 2250 3100 0    50   ~ 0
SPEED_GND
Text Label 2250 3900 0    50   ~ 0
TURN_SIGNAL_LEFT
Text Label 2250 3700 0    50   ~ 0
OIL_PRESSURE
Text Label 2250 3600 0    50   ~ 0
NEUTRAL
Text Label 2250 4100 0    50   ~ 0
HIGH_BEAM
$Comp
L power:+5V #PWR0103
U 1 1 613DE64C
P 4500 5600
F 0 "#PWR0103" H 4500 5450 50  0001 C CNN
F 1 "+5V" H 4515 5773 50  0000 C CNN
F 2 "" H 4500 5600 50  0001 C CNN
F 3 "" H 4500 5600 50  0001 C CNN
	1    4500 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 613DE9E4
P 2250 4300
F 0 "#PWR0104" H 2250 4050 50  0001 C CNN
F 1 "GND" H 2255 4127 50  0000 C CNN
F 2 "" H 2250 4300 50  0001 C CNN
F 3 "" H 2250 4300 50  0001 C CNN
	1    2250 4300
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0105
U 1 1 613DEE20
P 2250 3400
F 0 "#PWR0105" H 2250 3250 50  0001 C CNN
F 1 "+12V" V 2265 3528 50  0000 L CNN
F 2 "" H 2250 3400 50  0001 C CNN
F 3 "" H 2250 3400 50  0001 C CNN
	1    2250 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 4200 2250 4200
Wire Wire Line
	2250 4200 2250 4300
Text Label 6950 5650 2    50   ~ 0
COIL
Text Label 5400 1500 0    50   ~ 0
PD1
$Comp
L power:GND #PWR0107
U 1 1 6183EBC4
P 7650 5750
F 0 "#PWR0107" H 7650 5500 50  0001 C CNN
F 1 "GND" H 7655 5577 50  0000 C CNN
F 2 "" H 7650 5750 50  0001 C CNN
F 3 "" H 7650 5750 50  0001 C CNN
	1    7650 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 5650 7650 5650
Wire Wire Line
	7650 5650 7650 5750
Wire Wire Line
	7550 5550 7650 5550
$Comp
L power:+5V #PWR0108
U 1 1 6183F867
P 7650 5050
F 0 "#PWR0108" H 7650 4900 50  0001 C CNN
F 1 "+5V" H 7665 5223 50  0000 C CNN
F 2 "" H 7650 5050 50  0001 C CNN
F 3 "" H 7650 5050 50  0001 C CNN
	1    7650 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5550 7650 5450
Connection ~ 7650 5550
Wire Wire Line
	7650 5550 7750 5550
Text Label 7050 1750 2    50   ~ 0
NEUTRAL
$Comp
L power:+5V #PWR0109
U 1 1 61845D0B
P 7250 1250
F 0 "#PWR0109" H 7250 1100 50  0001 C CNN
F 1 "+5V" H 7265 1423 50  0000 C CNN
F 2 "" H 7250 1250 50  0001 C CNN
F 3 "" H 7250 1250 50  0001 C CNN
	1    7250 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 61846369
P 7250 1500
F 0 "R2" H 7320 1546 50  0000 L CNN
F 1 "R" H 7320 1455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 7180 1500 50  0001 C CNN
F 3 "~" H 7250 1500 50  0001 C CNN
	1    7250 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1250 7250 1350
Wire Wire Line
	7250 1650 7250 1750
Text Label 5350 3600 0    50   ~ 0
PD2
Wire Wire Line
	7450 1750 7250 1750
Wire Wire Line
	7050 1750 7250 1750
Connection ~ 7250 1750
Text Label 9750 1800 2    50   ~ 0
OIL_PRESSURE
$Comp
L Device:R R3
U 1 1 6184DF63
P 9950 1550
F 0 "R3" H 10020 1596 50  0000 L CNN
F 1 "R" H 10020 1505 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 9880 1550 50  0001 C CNN
F 3 "~" H 9950 1550 50  0001 C CNN
	1    9950 1550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 6184E39F
P 9950 1300
F 0 "#PWR0110" H 9950 1150 50  0001 C CNN
F 1 "+5V" H 9965 1473 50  0000 C CNN
F 2 "" H 9950 1300 50  0001 C CNN
F 3 "" H 9950 1300 50  0001 C CNN
	1    9950 1300
	1    0    0    -1  
$EndComp
Text Label 10150 1800 0    50   ~ 0
PD3
Wire Wire Line
	9750 1800 9950 1800
Wire Wire Line
	9950 1800 9950 1700
Connection ~ 9950 1800
Wire Wire Line
	9950 1800 10150 1800
Wire Wire Line
	9950 1400 9950 1300
$Comp
L Device:R R1
U 1 1 618559FE
P 9500 3200
F 0 "R1" H 9570 3246 50  0000 L CNN
F 1 "R" H 9570 3155 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 9430 3200 50  0001 C CNN
F 3 "~" H 9500 3200 50  0001 C CNN
	1    9500 3200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 618567BB
P 9500 3750
F 0 "#PWR0111" H 9500 3500 50  0001 C CNN
F 1 "GND" H 9505 3577 50  0000 C CNN
F 2 "" H 9500 3750 50  0001 C CNN
F 3 "" H 9500 3750 50  0001 C CNN
	1    9500 3750
	1    0    0    -1  
$EndComp
Text Label 2250 4000 0    50   ~ 0
TURN_SIGNAL_RIGHT
Text Label 9000 2750 2    50   ~ 0
TURN_SIGNAL_LEFT
Text Label 9000 2950 2    50   ~ 0
TURN_SIGNAL_RIGHT
$Comp
L Device:D D1
U 1 1 6186C044
P 9250 2750
F 0 "D1" H 9250 2550 50  0000 C CNN
F 1 "D" H 9250 2650 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 9250 2750 50  0001 C CNN
F 3 "~" H 9250 2750 50  0001 C CNN
	1    9250 2750
	-1   0    0    1   
$EndComp
$Comp
L Device:D D2
U 1 1 6186C8A7
P 9250 2950
F 0 "D2" H 9250 3150 50  0000 C CNN
F 1 "D" H 9250 3050 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 9250 2950 50  0001 C CNN
F 3 "~" H 9250 2950 50  0001 C CNN
	1    9250 2950
	-1   0    0    1   
$EndComp
Wire Wire Line
	9100 2950 9000 2950
Wire Wire Line
	9000 2750 9100 2750
Wire Wire Line
	9400 2750 9500 2750
Wire Wire Line
	9500 2750 9500 2950
Wire Wire Line
	9500 2950 9400 2950
Text Label 6750 2950 2    50   ~ 0
HIGH_BEAM
$Comp
L power:GND #PWR0106
U 1 1 6187B8D1
P 6850 3750
F 0 "#PWR0106" H 6850 3500 50  0001 C CNN
F 1 "GND" H 6855 3577 50  0000 C CNN
F 2 "" H 6850 3750 50  0001 C CNN
F 3 "" H 6850 3750 50  0001 C CNN
	1    6850 3750
	1    0    0    -1  
$EndComp
Text Label 7750 3550 0    50   ~ 0
PD4
Text Label 7750 5550 0    50   ~ 0
PD5
Text Label 2250 3800 0    50   ~ 0
KEY_12V
Text Label 6750 4950 2    50   ~ 0
KEY_12V
Text Label 9350 4750 2    50   ~ 0
KEY_12V
$Comp
L Device:R R5
U 1 1 618A4E09
P 9450 5000
F 0 "R5" H 9520 5046 50  0000 L CNN
F 1 "R" H 9520 4955 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 9380 5000 50  0001 C CNN
F 3 "~" H 9450 5000 50  0001 C CNN
	1    9450 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 618A544E
P 9450 5500
F 0 "R6" H 9520 5546 50  0000 L CNN
F 1 "R" H 9520 5455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 9380 5500 50  0001 C CNN
F 3 "~" H 9450 5500 50  0001 C CNN
	1    9450 5500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 618A5A6C
P 9450 5850
F 0 "#PWR0112" H 9450 5600 50  0001 C CNN
F 1 "GND" H 9455 5677 50  0000 C CNN
F 2 "" H 9450 5850 50  0001 C CNN
F 3 "" H 9450 5850 50  0001 C CNN
	1    9450 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 618A6283
P 9850 5500
F 0 "C1" H 9965 5546 50  0000 L CNN
F 1 "C" H 9965 5455 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 9888 5350 50  0001 C CNN
F 3 "~" H 9850 5500 50  0001 C CNN
	1    9850 5500
	1    0    0    -1  
$EndComp
Text Label 9950 5250 0    50   ~ 0
ADC7
Wire Wire Line
	9350 4750 9450 4750
Wire Wire Line
	9450 4750 9450 4850
Wire Wire Line
	9450 5150 9450 5250
Wire Wire Line
	9450 5250 9850 5250
Connection ~ 9450 5250
Wire Wire Line
	9450 5250 9450 5350
Connection ~ 9850 5250
Wire Wire Line
	9850 5250 9950 5250
Wire Wire Line
	9850 5250 9850 5350
Wire Wire Line
	9450 5850 9450 5750
Wire Wire Line
	9450 5750 9850 5750
Wire Wire Line
	9850 5750 9850 5650
Connection ~ 9450 5750
Wire Wire Line
	9450 5750 9450 5650
$Comp
L power:+12V #PWR0113
U 1 1 61914F19
P 3500 5600
F 0 "#PWR0113" H 3500 5450 50  0001 C CNN
F 1 "+12V" V 3515 5728 50  0000 L CNN
F 2 "" H 3500 5600 50  0001 C CNN
F 3 "" H 3500 5600 50  0001 C CNN
	1    3500 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 619157D5
P 3500 6300
F 0 "#PWR0114" H 3500 6050 50  0001 C CNN
F 1 "GND" H 3505 6127 50  0000 C CNN
F 2 "" H 3500 6300 50  0001 C CNN
F 3 "" H 3500 6300 50  0001 C CNN
	1    3500 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 5700 3500 5700
Wire Wire Line
	3500 5700 3500 5600
Wire Wire Line
	4400 5700 4500 5700
Wire Wire Line
	4500 5700 4500 5600
Wire Wire Line
	7750 3550 7650 3550
Wire Wire Line
	6950 3450 6850 3450
Wire Wire Line
	6850 3650 6850 3750
$Comp
L power:GND #PWR0115
U 1 1 61957411
P 7650 3750
F 0 "#PWR0115" H 7650 3500 50  0001 C CNN
F 1 "GND" H 7655 3577 50  0000 C CNN
F 2 "" H 7650 3750 50  0001 C CNN
F 3 "" H 7650 3750 50  0001 C CNN
	1    7650 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0116
U 1 1 61957CB6
P 7650 3050
F 0 "#PWR0116" H 7650 2900 50  0001 C CNN
F 1 "+5V" H 7665 3223 50  0000 C CNN
F 2 "" H 7650 3050 50  0001 C CNN
F 3 "" H 7650 3050 50  0001 C CNN
	1    7650 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3650 7650 3650
Wire Wire Line
	7650 3650 7650 3750
Wire Wire Line
	7650 3550 7650 3450
Connection ~ 7650 3550
Wire Wire Line
	7650 3550 7550 3550
$Comp
L Device:R R7
U 1 1 6195F614
P 6850 5200
F 0 "R7" H 6920 5246 50  0000 L CNN
F 1 "R" H 6920 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 6780 5200 50  0001 C CNN
F 3 "~" H 6850 5200 50  0001 C CNN
	1    6850 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 6195FC42
P 7650 5300
F 0 "R9" H 7720 5346 50  0000 L CNN
F 1 "R" H 7720 5255 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 7580 5300 50  0001 C CNN
F 3 "~" H 7650 5300 50  0001 C CNN
	1    7650 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 619602EB
P 6850 3200
F 0 "R4" H 6920 3246 50  0000 L CNN
F 1 "R" H 6920 3155 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 6780 3200 50  0001 C CNN
F 3 "~" H 6850 3200 50  0001 C CNN
	1    6850 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 619607C2
P 7650 3300
F 0 "R8" H 7720 3346 50  0000 L CNN
F 1 "R" H 7720 3255 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 7580 3300 50  0001 C CNN
F 3 "~" H 7650 3300 50  0001 C CNN
	1    7650 3300
	1    0    0    -1  
$EndComp
$Comp
L Isolator:4N35 U3
U 1 1 61974C71
P 7250 5550
F 0 "U3" H 7250 5875 50  0000 C CNN
F 1 "4N35" H 7250 5784 50  0000 C CNN
F 2 "footprints:4N35S" H 7050 5350 50  0001 L CIN
F 3 "https://www.vishay.com/docs/81181/4n35.pdf" H 7250 5550 50  0001 L CNN
	1    7250 5550
	1    0    0    -1  
$EndComp
$Comp
L Isolator:4N35 U2
U 1 1 619767AC
P 7250 3550
F 0 "U2" H 7250 3875 50  0000 C CNN
F 1 "4N35" H 7250 3784 50  0000 C CNN
F 2 "footprints:4N35S" H 7050 3350 50  0001 L CIN
F 3 "https://www.vishay.com/docs/81181/4n35.pdf" H 7250 3550 50  0001 L CNN
	1    7250 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 3650 6950 3650
Wire Wire Line
	6950 5450 6850 5450
Wire Wire Line
	6850 5450 6850 5350
Wire Wire Line
	6850 5050 6850 4950
Wire Wire Line
	6850 4950 6750 4950
Wire Wire Line
	7650 5150 7650 5050
Wire Wire Line
	6750 2950 6850 2950
Wire Wire Line
	6850 2950 6850 3050
Wire Wire Line
	6850 3350 6850 3450
Wire Wire Line
	7650 3150 7650 3050
$Comp
L Isolator:4N35 U4
U 1 1 614D239C
P 9900 3550
F 0 "U4" H 9900 3875 50  0000 C CNN
F 1 "4N35" H 9900 3784 50  0000 C CNN
F 2 "footprints:4N35S" H 9700 3350 50  0001 L CIN
F 3 "https://www.vishay.com/docs/81181/4n35.pdf" H 9900 3550 50  0001 L CNN
	1    9900 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 3050 9500 2950
Connection ~ 9500 2950
Wire Wire Line
	9500 3350 9500 3450
Wire Wire Line
	9500 3450 9600 3450
Wire Wire Line
	9600 3650 9500 3650
Wire Wire Line
	9500 3650 9500 3750
$Comp
L Device:R R10
U 1 1 614F3ED1
P 10300 3300
F 0 "R10" H 10370 3346 50  0000 L CNN
F 1 "R" H 10370 3255 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 10230 3300 50  0001 C CNN
F 3 "~" H 10300 3300 50  0001 C CNN
	1    10300 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 614F4399
P 10300 3750
F 0 "#PWR0117" H 10300 3500 50  0001 C CNN
F 1 "GND" H 10305 3577 50  0000 C CNN
F 2 "" H 10300 3750 50  0001 C CNN
F 3 "" H 10300 3750 50  0001 C CNN
	1    10300 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0118
U 1 1 614FDD9D
P 10300 3050
F 0 "#PWR0118" H 10300 2900 50  0001 C CNN
F 1 "+5V" H 10315 3223 50  0000 C CNN
F 2 "" H 10300 3050 50  0001 C CNN
F 3 "" H 10300 3050 50  0001 C CNN
	1    10300 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 3650 10300 3650
Wire Wire Line
	10300 3650 10300 3750
Wire Wire Line
	10400 3550 10300 3550
Wire Wire Line
	10300 3450 10300 3550
Connection ~ 10300 3550
Wire Wire Line
	10300 3550 10200 3550
Wire Wire Line
	10300 3150 10300 3050
Wire Wire Line
	1850 1700 1950 1700
Wire Wire Line
	1950 1800 1850 1800
Wire Wire Line
	1850 1900 1950 1900
Wire Wire Line
	1950 2000 1850 2000
Wire Wire Line
	1850 2100 1950 2100
Wire Wire Line
	1950 2200 1850 2200
Wire Wire Line
	2450 2200 2550 2200
Wire Wire Line
	2550 2100 2450 2100
Wire Wire Line
	2450 1900 2550 1900
Wire Wire Line
	2550 1700 2450 1700
$Comp
L power:GND #PWR0119
U 1 1 6153B8BC
P 4400 2050
F 0 "#PWR0119" H 4400 1800 50  0001 C CNN
F 1 "GND" H 4405 1877 50  0000 C CNN
F 2 "" H 4400 2050 50  0001 C CNN
F 3 "" H 4400 2050 50  0001 C CNN
	1    4400 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1750 4500 1750
$Comp
L symbols:TLSM U5
U 1 1 61560850
P 4850 1650
F 0 "U5" H 4850 2065 50  0000 C CNN
F 1 "TLSM" H 4850 1974 50  0000 C CNN
F 2 "footprints:TLSM" H 4910 775 50  0001 C CNN
F 3 "" H 4910 775 50  0001 C CNN
	1    4850 1650
	1    0    0    -1  
$EndComp
Text Label 10400 3550 0    50   ~ 0
PD6
Wire Wire Line
	5200 1500 5300 1500
$Comp
L power:+5V #PWR0120
U 1 1 6153E100
P 5300 1000
F 0 "#PWR0120" H 5300 850 50  0001 C CNN
F 1 "+5V" H 5315 1173 50  0000 C CNN
F 2 "" H 5300 1000 50  0001 C CNN
F 3 "" H 5300 1000 50  0001 C CNN
	1    5300 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 615403F8
P 5300 1250
F 0 "R12" H 5370 1296 50  0000 L CNN
F 1 "R" H 5370 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5230 1250 50  0001 C CNN
F 3 "~" H 5300 1250 50  0001 C CNN
	1    5300 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 1000 5300 1100
Wire Wire Line
	5300 1400 5300 1500
Connection ~ 5300 1500
Wire Wire Line
	5300 1500 5400 1500
Text Label 7450 1750 0    50   ~ 0
PD7
Wire Wire Line
	2250 3300 2150 3300
Wire Wire Line
	2150 3400 2250 3400
Wire Wire Line
	2250 3500 2150 3500
Wire Wire Line
	2150 3600 2250 3600
Wire Wire Line
	2250 3700 2150 3700
Wire Wire Line
	2150 3800 2250 3800
Wire Wire Line
	2250 3900 2150 3900
Wire Wire Line
	2150 4000 2250 4000
Text Label 2250 3200 0    50   ~ 0
SPEED_5V
Text Label 2250 3300 0    50   ~ 0
SPEED_OUT
Text Label 4700 3800 2    50   ~ 0
SPEED_GND
Text Label 4700 3400 2    50   ~ 0
SPEED_5V
Text Label 4700 3600 2    50   ~ 0
SPEED_OUT
$Comp
L Connector_Generic:Conn_01x12 J2
U 1 1 6161BE5C
P 1950 3700
F 0 "J2" H 1868 2875 50  0000 C CNN
F 1 "Conn_01x12" H 1868 2966 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 1950 3700 50  0001 C CNN
F 3 "~" H 1950 3700 50  0001 C CNN
	1    1950 3700
	-1   0    0    1   
$EndComp
Wire Wire Line
	2150 3200 2250 3200
Wire Wire Line
	2250 3100 2150 3100
$Comp
L power:GND #PWR0121
U 1 1 6165B34D
P 4800 3900
F 0 "#PWR0121" H 4800 3650 50  0001 C CNN
F 1 "GND" H 4805 3727 50  0000 C CNN
F 2 "" H 4800 3900 50  0001 C CNN
F 3 "" H 4800 3900 50  0001 C CNN
	1    4800 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3800 4800 3800
Wire Wire Line
	4800 3800 4800 3900
$Comp
L power:+5V #PWR0122
U 1 1 6166B696
P 4850 3000
F 0 "#PWR0122" H 4850 2850 50  0001 C CNN
F 1 "+5V" H 4865 3173 50  0000 C CNN
F 2 "" H 4850 3000 50  0001 C CNN
F 3 "" H 4850 3000 50  0001 C CNN
	1    4850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3400 4850 3400
Wire Wire Line
	5350 3600 5250 3600
$Comp
L Device:R R11
U 1 1 616846C0
P 5250 3350
F 0 "R11" H 5320 3396 50  0000 L CNN
F 1 "R" H 5320 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 3350 50  0001 C CNN
F 3 "~" H 5250 3350 50  0001 C CNN
	1    5250 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3100 4850 3400
Wire Wire Line
	5250 3200 5250 3100
Wire Wire Line
	5250 3100 4850 3100
Connection ~ 4850 3100
Wire Wire Line
	4850 3100 4850 3000
Wire Wire Line
	5250 3500 5250 3600
Connection ~ 5250 3600
Wire Wire Line
	5250 3600 4700 3600
Text Notes 4600 1050 0    50   ~ 0
Mode button
Text Notes 6950 950  0    50   ~ 0
Neutral switch
Text Notes 9600 950  0    50   ~ 0
Oil pressure switch
Text Notes 9750 2700 0    50   ~ 0
Turn signal indicator
Text Notes 9100 4550 0    50   ~ 0
Battery voltage
Text Notes 7000 4700 0    50   ~ 0
Tachometer
Text Notes 6850 2750 0    50   ~ 0
High beam indicator
Text Notes 4700 2750 0    50   ~ 0
Speedometer
Text Notes 3850 5300 0    50   ~ 0
Power supply
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 6175719F
P 4900 2250
F 0 "J3" V 4772 2330 50  0000 L CNN
F 1 "Conn_01x02" V 4863 2330 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x01_P2.54mm_Vertical" H 4900 2250 50  0001 C CNN
F 3 "~" H 4900 2250 50  0001 C CNN
	1    4900 2250
	0    1    1    0   
$EndComp
$Comp
L Device:D D3
U 1 1 6175EAF8
P 9850 5000
F 0 "D3" V 9804 5080 50  0000 L CNN
F 1 "D" V 9895 5080 50  0000 L CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 9850 5000 50  0001 C CNN
F 3 "~" H 9850 5000 50  0001 C CNN
	1    9850 5000
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0123
U 1 1 6175FF7A
P 9850 4750
F 0 "#PWR0123" H 9850 4600 50  0001 C CNN
F 1 "+5V" H 9865 4923 50  0000 C CNN
F 2 "" H 9850 4750 50  0001 C CNN
F 3 "" H 9850 4750 50  0001 C CNN
	1    9850 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 4850 9850 4750
Wire Wire Line
	9850 5150 9850 5250
Wire Wire Line
	4900 2050 4900 1950
Wire Wire Line
	4900 1950 5300 1950
Wire Wire Line
	5300 1950 5300 1500
Wire Wire Line
	4800 2050 4800 1950
Wire Wire Line
	4400 1950 4400 2050
Wire Wire Line
	4400 1950 4800 1950
Wire Wire Line
	4400 1750 4400 1950
Connection ~ 4400 1950
$Comp
L symbols:LM340MP U1
U 1 1 617D50E9
P 4000 6000
F 0 "U1" H 4000 6565 50  0000 C CNN
F 1 "LM340MP" H 4000 6474 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 4000 6000 50  0001 C CNN
F 3 "" H 4000 6000 50  0001 C CNN
	1    4000 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 617E0776
P 4500 6300
F 0 "#PWR0124" H 4500 6050 50  0001 C CNN
F 1 "GND" H 4505 6127 50  0000 C CNN
F 2 "" H 4500 6300 50  0001 C CNN
F 3 "" H 4500 6300 50  0001 C CNN
	1    4500 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 6300 3500 6200
Wire Wire Line
	3500 6200 3600 6200
Wire Wire Line
	4400 6200 4500 6200
Wire Wire Line
	4500 6200 4500 6300
Wire Wire Line
	2150 4100 2250 4100
$EndSCHEMATC

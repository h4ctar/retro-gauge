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
L symbols:VIM878 U?
U 1 1 613313D6
P 6500 3300
F 0 "U?" H 6525 4375 50  0000 C CNN
F 1 "VIM878" H 6525 4284 50  0000 C CNN
F 2 "" H 6500 3200 50  0001 C CNN
F 3 "" H 6500 3200 50  0001 C CNN
	1    6500 3300
	1    0    0    -1  
$EndComp
Text Label 2550 3800 2    50   ~ 0
COM0
Text Label 2550 3900 2    50   ~ 0
COM1
Text Label 3750 3900 0    50   ~ 0
COM2
Text Label 5950 4050 2    50   ~ 0
COM0
Text Label 5950 4150 2    50   ~ 0
COM1
Text Label 7100 4150 0    50   ~ 0
COM2
Text Label 2550 2800 2    50   ~ 0
SEG1
Text Label 2550 2700 2    50   ~ 0
SEG3
$Comp
L symbols:HT1621D U?
U 1 1 61336984
P 3150 3250
F 0 "U?" H 3150 4165 50  0000 C CNN
F 1 "HT1621D" H 3150 4074 50  0000 C CNN
F 2 "" H 3150 3000 50  0001 C CNN
F 3 "" H 3150 3000 50  0001 C CNN
	1    3150 3250
	1    0    0    -1  
$EndComp
Text Label 2550 2600 2    50   ~ 0
SEG5
Text Label 3750 2600 0    50   ~ 0
SEG7
Text Label 3750 2700 0    50   ~ 0
SEG9
Text Label 3750 2800 0    50   ~ 0
SEG11
Text Label 3750 2900 0    50   ~ 0
SEG13
Text Label 3750 3000 0    50   ~ 0
SEG15
Text Label 3750 3100 0    50   ~ 0
SEG17
Text Label 3750 3200 0    50   ~ 0
SEG19
Text Label 3750 3300 0    50   ~ 0
SEG21
Text Label 3750 3400 0    50   ~ 0
SEG23
Text Label 3750 3500 0    50   ~ 0
SEG25
Text Label 3750 3600 0    50   ~ 0
SEG27
Text Label 3750 3700 0    50   ~ 0
SEG29
Text Label 3750 3800 0    50   ~ 0
SEG31
Text Label 5950 2450 2    50   ~ 0
SEG1
Text Label 5950 2550 2    50   ~ 0
SEG3
Text Label 5950 2650 2    50   ~ 0
SEG5
Text Label 5950 2750 2    50   ~ 0
SEG7
Text Label 5950 2850 2    50   ~ 0
SEG9
Text Label 5950 2950 2    50   ~ 0
SEG11
Text Label 5950 3050 2    50   ~ 0
SEG13
Text Label 5950 3150 2    50   ~ 0
SEG15
Text Label 5950 3250 2    50   ~ 0
SEG17
Text Label 5950 3350 2    50   ~ 0
SEG19
Text Label 5950 3450 2    50   ~ 0
SEG21
Text Label 5950 3550 2    50   ~ 0
SEG23
Text Label 5950 3650 2    50   ~ 0
SEG25
Text Label 5950 3750 2    50   ~ 0
SEG27
Text Label 5950 3850 2    50   ~ 0
SEG29
Text Label 5950 3950 2    50   ~ 0
SEG31
$Comp
L power:+5V #PWR?
U 1 1 61342B8E
P 1800 3300
F 0 "#PWR?" H 1800 3150 50  0001 C CNN
F 1 "+5V" H 1815 3473 50  0000 C CNN
F 2 "" H 1800 3300 50  0001 C CNN
F 3 "" H 1800 3300 50  0001 C CNN
	1    1800 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3400 1800 3400
Wire Wire Line
	2550 3500 1800 3500
Wire Wire Line
	1800 3500 1800 3400
Connection ~ 1800 3400
Wire Wire Line
	1800 3300 1800 3400
$Comp
L power:GND #PWR?
U 1 1 61343D3F
P 2450 3300
F 0 "#PWR?" H 2450 3050 50  0001 C CNN
F 1 "GND" V 2455 3172 50  0000 R CNN
F 2 "" H 2450 3300 50  0001 C CNN
F 3 "" H 2450 3300 50  0001 C CNN
	1    2450 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 3300 2550 3300
Text GLabel 1450 2550 0    50   Input ~ 0
LCD_WR
Text GLabel 1450 2750 0    50   Input ~ 0
LCD_DATA
Wire Wire Line
	2550 3100 2100 3100
Wire Wire Line
	2100 3100 2100 2550
Wire Wire Line
	2100 2550 1450 2550
Wire Wire Line
	1450 2750 2000 2750
Wire Wire Line
	2000 2750 2000 3200
Wire Wire Line
	2000 3200 2550 3200
Wire Wire Line
	2200 2900 2550 2900
Wire Wire Line
	2200 2350 2200 2900
Wire Wire Line
	1450 2350 2200 2350
Text GLabel 1450 2350 0    50   Input ~ 0
LCD_CS
$EndSCHEMATC

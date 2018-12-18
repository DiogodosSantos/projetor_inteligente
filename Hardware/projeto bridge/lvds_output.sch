EESchema Schematic File Version 2
LIBS:dsi_to_lvds_bridge-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:QSH-060-01-X-D-A - femea eagle
LIBS:dsi_to_lvds_bridge-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
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
L CONN_01X15 J7
U 1 1 59554DA7
P 4200 2350
F 0 "J7" H 4200 3150 50  0000 C CNN
F 1 "LVDS_A" V 4300 2350 50  0000 C CNN
F 2 "molex:052271-1579" H 4200 2350 50  0001 C CNN
F 3 "" H 4200 2350 50  0001 C CNN
	1    4200 2350
	1    0    0    1   
$EndComp
$Comp
L CONN_01X15 J8
U 1 1 59554E72
P 7000 2350
F 0 "J8" H 7000 3150 50  0000 C CNN
F 1 "LVDS_B" V 7100 2350 50  0000 C CNN
F 2 "molex:052271-1579" H 7000 2350 50  0001 C CNN
F 3 "" H 7000 2350 50  0001 C CNN
	1    7000 2350
	1    0    0    1   
$EndComp
Text GLabel 3350 1650 0    60   Input ~ 0
LVDS_A0_N
Text GLabel 3350 1750 0    60   Input ~ 0
LVDS_A0_P
Text GLabel 3350 1950 0    60   Input ~ 0
LVDS_A1_N
Text GLabel 3350 2050 0    60   Input ~ 0
LVDS_A1_P
Text GLabel 3350 2250 0    60   Input ~ 0
LVDS_A2_N
Text GLabel 3350 2350 0    60   Input ~ 0
LVDS_A2_P
Text GLabel 3350 2550 0    60   Input ~ 0
LVDS_ACLK_N
Text GLabel 3350 2650 0    60   Input ~ 0
LVDS_ACLK_P
Text GLabel 3350 2850 0    60   Input ~ 0
LVDS_A3_N
Text GLabel 3350 2950 0    60   Input ~ 0
LVDS_A3_P
Text GLabel 6150 1650 0    60   Input ~ 0
LVDS_B0_N
Text GLabel 6150 1750 0    60   Input ~ 0
LVDS_B0_P
Text GLabel 6150 1950 0    60   Input ~ 0
LVDS_B1_N
Text GLabel 6150 2050 0    60   Input ~ 0
LVDS_B1_P
Text GLabel 6150 2250 0    60   Input ~ 0
LVDS_B2_N
Text GLabel 6150 2350 0    60   Input ~ 0
LVDS_B2_P
Text GLabel 6150 2550 0    60   Input ~ 0
LVDS_BCLK_N
Text GLabel 6150 2650 0    60   Input ~ 0
LVDS_BCLK_P
Text GLabel 6150 2850 0    60   Input ~ 0
LVDS_B3_N
Text GLabel 6150 2950 0    60   Input ~ 0
LVDS_B3_P
Wire Wire Line
	4000 1650 3350 1650
Wire Wire Line
	3350 1750 4000 1750
Wire Wire Line
	4000 1950 3350 1950
Wire Wire Line
	3350 2050 4000 2050
Wire Wire Line
	4000 2250 3350 2250
Wire Wire Line
	3350 2350 4000 2350
Wire Wire Line
	4000 2550 3350 2550
Wire Wire Line
	3350 2650 4000 2650
Wire Wire Line
	4000 2850 3350 2850
Wire Wire Line
	3350 2950 4000 2950
Wire Wire Line
	6800 1650 6150 1650
Wire Wire Line
	6150 1750 6800 1750
Wire Wire Line
	6800 1950 6150 1950
Wire Wire Line
	6150 2050 6800 2050
Wire Wire Line
	6800 2250 6150 2250
Wire Wire Line
	6150 2350 6800 2350
Wire Wire Line
	6800 2550 6150 2550
Wire Wire Line
	6150 2650 6800 2650
Wire Wire Line
	6800 2850 6150 2850
Wire Wire Line
	6150 2950 6800 2950
$Comp
L GND #PWR033
U 1 1 59555638
P 3850 3200
F 0 "#PWR033" H 3850 2950 50  0001 C CNN
F 1 "GND" H 3850 3050 50  0000 C CNN
F 2 "" H 3850 3200 50  0001 C CNN
F 3 "" H 3850 3200 50  0001 C CNN
	1    3850 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3200 3850 1850
Wire Wire Line
	3850 1850 4000 1850
Wire Wire Line
	4000 2150 3850 2150
Connection ~ 3850 2150
Wire Wire Line
	4000 2450 3850 2450
Connection ~ 3850 2450
Wire Wire Line
	4000 2750 3850 2750
Connection ~ 3850 2750
NoConn ~ 4000 3050
$Comp
L GND #PWR034
U 1 1 595557A7
P 6650 3200
F 0 "#PWR034" H 6650 2950 50  0001 C CNN
F 1 "GND" H 6650 3050 50  0000 C CNN
F 2 "" H 6650 3200 50  0001 C CNN
F 3 "" H 6650 3200 50  0001 C CNN
	1    6650 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 3200 6650 1850
Wire Wire Line
	6650 1850 6800 1850
Wire Wire Line
	6800 2450 6650 2450
Connection ~ 6650 2450
Wire Wire Line
	6800 2750 6650 2750
Connection ~ 6650 2750
NoConn ~ 6800 3050
Wire Wire Line
	6800 2150 6650 2150
Connection ~ 6650 2150
$EndSCHEMATC

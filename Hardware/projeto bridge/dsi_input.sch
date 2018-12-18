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
Sheet 2 3
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
L QSH-060-01-X-D-A J6
U 1 1 5954F33C
P 3250 1900
AR Path="/5954F33C" Ref="J6"  Part="1" 
AR Path="/5954EFC1/5954F33C" Ref="J6"  Part="1" 
F 0 "J6" H 3250 3850 60  0000 C CNN
F 1 "QSH-060-01-X-D-A" H 3250 3750 60  0000 C CNN
F 2 "samtec:QSH-060-01-X-D-A" H 3400 3600 60  0001 C CNN
F 3 "" H 3400 3600 60  0001 C CNN
	1    3250 1900
	1    0    0    -1  
$EndComp
$Comp
L QSH-060-01-X-D-A J6
U 2 1 5954F395
P 7600 1900
AR Path="/5954F395" Ref="J6"  Part="2" 
AR Path="/5954EFC1/5954F395" Ref="J6"  Part="2" 
F 0 "J6" H 7600 3850 60  0000 C CNN
F 1 "QSH-060-01-X-D-A" H 7600 3750 60  0000 C CNN
F 2 "samtec:QSH-060-01-X-D-A" H 7750 3600 60  0001 C CNN
F 3 "" H 7750 3600 60  0001 C CNN
	2    7600 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR027
U 1 1 5954F41C
P 2950 5400
F 0 "#PWR027" H 2950 5150 50  0001 C CNN
F 1 "GND" H 2950 5250 50  0000 C CNN
F 2 "" H 2950 5400 50  0001 C CNN
F 3 "" H 2950 5400 50  0001 C CNN
	1    2950 5400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 5954F470
P 4150 5400
F 0 "#PWR028" H 4150 5150 50  0001 C CNN
F 1 "GND" H 4150 5250 50  0000 C CNN
F 2 "" H 4150 5400 50  0001 C CNN
F 3 "" H 4150 5400 50  0001 C CNN
	1    4150 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 4200 4150 5400
Wire Wire Line
	3050 5100 2950 5100
Wire Wire Line
	2950 2100 2950 5400
Wire Wire Line
	3050 5200 2950 5200
Connection ~ 2950 5200
Wire Wire Line
	3050 4800 2950 4800
Connection ~ 2950 5100
Wire Wire Line
	3050 2100 2950 2100
Connection ~ 2950 4800
Wire Wire Line
	3050 2400 2950 2400
Connection ~ 2950 2400
Wire Wire Line
	3050 2700 2950 2700
Connection ~ 2950 2700
Wire Wire Line
	3050 3000 2950 3000
Connection ~ 2950 3000
Wire Wire Line
	3050 3300 2950 3300
Connection ~ 2950 3300
Wire Wire Line
	3050 3600 2950 3600
Connection ~ 2950 3600
Wire Wire Line
	3050 3900 2950 3900
Connection ~ 2950 3900
Wire Wire Line
	3050 4200 2950 4200
Connection ~ 2950 4200
Wire Wire Line
	3050 4500 2950 4500
Connection ~ 2950 4500
Wire Wire Line
	4050 4200 4150 4200
Wire Wire Line
	4050 4400 4150 4400
Connection ~ 4150 4400
Wire Wire Line
	4050 4800 4150 4800
Connection ~ 4150 4800
$Comp
L GND #PWR029
U 1 1 5954F76A
P 7300 5400
F 0 "#PWR029" H 7300 5150 50  0001 C CNN
F 1 "GND" H 7300 5250 50  0000 C CNN
F 2 "" H 7300 5400 50  0001 C CNN
F 3 "" H 7300 5400 50  0001 C CNN
	1    7300 5400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR030
U 1 1 5954F770
P 8500 5400
F 0 "#PWR030" H 8500 5150 50  0001 C CNN
F 1 "GND" H 8500 5250 50  0000 C CNN
F 2 "" H 8500 5400 50  0001 C CNN
F 3 "" H 8500 5400 50  0001 C CNN
	1    8500 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 5100 7300 5100
Wire Wire Line
	7300 2100 7300 5400
Wire Wire Line
	7400 5200 7300 5200
Connection ~ 7300 5200
Wire Wire Line
	7400 2100 7300 2100
Connection ~ 7300 5100
Wire Wire Line
	7400 2200 7300 2200
Connection ~ 7300 2200
Wire Wire Line
	5950 2500 7400 2500
Connection ~ 7300 2500
Wire Wire Line
	7400 2600 7300 2600
Connection ~ 7300 2600
Wire Wire Line
	7400 2900 7300 2900
Connection ~ 7300 2900
Wire Wire Line
	7400 3000 7300 3000
Connection ~ 7300 3000
Wire Wire Line
	7400 3400 7300 3400
Connection ~ 7300 3400
Wire Wire Line
	7400 3700 7300 3700
Connection ~ 7300 3700
Wire Wire Line
	7400 4000 7300 4000
Connection ~ 7300 4000
Wire Wire Line
	7400 4300 7300 4300
Connection ~ 7300 4300
Wire Wire Line
	7400 4600 7300 4600
Connection ~ 7300 4600
Wire Wire Line
	8500 2300 8500 5400
Wire Wire Line
	8400 2300 8500 2300
Wire Wire Line
	8400 2600 8500 2600
Connection ~ 8500 2600
Wire Wire Line
	8400 2700 8500 2700
Connection ~ 8500 2700
Wire Wire Line
	8400 3300 8500 3300
Connection ~ 8500 3300
Wire Wire Line
	8400 3600 8500 3600
Connection ~ 8500 3600
Wire Wire Line
	8400 3900 8500 3900
Connection ~ 8500 3900
Wire Wire Line
	8400 4400 8500 4400
Connection ~ 8500 4400
Text GLabel 2100 2800 0    60   Input ~ 0
DSI_B1_N
Text GLabel 2100 2900 0    60   Input ~ 0
DSI_B1_P
Text GLabel 2100 3100 0    60   Input ~ 0
DSI_B0_N
Text GLabel 2100 3200 0    60   Input ~ 0
DSI_B0_P
Text GLabel 2100 2500 0    60   Input ~ 0
DSI_BCLK_N
Text GLabel 2100 2600 0    60   Input ~ 0
DSI_BCLK_P
Text GLabel 2100 2200 0    60   Input ~ 0
DSI_B2_N
Text GLabel 2100 2300 0    60   Input ~ 0
DSI_B2_P
Text GLabel 2100 1900 0    60   Input ~ 0
DSI_B3_N
Text GLabel 2100 2000 0    60   Input ~ 0
DSI_B3_P
Text GLabel 2100 4300 0    60   Input ~ 0
DSI_A1_N
Text GLabel 2100 4400 0    60   Input ~ 0
DSI_A1_P
Text GLabel 2100 4600 0    60   Input ~ 0
DSI_A0_N
Text GLabel 2100 4700 0    60   Input ~ 0
DSI_A0_P
Text GLabel 2100 4000 0    60   Input ~ 0
DSI_ACLK_N
Text GLabel 2100 4100 0    60   Input ~ 0
DSI_ACLK_P
Text GLabel 2100 3700 0    60   Input ~ 0
DSI_A2_N
Text GLabel 2100 3800 0    60   Input ~ 0
DSI_A2_P
Text GLabel 2100 3400 0    60   Input ~ 0
DSI_A3_N
Text GLabel 2100 3500 0    60   Input ~ 0
DSI_A3_P
Wire Wire Line
	2100 3500 3050 3500
Wire Wire Line
	2100 3400 3050 3400
Wire Wire Line
	2100 3200 3050 3200
Wire Wire Line
	2100 3100 3050 3100
Wire Wire Line
	2100 2900 3050 2900
Wire Wire Line
	2100 2800 3050 2800
Wire Wire Line
	2100 2600 3050 2600
Wire Wire Line
	2100 2500 3050 2500
Wire Wire Line
	2100 2300 3050 2300
Wire Wire Line
	2100 2200 3050 2200
Wire Wire Line
	2100 2000 3050 2000
Wire Wire Line
	2100 1900 3050 1900
$Comp
L +3V3 #PWR031
U 1 1 59551325
P 7100 1700
F 0 "#PWR031" H 7100 1550 50  0001 C CNN
F 1 "+3V3" H 7100 1840 50  0000 C CNN
F 2 "" H 7100 1700 50  0001 C CNN
F 3 "" H 7100 1700 50  0001 C CNN
	1    7100 1700
	1    0    0    -1  
$EndComp
$Comp
L +1V8_INPUT #PWR032
U 1 1 59551345
P 6650 1700
F 0 "#PWR032" H 6650 1550 50  0001 C CNN
F 1 "+1V8_INPUT" H 6650 1840 50  0000 C CNN
F 2 "" H 6650 1700 50  0001 C CNN
F 3 "" H 6650 1700 50  0001 C CNN
	1    6650 1700
	1    0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 595513E5
P 5950 2250
F 0 "C15" H 5975 2350 50  0000 L CNN
F 1 "10µF" H 5975 2150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5988 2100 50  0001 C CNN
F 3 "" H 5950 2250 50  0001 C CNN
	1    5950 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2000 7100 2000
Wire Wire Line
	7100 2000 7100 1700
Wire Wire Line
	6300 1900 7400 1900
Connection ~ 7100 1900
Wire Wire Line
	7400 2300 6650 2300
Wire Wire Line
	6650 1700 6650 2400
Wire Wire Line
	6650 2400 7400 2400
Connection ~ 6650 2300
$Comp
L C C16
U 1 1 5955179D
P 6300 2250
F 0 "C16" H 6325 2350 50  0000 L CNN
F 1 "10µF" H 6325 2150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6338 2100 50  0001 C CNN
F 3 "" H 6300 2250 50  0001 C CNN
	1    6300 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2100 6300 1900
Wire Wire Line
	6650 2000 5950 2000
Wire Wire Line
	5950 2000 5950 2100
Connection ~ 6650 2000
Wire Wire Line
	5950 2500 5950 2400
Wire Wire Line
	6300 2400 6300 2500
Connection ~ 6300 2500
NoConn ~ 7400 2700
NoConn ~ 7400 2800
NoConn ~ 7400 3100
NoConn ~ 7400 3200
NoConn ~ 7400 3300
NoConn ~ 7400 3500
NoConn ~ 7400 3600
NoConn ~ 7400 3800
NoConn ~ 7400 3900
NoConn ~ 7400 4100
NoConn ~ 7400 4200
NoConn ~ 7400 4400
NoConn ~ 7400 4500
NoConn ~ 7400 4700
NoConn ~ 7400 4800
NoConn ~ 8400 4800
NoConn ~ 8400 4700
NoConn ~ 8400 4600
NoConn ~ 8400 4500
NoConn ~ 8400 4300
NoConn ~ 8400 4200
NoConn ~ 8400 4100
NoConn ~ 8400 4000
Wire Wire Line
	2100 3800 3050 3800
Wire Wire Line
	2100 3700 3050 3700
Wire Wire Line
	2100 4100 3050 4100
Wire Wire Line
	2100 4000 3050 4000
Wire Wire Line
	2100 4400 3050 4400
Wire Wire Line
	2100 4300 3050 4300
Wire Wire Line
	2100 4700 3050 4700
Wire Wire Line
	2100 4600 3050 4600
$Comp
L CONN_01X01 H5
U 1 1 59557C9B
P 3600 1200
F 0 "H5" H 3600 1300 50  0000 C CNN
F 1 "4.24" V 3700 1200 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_4.3mm_M4_Pad" H 3600 1200 50  0001 C CNN
F 3 "" H 3600 1200 50  0001 C CNN
	1    3600 1200
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X01 H6
U 1 1 59557E67
P 7950 5550
F 0 "H6" H 7950 5650 50  0000 C CNN
F 1 "4.24" V 8050 5550 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_4.3mm_M4_Pad" H 7950 5550 50  0001 C CNN
F 3 "" H 7950 5550 50  0001 C CNN
	1    7950 5550
	0    -1   -1   0   
$EndComp
NoConn ~ 3600 1400
NoConn ~ 7950 5750
Text Notes 7050 6700 0    60   ~ 0
Note: 54mm between screw holes
NoConn ~ 4050 4700
NoConn ~ 4050 4600
NoConn ~ 4050 4500
NoConn ~ 4050 4300
NoConn ~ 4050 4100
NoConn ~ 4050 4000
NoConn ~ 4050 3900
NoConn ~ 4050 3800
NoConn ~ 4050 3700
NoConn ~ 4050 3600
NoConn ~ 4050 3500
NoConn ~ 4050 3400
NoConn ~ 4050 3300
NoConn ~ 4050 3200
NoConn ~ 4050 3100
NoConn ~ 4050 2800
NoConn ~ 4050 2700
NoConn ~ 4050 2600
NoConn ~ 4050 2500
NoConn ~ 4050 2400
NoConn ~ 4050 2300
NoConn ~ 4050 2200
NoConn ~ 4050 2100
NoConn ~ 4050 2000
NoConn ~ 4050 1900
NoConn ~ 8400 1900
NoConn ~ 8400 2000
NoConn ~ 8400 2100
NoConn ~ 8400 2200
NoConn ~ 8400 2400
NoConn ~ 8400 2500
NoConn ~ 8400 2800
NoConn ~ 8400 2900
NoConn ~ 8400 3000
NoConn ~ 8400 3100
NoConn ~ 8400 3200
NoConn ~ 8400 3400
NoConn ~ 8400 3500
NoConn ~ 8400 3800
Text GLabel 5000 2900 2    60   Input ~ 0
I2C_SCL
Text GLabel 5000 3000 2    60   Input ~ 0
I2C_SDA
$Comp
L R R23
U 1 1 5956C0FD
P 4650 2900
F 0 "R23" V 4700 3150 50  0000 C CNN
F 1 "0" V 4650 2900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4580 2900 50  0001 C CNN
F 3 "" H 4650 2900 50  0001 C CNN
	1    4650 2900
	0    -1   -1   0   
$EndComp
$Comp
L R R24
U 1 1 5956C103
P 4650 3000
F 0 "R24" V 4700 2750 50  0000 C CNN
F 1 "0" V 4650 3000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 4580 3000 50  0001 C CNN
F 3 "" H 4650 3000 50  0001 C CNN
	1    4650 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 3000 4500 3000
Wire Wire Line
	4500 2900 4050 2900
Wire Wire Line
	5000 3000 4800 3000
Wire Wire Line
	4800 2900 5000 2900
Text GLabel 9350 3700 2    60   Input ~ 0
IRQ
$Comp
L R R25
U 1 1 5956FACF
P 9000 3700
F 0 "R25" V 9100 3700 50  0000 C CNN
F 1 "0" V 9000 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 8930 3700 50  0001 C CNN
F 3 "" H 9000 3700 50  0001 C CNN
	1    9000 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8850 3700 8400 3700
Wire Wire Line
	9150 3700 9350 3700
Text Label 2650 1900 0    60   ~ 0
D_B3_N
Text Label 2650 2000 0    60   ~ 0
D_B3_P
Text Label 2650 2200 0    60   ~ 0
D_B2_N
Text Label 2650 2500 0    60   ~ 0
D_BCLK_N
Text Label 2650 2800 0    60   ~ 0
D_B1_N
Text Label 2650 3100 0    60   ~ 0
D_B0_N
Text Label 2650 2300 0    60   ~ 0
D_B2_P
Text Label 2650 2600 0    60   ~ 0
D_BCLK_P
Text Label 2650 2900 0    60   ~ 0
D_B1_P
Text Label 2650 3200 0    60   ~ 0
D_B0_P
Wire Wire Line
	3050 5300 2950 5300
Connection ~ 2950 5300
Wire Wire Line
	3050 5000 2950 5000
Connection ~ 2950 5000
Wire Wire Line
	7400 5000 7300 5000
Connection ~ 7300 5000
Wire Wire Line
	7400 5300 7300 5300
Connection ~ 7300 5300
$EndSCHEMATC

EESchema Schematic File Version 2
LIBS:ESP32-footprints-Shem-Lib
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
LIBS:SamacSys_Parts
LIBS:Whale_Gosth-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Whale_Gosth"
Date "2017-03-28"
Rev "2.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +24V #PWR01
U 1 1 5A786DA5
P 1700 750
F 0 "#PWR01" H 1700 600 50  0001 C CNN
F 1 "+24V" H 1700 890 50  0000 C CNN
F 2 "" H 1700 750 50  0001 C CNN
F 3 "" H 1700 750 50  0001 C CNN
	1    1700 750 
	1    0    0    -1  
$EndComp
$Comp
L Screw_Terminal_1x04 Buck_converter1
U 1 1 5A786E13
P 2000 7350
F 0 "Buck_converter1" H 2000 7800 50  0000 C TNN
F 1 "BUCK-CONVERTER1" V 1850 7350 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-4_P5.08mm" H 2000 6925 50  0001 C CNN
F 3 "" H 1975 7550 50  0001 C CNN
	1    2000 7350
	0    -1   -1   0   
$EndComp
NoConn ~ 13200 3550
Text Notes 3000 2400 0    60   ~ 0
3V3
Text Notes 3000 2500 0    60   ~ 0
EN
Text Notes 3000 2600 0    60   ~ 0
SVP
Text Notes 3000 2700 0    60   ~ 0
SVN
Text Notes 3000 2800 0    60   ~ 0
IO34
Text Notes 3000 2900 0    60   ~ 0
IO35
Text Notes 3000 3000 0    60   ~ 0
IO32
Text Notes 3000 3100 0    60   ~ 0
IO33
Text Notes 3000 3200 0    60   ~ 0
IO25
Text Notes 3000 3300 0    60   ~ 0
IO26
Text Notes 3000 3400 0    60   ~ 0
IO27
Text Notes 3000 3500 0    60   ~ 0
IO14
Text Notes 3000 3600 0    60   ~ 0
IO12
Text Notes 3000 3700 0    60   ~ 0
GND
Text Notes 3000 3800 0    60   ~ 0
IO13
Text Notes 3000 3900 0    60   ~ 0
SD2
Text Notes 3000 4000 0    60   ~ 0
SD3
Text Notes 3000 4100 0    60   ~ 0
CMD
Text Notes 3000 4200 0    60   ~ 0
5V
$Comp
L CONN_01X19 ESP-G1
U 1 1 5A788AA6
P 2850 3250
F 0 "ESP-G1" H 2850 4250 50  0000 C CNN
F 1 "ESP32-G" V 2950 3250 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x19_Pitch2.54mm" H 2850 3250 50  0001 C CNN
F 3 "" H 2850 3250 50  0001 C CNN
	1    2850 3250
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X19 ESP-D1
U 1 1 5A788AEB
P 4000 3250
F 0 "ESP-D1" H 4000 4250 50  0000 C CNN
F 1 "ESP32-D" V 4100 3250 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x19_Pitch2.54mm" H 4000 3250 50  0001 C CNN
F 3 "" H 4000 3250 50  0001 C CNN
	1    4000 3250
	-1   0    0    -1  
$EndComp
Text Notes 3850 2400 2    60   ~ 0
GND
Text Notes 3850 2500 2    60   ~ 0
IO23
Text Notes 3850 2600 2    60   ~ 0
IO22
Text Notes 3850 2700 2    60   ~ 0
TXD0
Text Notes 3850 2800 2    60   ~ 0
RXD0
Text Notes 3850 2900 2    60   ~ 0
IO21
Text Notes 3850 3000 2    60   ~ 0
GND
Text Notes 3850 3100 2    60   ~ 0
IO19
Text Notes 3850 3200 2    60   ~ 0
IO18
Text Notes 3850 3300 2    60   ~ 0
IO5
Text Notes 3850 3400 2    60   ~ 0
IO17
Text Notes 3850 3500 2    60   ~ 0
IO16
Text Notes 3850 3600 2    60   ~ 0
IO4
Text Notes 3850 3700 2    60   ~ 0
IO0
Text Notes 3850 3800 2    60   ~ 0
IO2
Text Notes 3850 3900 2    60   ~ 0
IO15
Text Notes 3850 4000 2    60   ~ 0
SD1
Text Notes 3850 4100 2    60   ~ 0
SD0
Text Notes 3850 4200 2    60   ~ 0
CLK
Text GLabel 4500 2450 2    60   BiDi ~ 0
WS0
Text GLabel 1550 6450 3    60   BiDi ~ 0
WS0
Text GLabel 2550 6450 3    60   BiDi ~ 0
WS1
Text GLabel 3550 6450 3    60   BiDi ~ 0
WS2
Text GLabel 4550 6450 3    60   BiDi ~ 0
WS3
Text GLabel 5550 6450 3    60   BiDi ~ 0
WS4
Text GLabel 6550 6450 3    60   BiDi ~ 0
WS5
Text GLabel 4500 2550 2    60   BiDi ~ 0
WS1
Text GLabel 4500 2850 2    60   BiDi ~ 0
WS4
Text GLabel 4500 3050 2    60   BiDi ~ 0
WS5
Text GLabel 4500 3150 2    60   BiDi ~ 0
WS2
Text GLabel 4500 3250 2    60   BiDi ~ 0
WS3
$Comp
L CONN_01X29 PIN-NO-USE1
U 1 1 5A78AB55
P 6150 2550
F 0 "PIN-NO-USE1" H 6150 4050 50  0000 C CNN
F 1 "PIN-NO-USE" V 6250 2550 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x29_Pitch2.54mm" H 6150 2550 50  0001 C CNN
F 3 "" H 6150 2550 50  0001 C CNN
	1    6150 2550
	-1   0    0    -1  
$EndComp
Text GLabel 6700 1150 2    60   BiDi ~ 0
3V3
Text GLabel 6700 1250 2    60   BiDi ~ 0
EN
Text GLabel 6700 1350 2    60   BiDi ~ 0
SVP
Text GLabel 6700 1550 2    60   BiDi ~ 0
IO34
Text GLabel 6700 1650 2    60   BiDi ~ 0
IO35
Text GLabel 6700 1750 2    60   BiDi ~ 0
IO32
Text GLabel 6700 1850 2    60   BiDi ~ 0
IO33
Text GLabel 6700 1950 2    60   BiDi ~ 0
IO25
Text GLabel 6700 2050 2    60   BiDi ~ 0
IO26
Text GLabel 6700 2150 2    60   BiDi ~ 0
IO27
Text GLabel 6700 2250 2    60   BiDi ~ 0
IO14
Text GLabel 6700 2350 2    60   BiDi ~ 0
IO12
Text GLabel 6700 2450 2    60   BiDi ~ 0
IO13
Text GLabel 6700 2550 2    60   BiDi ~ 0
SD2
Text GLabel 6700 2650 2    60   BiDi ~ 0
SD3
Text GLabel 6700 2750 2    60   BiDi ~ 0
CMD
Text GLabel 6700 2850 2    60   BiDi ~ 0
TXDO
Text GLabel 6700 2950 2    60   BiDi ~ 0
RXD0
Text GLabel 6700 3050 2    60   BiDi ~ 0
GND
Text GLabel 6700 3150 2    60   BiDi ~ 0
IO17
Text GLabel 6700 3250 2    60   BiDi ~ 0
IO16
Text GLabel 6700 3350 2    60   BiDi ~ 0
IO4
Text GLabel 6700 3450 2    60   BiDi ~ 0
IO0
Text GLabel 6700 3550 2    60   BiDi ~ 0
IO2
Text GLabel 6700 3650 2    60   BiDi ~ 0
IO15
Text GLabel 6700 3750 2    60   BiDi ~ 0
SD1
Text GLabel 6700 3850 2    60   BiDi ~ 0
SD0
Text GLabel 6700 3950 2    60   BiDi ~ 0
CLK
Text GLabel 6700 1450 2    60   BiDi ~ 0
SVN
Text GLabel 2550 2350 0    60   BiDi ~ 0
3V3
Text GLabel 2550 2450 0    60   BiDi ~ 0
EN
Text GLabel 2550 2550 0    60   BiDi ~ 0
SVP
Text GLabel 2550 2750 0    60   BiDi ~ 0
IO34
Text GLabel 2550 2850 0    60   BiDi ~ 0
IO35
Text GLabel 2550 2950 0    60   BiDi ~ 0
IO32
Text GLabel 2550 3050 0    60   BiDi ~ 0
IO33
Text GLabel 2550 3150 0    60   BiDi ~ 0
IO25
Text GLabel 2550 3250 0    60   BiDi ~ 0
IO26
Text GLabel 2550 3350 0    60   BiDi ~ 0
IO27
Text GLabel 2550 3450 0    60   BiDi ~ 0
IO14
Text GLabel 2550 3550 0    60   BiDi ~ 0
IO12
Text GLabel 2550 3750 0    60   BiDi ~ 0
IO13
Text GLabel 2550 3850 0    60   BiDi ~ 0
SD2
Text GLabel 2550 3950 0    60   BiDi ~ 0
SD3
Text GLabel 2550 4050 0    60   BiDi ~ 0
CMD
Text GLabel 4300 2650 2    60   BiDi ~ 0
TXDO
Text GLabel 4300 2750 2    60   BiDi ~ 0
RXD0
Text GLabel 4300 2950 2    60   BiDi ~ 0
GND
Text GLabel 4300 3350 2    60   BiDi ~ 0
IO17
Text GLabel 4300 3450 2    60   BiDi ~ 0
IO16
Text GLabel 4300 3550 2    60   BiDi ~ 0
IO4
Text GLabel 4300 3650 2    60   BiDi ~ 0
IO0
Text GLabel 4300 3750 2    60   BiDi ~ 0
IO2
Text GLabel 4300 3850 2    60   BiDi ~ 0
IO15
Text GLabel 4300 3950 2    60   BiDi ~ 0
SD1
Text GLabel 4300 4050 2    60   BiDi ~ 0
SD0
Text GLabel 4300 4150 2    60   BiDi ~ 0
CLK
Text GLabel 2550 2650 0    60   BiDi ~ 0
SVN
$Comp
L GND #PWR02
U 1 1 5A78ED88
P 2000 4750
F 0 "#PWR02" H 2000 4500 50  0001 C CNN
F 1 "GND" H 2000 4600 50  0000 C CNN
F 2 "" H 2000 4750 50  0001 C CNN
F 3 "" H 2000 4750 50  0001 C CNN
	1    2000 4750
	1    0    0    -1  
$EndComp
$Comp
L Screw_Terminal_1x03 WS_0
U 1 1 5A796D5D
P 1550 5900
F 0 "WS_0" H 1550 6250 50  0000 C TNN
F 1 "Screw_Terminal_1x03" V 1400 5900 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-3_P5.08mm" H 1550 5575 50  0001 C CNN
F 3 "" H 1525 6000 50  0001 C CNN
	1    1550 5900
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x03 WS_1
U 1 1 5A796DAB
P 2550 5900
F 0 "WS_1" H 2550 6250 50  0000 C TNN
F 1 "Screw_Terminal_1x03" V 2400 5900 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-3_P5.08mm" H 2550 5575 50  0001 C CNN
F 3 "" H 2525 6000 50  0001 C CNN
	1    2550 5900
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x03 WS_2
U 1 1 5A796DE4
P 3550 5900
F 0 "WS_2" H 3550 6250 50  0000 C TNN
F 1 "Screw_Terminal_1x03" V 3400 5900 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-3_P5.08mm" H 3550 5575 50  0001 C CNN
F 3 "" H 3525 6000 50  0001 C CNN
	1    3550 5900
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x03 WS_3
U 1 1 5A796E37
P 4550 5900
F 0 "WS_3" H 4550 6250 50  0000 C TNN
F 1 "Screw_Terminal_1x03" V 4400 5900 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-3_P5.08mm" H 4550 5575 50  0001 C CNN
F 3 "" H 4525 6000 50  0001 C CNN
	1    4550 5900
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x03 WS_4
U 1 1 5A796E70
P 5550 5900
F 0 "WS_4" H 5550 6250 50  0000 C TNN
F 1 "Screw_Terminal_1x03" V 5400 5900 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-3_P5.08mm" H 5550 5575 50  0001 C CNN
F 3 "" H 5525 6000 50  0001 C CNN
	1    5550 5900
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x03 WS_5
U 1 1 5A796ED1
P 6550 5900
F 0 "WS_5" H 6550 6250 50  0000 C TNN
F 1 "Screw_Terminal_1x03" V 6400 5900 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-3_P5.08mm" H 6550 5575 50  0001 C CNN
F 3 "" H 6525 6000 50  0001 C CNN
	1    6550 5900
	0    1    1    0   
$EndComp
$Comp
L 1902547 OUT_24V1
U 1 1 5A799224
P 2200 1200
F 0 "OUT_24V1" H 2550 1350 50  0000 C CNN
F 1 "1902547" H 2550 950 50  0000 C CNN
F 2 "SHDR2W120P0X952_1X2_1904X1600X2150P" H 2550 850 50  0001 C CNN
F 3 "https://www.phoenixcontact.com/online/portal/us?uri=pxc-oc-itemdetail:pid=1902547" H 2550 750 50  0001 C CNN
F 4 "MKDS 5 HV /2-9,52 2way 9.52mm" H 2550 650 50  0001 C CNN "Description"
F 5 "RS" H 2550 550 50  0001 C CNN "Supplier_Name"
F 6 "8032844" H 2550 450 50  0001 C CNN "RS Part Number"
F 7 "Phoenix Contact" H 2550 350 50  0001 C CNN "Manufacturer_Name"
F 8 "1902547" H 2550 250 50  0001 C CNN "Manufacturer_Part_Number"
F 9 "" H 2550 150 50  0001 C CNN "Allied_Number"
F 10 "" H 2550 50  50  0001 C CNN "Other Part Number"
F 11 "21.5" H 2750 -50 50  0001 C CNN "Height"
	1    2200 1200
	1    0    0    -1  
$EndComp
$Comp
L 1902547 IN_24V1
U 1 1 5A7992A1
P 1200 1300
F 0 "IN_24V1" H 1550 1450 50  0000 C CNN
F 1 "1902547" H 1550 1050 50  0000 C CNN
F 2 "SHDR2W120P0X952_1X2_1904X1600X2150P" H 1550 950 50  0001 C CNN
F 3 "https://www.phoenixcontact.com/online/portal/us?uri=pxc-oc-itemdetail:pid=1902547" H 1550 850 50  0001 C CNN
F 4 "MKDS 5 HV /2-9,52 2way 9.52mm" H 1550 750 50  0001 C CNN "Description"
F 5 "RS" H 1550 650 50  0001 C CNN "Supplier_Name"
F 6 "8032844" H 1550 550 50  0001 C CNN "RS Part Number"
F 7 "Phoenix Contact" H 1550 450 50  0001 C CNN "Manufacturer_Name"
F 8 "1902547" H 1550 350 50  0001 C CNN "Manufacturer_Part_Number"
F 9 "" H 1550 250 50  0001 C CNN "Allied_Number"
F 10 "" H 1550 150 50  0001 C CNN "Other Part Number"
F 11 "21.5" H 1750 50  50  0001 C CNN "Height"
	1    1200 1300
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J1
U 1 1 5A7A0F0C
P 1050 3600
F 0 "J1" H 1050 3700 50  0000 C CNN
F 1 "CONN_01X01" V 1150 3600 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2mmDrill" H 1050 3600 50  0001 C CNN
F 3 "" H 1050 3600 50  0001 C CNN
	1    1050 3600
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J2
U 1 1 5A7A0FD5
P 1050 3800
F 0 "J2" H 1050 3900 50  0000 C CNN
F 1 "CONN_01X01" V 1150 3800 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2mmDrill" H 1050 3800 50  0001 C CNN
F 3 "" H 1050 3800 50  0001 C CNN
	1    1050 3800
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J3
U 1 1 5A7A101A
P 1050 4000
F 0 "J3" H 1050 4100 50  0000 C CNN
F 1 "CONN_01X01" V 1150 4000 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2mmDrill" H 1050 4000 50  0001 C CNN
F 3 "" H 1050 4000 50  0001 C CNN
	1    1050 4000
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X01 J4
U 1 1 5A7A1059
P 1050 4200
F 0 "J4" H 1050 4300 50  0000 C CNN
F 1 "CONN_01X01" V 1150 4200 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2mmDrill" H 1050 4200 50  0001 C CNN
F 3 "" H 1050 4200 50  0001 C CNN
	1    1050 4200
	-1   0    0    1   
$EndComp
$Comp
L Screw_Terminal_1x04 Buck_converter2
U 1 1 5A7AD2C9
P 3950 7400
F 0 "Buck_converter2" H 3950 7850 50  0000 C TNN
F 1 "BUCK-CONVERTER2" V 3800 7400 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-4_P5.08mm" H 3950 6975 50  0001 C CNN
F 3 "" H 3925 7600 50  0001 C CNN
	1    3950 7400
	0    -1   -1   0   
$EndComp
$Comp
L Screw_Terminal_1x04 Buck_converter3
U 1 1 5A7AD4F6
P 6100 7350
F 0 "Buck_converter3" H 6100 7800 50  0000 C TNN
F 1 "BUCK-CONVERTER3" V 5950 7350 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_bornier-4_P5.08mm" H 6100 6925 50  0001 C CNN
F 3 "" H 6075 7550 50  0001 C CNN
	1    6100 7350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	600  2400 1700 2400
Wire Wire Line
	4200 2450 4500 2450
Wire Wire Line
	4200 2550 4500 2550
Wire Wire Line
	4200 2850 4500 2850
Wire Wire Line
	4200 3050 4500 3050
Wire Wire Line
	4200 3150 4500 3150
Wire Wire Line
	4200 3250 4500 3250
Wire Wire Line
	2550 6450 2550 6100
Wire Wire Line
	3550 6450 3550 6100
Wire Wire Line
	4550 6450 4550 6100
Wire Wire Line
	5550 6450 5550 6100
Wire Wire Line
	6550 6450 6550 6100
Wire Wire Line
	2550 2350 2650 2350
Wire Wire Line
	2650 2450 2550 2450
Wire Wire Line
	2550 2550 2650 2550
Wire Wire Line
	2650 2650 2550 2650
Wire Wire Line
	2550 2750 2650 2750
Wire Wire Line
	2650 2850 2550 2850
Wire Wire Line
	2550 2950 2650 2950
Wire Wire Line
	2650 3050 2550 3050
Wire Wire Line
	2550 3150 2650 3150
Wire Wire Line
	2650 3250 2550 3250
Wire Wire Line
	2550 3350 2650 3350
Wire Wire Line
	2650 3450 2550 3450
Wire Wire Line
	2650 3550 2550 3550
Wire Wire Line
	2650 3750 2550 3750
Wire Wire Line
	2650 3850 2550 3850
Wire Wire Line
	2650 3950 2550 3950
Wire Wire Line
	2650 4050 2550 4050
Wire Wire Line
	4200 2650 4300 2650
Wire Wire Line
	4200 2750 4300 2750
Wire Wire Line
	4200 2950 4300 2950
Wire Wire Line
	4200 3350 4300 3350
Wire Wire Line
	4200 3450 4300 3450
Wire Wire Line
	4200 3550 4300 3550
Wire Wire Line
	4200 3650 4300 3650
Wire Wire Line
	4200 3750 4300 3750
Wire Wire Line
	4200 3850 4300 3850
Wire Wire Line
	4200 3950 4300 3950
Wire Wire Line
	6350 1150 6700 1150
Wire Wire Line
	6350 1250 6700 1250
Wire Wire Line
	6350 1350 6700 1350
Wire Wire Line
	6350 1450 6700 1450
Wire Wire Line
	6350 1550 6700 1550
Wire Wire Line
	6350 1650 6700 1650
Wire Wire Line
	6350 1750 6700 1750
Wire Wire Line
	6350 1850 6700 1850
Wire Wire Line
	6350 1950 6700 1950
Wire Wire Line
	6350 2050 6700 2050
Wire Wire Line
	6350 2150 6700 2150
Wire Wire Line
	6350 2250 6700 2250
Wire Wire Line
	6350 2350 6700 2350
Wire Wire Line
	6350 2450 6700 2450
Wire Wire Line
	6350 2550 6700 2550
Wire Wire Line
	6350 2650 6700 2650
Wire Wire Line
	6350 2750 6700 2750
Wire Wire Line
	6350 2850 6700 2850
Wire Wire Line
	6350 2950 6700 2950
Wire Wire Line
	6350 3050 6700 3050
Wire Wire Line
	6350 3150 6700 3150
Wire Wire Line
	6350 3250 6700 3250
Wire Wire Line
	6350 3350 6700 3350
Wire Wire Line
	6350 3450 6700 3450
Wire Wire Line
	6350 3550 6700 3550
Wire Wire Line
	6350 3650 6700 3650
Wire Wire Line
	6350 3750 6700 3750
Wire Wire Line
	1200 1200 2200 1200
Wire Wire Line
	2000 1300 2000 4750
Wire Wire Line
	1700 2400 1700 750 
Connection ~ 1700 1200
Wire Wire Line
	1550 6450 1550 6100
Wire Wire Line
	4200 4150 4300 4150
Wire Wire Line
	4200 4050 4300 4050
Wire Wire Line
	6350 3950 6700 3950
Wire Wire Line
	6350 3850 6700 3850
Wire Wire Line
	1200 1300 2200 1300
Connection ~ 2000 1300
Wire Wire Line
	2650 4150 1350 4150
Wire Wire Line
	1350 4150 1350 4200
Wire Wire Line
	1350 4200 1250 4200
Wire Wire Line
	1250 4000 2000 4000
Connection ~ 2000 4000
Wire Wire Line
	1250 3800 1450 3800
Wire Wire Line
	1450 3800 1450 2400
Connection ~ 1450 2400
Wire Wire Line
	600  2400 600  7050
Wire Wire Line
	600  7050 5800 7050
Wire Wire Line
	5800 7050 5800 7150
Wire Wire Line
	3650 7200 3650 7050
Connection ~ 3650 7050
Wire Wire Line
	3850 7200 4050 7200
Wire Wire Line
	6000 7150 6200 7150
Wire Wire Line
	1750 6100 1750 6800
Wire Wire Line
	1750 6800 2750 6800
Wire Wire Line
	2300 6800 2300 7150
Wire Wire Line
	2750 6800 2750 6100
Connection ~ 2300 6800
Wire Wire Line
	3750 6100 3750 6800
Wire Wire Line
	3750 6800 4750 6800
Wire Wire Line
	4250 6800 4250 7200
Wire Wire Line
	4750 6800 4750 6100
Connection ~ 4250 6800
Wire Wire Line
	5750 6100 5750 6800
Wire Wire Line
	5750 6800 6750 6800
Wire Wire Line
	6400 6800 6400 7150
Wire Wire Line
	6750 6800 6750 6100
Connection ~ 6400 6800
Wire Wire Line
	2650 3650 2000 3650
Connection ~ 2000 3650
Wire Wire Line
	4200 2350 5100 2350
Wire Wire Line
	5100 2350 5100 4750
Wire Wire Line
	5100 4750 2000 4750
Wire Wire Line
	2000 4600 700  4600
Wire Wire Line
	700  4600 700  6900
Wire Wire Line
	700  6900 6000 6900
Wire Wire Line
	6000 6100 6000 7150
Connection ~ 2000 4600
Wire Wire Line
	1350 6100 1350 6900
Connection ~ 1350 6900
Wire Wire Line
	2350 6100 2350 6900
Connection ~ 2350 6900
Wire Wire Line
	3350 6100 3350 6900
Connection ~ 3350 6900
Wire Wire Line
	4350 6100 4350 6900
Connection ~ 4350 6900
Wire Wire Line
	5350 6100 5350 6900
Connection ~ 5350 6900
Wire Wire Line
	6350 6100 6000 6100
Connection ~ 6000 6900
Wire Wire Line
	1700 7150 1700 7050
Connection ~ 1700 7050
Wire Wire Line
	1900 7150 1900 6900
Connection ~ 1900 6900
Wire Wire Line
	2100 7150 1900 7150
Wire Wire Line
	3850 7200 3850 6900
Connection ~ 3850 6900
$EndSCHEMATC

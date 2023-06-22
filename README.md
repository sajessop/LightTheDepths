# LightTheDepths
An underwater light module for use with pelagic stereo-BRUVs with built in depth sensor data logger.

Underwater enclosure details:  
BlueRobotics Watertight Enclosure 100mm diameter, 300mm long aluminum with 1 blank acrylic end cap and one aluminum 5 hole (M10) end cap.
I chose this one to make sure I could fit everything in, however a smaller option would have been better. 

Depth sensor details:
- BlueRobotics Bar30 sensor
- BlueRobotics I2C level converter
- Uno microcontroller
- Ethernet SD shield
Sensor is wired following the guide found at:  
https://bluerobotics.com/learn/bar30-arduino-guide/
Code used to log the sensor data to a SD card is included in this repository. It is based off the code in the “BlueRobotics MS5837” library with modifications made to log data to a SD card rather than the serial monitor.
The SD card must be formatted as FAT32.

Battery details:  
Both the Uno microcontroller and the LED lights are powered by 7 Amp hour 14 V custom made rechargable battery pack. Batteries were sourced from: https://www.premierbatteries.com.au/

LED details:  
LEDs consist of Cree XPG3 Royal Blue on a 6 UP PCB. Driven by CUTE-48-1.00W DC DC driver. LEDs are wired in series strings of two LEDs and each string has its own driver. The three drivers are wired in parallel to the battery. An Anna-40-60-S-XP-G optic is used to direct light. LED PCB is mounted via thermal tape to a heatsink to move heat away from LEDs. All LED and wiring equiptment was sourced from: https://www.cutter.com.au/
Blue lights are used to minimise the behavioural impact of the lights on fishes. 

Mounting:  
The LED PCB is mounted to the heatsink using thermal tape and the heatsink is mounted with temperature resistant epoxy putty to a piece of sheet metal cut to size. The sheet metal mount has holes cut for the wires to go through and to enable the inner mounting holes on the flange to be used to secure the set up. 25mm M3 bolts are used for this. 
The light module is mounted to the bait arm of the pelagic stereo-BRUV using Rola 100mm pipe clamps. Duct tape and calbe ties are used as a back up. 

Future Modifications:  
Program mocrocontroller to turn on LEDs once the depth sensor reads >1m.

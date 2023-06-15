/* LightTheDepths 
-------------------------------
Title: LightTheDepths log data

Description: This code reads data from the BlueRobotics Bar30 depth sensor and logs to a .csv on a SD card.
This code is designed to be used with an Arduino Uno microcontroller and SD shield.

The below code is partially based of the BlueRobotics code in the "BlueRoboticsMS5837" library and modified to log the data to a SD card rather than the serial monitor.
Below is the copyright notice attached to the original software published by BlueRobotics.
-------------------------------
The MIT License (MIT)

Copyright (c) 2015 Blue Robotics Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-------------------------------*/

#include <Wire.h>
#include "MS5837.h"
#include <SPI.h>
#include <SD.h>

MS5837 sensor;
File myFile;

void setup() {
  
  Serial.begin(9600);

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(4)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
  Serial.println("Setting up .csv");
  //Set up col name string
  String colnames = "Pressure,Temperature,Depth,Altitude";
    //Open file to write col names
    File myFile = SD.open("Data.csv", FILE_WRITE);
      if (myFile) {
                    myFile.println(colnames);
                    delay(3000);
                    myFile.close();
                    Serial.println("Ready to log some data");
                    delay(3000);
                    }
      // if the file isn't open, print error:
      else {
           Serial.println("error opening file");
           } 

  
  Serial.println("Starting");
  
  Wire.begin();

  // Initialize pressure sensor
  // Returns true if initialization was successful
  // We can't continue with the rest of the program unless we can initialize the sensor
  while (!sensor.init()) {
    Serial.println("Init failed!");
    Serial.println("Are SDA/SCL connected correctly?");
    Serial.println("Blue Robotics Bar30: White=SDA, Green=SCL");
    Serial.println("\n\n\n");
    delay(5000);
  }
  
  sensor.setModel(MS5837::MS5837_30BA);
  sensor.setFluidDensity(1029); // kg/m^3 (freshwater, 1029 for seawater)
}

void loop() {
  // Update pressure and temperature readings
  sensor.read();
// Set up data string structure
String dataString = "";
   dataString = dataString + sensor.pressure() + "," + sensor.temperature() + "," + sensor.depth() + "," + sensor.altitude();
  
      // open the file for logging of data
      File myFile = SD.open("Data.csv", FILE_WRITE);

    // if the file is available, write to it:
      if (myFile) {
                    myFile.println(dataString);
                    delay(3000);
                    myFile.close();
                    // print to the serial port too:
                    Serial.println(dataString);
                    delay(3000);
                    }
      // if the file isn't open, pop up an error:
      else {
           Serial.println("error opening file");
           }

  delay(5000);
}
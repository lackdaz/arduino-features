// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011

#include <Wire.h>
#include "SSD1306.h"

SSD1306  display(0x3C, D2, D3);

void setup() {
  Serial.begin (115200);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);

  display.init();
  display.display();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  byte pos = 0;
  // Leonardo: wait for serial port to connect
  while (!Serial) 
    {
    }

  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  display.drawString(0, pos, "I2C Scanner. Scanning ...");
  display.display();
  delay(500);
  byte count = 0;
  
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      display.drawString(0, pos += 10, "Found address: " + String(i, DEC) + " (0x" + String(i, HEX) + ")");
      display.display();
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  display.drawString(0, pos += 10, "Completed. Found " + String(count, DEC) + " device(s)");
  display.display();
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  // end of setup

void loop() {}

// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011

#include <Wire.h>
#include <Adafruit_SSD1306.h>

//// If using software SPI (the default case):
#define OLED_MOSI   D6
#define OLED_CLK   D5
#define OLED_DC    D7
#define OLED_CS    D0
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  pinMode(D8, OUTPUT);
  digitalWrite(D8, LOW);
  Wire.begin(D3, D4);
  Serial.begin (115200);

  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  byte pos = 0;
  // Leonardo: wait for serial port to connect
  while (!Serial) 
    {
    }

  display.clearDisplay();
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  display.println("I2C Scan..");
  display.display();
  delay(500);
  display.clearDisplay();
  display.setCursor(0,0);
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
      display.println(String(count + 1) + ":" + String(i, DEC) + "(0x" + String(i, HEX) + ")");
      display.display();
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  display.println("Found " + String(count, DEC) + " device(s)");
  display.display();
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  // end of setup

void loop() {}

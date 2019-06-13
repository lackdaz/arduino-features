#include <Adafruit_NeoPixel.h>

#define PIN D6
#define NUM_LED 2
#define DELAY 1000
#define STEP 5

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LED, PIN, NEO_RGB + NEO_KHZ800);

const byte numChars = 32;
String color_string = "";
boolean newData = false;
uint32_t c;
uint8_t new_color = 0;
uint8_t current_color = 255;


void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.println("Color?");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  delay(50);

  char endMarker = '\n';
  char rc;
  
  while (Serial.available() > 0 && newData == false) {
      rc = Serial.read();

      if (rc != endMarker) {
          color_string += rc;
      }
      else {
//          color_string += '\0'; // terminate the string
          newData = true;
      }
  }
  
  if (newData == true) {
      Serial.print("Int:");
      Serial.println(color_string);
      newData = false;
      current_color = new_color;
      new_color = color_string.toInt() & 255;
      Serial.println(new_color);
      color_string = "";
      Serial.read();
  }
  
  breathe(current_color, new_color);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  delay(50);
}

void insta_change(uint8_t current_color) {
    uint32_t c = get_rgb(current_color);
    strip.setPixelColor(0, c);
    strip.show();
}

uint32_t get_rgb(uint8_t _color) {
    uint8_t r, g, b;
    String data;
    if (_color <= 85) {
      r = incumbent_color(_color);
      g = minor_color(_color);
      b = 0;
    }
    else if (_color <= 170){
      _color -= 85;
      r = 0;
      g = incumbent_color(_color);
      b = minor_color(_color);
      }
    else if (_color <= 255) {
      _color -= 170;
      r = minor_color(_color);
      g = 0;
      b = incumbent_color(_color);  
    }
    data = "r: " + String(r) + ", g: " + String(g) + ", b:" + String(b);
    Serial.println(data);    
    return strip.Color(r, g, b);
}

uint8_t incumbent_color(uint8_t _color) {
  return (current_color - (_color * 3));
}

uint8_t minor_color(uint8_t _color) {
  return (_color * 3);
}

void breathe(uint8_t current_color, uint8_t new_color) {
  uint8_t change = 0;
//  Serial.print("difference:");
//  Serial.println(abs(current_color - new_color));
  if (current_color > new_color) {
    if ((current_color - new_color) > 127) {
      change = STEP;
    }
    else change = -STEP;
  } else {
    if ((current_color - new_color) <= 127) {
  }
    if (abs(current_color - new_color) <= 127) {
      change = STEP;
    }
    else change = -STEP;
  }
  while(abs(current_color - new_color) >= 5) {
    Serial.println(current_color);
    current_color += change;
    insta_change(current_color);
    delay(200);
  }
  ::current_color = new_color;
}

#include <Keyboard.h>
int buttonPin = 9;  // Set a button to any pin

void setup()
{
  pinMode(buttonPin, INPUT);  // Set the button as an input
  digitalWrite(buttonPin, HIGH);  // Pull the button high
}

void loop()
{
  Keyboard.write('z');  // send a 'z' to the computer via Keyboard HID
  digitalWrite()
  delay(10000);  // delay so there aren't a kajillion z'
}
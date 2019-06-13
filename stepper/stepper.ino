# include "stepper.h"

Stepper stepper1(2, 3, 4, 16, 40);

void setup() {
  Serial.begin(115200);
  stepper1.begin();
}

void loop() {
  stepper1.test();
}


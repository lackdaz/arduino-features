# include "stepper.h"

// stepper(stp, dir, en, steps, mm/rev)
Stepper stepper1(D8, D7, D6, 16, 40);

// example
void setup() {
  Serial.begin(115200);
  stepper1.begin();
}

void loop() {
  stepper1.test();
  delay(1000);
}

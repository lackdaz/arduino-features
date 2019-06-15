# include "stepper.h"
# include "if-ir.h"

Stepper stepper1(2, 3, 4, 16, 40);
Break_beam_sensor left(50, 48);
Break_beam_sensor right(-1, -1);

int count;
bool detected;

void setup() {
  Serial.begin(115200);
  stepper1.begin();
  left.begin();
  right.begin();
  pinMode(52, OUTPUT);
  digitalWrite(52, HIGH);
  count = 0;
}

void loop() {
  left.update();
  Serial.println(left.is_triggered);
  
  if (!left.is_triggered && detected == true) {
    detected = false;
  } 
  else if (left.is_triggered && detected == false) {
    detected = true;
    count++;
    delay(1000);
  } 
  else {
    stepper1.charge();
  }

  if (count == 3) {
    count = 0;
    stepper1.move_backwards(75);
    delay(2500);
  }
}


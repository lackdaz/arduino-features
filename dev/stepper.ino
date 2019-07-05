# include "stepper.h"
# include "if-ir.h"

#define STOP 2000

Stepper stepper1(2, 3, 4, 16, 40);
// Break_beam_sensor left(50, 48);
Break_beam_sensor left(52);
Break_beam_sensor right(53);

int count;
bool detected;

void setup() {
  Serial.begin(115200);
  stepper1.begin();
  left.begin();
  right.begin();
  // pinMode(52, OUTPUT);
  // digitalWrite(52, HIGH);
  count = 0;
}

void loop() {
  left.update();
  right.update();
  // Serial.print("left: ")
  Serial.print(left.is_triggered);
  Serial.print(", ");
  Serial.println(right.is_triggered);

  // Serial.println(count);

  long now = millis();
  if (detected) {
    if (now - stepper1.stop_time > STOP) {
      stepper1.charge();
    }
    if (!left.is_triggered && !right.is_triggered) { // one cycle done
      detected = false;
      count++;
      stepper1.move_backwards(75);
      Serial.println("One Cycle done.");
    }
    else {
      // do nothing
    }
  }
  else if (!detected) {
    if (left.is_triggered && right.is_triggered) {
      detected = true;
      stepper1.stop();
      stepper1.stop_time = now;
    }
    else if (left.is_triggered || left.is_triggered) { // only one side, continue moving
      stepper1.charge();
    }
    else {
      stepper1.charge();
    }
  }

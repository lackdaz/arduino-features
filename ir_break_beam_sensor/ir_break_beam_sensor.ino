# include "ir.h"

Break_beam_sensor left(D4, D3);

void setup() {
  Serial.begin(115200);
  left.begin();
}

void loop() {
  left.update();
  left.disable();
  Serial.println(left.is_triggered);
  delay(200);
}
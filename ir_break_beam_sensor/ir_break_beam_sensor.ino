# include "ir.h"

Break_beam_sensor left(50, 48);

void setup() {
  Serial.begin(115200);
  left.begin();
  pinMode(52, OUTPUT);
  digitalWrite(52, HIGH)
}

void loop() {
  left.update();
  left.enable();
  Serial.println(left.is_triggered);
  delay(200);
}
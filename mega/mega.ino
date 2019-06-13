void setup() {
  pinMode(53, OUTPUT);
  digitalWrite(53, LOW);
}

void loop() {
  digitalWrite(53, HIGH);
  delay(5000);
  digitalWrite(53, LOW);
  delay(5000);
}
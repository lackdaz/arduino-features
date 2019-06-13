/* 
  For the ACS712 5A
 */

int signal_pin = A7;

void setup() {
  Serial.begin(115200);
  pinMode(signal_pin, INPUT);
}

void loop() {
  int reading = analogRead(signal_pin);
  double voltage = ((float)reading / 1024) * 5;
  double current = (voltage - 2.5) / 0.185;
  Serial.println(current);
  delay(50);
}
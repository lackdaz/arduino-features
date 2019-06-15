int A1 = D4;
int A2 = D3;

void setup() {
  Serial.begin(115200);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  digitalWrite(A1, LOW);
  delay(5000);
}

void loop() {
  digitalWrite(A2, LOW);
  digitalWrite(A1, HIGH);
  delay(10);
}
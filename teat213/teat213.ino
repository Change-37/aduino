void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {

  digitalWrite(2, 1);
  digitalWrite(3, 0);
  analogWrite(6, 150);
  delay(1000);
  
  digitalWrite(2, 0);
  digitalWrite(3, 1);
  analogWrite(6, 150);
  delay(1000);
}

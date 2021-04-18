void setup() {
  for (byte i = 2; i <= 9; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  for (byte i = 3; i <= 9; i++){
    digitalWrite(i, HIGH);
    digitalWrite(i-1, LOW);
    delay(500);
  }
  for (byte i = 8; i >= 2; i--){
    digitalWrite(i, HIGH);
    digitalWrite(i+1, LOW);
    delay(500);
  }
}

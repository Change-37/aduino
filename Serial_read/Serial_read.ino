void setup() {
  Serial.begin(9600);
}

void loop() {
  char a;
  if(Serial.available()){
    a = Serial.read();
    Serial.write(a);
  }
}

void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available())
  {
    float a = Serial.parseFloat();
    float b = Serial.parseFloat();

    Serial.print("a : ");
    Serial.println(a);
    Serial.print("b : ");
    Serial.println(b);
    Serial.print("a + b : ");
    Serial.println(a+b);
  }
}

byte a[8] = {2, 3, 4, 5, 6, 7, 8, 9};
byte val = 0x00;
void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < 8; i++)
    pinMode(a[i], OUTPUT);
  for (int i = 0; i < 8; i++)
    digitalWrite(a[i], val & (0x01<<i));
}

void loop() {
  if(Serial.available()){
   val = Serial.parseInt();
   Serial.println(val);
   for (int i = 0; i < 8; i++)
     digitalWrite(a[i], val & (0x01<<i));
  }
}

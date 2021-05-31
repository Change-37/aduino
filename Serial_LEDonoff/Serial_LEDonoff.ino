#define LED 11
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  long a;
  if(Serial.available()){
   a = Serial.parseInt();
   Serial.write(a);
   if (a==1)
      digitalWrite(LED, HIGH);
   else if (a==0)
      digitalWrite(LED, LOW);
  }
}

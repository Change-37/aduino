#define LED 11
byte a;
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if(Serial.available()){
   int i = Serial.parseInt();
   Serial.write(i);
   if (i==1){
    a = a^1;
    digitalWrite(LED, a);
   }
  }
}

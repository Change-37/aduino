#define LED1 11
#define LED2 12
#define SW1 2
#define SW2 3
void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(SW1,INPUT_PULLUP);
  pinMode(LED2,OUTPUT);
  pinMode(SW2,INPUT_PULLUP);

}

void loop() {
  byte sw1_in;
  byte sw2_in;
  sw1_in=digitalRead(SW1);
  sw2_in=digitalRead(SW2);
  if(sw1_in==LOW){
    digitalWrite(LED1,HIGH);
    delay(2000);
    digitalWrite(LED1,LOW);
  }
  else if(sw2_in==LOW){
    digitalWrite(LED2,HIGH);
    delay(2000);
    digitalWrite(LED2,LOW);
  }
  else{
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
  }
}

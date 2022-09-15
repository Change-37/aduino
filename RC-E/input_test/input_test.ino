#include <IRremote.h>
int a = A0;
IRrecv irrecv(a);
decode_results result;


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&result)==true) {
    Serial.println(result.value, HEX);
    delay(100);
    irrecv.resume();
  }
  

}
/*
4BDD5337
7BE94288
25AE7EE0
FF4AB5
70CB0D2B
1BC0157B
*/

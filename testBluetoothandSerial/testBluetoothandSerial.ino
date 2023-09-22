#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial BTSerial(2, 3);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available()){
    char a = BTSerial.read();
    Serial.write(a);
  }
  if(Serial.available()){
    char b = Serial.read();
    BTSerial.write(b);
  }

}

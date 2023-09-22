#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)


void setup() {
  Serial.begin(9600);

  BTSerial.begin(9600);       //시리얼 통신 초기화
  BTSerial.println("Hello!"); //터미널 작동 확인용 문자열
}

void loop() {
  if(BTSerial.available())
    Serial.write(BTSerial.read());
  if(Serial.available())
    BTSerial.write(Serial.read());
}

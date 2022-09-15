#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)

int led = 8;

void setup() {
  BTSerial.begin(9600);       //시리얼 통신 초기화
  BTSerial.println("Hello!"); //터미널 작동 확인용 문자열
  pinMode(led, OUTPUT);
}

void loop() {
  char bt_cmd = 0;
  if (BTSerial.available())   //데이터가 입력되었을 때
  {
    bt_cmd = BTSerial.read();
    if(bt_cmd == '1')
      digitalWrite(led, 1);
    else if(bt_cmd == '2')
      digitalWrite(led, 0);
  }
  delay(100);
}

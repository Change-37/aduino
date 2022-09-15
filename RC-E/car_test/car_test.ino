#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)

bool att;
int mh = A0;
int sensor; 

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  BTSerial.begin(9600);
  
  pinMode(mh, INPUT);
}

void loop() {
  char a;
  sensor = analogRead(mh);
    // 센서가 움직이지 않을때는 센서 값이 1023입니다.
    if(sensor <= 1000){
      BTSerial.print("Sensor Value: "); 
      BTSerial.println(sensor);
    }
  if(BTSerial.available()){
    a = BTSerial.read();
    BTSerial.write(a);
    if(a == 'w'){
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(11, LOW);
    }
    else if(a == 's'){
      digitalWrite(8, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    }
    else if(a == 'a'){
      digitalWrite(8, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);
    }
    else if(a == 'd'){
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(10, LOW);
    }
    else if(a == 'x'){
      digitalWrite(8, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);
    }
    else if(a == 'f'){
      att = !att;
      digitalWrite(4, att);
    }
  }
}

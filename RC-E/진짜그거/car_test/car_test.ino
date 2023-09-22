#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)

#define MOTORA_a 8
#define MOTORA_b 9  
#define MOTORB_a 10    
#define MOTORB_b 11     
#define MOTORC_a 4
#define MOTORC_b 5

int mh = A0;
int sensor = 0;
int spd = 220;
int uspd = 255 - spd;

void setup()
{
  pinMode(MOTORA_a, OUTPUT);
  pinMode(MOTORA_b, OUTPUT);
  pinMode(MOTORB_a, OUTPUT);
  pinMode(MOTORB_b, OUTPUT);
  pinMode(MOTORC_a, OUTPUT);
  pinMode(MOTORC_b, OUTPUT);

  Serial.begin(9600);
  Serial.println("Hello!");
  BTSerial.begin(9600);

  
  
  pinMode(mh, INPUT);
}

void loop() {
  char a; 
  sensor = analogRead(mh);
    // 센서가 움직이지 않을때는 센서 값이 1023입니다.
    if(sensor >= 900){
      sensor -= 900;
      BTSerial.println(sensor);
      Serial.println(sensor);
      delay(10);
    }
  if(BTSerial.available()){
    a = BTSerial.read();
    Serial.println(a);
    if(a == 'w'){
      digitalWrite(MOTORA_a, LOW);
      analogWrite(MOTORA_b, spd);
      analogWrite(MOTORB_a, spd);
      analogWrite(MOTORB_b, LOW);
    }
    else if(a == 's'){
      digitalWrite(MOTORA_a, HIGH); // 문제 발생 - 움직이지 않음. b가 high일 때 동작 O, a가 high일때 동작 X
      analogWrite(MOTORA_b, uspd); // 해결 - pwm핀이 아니던 8핀은 디지털으로 두고 
      analogWrite(MOTORB_a, LOW);
      analogWrite(MOTORB_b, spd);
    }
    else if(a == 'a'){
      digitalWrite(MOTORA_a, HIGH);
      analogWrite(MOTORA_b, uspd);
      analogWrite(MOTORB_a, spd);
      analogWrite(MOTORB_b, LOW);
    }
    else if(a == 'd'){
      digitalWrite(MOTORA_a, LOW);
      analogWrite(MOTORA_b, spd);
      analogWrite(MOTORB_a, LOW);
      analogWrite(MOTORB_b, spd);
    }
    else if(a == 'x'){
      digitalWrite(MOTORA_a, LOW);
      digitalWrite(MOTORA_b, LOW);
      digitalWrite(MOTORB_a, LOW);
      digitalWrite(MOTORB_b, LOW);
    }
    else if(a == 'f'){
      att1 = !att1;
      if(att1){
        digitalWrite(MOTORC_a, att);
        att = !att;
      }
      else
        digitalWrite(MOTORC_b, att);
    }
  }
}

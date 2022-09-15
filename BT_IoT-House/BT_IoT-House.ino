#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
#include <Servo.h>             //서보모터 라이브러리 추가
SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)

Servo S;
int led = 7;
int piezo = 8;
int servo = 9;
int mA = 5;
int mB = 4;
int mS = 6;

int m_spd = 200;

#define c4 3822 // 261.63Hz 도
#define e4 3034 // 329.63Hz 미
#define g4 2551 // 392.11Hz 솔
#define c5 1910 // 523.25Hz 도

int song_pivot = 0;
int song[] = { c4, e4, g4, c5 };

void sing(int eum, int Long) {
  long lele = 750000;
  
  for(long i=0; i< lele ; i+= eum) { 
    digitalWrite(piezo, HIGH);
    delayMicroseconds(eum/2);
    digitalWrite(piezo, LOW);
    delayMicroseconds(eum/2);
  }
}


void setup() {
  BTSerial.begin(9600);       //시리얼 통신 초기화
  BTSerial.println("Hello!"); //터미널 작동 확인용 문자열
  pinMode(led, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(mA, OUTPUT);
  pinMode(mB, OUTPUT);
  pinMode(mS, OUTPUT);

  S.attach(servo);

}

void loop() {
  char bt_cmd = 0;
  digitalWrite(mA, 1);
  digitalWrite(mB, 0);
  analogWrite(mS, m_spd);
  if (BTSerial.available())   //데이터가 입력되었을 때
  {
    bt_cmd = BTSerial.read();
    switch(bt_cmd){
      case '1':
        digitalWrite(led, 1);
        break;
      case '2':
        digitalWrite(led, 0);
        break;
      case '5':
        S.write(180);
        break;
      case '6':
        S.write(0);
        break;
      case '7':
        int Long = 6;
        sing(song[song_pivot++], Long); // 다음 음을 내기 위해 ++를 해줌
        break;
      default:
        ;
    }
  }
  delay(100);
}

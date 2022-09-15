#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)

#define MOTOR_A_a 10   
#define MOTOR_A_b 11    
#define MOTOR_B_a 8     
#define MOTOR_B_b 9      
#define MOTOR_C_a 4     
#define MOTOR_C_b 5   

int mh = A0;
int sensor; 

boolean m_a_dir = 0, m_b_dir = 0;      //모터의 방향을 결정하는 전역변수

bool attack = 0;

void setup()
{
  //모터 제어 핀들을 출력으로 설정합니다.
  pinMode(MOTOR_A_a, OUTPUT);
  pinMode(MOTOR_A_b, OUTPUT);
  pinMode(MOTOR_B_a, OUTPUT);
  pinMode(MOTOR_B_b, OUTPUT);
  pinMode(MOTOR_C_a, OUTPUT);
  pinMode(MOTOR_C_b, OUTPUT);

  Serial.begin(9600);       //시리얼 통신 초기화
  Serial.println("Hello!"); //터미널 작동 확인용 문자열
  
  pinMode(mh, INPUT);
  mh_check();
}

void loop()
{
  char cmd = 0;   //명령어 저장용 문자형 변수
  
  if (Serial.available())   //데이터가 입력되었을 때
  {
    cmd = Serial.read(); //변수에 입력된 데이터 저장함수
    Serial.println(cmd);
    if(cmd == 'w')  //'w'가 입력되었을 때, 전진
    {
      digitalWrite(MOTOR_A_a, HIGH); 
      digitalWrite(MOTOR_A_b, LOW);
      digitalWrite(MOTOR_B_a, HIGH); 
      digitalWrite(MOTOR_B_b, LOW);
      BTSerial.println("W Pressed");
    }
    else if(cmd == 'a')  //'a'가 입력되었을 때, 제자리 좌회전
    {
      digitalWrite(MOTOR_A_a, LOW); 
      digitalWrite(MOTOR_A_b, HIGH);
      digitalWrite(MOTOR_B_a, HIGH); 
      digitalWrite(MOTOR_B_b, LOW);
      BTSerial.println("A Pressed");
    }
    else if(cmd == 'd')  //'d'가 입력되었을 때, 제자리 우회전
    {
      digitalWrite(MOTOR_A_a, HIGH); 
      digitalWrite(MOTOR_A_b, LOW);
      digitalWrite(MOTOR_B_a, LOW); 
      digitalWrite(MOTOR_B_b, HIGH);
      BTSerial.println("D Pressed");
    }
    else if(cmd == 's')  //'s'가 입력되었을 때, 후진
    {
      digitalWrite(MOTOR_A_a, LOW); 
      digitalWrite(MOTOR_A_b, HIGH);
      digitalWrite(MOTOR_B_a, LOW); 
      digitalWrite(MOTOR_B_b, HIGH);
      BTSerial.println("S Pressed");
    }
    else if(cmd == 'x')
    {
      digitalWrite(MOTOR_A_a, LOW); 
      digitalWrite(MOTOR_A_b, LOW);
      digitalWrite(MOTOR_B_a, LOW); 
      digitalWrite(MOTOR_B_b, LOW);
      BTSerial.println("Unpressed");
    }
    else if(cmd == 'f')
    {
      attack = !attack; //토글
      if(attack) digitalWrite(MOTOR_C_a, HIGH);
      else digitalWrite(MOTOR_C_a, LOW);
      BTSerial.print("f = ");
      BTSerial.println(attack);
    }
  }
}

void rc_ctrl_val(char cmd) //입력된 데이터에 따라 모터에 입력될 변수를 조정하는 함수
{
  
}


void mh_check(){
  while(1){
    sensor = analogRead(mh);
    // 센서가 움직이지 않을때는 센서 값이 1023입니다.
    if(sensor <= 950){
      BTSerial.print("Sensor Value: "); 
      BTSerial.println(sensor);
    }
    delay(100);
  }
}

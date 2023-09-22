
#define MOTORA_a 8
#define MOTORA_b 9  
#define MOTORB_a 10    
#define MOTORB_b 11     
#define MOTORC_a 4
#define MOTORC_b 5

int mh = A0;
bool att;
bool att1;
int sensor = 0;
int spd = 180;
int uspd = 75;

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
  
  pinMode(mh, INPUT);
}

void loop()
{
  char a = 0;   //명령어 저장용 문자형 변수
  sensor = analogRead(mh);
    // 센서가 움직이지 않을때는 센서 값이 1023입니다.
      Serial.print("Sensor Value: "); 
      Serial.println(sensor);
  if (Serial.available())   //데이터가 입력되었을 때
  {
    a = Serial.read(); //변수에 입력된 데이터 저장함수
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

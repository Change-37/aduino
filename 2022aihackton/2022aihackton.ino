#include <TM1637Display.h>
#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
#include <DHT11.h>
#include <string.h>

SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)

int buz = 4 ;
#define led 5
#define CLK1 8
#define DIO1 9
#define CLK2 10
#define DIO2 11
TM1637Display display1(CLK1, DIO1);
TM1637Display display2(CLK2, DIO2);

int pin=A1;
DHT11 dht11(pin);

int turn = 0;
int indoor = 24;
int outdoor = 0;
byte C[] = {0x58};
unsigned char i;

void setup() {
  display1.clear();
  display2.clear();
  Serial.begin(9600);
  pinMode(buz, OUTPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(led, 0);

  BTSerial.begin(9600);       //시리얼 통신 초기화
  BTSerial.println("Hello!"); //터미널 작동 확인용 문자열
  
  display1.setBrightness(0x0f);
  display2.setBrightness(0x0f);
  display1.setSegments(C, 1, 3);
  display2.setSegments(C, 1, 3);
}

void loop() {  
  int DELAY = 1000;
  float temp, humi;
  int err;
  if((err=dht11.read(humi, temp))==0)
  {
    outdoor = temp;
  }
  else
  {   
  }
  
  if(BTSerial.available()){
    String inputStr = BTSerial.readStringUntil('\n');
    Serial.println(inputStr); 
    if(inputStr.startsWith("temp:")){
      String Ostr  = inputStr.substring(5);
      indoor = Ostr.toInt();
    }
    else if(inputStr.startsWith("btn:")){
      String Ostr = inputStr.substring(4);
      turn = Ostr.toInt();
      if(turn == 1){
        digitalWrite(led, HIGH);
        for (i = 0; i <80; i++)
        {
          digitalWrite (buz, HIGH) ;
          delay (1) ;
          digitalWrite (buz, LOW) ;
          delay (1) ;
        }
        for (i = 0; i <100; i++) 
        {
          digitalWrite (buz, HIGH) ;
          delay (2) ;
          digitalWrite (buz, LOW) ;
          delay (2) ;
        }
      }
      else if(turn == 0){
        digitalWrite(led, LOW);
      }
    }
  }
  if(Serial.available()){
    String inputStr = Serial.readStringUntil('\n');
    Serial.println(inputStr);
    BTSerial.println(inputStr); 
    if(inputStr.startsWith("temp:")){
      String Ostr  = inputStr.substring(5);
      indoor = Ostr.toInt();
    }
    else if(inputStr.startsWith("btn:")){
      String Ostr = inputStr.substring(4);
      turn = Ostr.toInt();
      if(turn == 1){
        digitalWrite(led, HIGH);
        Serial.println("buz");
        for (i = 0; i <80; i++)
        {
          digitalWrite (buz, HIGH) ;
          delay (1) ;
          digitalWrite (buz, LOW) ;
          delay (1) ;
        }
        for (i = 0; i <100; i++) 
        {
          digitalWrite (buz, HIGH) ;
          delay (2) ;
          digitalWrite (buz, LOW) ;
          delay (2) ;
        }
        Serial.println("buzz");
      }
      else if(turn == 0){
        digitalWrite(led, LOW);
      }
    }
  }

  
  digitalWrite (buz, 1) ;
  display1.showNumberDec(indoor, false, 2, 1);
  display2.showNumberDec(outdoor, false, 2, 1);
}

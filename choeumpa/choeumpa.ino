#include <SoftwareSerial.h>

#define TRIG 2  //TRIG pin set(초음파 발생)
#define ECHO 3  //ECHO pin set(초음파 받음)
#define RXD 8  // 블루투스 송신선
#define TXD 7  // 블루투스 수신선

SoftwareSerial bluetooth(RXD, TXD);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  long duration, distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  distance = duration * 17 / 1000;
  

  if(distance <= 1) {
    bluetooth.write('1');
    delay(5000);
  }

  Serial.println(duration);
  Serial.print("\nDistance: ");
  Serial.print(distance);
  Serial.println(" Cm");

  delay(50);
}

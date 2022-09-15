int busser = 8;
int timer = 180;
int gap = 500;
int cnt = 0;
int mh = A0;
int sensor; 

void setup()
{
  Serial.begin(9600);    
  pinMode(busser, OUTPUT);
  pinMode(mh, INPUT);
  
}
 
void loop()
{
  sensor = analogRead(mh);
  // 센서가 움직이지 않을때는 센서 값이 1023입니다.
  cnt = 0;
  Serial.print("Sensor Value: "); 
  Serial.println(sensor);
  delay(100);
}

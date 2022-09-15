int Dir1Pin_A = 6;      
int Dir2Pin_A = 7;     
int Dir1Pin_B = 8;      
int Dir2Pin_B = 9;  
int SpeedPin_A = A5;     
int SpeedPin_B = A4; 
int b1 =  3;
int b2 = 4;
int lin = 5;
int lout = 2;
int apeed = 131;
int bpeed = 131;
int a = 0;
int b = 0;
int l = 1;

void setup() {
  pinMode(Dir1Pin_A, OUTPUT);             
  pinMode(Dir2Pin_A, OUTPUT);             
  pinMode(SpeedPin_A, OUTPUT);     
  pinMode(Dir1Pin_B, OUTPUT);             
  pinMode(Dir2Pin_B, OUTPUT);             
  pinMode(SpeedPin_B, OUTPUT);  
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);    
  pinMode(lin, INPUT);
  pinMode(lout, OUTPUT); 
  Serial.begin(9600);
  start();
}
 
void loop() {
  ssetup();
  loopR();
}

void start(){
  
  digitalWrite(Dir1Pin_A, HIGH);         
  digitalWrite(Dir2Pin_A, LOW);
  analogWrite(SpeedPin_A, apeed); 
  delay(1000);
  digitalWrite(Dir1Pin_B, HIGH);         
  digitalWrite(Dir2Pin_B, LOW);
  analogWrite(SpeedPin_B, bpeed);          
  delay(1000);
}

void ssetup(){
  
  if(digitalRead(lin) == 1){
    l++;
    l %= 2;
  }
  if(digitalRead(b1) == 1){
    a++;
    a %= 14;
    Serial.println(a);
    apeed = apeed + (a*7);
  }
  if(digitalRead(b2) == 1){
    b++;
    b %= 14;
    Serial.println(b);
    bpeed = bpeed + (b*7);
  }
  delay(10);
}
void loopR(){
  digitalWrite(lout, l);
  digitalWrite(Dir1Pin_A, HIGH);         
  digitalWrite(Dir2Pin_A, LOW);
  analogWrite(SpeedPin_A, apeed); 
  digitalWrite(Dir1Pin_B, HIGH);         
  digitalWrite(Dir2Pin_B, LOW);
  analogWrite(SpeedPin_B, bpeed);          
  delay(100); 
}

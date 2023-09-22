#define btn 4
#define led 5
int output = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  output ? output = 0 : output = 1;
  digitalWrite(led, output);
  
  Serial.print("led : ");
  Serial.println(output);
  int a = digitalRead(btn);
  Serial.print("btn : ");
  Serial.println(a);
  delay(500);
}

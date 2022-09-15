
#define MOTOR_B_a 5     //모터B의 +출력핀은 5번핀입니다
#define MOTOR_B_b 6     //모터B의 -출력핀은 6번핀입니다

void setup() {
  pinMode(MOTOR_B_a, OUTPUT);
  pinMode(MOTOR_B_b, OUTPUT);
}

void loop() {
  digitalWrite(MOTOR_B_a, LOW);
  analogWrite(MOTOR_B_b, 255); 
}

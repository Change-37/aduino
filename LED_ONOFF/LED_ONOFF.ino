#define LED 12
// 스위치 연결 테스트용 코드

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH); // 계속 전원을 준다.
  delay(1000);
}

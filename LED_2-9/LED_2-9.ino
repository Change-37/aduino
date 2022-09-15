void setup() {
  for (byte i = 2; i <= 9; i++)
    pinMode(i, OUTPUT); // 2번 부터 9번 까지 8개의 포트를 output으로 설정
  digitalWrite(2, HIGH); // 코드 상 3번에서 시작하지 때문에 2번을 켜주고 시작.
  delay(500);
}

void loop() {
  for (byte i = 3; i <= 9; i++){ // 이렇게 하면 밑의 반복문의 끝에서 2번이 켜진 뒤 자연스럽게 3번이 켜진다.
    digitalWrite(i, HIGH); // 현재 LED 켜기
    digitalWrite(i-1, LOW); // 이전 LED 끄기
    delay(500);
  }
  for (byte i = 8; i >= 2; i--){ // 이렇게 하면 위의 반복문의 끝에서 9번이 켜진 뒤 자연스럽게 8번이 켜진다.
    digitalWrite(i, HIGH); // 현재 LED 켜기
    digitalWrite(i+1, LOW); // 이전 LED 끄기
    delay(500);
  }
}

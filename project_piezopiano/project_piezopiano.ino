int piezo = 8;
 
void setup(){
  pinMode(piezo, OUTPUT);
 
  tone(piezo, 261); // 5옥타브 도
  delay(1000);
  tone(piezo, 293); // 레
  delay(1000);
  tone(piezo, 329); // 미
  delay(1000);
  tone(piezo, 349); // 파
  delay(1000);  
  tone(piezo, 391); // 솔
  delay(1000);
  tone(piezo, 440); // 라
  delay(1000);
  tone(piezo, 493); // 시
  delay(1000);
  tone(piezo, 523); // 6옥타브 도
  delay(1000);
  noTone(piezo);
}
 
void loop() {
  
}

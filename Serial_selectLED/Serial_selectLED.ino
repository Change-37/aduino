byte LED[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte a[] = {0, 0, 0, 0, 0, 0, 0, 0};
void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 8; i++)
    pinMode(LED[i], OUTPUT);
}

void loop() {
  if(Serial.available()){
   int i = Serial.parseInt();
   Serial.println(i);
   i--;
   a[i] = a[i]^1;
   digitalWrite(LED[i], a[i]);
  }
}

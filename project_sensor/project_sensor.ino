void setup() { 
  Serial.begin(9600); 
  pinMode(5, INPUT); 
  } 
  int sum = 0; 
void loop() { 
  int val = analogRead(A0); 
  Serial.print("Val = "); 
  Serial.println(val); 
  sum = sum+val; 
  Serial.print("Sum = "); 
  Serial.println(sum); 
  delay(1000); 
}

void setup() {
  Serial.begin(9600);

  Serial.println("Start : ");
  Serial.println("Write data : ");
  Serial.write('A');
  Serial.write('\n');
  Serial.write(65);
  Serial.write('\n');
  Serial.write("Hello");
  Serial.write('\n');

  char str[] = {'W', 'o', 'r', 'l', 'd', '\0'};
  Serial.write(str);
  Serial.write('\n');
  Serial.write(str, 3);
}

void loop() {
  // put your main code here, to run repeatedly:

}

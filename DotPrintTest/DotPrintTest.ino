int inA = 6;
int inB = 7;
int out1 = 8;
int out2 = 9;

void setup() {
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);

}

void loop() {
  digitalWrite(out1, HIGH);
  digitalWrite(inA, LOW);
  digitalWrite(inB, HIGH);
  digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);
  digitalWrite(inA, LOW);
  digitalWrite(inB, LOW);
  digitalWrite(out2, LOW);
  
}

#define A 9
#define B 10
#define C 11
#define D 12


void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop() {
  for (byte num = 0; num<16; num++){ 

    if(num & 1) digitalWrite(A, HIGH);
    else digitalWrite(A, LOW);
    
    if(num & 2) digitalWrite(B, HIGH);
    else digitalWrite(B, LOW);
    
    if(num & 4) digitalWrite(C, HIGH);
    else digitalWrite(C, LOW);
    
    if(num & 8) digitalWrite(D, HIGH);
    else digitalWrite(D, LOW);
       
    delay(1000);
  }
}

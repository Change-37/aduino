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
  byte n;
  for (byte num = 0; num<16; num++){    
    if(num / 8){ 
      n = num%8;
      digitalWrite(A,HIGH);
        if(n / 4){
          n %= 4; 
          digitalWrite(B,HIGH);
          if(n / 2){ 
            n %= 2;
            digitalWrite(C,HIGH);
            if(n / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
          else{
            n %= 2;
            digitalWrite(C,LOW);
            if(n / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
        }
        else{
          n %= 4;
          digitalWrite(B,LOW);
          if(n / 2){ 
            n %= 2;
            digitalWrite(C,HIGH);
            if(n / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
          else{
            n %= 2;
            digitalWrite(C,LOW);
            if(n / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
        }
      }
      
      
      
      
      
      else{
        n = num % 8;
        digitalWrite(A,LOW);
        if(n / 4){
          n %= 4;
          digitalWrite(B,HIGH);
          if(n / 2){
            n %= 2;
            digitalWrite(C,HIGH);
            if(n / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
          else{
            n %= 2;
            digitalWrite(C,LOW);
            if(n / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
        }
        else{
          n %= 4;
          digitalWrite(B,LOW);
          if(n / 2){
            n %= 2;
            digitalWrite(C,HIGH);
            if(n / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
          else{
            n %= 2;
            digitalWrite(C,LOW);
            if(n / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
        }
      }
    


    delay(1000);
  }
}

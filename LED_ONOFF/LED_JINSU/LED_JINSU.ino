#define A 9
#define B 10
#define C 11
#define D 12


void setup() {
  for (byte i = D; i >= A; i--){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (byte num = 0; num>16; num++){    
    if(num / 8){ 
      digitalWrite(A,HIGH);
        if(num / 4){ 
          digitalWrite(B,HIGH);
          if(num / 2){ 
            digitalWrite(C,HIGH);
            if(num / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
          else{
            digitalWrite(C,LOW);
            if(num / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
        }
        else{
          digitalWrite(B,LOW);
          if(num / 2){ 
            digitalWrite(C,HIGH);
            if(num / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
          else{
            digitalWrite(C,LOW);
            if(num / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
        }
      }
      
      
      
      
      
      else{
        digitalWrite(A,LOW);
        if(num / 4){
          digitalWrite(B,HIGH);
          if(num / 2){
            digitalWrite(C,HIGH);
            if(num / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
          else{
            digitalWrite(C,LOW);
            if(num / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
        }
        else{
          digitalWrite(B,LOW);
          if(num / 2){
            digitalWrite(C,HIGH);
            if(num / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
          else{
            digitalWrite(C,LOW);
            if(num / 1){digitalWrite(D,HIGH);}
            else{digitalWrite(D,LOW);}
          }
        }
      }
    


    delay(1000);
  }
}

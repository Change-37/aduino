void setup() {
  for (byte i = 13; i >= 10; i--){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (byte num = 0; num>16; num++){
    if(num / 1){ 
      digitalWrite(13,HIGH);
    }
    else{
      digitalWrite(13,LOW);
    }
    
    if(num / 2){ 
      digitalWrite(12,HIGH);
      }
    else{
      digitalWrite(12,LOW);
    }
    
    if(num / 4){ 
      digitalWrite(11,HIGH);
      }
    else{
      digitalWrite(11,LOW);
    }
    
    if(num / 8){ 
      digitalWrite(10,HIGH);
      }
    else{
      digitalWrite(10,LOW);
    }

    delay(1000);
  }
}

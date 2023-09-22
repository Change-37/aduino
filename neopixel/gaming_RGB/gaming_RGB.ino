#include <Adafruit_NeoPixel.h>
#include <avr/power.h>            

#define pin 7
#define num 1 // 네오픽셀 led 개수
#define light 160 // 밝기 조절. 0~255
#define btn1 4
#define btn2 5
#define btn3 6
#define del 10


Adafruit_NeoPixel strip = Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);

int color_index = 0;
int r=255, g=0, b=0;

void setup() {
//  pinMode(btn1, INPUT);
//  pinMode(btn2, INPUT);
//  pinMode(btn3, INPUT);
  
  strip.setBrightness(light);
  strip.begin(); 
  strip.show(); 

}

void loop() {
  for(int g = 0; g < 256; r-=5, g+=5){
    strip.setPixelColor(0, r, g, b);
    delay(del);
  }
  for(int b = 0; b < 256; g-=5, b+=5){
    strip.setPixelColor(0, r, g, b);
    delay(del);
  }
  for(int r = 0; r < 256; b-=5, r+=5){
    strip.setPixelColor(0, r, g, b);
    delay(del);
  }
//  strip.setBrightness(light);
//  strip.begin();
//  strip.setPixelColor(0, rgb[color_index][0], rgb[color_index][1], rgb[color_index][2]); 
//  strip.show();
//  delay(2000); 
}

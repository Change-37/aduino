#define R 3
#define G 5
#define B 6
#define DELAY 1000


void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  setColor(255, 0, 255);
  delay (DELAY);
}

void setColor(int r, int g, int b)
{
  analogWrite(R, 255-r);
  analogWrite(G, 255-g);
  analogWrite(B, 255-b);
}

int rPin=6;
int gPin=5;
int bPin=3;
int r=255;
int g=0;
int b=0;
void setup() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  while (g!=255){
    g++;
    delay(15);
    setColor(r,g,b);
  }
  while (r!=0){
    r--;
    delay(15);
    setColor(r,g,b);
  }
    while (b!=255){
    b++;
    delay(15);
    setColor(r,g,b);
  }
  while (g!=0){
    g--;
    delay(15);
    setColor(r,g,b);
  }
  while (r!=255){
    r++;
    delay(15);
    setColor(r,g,b);
  }
  while (b!=0){
    b--;
    delay(15);
    setColor(r,g,b);
  }
}
void setColor(int red,int green,int blue){
  analogWrite(rPin, red);
  analogWrite(gPin, green);
  analogWrite(bPin, blue);
}

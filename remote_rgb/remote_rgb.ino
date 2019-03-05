#include <IRremote.h>
int rPin=6;
int gPin=5;
int bPin=9;
int lastr=255;
int lastg=255;
int lastb=255;
int onoff=0;
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  Serial.println(lastr);
  Serial.println(lastg);
  Serial.println(lastb);
  if (irrecv.decode(&results)){
        switch(results.value){
          case 0xFFA25D:
          if (onoff==0){
            setColor(lastr,lastg,lastb);
            onoff=1;
          }
          else{
            off();
            onoff=0;
          }
          Serial.println("ON/OFF");
          break;  
          case 0xFF6897:
          setColor(255,255,255);
          lastr=255;
          lastg=255;
          lastb=255;
          Serial.println("0");
          break ;  
          case 0xFF30CF:
          setColor(255,0,0);
          Serial.println("1");
          break ;
          case 0xFF18E7:
          setColor(0,255,0);
          Serial.println("2");
          break ;
          case 0xFF7A85:
          setColor(0,0,255);
          Serial.println("3");
          break ;
          case 0xFF10EF:
          setColor(255,255,0);
          Serial.println("4");
          break ;
          case 0xFF38C7:
          setColor(0,255,255);
          Serial.println("5");
          break ;
          case 0xFF5AA5:
          setColor(255,0,255);
          Serial.println("6");
          break ;
          case 0xFF42BD:
          setColor(lastr-10,lastg,lastb);
          Serial.println("7");
          setColor(255,0,60);
          break ;
          case 0xFF4AB5:
          setColor(255,30,0);
          Serial.println("8");
          break ;
          case 0xFF52AD:
          setColor(60,60,60);
          Serial.println("9");
          break ;
        }
        irrecv.resume(); 
  }
}
void setColor(int red,int green,int blue){
  analogWrite(rPin, red);
  analogWrite(gPin, green);
  analogWrite(bPin, blue);
  lastr=red;
  lastg=green;
  lastb=blue;
}
void off(){
  analogWrite(rPin, 0);
  analogWrite(gPin, 0);
  analogWrite(bPin, 0);
}

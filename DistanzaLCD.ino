#include <LiquidCrystal.h>
int rs=12;
int e=11;
int D4=5;
int D5=4;
int D6=3;
int D7=2;
int triggerPin=9;
int echoPin=10;
long duration;
int distance;
//buzzpin attiva anche il led
int buzzPin=8;
LiquidCrystal lcd(rs,e,D4,D5,D6,D7);
void setup()
{
  //inizializza i pin 
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzPin,OUTPUT);
  Serial.begin(9600);
  //inizializza l'lcd con le seguenti dimensioni
  lcd.begin(16,2);
  lcd.print("Dio bufu");
}
void loop()
{
  //Reset dello schermo e del sensore
  lcd.clear();
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);
  
  //Manda un impulso con il sensore
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  duration=pulseIn(echoPin, HIGH);
  
  //Calcola la distanza
  distance=duration*0.034/2;
  
  //Manda l'output alla console e allo schermo
  Serial.println(distance);
  lcd.print("Distanza: ");
  lcd.setCursor(0,1);
  //Se la distanza è > di 500 dà errore
  if (distance <=500)
  {
    digitalWrite(buzzPin,LOW);
    lcd.print(distance);
  }
  else
  {
    digitalWrite(buzzPin,HIGH);
    lcd.print("errore");
  }
  //Delay finale
  delay(100);  
}

//Lo scopo è di misurare una distanza e mostrarla sull'lcd
//Include la libreria per lo schermo
#include <LiquidCrystal.h>
//Stabilisce i pin dell'lcd
int rs=12;
int e=11;
int D4=5;
int D5=4;
int D6=3;
int D7=2;
//Stabilisce i pin del sensore
int triggerPin=9;
int echoPin=10;
//Stabilisce le variabili usate dal sensore
long duration;
int distance;
//Stabilisce i pin del bottone
int botPin=13;
//Stabilisce la variabile per leggere lo stato del bottone (HIGH,LOW)
int botStatus;
//Inizializza buzzpin che attiva anche il led
int buzzPin=8;
//Inizializza l'lcd con i pin stabiliti sopra
LiquidCrystal lcd(rs,e,D4,D5,D6,D7);
void setup()
{
  //inizializza i pin 
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzPin,OUTPUT);
  pinMode(botPin,INPUT);
  
  //Inizializza la console
  Serial.begin(9600);
  
  //inizializza l'lcd con le seguenti dimensioni
  lcd.begin(16,2);
 }
void loop()
{
  //Legge lo stato del bottone
  botStatus=digitalRead(botPin);
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
  
   //determina se il bottone è stato sciacciato
  if (botStatus == HIGH)
  {
  //Inzia un timer di 2 secondi e poi printa la distanza misurata facendo anche suonare il buzzer
  lcd.print("1");
  delay(1000);
  lcd.clear();
  lcd.print("2");
  delay(1000);
  lcd.clear();
  digitalWrite(buzzPin, HIGH);
  lcd.print("Distanza:");
  lcd.print(distance);
  delay(2000);
  lcd.clear();
  delay(500);
  

  }
  else
  {
  
  //Manda l'output alla console e allo schermo
  Serial.println(distance);
  lcd.print("Distanza: ");
  lcd.setCursor(0,1);
  
  //Se la distanza è > di 500 dà errore
  if (distance <=500)
  {
    //Spegne il led e il buzzer se accesi
    digitalWrite(buzzPin,LOW);
    //Mostra sull'lcd la distanza
    lcd.print(distance);
  }
  else
  {
    //Accende il buzzer e il led
    digitalWrite(buzzPin,HIGH);
    //Mostra un errore sul lcd
    lcd.print("errore");
  }
  //Delay finale
  delay(200);  
  }
}

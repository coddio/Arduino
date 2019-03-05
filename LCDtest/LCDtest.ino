#include <LiquidCrystal.h>
int rs=12;
int e=11;
int D4=5;
int D5=4;
int D6=3;
int D7=2;
int triggerPin=9;
int echoPin=10;
LiquidCrystal lcd(rs,e,D4,D5,D6,D7);
void setup()
{
  //inizializza l'lcd con le seguenti dimensioni
  lcd.begin(16,2);
}
void loop()
{
  //stampa i seguenti caratteri
  lcd.print("Dio porco");
  //imposta il cursore alle cordinate (x,y)
  lcd.setCursor(3,1);
  lcd.print("Gesu fritto");
  delay(3000);
  //pulisce lo schermo
  lcd.clear();
  
  lcd.print("Madonna negra");
  lcd.setCursor(3,1);
  lcd.print("Cristo morto");
  delay(3000);

  lcd.clear();
  
}

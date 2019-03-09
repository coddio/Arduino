//lo scopo del codice è mostrare su un LCD il valore di un  bottone usato come interruttore

//inizializzazione variabili e libreria LCD
#include <LiquidCrystal.h>
int rs=12;
int e=11;
int D4=5;
int D5=4;
int D6=3;
int D7=2;
LiquidCrystal lcd(rs,e,D4,D5,D6,D7);

//inizializzazione variabili bottone
int butPin=7;
int butState=0;
int lastState=1;
bool Switch=false;
bool lastSwitch=false; 

void setup() {
  //inizializzazione
  lcd.begin(16,2); //avvia l'LCD
  pinMode(butPin,INPUT); //imposta il bottone come input
  Serial.begin(9600); //avvia Serial
}

void loop() {
  butState=digitalRead(butPin); //legge lo stato del bottone e lo assegna ad una variabile
  //verifica che il bottone sia acceso e che non fosse acceso prima per evitare che venga tenuto premuto
  if ((butState==1)and(lastState==0)){
    Switch = !Switch; //inverte il valore di Switch 
    Serial.println(Switch);
    lastState=1; //segnala che il bottone è già stato considerato, e quindi non può essere tenuto èremuto
  }
  //altrimenti se il bottone è spento resetta il laststate
  else if (butState==0){
    lastState=0;
  }
  //se l'interruttore è appena stato acceso
  if((Switch==true)and(Switch!=lastSwitch)){
    lcd.clear(); //reset dello schermo
    lcd.print("on"); //mostra on sull'LCD
    lastSwitch=true; //infine per evitare ripetizioni dice che è già stato attivato
  }
  //se l'interruttore è appena stato spento
  else if ((Switch==false)and(Switch!=lastSwitch)){
    lcd.clear(); //reset dello schermo
    lcd.print("off"); //mostra on sull'LCD
    lastSwitch=false; //infine per evitare ripetizioni dice che è già stato attivato
  }
}

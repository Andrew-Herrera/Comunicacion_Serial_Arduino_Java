#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
const int led1 = 10; 
const int led2 = 9;
const int led3 = 8;

void setup() {
  lcd.begin(16, 2); 
  Serial.begin(9600); 
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  lcd.setCursor(0,0);
  lcd.print("Bienvenidos!!"); 
   lcd.setCursor(0,1);
  lcd.print(":3"); 
}

void loop() { 
  if(Serial.available() > 0){ 
    char opc = Serial.read();
    lcd.clear();
    if(opc == 'a'){ //area de atencion al cliente
      lcd.setCursor(0,0);
       lcd.print("Pase a: atencion"); 
       lcd.setCursor(0,1);
       lcd.print("al cliente");
       digitalWrite(led1, HIGH);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
    }else if(opc == 'b'){ //area de ventanilla
       lcd.setCursor(0,0);
       lcd.print("Pase a:"); 
       lcd.setCursor(0,1);
       lcd.print("ventanilla");
       digitalWrite(led1, LOW);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, LOW);
    }else if(opc== 'c'){ //area de cajero/practicaja
       lcd.setCursor(0,0);
       lcd.print("Pase a: "); 
       lcd.setCursor(0,1);
       lcd.print("cajero");
       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
       digitalWrite(led3, HIGH);
    } else if(opc == 'd'){ //salida
       lcd.setCursor(0,0);
       lcd.print("Adios !!"); 
       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
    }else{
       lcd.setCursor(0,0);
       lcd.print("ERROR! opcion");
       lcd.setCursor(0,1);
       lcd.print("no valida");
    }
  }
  Serial.flush();
  delay(1000);
}
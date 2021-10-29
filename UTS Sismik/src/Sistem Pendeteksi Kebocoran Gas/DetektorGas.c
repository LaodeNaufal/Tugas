// Laode M Naufal 
// Prak Sistem Kendali B2
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int alarm = 8; 
int gas_pin = 0;
float gas_data = 0;
int LED_danger = 9;
int LED_safe = 10;

void setup() {

    lcd.begin(16, 2);
}

void loop() {


    gas_data = analogRead(gas_pin);
    lcd.setCursor(0, 0);
	lcd.print("Pendeteksi Gass");
	lcd.setCursor(0, 1);
      lcd.print("Gas : ");
      lcd.setCursor(6, 1);
      lcd.print(gas_data);
      digitalWrite(alarm,LOW);
      digitalWrite(LED_danger,LOW);
      digitalWrite(LED_safe,HIGH);

    while(gas_data>200){//200
      gas_data = analogRead(gas_pin);
      digitalWrite(alarm,HIGH);
      digitalWrite(LED_danger,HIGH);
      digitalWrite(LED_safe,LOW);
      lcd.setCursor(0, 0);
      lcd.print("Pendeteksi Gas");
      lcd.setCursor(0, 1);
      lcd.print("Bahaya bozz!!");
      delay(200);
	}
	delay(200);
}
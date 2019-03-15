// 02/18/2019 - Written by Austin Randolph

#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 2        // digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11 sensor

// lcd display object instance
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// dht sensor object instance
DHT dht(DHTPIN, DHTTYPE);

void printLcdTemperatureRow() {
  
  lcd.setCursor(0, 0);
  lcd.print("TEMP: " + String(dht.readTemperature(true)) + "F");
}

void printLcdDataRow() {
  
  lcd.setCursor(0, 1); 
  lcd.print("HUMIDITY: " + String(dht.readHumidity()) + "%");
}

void scrollText(){

  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(100);
  }
}
//
// ******************************************************* [SETUP] ****************************************************
//

void setup() {
  
   Serial.begin(9600);                // debug
  
  lcd.begin(16, 2);                     // set up the LCD's number of columns and rows:

  dht.begin();

  Serial.println("DHT11 Started..."); // debug
}

//
// ******************************************************** [LOOP] *****************************************************
//

void loop() {

  lcd.clear();

  printLcdTemperatureRow();
  printLcdDataRow();
  delay(1000);

  lcd.clear();

  delay(500);

  printLcdTemperatureRow();
  printLcdDataRow();
  delay(5000);

  scrollText();

  delay(500);
}

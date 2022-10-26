/* 
* Current Humidity and Temperature Output to an LCD Display
* Author: Zachary Kruljac
* Description: This project takes the DHT11, which records humidity and temperature, and displays these variables to an
* LCD display. 
* Required Hardware: Mega 2560, DHT11, LCD1602, 10k Potentiometer, Breadboard & wire
* Setup: A - Positive, K - Ground, 
*/
#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 5
#define DHTTYPE DHT11

LiquidCrystal lcd(7,8,9,10,11,12);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);

  dht.begin();                                      //Starts DHT11
  lcd.print("Temperature: ");
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
}

void loop() {
  delay(500);                                       //Waits .5 seconds to loop through again
  float temp = dht.readTemperature() * 2 + 30;      //Reads Temp in Celcius and converts to Farehenheit
  float humidity = dht.readHumidity();

  if(isnan(humidity) && isnan(temp)){               // If temp or humidity are non readable numbers print ERROR
    lcd.print("ERROR");
    return;
  }

  lcd.setCursor(12,0);                            
  lcd.print(temp);
  lcd.setCursor(12,1);
  lcd.print(humidity);

}

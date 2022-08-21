#include <Wire.h> 
#include <SimpleDHT.h>
#include <LiquidCrystal_I2C.h> 

SimpleDHT11 dht11;
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte pin = 2;

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  byte temperature;
  byte humidity;
  dht11.read(pin, &temperature, &humidity, NULL);

  Serial.print(temperature);
  Serial.print("°C, "); 
  Serial.print(humidity); 
  Serial.println(" H");
 
  lcd.begin();
  lcd.print("Temperature:");
  lcd.print(temperature);
  lcd.print((char) 0xDF);
  lcd.print("C");
  lcd.setCursor(3, 1);
  lcd.print("Humidity:");
  lcd.print(humidity);
  lcd.print(" %");

  delay(1500);
  
}

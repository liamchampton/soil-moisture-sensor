#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 128;
const int colorG = 0;
const int colorB = 128;
const int dry = 599; // value for dry sensor
const int wet = 253; // value for wet sensor
const unsigned long SECOND = 1000; // 1 second = 1000 milliseconds
const unsigned long HOUR = 3600*SECOND;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {

  int sensorVal = analogRead(A0);
  lcd.clear();

  // transate sensor value range into %

  int percentageConversion = map(sensorVal, wet, dry, 100, 0);

  if (percentageConversion < 50) {
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);             // wait for a second
    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);             // wait for a second 
  }

  
  Serial.print(percentageConversion);
  Serial.println("%");

  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print(F("Soil moisture"));
  lcd.setCursor(0, 1);
  lcd.print(String(percentageConversion)+F("%"));
  
  delay(2*HOUR);
}

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

// C++ code
//
const int trigPin = 9;
const int echoPin = 10;
float duration, distance;
const int khoangcach = 88; 
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.blacklight();
  lcd.setCursor(0, 0); 
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  if (distance < khoangcach) {
    lcd.print("   HELLO  "); 
  } else {
    lcd.print("  NO SIGNAL  "); 
  }  
  delay(1000); 
}
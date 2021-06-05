#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
Servo myservo; 
LiquidCrystal_I2C lcd(0x27, 16, 2);
int merahPin = 6; //nama alias pin 6 sebagai merahPin
int hijauPin = 5; //nama alias pin 5 sebagai hijaupin
int biruPin = 3; //nama alias pin 3 sebagai biruPin
int tunda = 1; // satuan dalam milisecond
#define DHTPIN A3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  myservo.attach(9); 
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sensor DHT11");
  dht.begin();
  pinMode(merahPin, OUTPUT);
  pinMode(hijauPin, OUTPUT);
  pinMode(biruPin, OUTPUT);
}

void loop() {
  lcd.clear();
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0,0);
  lcd.print("Temp : ");
  lcd.print(t);
  lcd.print(" 'C");
  lcd.setCursor(0,1);
  lcd.print("Hum : ");
  lcd.print(h);
  lcd.print(" %");
  delay(1000);

    if (t >= 40) {
    delay(100);  
    digitalWrite(merahPin, LOW);
    delay(tunda);
    digitalWrite(merahPin, HIGH);
    myservo.write(30); 
    delay(150);
    myservo.write(180); 
    delay(150);
    myservo.write(270); }
    
  else if (t <=40, t >= 35){
    digitalWrite(hijauPin, LOW);
    delay(tunda);
    digitalWrite(hijauPin, HIGH);
    myservo.write(30); 
    delay(100);
    myservo.write(180); 
    delay(100);
    myservo.write(270); 
    }
  else {
    digitalWrite(biruPin, LOW);
    delay(tunda);
    digitalWrite(biruPin, HIGH);
} 
}

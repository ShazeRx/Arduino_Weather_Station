#include "DHT.h"
#define DHT11_PIN 7
#include <Process.h>
#include <Bridge.h>
DHT dht;
int measurePin = A1;
int ledPower = 4;

unsigned int samplingTime = 280;
unsigned int deltaTime = 40;
unsigned int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  
  dht.setup(DHT11_PIN);
  Bridge.begin(); 

}

void loop() {
  digitalWrite(ledPower,LOW);
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin);

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH);
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured*(5.0/1024);
  dustDensity = 0.17*calcVoltage-0.1;
  if ( dustDensity < 0)
  {
    dustDensity = 0.00;
  }
  
  int wilgotnosc = dht.getHumidity();
  int temperatura = dht.getTemperature();
  Process p;
  p.begin("/mnt/sda1/db.php");  
  p.addParameter(String(temperatura));
  p.addParameter(String(wilgotnosc));
  p.addParameter(String(dustDensity));
  
  
  p.run();
  delay(300000);
  

}

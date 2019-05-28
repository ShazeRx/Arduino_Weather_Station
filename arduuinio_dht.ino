#include "DHT.h"
#define DHT11_PIN 7
DHT dht;
int sensor_A0 = A0;    // podłączenie od A0 na czujniku do A0 na Arduino
int sensor_D0 = 2;     // podłączenie od D0 na czujniku do pinu 2 na Arduino
int wartosc_A0;        // zmienna dla wartości A0
int wartosc_D0; 
 
void setup()
{
  Serial.begin(9600);
  dht.setup(DHT11_PIN);
  pinMode(2, INPUT);
  
}
 
void loop()
{
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  //Pobranie informacji o temperaturze
  int temperatura = dht.getTemperature();
  
  if (dht.getStatusString() == "OK") {
    Serial.print(wilgotnosc);
    Serial.print("%RH | ");
    Serial.print(temperatura);
    Serial.println("*C");
  }
  wartosc_A0 = analogRead(sensor_A0);      // pobranie wartości z A0
 wartosc_D0 = digitalRead(sensor_D0);     // pobranie wartości z D0
 
 Serial.print("D0: ");                    // wyświetlenie na monitorze szeregowym
 Serial.print(wartosc_D0);
 Serial.print("  --  A0: ");
 Serial.println(wartosc_A0);
  
  //Odczekanie wymaganego czasugo
  delay(dht.getMinimumSamplingPeriod());
}

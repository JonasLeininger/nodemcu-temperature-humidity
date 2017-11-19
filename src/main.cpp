#include <Arduino.h>

#include "DHT.h"

DHT dht(D4, DHT22);

void setup()
{
  Serial.begin(9600);
//   // Serial.begin(115200);
  Serial.println("DHT Test!");
  dht.begin();
}

void loop()
{
  delay(2000);
    float temp = dht.readTemperature();
    float humid = dht.readHumidity();

    if(isnan(temp) || isnan(humid)) {
        Serial.println("There are no Values!");
    } else {
        Serial.print(" Temperature: ");
        Serial.print(temp);
        Serial.print("C");
        Serial.print("\t Humidity: ");
        Serial.print(humid);
        Serial.println("%");
    }
}

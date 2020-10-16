#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Initialization
void setup() {
  
  dht.begin();
  Serial.begin(9600);
  
}

void loop() {
  
  // Read values
  float h = dht.readHumidity();
  float v = dht.readTemperature(true);

  // Not a Number
  if( isnan(h) || isnan(v) ){
    Serial.print("No Data.\n");
    delay(10000);
    return;
  }
    
  // Print results
  Serial.print("Temp (°F): ");
  Serial.print(v);
  Serial.print("\n");

  Serial.print("Humidity (%): ");
  Serial.print(h);
  Serial.print("\n");
  
  delay(10000);
}

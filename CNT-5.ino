//Temp
  #include <DHT.h>
  #include <Adafruit_Sensor.h>
  
  #define DHTPIN 2
  #define DHTTYPE DHT11
  DHT dht(DHTPIN, DHTTYPE);
  
void setup() {
//Start DHT11
  dht.begin();
//Start Serial
  Serial.begin(9600);
}

void loop() {
//Read values
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  float valid = dht.readTemperature(true);
//Check Reading State
  if (isnan(humi) || isnan(temp) || isnan(valid)) {
    Serial.println(F("Read Failed"));
    return;
  }
//Set Index
  float hif = dht.computeHeatIndex(valid, humi);
  float hic = dht.computeHeatIndex(temp, humi, false);
//Print 
  Serial.println(" ");
  Serial.print(F("Humidity: "));
  Serial.print(humi);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp);
  Serial.print(F("°C "));
  Serial.print(valid);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  delay(1000);
}
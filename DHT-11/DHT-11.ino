#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 16
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// START
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object

// Initialization
void setup() {

  dht.begin();

  // START
  byte numDigits = 4;
  byte digitPins[] = {A3, A0, 15, 7};
//  byte segmentPins[] = {A2, 14, 5, 3, 2, A1, 6, 4};
  byte segmentPins[] = {A2, A1, 14, 2, 3, 4, 5, 6};
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = NP_COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);

  Serial.begin(9600);

}

void loop() {

//  delay(10);

  // Read values
  float h = dht.readHumidity();
  float v = dht.readTemperature(true);

  // Not a Number
  if ( isnan(h) || isnan(v) ) {
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

  sevseg.setNumber(v);
  sevseg.refreshDisplay();

}

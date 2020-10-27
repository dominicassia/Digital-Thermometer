#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object

int d1 = A3;
int d2 = A0;
int d3 = 15;
int d4 = 7;

int a = A2;
int b = 14;
int c = 5;
int d = 3;
int e = 2;
int f = A1;
int g = 6;
int dp = 4;

int input = 16;

void setup() {

  // Set pin mode

    pinMode(input, INPUT);  // Temp sensor

    pinMode(d1, OUTPUT);    // Cathode
    pinMode(d2, OUTPUT);    // Cathode
    pinMode(d3, OUTPUT);    // Cathode
    pinMode(d4, OUTPUT);    // Cathode

    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(dp, OUTPUT);
  
//  byte numDigits = 4;
//  byte digitPins[] = {A3, A0, 15, 7};
//  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
//  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
//  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
//  bool updateWithDelays = false; // Default 'false' is Recommended
//  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
//  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]
//
//  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
//  updateWithDelays, leadingZeros, disableDecPoint);
}

void loop() {

  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);

  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, HIGH);

  delay(2500);

  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
  
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  delay(5000);
  
}

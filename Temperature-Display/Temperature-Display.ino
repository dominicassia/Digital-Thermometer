/* 
 *****DHT-11*****
     -------
    | ##### |
    | ##### |
    | ##### |
    |-------|
    | + S - |
     -------
    
 *****SEGMENT*****
        AAA
       F   B
       F   B
        GGG
       E   C
       E   C
        DDD  DP
        
  *****DISPLAY*****
  --------------------------
 |     D1 A  F  D2 D3 B     |
 |                          |
 |     E  D  DP C  G  D4    |
  --------------------------

  *****MICRO PRO*****
  -----------------------------
 | VCC A3 A2 A1 A0 15 14 (16)  |
 |                             |
 | GND 2  3  4  5  6  7        |
  -----------------------------

  *****PINS*****
  MICRO PRO :   DISPLAY
  
         [ TOP ]
      A3    :    D1
      A2    :    A
      A1    :    F
      A0    :    D2
      15    :    D3
      14    :    B
      
        [ BOTTOM ]
      02    :    E
      03    :    D
      04    :    DP
      05    :    C
      06    :    G
      07    :    D4
      
  MICRO PRO :   DHT-11
      16    :   SIGNAL 
      VCC   :   (+)
      GND   :   (-)


  Note: Common Cathode Display    
*/

// DHT-11
  #include <DHT.h>
  #include <Adafruit_Sensor.h>
  
  #define DHTPIN 16
  #define DHTTYPE DHT11
  
  DHT dht(DHTPIN, DHTTYPE);

// 7 Segment Display
  // -- Digits
  #define d1 A3
  #define d2 A0
  #define d3 15
  #define d4 7
  
  // -- Segments
  #define a A2
  #define b 14
  #define c 5
  #define d 3
  #define e 2
  #define f A1
  #define g 6
  #define dp 4

// ** BEGIN Display Functions **

void pinOn(char pin){
  digitalWrite(pin, HIGH);
}

void pinOff(char pin){
  digitalWrite(pin, LOW);
}

void blinkSeg(char pin, int i){
    pinOn(pin);
    delay(i);
    pinOff(pin);
    delay(i); 
}

void checkDigit(char digit, int i){
    pinOn(digit);
    blinkSeg(a, i);
    blinkSeg(b, i);
    blinkSeg(c, i);
    blinkSeg(d, i);
    blinkSeg(e, i);
    blinkSeg(f, i);
    blinkSeg(g, i);
    blinkSeg(dp, i);
    pinOff(digit);
}

void allSegCheck(int i){
  // i is the delay between each blink 50-100ms recommended
  checkDigit(d1, i);
  checkDigit(d2, i);
  checkDigit(d3, i);
  checkDigit(d4, i);
}

void allOn(){
  pinOn(d1);
  pinOn(d2);
  pinOn(d3);
  pinOn(d4);
  
  pinOn(a);
  pinOn(b);
  pinOn(c);
  pinOn(d);
  pinOn(e);
  pinOn(f);
  pinOn(g);
  pinOn(dp);
  
}

void allOff(){
  pinOff(d1);
  pinOff(d2);
  pinOff(d3);
  pinOff(d4);
  
  pinOff(a);
  pinOff(b);
  pinOff(c);
  pinOff(d);
  pinOff(e);
  pinOff(f);
  pinOff(g);
  pinOff(dp);
}

void flashAll(int n, int i){
  // n: number of times, i: delay
  int count = 0;
  while(count != n){
    allOn();
    delay(i);
    allOff();
    delay(i);
    count = count + 1;
  }
}

void numOn(int n, String dec = "none"){
  // Add decimal point
  if(dec == "dp"){
    pinOn(dp);
  }else{
    pinOff(dp);
  }
  switch(n){
    case 0:
      pinOn(a);
      pinOn(b);
      pinOn(c);
      pinOn(d);
      pinOn(e);
      pinOn(f);
      break;
    case 1:
      pinOn(b);
      pinOn(c);
      break;
    case 2:
      pinOn(a);
      pinOn(b);
      pinOn(g);
      pinOn(e);
      pinOn(d);
      break;
    case 3:
      pinOn(a);
      pinOn(b);
      pinOn(g);
      pinOn(c);
      pinOn(d);
      break;
    case 4:
      pinOn(b);
      pinOn(c);
      pinOn(g);
      pinOn(f);
      break;
    case 5:
      pinOn(a);
      pinOn(f);
      pinOn(g);
      pinOn(c);
      pinOn(d);
      break;
    case 6:
      pinOn(a);
      pinOn(f);
      pinOn(g);
      pinOn(c);
      pinOn(e);
      pinOn(d);
      break;
    case 7:
      pinOn(a);
      pinOn(b);
      pinOn(c);
      break;
    case 8:
      pinOn(a);
      pinOn(b);
      pinOn(c);
      pinOn(d);
      pinOn(e);
      pinOn(f);
      pinOn(g);
      break;
    case 9:
      pinOn(a);
      pinOn(b);
      pinOn(c);
      pinOn(f);
      pinOn(g);
      break;     
    default:
      pinOn(g);
      break;
  }
  
}

void numOff(int n, String dec = "none"){
  // Add decimal point
  if(dec == "dp"){
    pinOff(dp);
  }else{
    pinOff(dp);
  }
  
  switch(n){
    case 0:
      pinOff(a);
      pinOff(b);
      pinOff(c);
      pinOff(d);
      pinOff(e);
      pinOff(f);
      break;
    case 1:
      pinOff(b);
      pinOff(c);
      break;
    case 2:
      pinOff(a);
      pinOff(b);
      pinOff(g);
      pinOff(e);
      pinOff(d);
      break;
    case 3:
      pinOff(a);
      pinOff(b);
      pinOff(g);
      pinOff(c);
      pinOff(d);
      break;
    case 4:
      pinOff(b);
      pinOff(c);
      pinOff(g);
      pinOff(f);
      break;
    case 5:
      pinOff(a);
      pinOff(f);
      pinOff(g);
      pinOff(c);
      pinOff(d);
      break;
    case 6:
      pinOff(a);
      pinOff(f);
      pinOff(g);
      pinOff(c);
      pinOff(e);
      pinOff(d);
      break;
    case 7:
      pinOff(a);
      pinOff(b);
      pinOff(c);
      break;
    case 8:
      pinOff(a);
      pinOff(b);
      pinOff(c);
      pinOff(d);
      pinOff(e);
      pinOff(f);
      pinOff(g);
      break;
    case 9:
      pinOff(a);
      pinOff(b);
      pinOff(c);
      pinOff(f);
      pinOff(g);
      break;  
    default:
      pinOn(g);
      break;   
  }
}

void cfOn(String deg){
  if(deg == "c"){
    pinOn(a);
    pinOn(d);
    pinOn(e);
    pinOn(f);
  }
  if(deg == "f"){
    pinOn(a);
    pinOn(f);
    pinOn(g);
    pinOn(e);
  }
}

void cfOff(String deg){
  if(deg == "c"){
    pinOff(a);
    pinOff(d);
    pinOff(e);
    pinOff(f);
  }
  if(deg == "f"){
    pinOff(a);
    pinOff(f);
    pinOff(g);
    pinOff(e);
  }
}

void count(char digit, int i, bool all = false){
    // digit: the digit to display on, i: amount of time number is displayed

    if( all == true ){
      pinOn(d1);
      pinOn(d2);
      pinOn(d3);
      pinOn(d4);
    }else{
      pinOn(digit);
    }
    
    int count = 0;
    while(count != 10){
      
      numOn(count);
      delay(i);
      numOff(count);
      
      count = count + 1;
    }

    if( all == true ){
      pinOff(d1);
      pinOff(d2);
      pinOff(d3);
      pinOff(d4);
    }else{
      pinOff(digit);
    }
}

int dpIndex(float value){
  
  // Convert to a string
  String v;
  v = String(value);
  
  for(int i = 0; i < 4; i++){
    
    // Index up the number
    String temp = v.substring(i,i+1);
    
    // Break if found, i is the index of the dp
    if(temp == "."){
      return i;
    }
  }
}

void displayValue(float value, int dpIndex, int i){

  // value: value to display, dpIndex: index of decimal point in value, i: delay between updating values

  // Convert to a string
  String v;
  v = String(value);

  switch(dpIndex){
    case 1:
   
      // Indices, digit 1 gets the decimal 0.00F
      flicker( v.substring(0,1).toInt(), v.substring(2,3).toInt(), v.substring(3,4).toInt(), 1, "f", i);
      break;
      
    case 2:
    
      // Indices, digit 2 gets the decimal 00.0F
      flicker( v.substring(0,1).toInt(), v.substring(1,2).toInt(), v.substring(3,4).toInt(), 2, "f", i);
      break;

    case 3:

      // No dp bc whole num
      flicker( v.substring(0,1).toInt(), v.substring(2,3).toInt(), v.substring(3,4).toInt(), 0, "f", i);
      break;
  }
}

void flicker(int v1, int v2, int v3, int decimal, String cf, int t){

  int dTime = 1;

  for( int i = 0; i < t*1000; i++ ){
    
    bool dec = false;
    
    // Digit 4
    if( i % 4 == 0 ){

      if( cf == "f" ){
        pinOn( d4 );
        cfOn( "f" );
        delay( dTime );
        cfOff( "f" );
        pinOff( d4 ); 
      }

      if( cf == "c" ){
        pinOn( d4 );
        cfOn( "c" );
        delay( dTime );
        cfOff( "c" );
        pinOff( d4 );
      }
      
    }

    // Digit 3
    if( i % 3 == 0){
      
      // Check for dp
      if( decimal == 3 ){
        pinOn( d3 );
        numOn( v3, "dp" );
        delay( dTime );
        numOff( v3, "dp" );
        pinOff( d3 );      
      }else{
        pinOn( d3 );
        numOn( v3 );
        delay( dTime );
        numOff( v3 );
        pinOff( d3 );  
      }
    }

    // Digit 2
    if( i % 2 == 0){
      
      // Check for dp
      if( decimal == 2 ){
        pinOn( d2 );
        numOn( v2, "dp" );
        delay( dTime );
        numOff( v2, "dp" );
        pinOff( d2 );
      }else{
        pinOn( d2 );
        numOn( v2 );
        delay( dTime );
        numOff( v2 );
        pinOff( d2 );  
      }
    }    

    // Digit 1
    if( i % 1 == 0){
      
      // Check for dp
      if( decimal == 1 ){
        pinOn( d1 );
        numOn( v1, "dp" );
        delay( dTime );
        numOff( v1, "dp" );
        pinOff( d1 );
      }else{
        pinOn( d1 );
        numOn( v1 );
        delay( dTime );
        numOff( v1 );
        pinOff( d1 );  
      }
    }
  }
  
}

void initialization(int i){
  allSegCheck(i/2);
  delay(i);
  count(d1, i*1.25);
  delay(i);
  count(d2, i*1.25);
  delay(i);
  count(d3, i*1.25);
  delay(i);
  count(d4, i*1.25);
  delay(i);
  count(d1, i*1.25, true);
  delay(i);
  flashAll(2, i);
  delay(i);
}

// ** END Display Functions **

void setup(){

  // DHT-11
    dht.begin();

  // 7 Segment Display - Assign Pins
    pinMode(DHTPIN, INPUT);  // Temp sensor

    pinMode(d1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(d4, OUTPUT);

    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(dp, OUTPUT);
}

void loop() {

  // 7 Segment Display initalization sequence
  int i = 100;
  initialization(i);

  while(true){
    
    // DHT-11 - Read values
    float h = dht.readHumidity();
    float v = dht.readTemperature(true);
  
    // Not a Number (nan)
    if ( isnan(h) || isnan(v) ) {
      Serial.print("No Data.\n");
      delay(10000);
      return;
    }

    // -5 to adjust for difference
    displayValue(v-5, dpIndex(v-5), 4);
    
  }
}

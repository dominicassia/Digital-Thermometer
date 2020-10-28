/* 
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
 |     A3 A2 A1 A0 15 14       |
 |                             |
 |     2  3  4  5  6  7        |
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


  Note: Common Cathode Display    
*/

// Digits
#define d1 A3
#define d2 A0
#define d3 15
#define d4 7

// Segments
#define a A2
#define b 14
#define c 5
#define d 3
#define e 2
#define f A1
#define g 6
#define dp 4

// Temp sensor
#define input 16


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

void numOn(int n){
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

void numOff(int n){
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

void count(char digit, int i){
    // digit: the digit to display on, i: amount of time number is displayed
  
    pinOn(digit);
  
    int count = 0;
    while(count != 10){
      
      numOn(count);
      delay(i);
      numOff(count);
      
      count = count + 1;
    }

    pinOff(digit);

}

void setup(){

  // Assign Pins
    pinMode(input, INPUT);  // Temp sensor

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

  int i = 100;


    

  

//  allSegCheck(i);
//
//  delay(i);
//
//  flashAll(2, i*2);
//
//  delay(i);

}

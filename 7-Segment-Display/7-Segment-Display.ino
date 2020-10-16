/* 
  Cathodes
  Digit 1 --> Digit 4
  D9, D10, D11, D12
  
  Anodes
  D0, D1, D2, D4, D5, D6, D7, D8

  2  --> G
  3  --> C
  4  --> DP
  5  --> D
  6  --> B
  7  --> F
  8  --> A
  A0 --> E
*/

int digit_1 = 12;
int digit_2 = 11;
int digit_3 = 10;
int digit_4 = 9;
char none = "none";

// ----- START on/off segments -----
void a(int i){
  if(i == 0)
    digitalWrite( 8, LOW );
  else
    digitalWrite( 8, HIGH );
}

void b(int i){
  if(i == 0)
    digitalWrite( 6, LOW );
  else
    digitalWrite( 6, HIGH );
}

void c(int i){
  if(i == 0)
    digitalWrite( 3, LOW );
  else
    digitalWrite( 3, HIGH );
}

void d(int i){
  if(i == 0)
    digitalWrite( 5, LOW );
  else
    digitalWrite( 5, HIGH );
}

void e(int i){
  if(i == 0)
    analogWrite( A0, 0 );
  else
    analogWrite( A0, 255 );
}

void f(int i){
  if(i == 0)
    digitalWrite( 7, LOW );
  else
    digitalWrite( 7, HIGH );
}

void g(int i){
  if(i == 0)
    digitalWrite( 2, LOW );
  else
    digitalWrite( 2, HIGH );
}

void dp(int i){
  if(i == 0)
    digitalWrite( 4, LOW );
  else
    digitalWrite( 4, HIGH );
}

void d1(int i){
  if(i == 0)
    digitalWrite( digit_1, LOW );
  else
    digitalWrite( digit_1, HIGH );
}

void d2(int i){
  if(i == 0)
    digitalWrite( digit_2, LOW );
  else
    digitalWrite( digit_2, HIGH );
}

void d3(int i){
  if(i == 0)
    digitalWrite( digit_3, LOW );
  else
    digitalWrite( digit_3, HIGH );
}

void d4(int i){
  if(i == 0)
    digitalWrite( digit_4, LOW );
  else
    digitalWrite( digit_4, HIGH );
}

// ------ END on/off segments -----

void all(int i, char data){
  if(data=="d"){
    if(i==0){
      d1(0);
      d2(0);
      d3(0);
      d4(0);
    }
    else{
      d1(1);
      d2(1);
      d3(1);
      d4(1);
    }
  }
  else{
    if(i==0){
      a(0);
      b(0);
      c(0);
      d(0);
      e(0);
      f(0);
      g(0);
      dp(0);
    }
    else{
      a(1);
      b(1);
      c(1);
      d(1);
      e(1);
      f(1);
      g(1);
      dp(1);
    } 
  }
}

// ----- END all -----

void initialization(){

  // A
  d1(1);

  a(1);
  delay(10);
  a(0);
  delay(10);

  d1(0);
  d2(1);

  a(1);
  delay(10);
  a(0);
  delay(10);

  d2(0);
  d3(1);

  a(1);
  delay(10);
  a(0);
  delay(10);

  d3(0);
  d4(1);
  
  a(1);
  delay(10);
  a(0);
  delay(10);

  d4(0);
  
 // B
  d1(1);
 
  b(1);
  delay(10);
  b(0);
  delay(10);

  d1(0);
  d2(1);

  b(1);
  delay(10);
  b(0);
  delay(10);

  d2(0);
  d3(1);

  b(1);
  delay(10);
  b(0);
  delay(10);

  d3(0);
  d4(1);
  
  b(1);
  delay(10);
  b(0);
  delay(10);

  d4(0);

  // C
  d1(1);
 
  c(1);
  delay(10);
  c(0);
  delay(10);

  d1(0);
  d2(1);

  c(1);
  delay(10);
  c(0);
  delay(10);

  d2(0);
  d3(1);

  c(1);
  delay(10);
  c(0);
  delay(10);

  d3(0);
  d4(1);
  
  c(1);
  delay(10);
  c(0);
  delay(10);

  d4(0);

  // D
  d1(1);
 
  d(1);
  delay(10);
  d(0);
  delay(10);

  d1(0);
  d2(1);
  
  d(1);
  delay(10);
  d(0);
  delay(10);

  d2(0);
  d3(1);

  d(1);
  delay(10);
  d(0);
  delay(10);

  d3(0);
  d4(1);
  
  d(1);
  delay(10);
  d(0);
  delay(10);

  d4(0);

  // E
  d1(1);
 
  e(1);
  delay(10);
  e(0);
  delay(10);

  d1(0);
  d2(1);
  
  e(1);
  delay(10);
  e(0);
  delay(10);

  d2(0);
  d3(1);

  e(1);
  delay(10);
  e(0);
  delay(10);

  d3(0);
  d4(1);
  
  e(1);
  delay(10);
  e(0);
  delay(10);

  d4(0);

// F
  d1(1);
 
  f(1);
  delay(10);
  f(0);
  delay(10);

  d1(0);
  d2(1);
  
  f(1);
  delay(10);
  f(0);
  delay(10);

  d2(0);
  d3(1);

  f(1);
  delay(10);
  f(0);
  delay(10);

  d3(0);
  d4(1);
  
  f(1);
  delay(10);
  f(0);
  delay(10);

  d4(0);

  // G
  d1(1);
 
  g(1);
  delay(10);
  g(0);
  delay(10);

  d1(0);
  d2(1);
  
  g(1);
  delay(10);
  g(0);
  delay(10);
  
  d2(0);
  d3(1);

  g(1);
  delay(10);
  g(0);
  delay(10);

  d3(0);
  d4(1);
  
  g(1);
  delay(10);
  g(0);
  delay(10);

  d4(0);

  // DP
  d1(1);
 
  dp(1);
  delay(10);
  dp(0);
  delay(10);

  d1(0);
  d2(1);
  
  dp(1);
  delay(10);
  dp(0);
  delay(10);
  
  d2(0);
  d3(1);

  dp(1);
  delay(10);
  dp(0);
  delay(10);

  d3(0);
  d4(1);
  
  dp(1);
  delay(10);
  dp(0);
  delay(10);

  d4(0);
}

// ----- END initialization -----



void allLoop() {

  all(1, none);

  digitalWrite( digit_1, HIGH );
  delay(100);
  digitalWrite( digit_1, LOW );
  delay(100);

  digitalWrite( digit_2, HIGH );
  delay(100);
  digitalWrite( digit_2, LOW );
  delay(100);

  digitalWrite( digit_3, HIGH );
  delay(100);
  digitalWrite( digit_3, LOW );
  delay(100);

  digitalWrite( digit_4, HIGH );
  delay(100);
  digitalWrite( digit_4, LOW );
  delay(100);

  digitalWrite( digit_1, HIGH );
  digitalWrite( digit_2, HIGH );
  digitalWrite( digit_3, HIGH );
  digitalWrite( digit_4, HIGH );

  delay(100);
  
  digitalWrite( digit_1, LOW );
  digitalWrite( digit_2, LOW );
  digitalWrite( digit_3, LOW );
  digitalWrite( digit_4, LOW );
  
  delay(100);

  digitalWrite( digit_1, HIGH );
  digitalWrite( digit_2, HIGH );
  digitalWrite( digit_3, HIGH );
  digitalWrite( digit_4, HIGH );

  delay(100);
  
  digitalWrite( digit_1, LOW );
  digitalWrite( digit_2, LOW );
  digitalWrite( digit_3, LOW );
  digitalWrite( digit_4, LOW );
  
  delay(100);
  
  all(0, none);
  
  delay(2500);
}

void setup() {

  // Assign Pins
  pinMode( 0, INPUT );
  pinMode( 1, INPUT );

  pinMode( 2, OUTPUT );
  pinMode( 3, OUTPUT );
  pinMode( 4, OUTPUT );
  pinMode( 5, OUTPUT );
  pinMode( 6, OUTPUT );
  pinMode( 7, OUTPUT );
  pinMode( 8, OUTPUT );
  pinMode( 9, OUTPUT );
  pinMode( 10, OUTPUT );
  pinMode( 11, OUTPUT );
  pinMode( 12, OUTPUT );
  pinMode( A0, OUTPUT );

  Serial.begin(9600);
}

void loop() {
  initialization();
  delay(10);
  allLoop();
  delay(100);
  all(0, none);
  all(0, d);
}

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

int digit_1 = 7;
int digit_2 = 4;
int digit_3 = 3;
int digit_4 = A7;
char none[5] = "none";

// ----- START on/off segments -----

void a(int i){
  if(i == 0)
    digitalWrite( 6, LOW );
  else
    digitalWrite( 6, HIGH );
}

void b(int i){
  if(i == 0)
    digitalWrite( 2, LOW );
  else
    digitalWrite( 2, HIGH );
}

void c(int i){
  if(i == 0)
    analogWrite( A5, 0 );
  else
    analogWrite( A5, 255 );
}

void d(int i){
  if(i == 0)
    analogWrite( A3, 0 );
  else
    analogWrite( A3, 255 );
}

void e(int i){
  if(i == 0)
    analogWrite( A2, 0 );
  else
    analogWrite( A2, 255 );
}

void f(int i){
  if(i == 0)
    digitalWrite( 5, LOW );
  else
    digitalWrite( 5, HIGH );
}

void g(int i){
  if(i == 0)
    analogWrite( A6, 0 );
  else
    analogWrite( A6, 255 );
}

void dp(int i){
  if(i == 0)
    analogWrite( A4, 0 );
  else
    analogWrite( A4, 255 );
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
    analogWrite( digit_4, 0 );
  else
    analogWrite( digit_4, 255 );
}

// ------ END on/off segments -----

void all(int i, char data[5]){
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

void disp_0(){
  a(1);
  b(1);
  c(1);
  d(1);
  e(1);
  f(1);
}
void disp_1(){
  b(1);
  c(1);
}
void disp_2(){
  a(1);
  b(1);
  g(1);
  e(1);
  d(1);
}
void disp_3(){
  a(1);
  b(1);
  g(1);
  c(1);
  d(1);
}
void disp_4(){
  b(1);
  c(1);
  g(1);
  f(1);
}
void disp_5(){
  a(1);
  f(1);
  g(1);
  c(1);
  d(1);
}
void disp_6(){
  a(1);
  f(1);
  e(1);
  g(1);
  c(1);
  d(1);
}
void disp_7(){
  a(1);
  b(1);
  c(1);
}
void disp_8(){
  a(1);
  b(1);
  c(1);
  d(1);
  e(1);
  f(1);
  g(1);
}
void disp_9(){
  a(1);
  b(1);
  c(1);
  f(1);
  g(1);
}
void disp_f(){
  a(1);
  f(1);
  g(1);
  e(1);
}

// ----- END display chars -----

void allNumbers(int i){
  
  disp_0();
  delay(i);
  all(0, none);

  delay(i);

  disp_1();
  delay(i);
  all(0, none);

  delay(i);

  disp_2();
  delay(i);
  all(0, none);

  delay(i);

  disp_3();
  delay(i);
  all(0, none);

  delay(i);

  disp_4();
  delay(i);
  all(0, none);

  delay(i);

  disp_5();
  delay(i);
  all(0, none);

  delay(i);

  disp_6();
  delay(i);
  all(0, none);

  delay(i);

  disp_7();
  delay(i);
  all(0, none);

  delay(i);

  disp_8();
  delay(i);
  all(0, none);

  delay(i);

  disp_9();
  delay(i);
  all(0, none);

  delay(i);

  disp_f();
  delay(i);
  all(0, none);

  delay(i);
}
// ----- END all Numbers -----

void displayValue(float value){
  
  // Convert float to string
  String i = String(value);

  for (int x=0;x<=3;x++){
    Serial.print(i[x]);
    Serial.print("\n");  
  }
 Serial.print(i[2]);
 if(i[2] == "\."){
  Serial.print("hey");
 }
}

void initialization(){

  int i = 75;

  // A
  d1(1);

  a(1);
  delay(i);
  a(0);
  delay(i);

  d1(0);
  d2(1);

  a(1);
  delay(i);
  a(0);
  delay(i);

  d2(0);
  d3(1);

  a(1);
  delay(i);
  a(0);
  delay(i);

  d3(0);
  d4(1);
  
  a(1);
  delay(i);
  a(0);
  delay(i);

  d4(0);
  
 // B
  d1(1);
 
  b(1);
  delay(i);
  b(0);
  delay(i);

  d1(0);
  d2(1);

  b(1);
  delay(i);
  b(0);
  delay(i);

  d2(0);
  d3(1);

  b(1);
  delay(i);
  b(0);
  delay(i);

  d3(0);
  d4(1);
  
  b(1);
  delay(i);
  b(0);
  delay(i);

  d4(0);

  // C
  d1(1);
 
  c(1);
  delay(i);
  c(0);
  delay(i);

  d1(0);
  d2(1);

  c(1);
  delay(i);
  c(0);
  delay(i);

  d2(0);
  d3(1);

  c(1);
  delay(i);
  c(0);
  delay(i);

  d3(0);
  d4(1);
  
  c(1);
  delay(i);
  c(0);
  delay(i);

  d4(0);

  // D
  d1(1);
 
  d(1);
  delay(i);
  d(0);
  delay(i);

  d1(0);
  d2(1);
  
  d(1);
  delay(i);
  d(0);
  delay(i);

  d2(0);
  d3(1);

  d(1);
  delay(i);
  d(0);
  delay(i);

  d3(0);
  d4(1);
  
  d(1);
  delay(i);
  d(0);
  delay(i);

  d4(0);

  // E
  d1(1);
 
  e(1);
  delay(i);
  e(0);
  delay(i);

  d1(0);
  d2(1);
  
  e(1);
  delay(i);
  e(0);
  delay(i);

  d2(0);
  d3(1);

  e(1);
  delay(i);
  e(0);
  delay(i);

  d3(0);
  d4(1);
  
  e(1);
  delay(i);
  e(0);
  delay(i);

  d4(0);

// F
  d1(1);
 
  f(1);
  delay(i);
  f(0);
  delay(i);

  d1(0);
  d2(1);
  
  f(1);
  delay(i);
  f(0);
  delay(i);

  d2(0);
  d3(1);

  f(1);
  delay(i);
  f(0);
  delay(i);

  d3(0);
  d4(1);
  
  f(1);
  delay(i);
  f(0);
  delay(i);

  d4(0);

  // G
  d1(1);
 
  g(1);
  delay(i);
  g(0);
  delay(i);

  d1(0);
  d2(1);
  
  g(1);
  delay(i);
  g(0);
  delay(i);
  
  d2(0);
  d3(1);

  g(1);
  delay(i);
  g(0);
  delay(i);

  d3(0);
  d4(1);
  
  g(1);
  delay(i);
  g(0);
  delay(i);

  d4(0);

  // DP
  d1(1);
 
  dp(1);
  delay(i);
  dp(0);
  delay(i);

  d1(0);
  d2(1);
  
  dp(1);
  delay(i);
  dp(0);
  delay(i);
  
  d2(0);
  d3(1);

  dp(1);
  delay(i);
  dp(0);
  delay(i);

  d3(0);
  d4(1);
  
  dp(1);
  delay(i);
  dp(0);
  delay(i);

  d4(0);

  // All digit end

  all(1, none);

  d1(1);
  delay(i);
  d1(0);
  delay(i);

  d2(1);
  delay(i);
  d2(0);
  delay(i);

  d3(1);
  delay(i);
  d3(0);
  delay(i);

  d4(1);
  delay(i);
  d4(0);
  delay(i);

  all(1, "d");
  delay(i);
  
  all(0, "d");
  delay(i);

  all(1, "d");
  delay(i);
  
  all(0, "d");
  delay(i);
  
  all(0, none);

  // Counting
  
  d1(1);
  allNumbers(i);
  d1(0);

  d2(1);
  allNumbers(i);
  d2(0);

  d3(1);
  allNumbers(i);
  d3(0);

  d4(1);
  allNumbers(i);
  d4(0);

  all(1, "d");
  allNumbers(i);
  all(0, "d");
}

// ----- END initialization -----

void snake(){
  int i = 100;

  // Trun on the first digit
  d1(1);

  // Blink the first dp three times
  dp(1);
  delay(i);
  dp(0);
  delay(i);

  dp(1);
  delay(i);
  dp(0);
  delay(i);

  dp(1);
  delay(i);
  dp(0);
  delay(i);
  
  // Turn off the first digit, and the second digit on
  d1(0);
  d2(1);

  d(1);
  delay(i);
  d(0);
  delay(i);

  // Turn off the second digit, and the third digit on
  d2(0);
  d3(1);

  d(1);
  delay(i);
  d(0);
  delay(i);

  // Turn off the third digit, and the fourth digit on: D, C, B, A
  d3(0);
  d4(1);

  d(1);
  delay(i);
  d(0);
  delay(i);

  c(1);
  delay(i);
  c(0);
  delay(i);

  b(1);
  delay(i);
  b(0);
  delay(i);

  a(1);
  delay(i);
  a(0);
  delay(i);

}

void setup() {

  // Assign Pins
  pinMode( 13, INPUT );

  pinMode( 2, OUTPUT );
  pinMode( 3, OUTPUT );
  pinMode( 4, OUTPUT );
  pinMode( 5, OUTPUT );
  pinMode( 6, OUTPUT );
  pinMode( 7, OUTPUT );

  pinMode( A2, OUTPUT );
  pinMode( A3, OUTPUT );
  pinMode( A4, OUTPUT );
  pinMode( A5, OUTPUT );
  pinMode( A6, OUTPUT );
  pinMode( A7, OUTPUT );
}

void loop() {
//  initialization();
  all(1,none);
  all(1,"d");
  delay(5000);
  all(0,none);
  all(0,"d");
  delay(5000);


}

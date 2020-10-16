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
  13 --> E
*/

int digit_1 = 12;
int digit_2 = 11;
int digit_3 = 10;
int digit_4 = 9;

void allLoop() {
  digitalWrite( 2, HIGH );
  digitalWrite( 3, HIGH );
  digitalWrite( 4, HIGH );
  digitalWrite( 5, HIGH );
  digitalWrite( 6, HIGH );
  digitalWrite( 7, HIGH );
  digitalWrite( 8, HIGH );
  digitalWrite( 13, HIGH );

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
  
  digitalWrite( 2, LOW );
  digitalWrite( 3, LOW );
  digitalWrite( 4, LOW );
  digitalWrite( 5, LOW );
  digitalWrite( 6, LOW );
  digitalWrite( 7, LOW );
  digitalWrite( 8, LOW );
  digitalWrite( 13, LOW );
  
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
  pinMode( 13, OUTPUT );

  Serial.begin(9600);
}

void loop() {

  allLoop();
}

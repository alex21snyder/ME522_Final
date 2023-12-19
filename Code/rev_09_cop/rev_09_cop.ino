/*
This script is for testing communication from slave
*/


#define interruptPin 3  // define pin D3 for input
//#define outputPin 5

void setup() {
  pinMode(interruptPin, INPUT);   // Sets the inputPin as an INPUT
  attachInterrupt(digitalPinToInterrupt(interruptPin), text, LOW); // could do FALLING here too
  
 // pinMode(outputPin, OUTPUT);  // Sets the inputPin as an INPUT

  // Serial Communication is starting with 9600 of baudrate speed
  Serial.begin(9600);
}

void loop() {
  //digitalWrite(outputPin, HIGH);


  // Add any additional code or delay as needed
}

void text(){
  Serial.print("Hit");
  Serial.println();
}



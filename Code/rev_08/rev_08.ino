#define inputPin 3  // define pin D3 for input
//#define outputPin 5

void setup() {
  pinMode(inputPin, INPUT);   // Sets the inputPin as an INPUT
  
 // pinMode(outputPin, OUTPUT);  // Sets the inputPin as an INPUT

  // Serial Communication is starting with 9600 of baudrate speed
  Serial.begin(9600);
}

void loop() {
  //digitalWrite(outputPin, HIGH);



  // Check if the input from pin 3 is HIGH
  if (digitalRead(inputPin) == LOW) {
    Serial.println("Hit");
  } else if (digitalRead(inputPin) == HIGH) {
    Serial.println("Not Hit");
  }

  // Add any additional code or delay as needed
}

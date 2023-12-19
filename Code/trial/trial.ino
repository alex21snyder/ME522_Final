const int motorPin = 5;  // Assuming the motor is connected to pin 5
const int interruptPin = 2;
volatile bool isrTriggered = false;
unsigned long motorStartTime = 0;
const unsigned long motorDuration = 3000;  // 3 seconds in milliseconds

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), motorISR, FALLING);
  Serial.begin(9600);
}

void loop() {
  // Wait for 3 seconds
  delay(3000);

  // Create the right scenario to trigger the ISR
  Serial.println("Triggering ISR...");
  // Simulate a falling edge on the interrupt pin
  digitalWrite(interruptPin, LOW);
  delayMicroseconds(10);  // Small delay for stability
  digitalWrite(interruptPin, HIGH);

  // Perform other tasks in the loop
}

void motorISR() {
  Serial.println("ISR triggered");
  isrTriggered = true;

  // Turn on the motor
  digitalWrite(motorPin, HIGH);
  motorStartTime = millis();

  // Wait for the specified duration
  while (millis() - motorStartTime < motorDuration) {
    // Allow other non-blocking tasks to execute if needed
  }

  // Turn off the motor after the specified duration
  digitalWrite(motorPin, LOW);
  isrTriggered = false;
}


/*

const int motorPin = 9;  // Replace 9 with the actual pin connected to your motor
const int inputPin = 2;  // Replace 2 with the actual pin connected to your input switch

unsigned long startTime;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop() {
  // Drive the motor for 5 seconds or until the input pin is HIGH
  digitalWrite(motorPin, HIGH);
  startTime = millis();  // Record the start time

  while (millis() - startTime < 5000) {
    // Check if the input pin is HIGH (1)
    if (digitalRead(inputPin) == HIGH) {
      // Stop the motor immediately
      digitalWrite(motorPin, LOW);
      break;  // Exit the loop
    }

    // You can add additional code here if needed

    // Add a small delay to reduce CPU usage
    delay(10);
  }

  // Ensure the motor is off after 5 seconds
  digitalWrite(motorPin, LOW);
}


*/



//    Final Project Start     //




/*
Code for only ultrasonic sensor rading info

Code for only the slave


** pot values range from 0 to 1023
*/

#define echoPin \
  2  // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin \
  3  // attach pin D3 Arduino to pin Trig of HC-SR04                                          \


#define outputPin 4  // define pin D4 for output

long duration;  // Variable to store time taken to the pulse
                // to reach receiver

int distance;  // Variable to store distance calculated using
               // formula

void setup() {
  pinMode(trigPin,
          OUTPUT);          // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, HIGH); 
    // Serial Communication is starting with 9600 of
  // baudrate speed
  Serial.begin(9600);

  // The text to be printed in serial monitor
  //Serial.println(
  //  "Distance measurement using Arduino Uno.");
  //delay(500);
}

void loop() {
  int state = digitalRead(outputPin);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  // wait for 2 ms to avoid
                         // collision in serial monitor

  digitalWrite(
    trigPin,
    HIGH);  // turn on the Trigger to generate pulse
  delayMicroseconds(
    10);  // keep the trigger "ON" for 10 ms to generate
          // pulse for 10 ms.

  digitalWrite(trigPin,
               LOW);  // Turn off the pulse trigger to stop
                      // pulse generation

  
  // If pulse reached the receiver echoPin
  // become high Then pulseIn() returns the
  // time taken by the pulse to reach the
  // receiver

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;  // Expression to calculate
                                     // distance using time

  //Serial.print("Distance: ");
  //Serial.print(
   // distance);  // Print the output in serial monitor
  //Serial.println(" cm");
  delay(100);
  if (distance < 5) {
    //Serial.print("Distance = Less than 5cm");
    //Serial.println();
    digitalWrite(outputPin, LOW);
  }
  else
  {
    digitalWrite(outputPin, HIGH);
  }

/*
  if(outputPin >= 3){           //also take these out
    //Serial.print("high");
    //Serial.println();
  }
  else if(outputPin < 3){
    //Serial.print("low");
    //Serial.println();
  }
  else{
    //Serial.print("other");
    //Serial.print(outputPin);
  }
  Serial.print(state); // take these out for faster code
  Serial.println();   // take these out for faster code
*/


}  ///// end of program



/*      REVISION# AND THERE GOALS

REV 00 - interface the push button
-if push button is held down turn the led on the arduino board on
-else led on arduino board is off
wiring- push button is wired to pin 2 and ground of arduino (has internal pull up resistor)

REV 01 - github uplaod test

REV 02 - refined script for legibility

Rev 03 - call for motor funciton if button == 0 (when button is pressed)

Rev 04 - add second motor

Rev 05 - working with ultrasonic sensor only
(Code for only ultrasonic sensor reading info)





*/



/*      NOTES

12/11
-started working on the push button
-succesfully got push button to function (1 is not pushed, 0 is pushed)
-Alex

12/12
-succesulfly encorperated 1 push button, H bridge and 1 motor 
-https://www.youtube.com/watch?v=YU17L650k3s (video that shows how to wire h brdige and motor with button)
-Alex

*/


/*      NICE TO KNOW THINGS

-pin 2 and 3 can be used for interupts
-pins with ~ can be used for analog input and PWM (need this for potentiometer)

INTURUPTS
- if you are using delay inside the IRS only use delayMicroseconds()  command
-you might have to declare global variables as "volitile?"
-variables that get used in irs function must be declared volitile variables in the begining of code



*/
//    Final Project Start     //



void setup() {
  
  //delay(1000);
  Serial.begin(9600);  // serial baud to communicate to serial monitor
  pinMode(2, INPUT_PULLUP); // inilize push button with internal pull up resistor
  pinMode(LED_BUILTIN, OUTPUT); // initialize digital pin LED_BUILTIN as an output.
}

// the loop function runs over and over again forever
void loop() {
  int sensorVal = digitalRead(2);
  Serial.println(sensorVal);
  
  if(sensorVal == 1){
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  } else if(sensorVal ==0){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on by making the voltage LOW
  }



} ///// end of program



/*
    REVISION AND THERE GOALS

REV 00 - interface the push button
-if push button is held down turn the led on the arduino board on
-else led on arduino board is off
wiring- push button is wired to pin 2 and ground of arduino (has internal pull up resistor)

REV 01 - github uplaod test

REV 02 - refined script for legibility

*/



/*
    NOTES

12/11
-started working on the push button
-succesfully got push button to function (1 is not pushed, 0 is pushed)
-Alex



*/
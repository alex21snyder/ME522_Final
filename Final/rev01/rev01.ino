//    Final Project Start     //


//test


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //delay(1000);
  Serial.begin(9600);  // serial baud to communicate to blah
  pinMode(2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int sensorVal = digitalRead(2);
  Serial.println(sensorVal);
  
  if(sensorVal == 1){
    digitalWrite(LED_BUILTIN, LOW); 
    // turn the LED off by making the voltage LOW
  } else if(sensorVal ==0){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED off by making the voltage LOW
  }














  /*
  //blink example
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
*/


} ///// end of program


/*
    REVISION AND THERE GOALS

REV 00 - interface the push button

-if push button is held down turn the led on the arduino board on
-else led on arduino board is off
wiring- push button is wired to pin 2 and ground of arduino



*/




/*
    NOTES

12/11
-started working on the push button
-Alex



*/
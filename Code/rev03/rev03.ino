//    Final Project Start     //


// declare variables
const int foward_pin1 = 11; //foward pin for motor 1
const int backward_pin1 = 12; //foward pin for motor 2
const int but_pin = 2; // pin for button 
int but;

void setup() {
  //delay(1000);
  Serial.begin(9600);  // serial baud to communicate to serial monitor
  pinMode(foward_pin1,OUTPUT);
  pinMode(backward_pin1, OUTPUT);
  pinMode(but_pin, INPUT_PULLUP); // inilize push button with internal pull up resistor
}


// the loop function runs over and over again forever
void loop() {

 but = digitalRead(but_pin); // but variable represents the input from physical button

 if(but == LOW){
  digitalWrite(foward_pin1, HIGH); // eventually turn this into function (see my ideas on drive)
  delay(1000); // cuases this process to go on for a second
 }
 else{
  digitalWrite(foward_pin1, LOW);
 }

} ///// end of program



/*      REVISION# AND THERE GOALS

REV 00 - interface the push button
-if push button is held down turn the led on the arduino board on
-else led on arduino board is off
wiring- push button is wired to pin 2 and ground of arduino (has internal pull up resistor)

REV 01 - github uplaod test

REV 02 - refined script for legibility

Rev 03 - call for motor funciton if button == 0 (when button is pressed)



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

*/
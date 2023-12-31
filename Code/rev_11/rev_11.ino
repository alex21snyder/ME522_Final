//    Final Project Start     //


//add two motors then encoperate potentiometer

/*
I take a guess that pin 9 should be like pin 1 on H bridge
this is where it gets tricky, 1 and 9 are both connected to normal power. 
I will try connecting 9 and 1 to pin 6 on arduino together

Its being difficult so i will try to have 2 speed pins lol


if you want ot be able to make it run more than 1 turn, you have to make a new variable that is not starttime but secondardy time orsomething like that


** pot values range from 0 to 1023
** if you are using green, make it right next to yellow
** must increase distance to 10, probably 15
*/

// DECLARE VARIABLES

//motor variables
const int foward_pin1 = 11; //foward pin for motor 1
const int backward_pin2 = 12; //backward pin for motor 1
const int foward_pin3 = 10; //foward pin for motor 2
const int backward_pin4 = 9; //backward pin for motor 2
const int but_pin = 2; // pin for button 
int but; //start button

//potentiometer variables
const int potpin = A0; //potentiometer input
const int speedpin = 6; //controlled by potentiometer 
int pot;
int speed;

//ultrasonic variables
const int ultrainput = 3; // input pin from ultrasonic sensor
unsigned long startTime;
int ultra_val;
int turnspeed;

//buzzer variables
const int buzzer = 8;

//rgb led variables
const int blue = 7; //rgb blue pin
const int green = 5; //rgb green pin
const int red = 4; //rgb red pin

const int thresh_1 = 600; //threshold for potentiomter values returned
const int thresh_2 = 810;
const int thresh_max = 1023;


void setup() {
  //delay(1000);
  Serial.begin(9600);  // serial baud to communicate to serial monitor
  pinMode(foward_pin1,OUTPUT);
  pinMode(backward_pin2, OUTPUT);
  pinMode(foward_pin3,OUTPUT);
  pinMode(backward_pin4, OUTPUT);
  
  pinMode(but_pin, INPUT_PULLUP); // inilize push button with internal pull up resistor (start button)

  pinMode(ultrainput, INPUT_PULLUP); // initialize ultrasonic sensor pin to high

  pinMode(buzzer, OUTPUT); // for buzzer

  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);


  // initililize motors low (need to add backward pins as well)
  digitalWrite(foward_pin1, LOW);
  digitalWrite(foward_pin3, LOW);
  digitalWrite(backward_pin2, LOW);
  digitalWrite(backward_pin4, LOW);
  // initilize rgb to low
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);

}


void loop() {


 but = digitalRead(but_pin); // but variable represents the input from physical button
 pot = analogRead(potpin);
 speed = map(pot,0,1023,0,255); // analog returns 0-1023, anaolg write = between 0-255
 analogWrite(speedpin,speed); // still needs HIGH command from digital write to move motor
 //Serial.print(pot);
 //Serial.print('\n');

 //photo sensor code go here (first in loop)
 // led decide here based on pot value i think
 if(pot <= thresh_1){ //green
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
 }
 else if(pot > thresh_1 && pot <= thresh_2){ // yellow
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
 }
 else{
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
 }



 if(but == LOW){ // START BUTTON PRESSSED
  
  startTime = millis(); //record start time

  while(millis() - startTime < 5000){
    digitalWrite(foward_pin1, HIGH); // 
    digitalWrite(foward_pin3, HIGH);
    ultra_val = digitalRead(ultrainput);
    if(ultra_val == LOW){

      digitalWrite(foward_pin1, LOW); // 
      digitalWrite(foward_pin3, LOW);
      
      startTime = millis(); //record start time
      while(millis()- startTime < 1000){
        tone(buzzer, 261);
      }
      noTone(buzzer);
      startTime = millis();



      //triple if statment here w variable name for time required to turn for each pot val (5000 turns to that var) (high med low times)
      if(pot >= 0){
        turnspeed = 5000; // time turning !!!
      }
      while(millis() - startTime < turnspeed){
        digitalWrite(foward_pin1, LOW); //
        digitalWrite(foward_pin3, HIGH); //
        //digitalWrite(backward_pin4, LOW); //
        //digitalWrite(backward_pin2, LOW);
        digitalWrite(backward_pin2, HIGH);

      }
      break;
    }
    //if statment with break here
  }
  digitalWrite(foward_pin1, LOW); // 
  digitalWrite(foward_pin3, LOW);
  digitalWrite(backward_pin2, LOW);
  digitalWrite(backward_pin4, LOW);
  Serial.print(pot);
  Serial.print('\n');
 }
 else{
  digitalWrite(foward_pin1, LOW);
  digitalWrite(foward_pin3, LOW);
  digitalWrite(backward_pin2, LOW);
  digitalWrite(backward_pin4, LOW);
  
  Serial.print('\n');
  Serial.print(pot);
  
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

Rev 04 - add second motor

poss rev 05 - add interupt of h bridge

rev 05 - code for slave only

rev 06

rev 07 - first working potentiomenter and h bridge config

rev 9 - sucesful communication between slave and master

rev 10- imlementing new way to contro mootrs indstead of delay and add ultrasonic if statment

rev 11- buzzer is implemented



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
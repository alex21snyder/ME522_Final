//    Final Project Start     //


/*
NOTES/TO DO

If you want ot be able to make it run more than 1 turn, you have to make a new variable that is not starttime but secondardy time orsomething like that
make a second tim variable

Slave is in charge of ultrasonic sensor values. pin 3 turns from HIGH to LOW if object is in front of it



** must increase distance to 10, probably 15
** take all serial print and serial monitor stuff out so code runs faster
** distance threshold is determined from slave code
** adjust photo value(rn its 700)
** can write function for all off to make it cleaners
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

const int thresh_0 = 700;
const int thresh_1 = 800; //threshold for potentiomter values returned
const int thresh_2 = 900;
const int thresh_max = 1023;

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

//photo sensor variables
const int pResistor = A1; // Photoresistor at Arduino analog pin A0
const int ledPin= A2;       // Led pin at Arduino pin 9
const int ledPin2= A3;       // Led pin at Arduino pin 9
int photo_value;				  // Store value from photoresistor (0-1023)




void setup() {
  
  Serial.begin(9600);  // serial baud to communicate to serial monitor

  // DECLARE INPUTS AND OUTPUTS

  // motor I/O
  pinMode(foward_pin1,OUTPUT);
  pinMode(backward_pin2, OUTPUT);
  pinMode(foward_pin3,OUTPUT);
  pinMode(backward_pin4, OUTPUT);

  // start button I/O
  pinMode(but_pin, INPUT_PULLUP); // inilize push button with internal pull up resistor (start button)

  // ultrasonic I/O
  pinMode(ultrainput, INPUT_PULLUP); // initialize ultrasonic sensor pin to high
  
  // buzzer I/O
  pinMode(buzzer, OUTPUT); // for buzzer

  // rgb I/O
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  // headlight led I/O
  pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
  pinMode(ledPin2, OUTPUT);  // Set lepPin - 9 pin as an output
  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)

  // TURN OFF ALL MOTORS AND LEDS (poss add headlightes)
  digitalWrite(foward_pin1, LOW);
  digitalWrite(foward_pin3, LOW);
  digitalWrite(backward_pin2, LOW);
  digitalWrite(backward_pin4, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
}


void loop() {
  
 //DEFINE VARIABLES (these variables can change value each iteration)
 but = digitalRead(but_pin); // input from physical button (1 not pushed, 0 pushed)
 pot = analogRead(potpin); // potentiometer value (0-1023)
 photo_value = analogRead(pResistor); // value from photosensor
 speed = map(pot,0,1023,0,255); // analog returns 0-1023, anaolg write = between 0-255
 analogWrite(speedpin,speed); // still needs HIGH command from digital write to move motor
 
 // RGB LED 
 if(pot <= thresh_1 && pot >= thresh_0){ //green
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
 }
 else if(pot > thresh_1 && pot <= thresh_2){ // yellow
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
 }
 else if(pot > thresh_2){
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
 }
 else{
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
 }

 //  HEADLIGHTS
 if (photo_value > 700){
    digitalWrite(ledPin, LOW);  //Turn led off
    digitalWrite(ledPin2, LOW);  //Turn led off
    //Serial.print("hi");
  }
  else{
    digitalWrite(ledPin, HIGH); //Turn led on
    digitalWrite(ledPin2, HIGH); //Turn led on
  }
  delay(100); //Small delay



 // START BUTTON PRESSED

 if(but == LOW){ // if button pressed
  
  startTime = millis(); //record current time

  while(millis() - startTime < 5000){ //run button loop for 5 seconds
    digitalWrite(foward_pin1, HIGH); // drive straight
    digitalWrite(foward_pin3, HIGH); // ^^
    ultra_val = digitalRead(ultrainput); // constantly see if object infront of it (info from slave)
    if(ultra_val == LOW){ // if object infront
      digitalWrite(foward_pin1, LOW); // stop motors
      digitalWrite(foward_pin3, LOW);// ^^
      
      startTime = millis(); //record start time
      while(millis()- startTime < 1000){ //turn buzzer on for 1 sec
        tone(buzzer, 261);
      }
      noTone(buzzer); // 
      
      startTime = millis();

      // turn speed selector
      if(pot <= thresh_1){ // slow speed turn value here
        turnspeed = 1900; // time turning !!!
      }
      else if(pot <= thresh_2 & pot > thresh_1){ 
        turnspeed = 1225;// middle speed turn value here
      }
      else{ 
        turnspeed = 750;//fast turn speed here
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
  digitalWrite(foward_pin1, LOW); // could make this function if i want
  digitalWrite(foward_pin3, LOW);
  digitalWrite(backward_pin2, LOW);
  digitalWrite(backward_pin4, LOW);
  Serial.print(pot);
  Serial.print('\n');
 }
 else{ //no motion if button not pressed
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
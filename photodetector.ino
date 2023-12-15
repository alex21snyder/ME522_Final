/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */
   

//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int ledPin=9;       // Led pin at Arduino pin 9
const int ledPin2=11;       // Led pin at Arduino pin 9
//Variables
int value;				  // Store value from photoresistor (0-1023)

void setup(){
 pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
 pinMode(ledPin2, OUTPUT);  // Set lepPin - 9 pin as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 Serial.begin(9600);
}

void loop(){
  value = analogRead(pResistor);
  Serial.println(value);
  //You can change value "25"
  if (value > 700){
    digitalWrite(ledPin, LOW);  //Turn led off
    digitalWrite(ledPin2, LOW);  //Turn led off
  }
  else{
    digitalWrite(ledPin, HIGH); //Turn led on
    digitalWrite(ledPin2, HIGH); //Turn led on
  }

  delay(100); //Small delay
}
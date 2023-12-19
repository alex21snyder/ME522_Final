const int blue = 7; 
const int green = 5;
const int red = 4;

void setup() {
  // put your setup code here, to run once:
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
pinMode(red, OUTPUT);
digitalWrite(blue, LOW);
digitalWrite(red, LOW);
digitalWrite(green, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
  /*
digitalWrite(red, HIGH);
//analogWrite(green, HIGH)
delay(1000);
digitalWrite(green, HIGH); 
digitalWrite(blue, HIGH); 
delay(1000);
digitalWrite(red, LOW);


digitalWrite(red, HIGH);
digitalWrite(green, HIGH);
delay(1000);
digitalWrite(blue, HIGH);
digitalWrite(red, HIGH);
digitalWrite(green, LOW);
delay(1000);
digitalWrite(blue, LOW);
digitalWrite(red, LOW);
digitalWrite(green, HIGH);
delay(1000);
*/
digitalWrite(green, LOW);
digitalWrite(red, HIGH);
delay(1000);
digitalWrite(red, HIGH);
digitalWrite(green, HIGH);
delay(1000);
digitalWrite(red, LOW);
//digitalWrite(green, HIGH);
delay(1000);
}

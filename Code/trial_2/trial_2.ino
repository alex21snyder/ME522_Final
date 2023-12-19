const int buzzer = 9;

void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tone(8, 261);
delay(1000);
noTone(8);
delay(1000);
}

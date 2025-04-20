
int LEDpin = 12;
int delayT = 1000;
void setup() {
  // put your setup code here, to run once:
pinMode(LEDpin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LEDpin, HIGH);
delay(delayT);
digitalWrite(LEDpin, LOW);
delay(delayT);
}
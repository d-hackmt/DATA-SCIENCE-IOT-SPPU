int knobValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  knobValue = analogRead(0); // read sensor value to analog input 0
  Serial.println(knobValue);   // send to pd
  delay(5);

}

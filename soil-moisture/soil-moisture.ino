void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

const int dry = 599; // value for dry sensor
const int wet = 253; // value for wet sensor

void loop() {

  int sensorVal = analogRead(A0);

  // transate sensor value range into %

  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);

  if (percentageHumidity < 50) {
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second 
  }

  
  Serial.print(percentageHumidity);
  Serial.println("%");
  
  delay(1000);
}

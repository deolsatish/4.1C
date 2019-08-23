  /*
  # Editor     : Lauren
  # Date       : 13.01.2012
  # Version    : 1.0
  # Connect the sensor to the A0(Analog 0) pin on the Arduino board
  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
  */
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {

  int val;
  val = analogRead(0); //connect sensor to Analog 0
  Serial.print("Soil Moisture: ");
  Serial.println(val); //print the value to serial port
  if(val<300)
  {
    int diff=15*val+200;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(diff);
    digitalWrite(LED_BUILTIN, LOW);
    delay(diff);
  }
  else if(val>700)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(5000);
  }
  else
  {
    delay(15000);
  }

  
  
}

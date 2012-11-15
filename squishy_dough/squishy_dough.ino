/* squishy_dough
 released by Codasign in November 2012
 under GPL 3.0
 
 CIRCUIT:
 speaker on pin 8
 
 on/off switch on pin 12
 
 1 analog input that is a voltage divider from 0 to 5V
 on pin A0
 
 */

int onSwitchPin = 12; //turns sound on and off

/****************************************
 * setup
 *****************************************/
void setup() {
  // initialize serial communications (for debugging only):
  Serial.begin(9600);

  pinMode(onSwitchPin, INPUT_PULLUP);

}

/****************************************
 * loop
 *****************************************/
void loop() {
  int onSwitch = digitalRead(onSwitchPin);

  if ( onSwitch == 0 ){
    // read the sensor:
    int sensorReading = analogRead(A0);
    // print the sensor reading so you know its range
    Serial.println(sensorReading);
    // map the pitch to the range of the analog input.
    // change the minimum and maximum input numbers below
    // depending on the range your sensor's giving:
    int thisPitch = map(sensorReading, 100, 1000, 100, 1000);

    // play the pitch:
    tone(8, thisPitch, 10);
    delay(1);        // delay in between reads for stability
  }
}








/* Korgish_dough
  released by Codasign in November 2012
  under GPL 3.0

  CIRCUIT:
  speaker on pin 5
  
  on/off switch on pin 12
  
  3 analog inputs that are voltage dividers from 0 to 5V
  on pins A2, A4, A5
  
*/

int speakerPin = 5; 

int sensorA = 19; // analog pin a5, controls repeating notes
int sensorB = 18; // analog pin a4, controls the frequency of the notes
int sensorC = 16; // analog pin a2, controls the duration of the notes

int onSwitchPin = 12; //turns sound on and off

int sensorAValue; //variable to store the value coming from first pressuse sensor
int sensorBValue; //variable to store the value coming from second pressure sensor
int sensorCValue; //variable to store the value coming from the light sensor


/****************************************
 * setup
 *****************************************/
void setup() 
{
  Serial.begin(9600); //initialize the serial port
  digitalWrite(16, HIGH); //sets analog pin a2 to high
  digitalWrite(18, HIGH); //sets analog pin a4 to high
  digitalWrite(19, HIGH); //sets analog pin a5 to high
  
  pinMode(onSwitchPin, INPUT_PULLUP);

}

/****************************************
 * loop
 *****************************************/
void loop() {
  int onSwitch = digitalRead(onSwitchPin);

  if ( onSwitch == 0 ){
    // repeats
    sensorAValue = analogRead(sensorA); // read the value from the sensor
    Serial.print("sensor A: ");
    Serial.println(sensorAValue); // send that value to the computer
    int repeats = map(sensorAValue, 0, 1024, 1, 4);

    // pitch
    sensorBValue = analogRead(sensorB); //read the value from the sensor
    Serial.print("sensor B: ");
    Serial.println(sensorBValue); //send that value to the computer
    int notePitch = map(sensorBValue, 0, 1024, 100, 2000);

    sensorCValue = analogRead(sensorC);//read the value from the sensor
    Serial.print("sensor C: ");
    Serial.println(sensorCValue);//send that value to the computer
    int noteDuration  = 1000/map( sensorCValue, 0, 1024, 4, 16);


    // iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < repeats; thisNote++) {

      //play note 
      tone(speakerPin, notePitch, noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration
      int pauseBetweenNotes = noteDuration * 1.10;
      delay(pauseBetweenNotes);
    }
  }
}

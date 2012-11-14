/*
  soft_keyboard
 
 Plays a pitch that changes based on a changing analog input
 
  released by Codasign in November 2012
  under GPL 3.0

  CIRCUIT:
  speaker on pin 9
  
  digital sensors on pins 2 through 8 that connect to ground
  (internal pull-ups used on input pins)
  
*/

#include "pitches.h"

int speakerPin = 9;
int keys [] = { 2, 3, 4, 5, 6, 7, 8 };
int numKeys = 7;

// notes to play, a blues scale:
int notes[] = {
  NOTE_C4, NOTE_DS4,NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_AS4, NOTE_C5 };

/****************************************
 * setup
 *****************************************/
void setup() {
  for ( int k= 0; k < numKeys; k++) {
   pinMode(keys[k], INPUT_PULLUP); 
  }
}

/****************************************
 * loop
 *****************************************/
void loop() {
  for( int i=0; i < numKeys; i++) {
   int keyIn = digitalRead( keys[i]);
   if( keyIn == 0) {
    tone( speakerPin, notes[i], 200);
    delay(190);
   }
  }
}



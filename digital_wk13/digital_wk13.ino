/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/digital/toneMelody/
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_A5

};
int ledPins[] = {2,3,4,5,6,7,8,9};

// 每個音符對應哪顆 LED 要亮
int LEDcontrol[8][8] = {

  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8
};

void setup() {
  // iterate over the notes of the melody:
    for(int i=0; i<8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}





void loop() {
  // no need to repeat the melody.
   for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(10, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    for(int led = 0; led < 8; led++) {

    if(LEDcontrol[thisNote][led] == 1) {
        digitalWrite(ledPins[led], HIGH);
    }
    else {
        digitalWrite(ledPins[led], LOW);
    }
    delay(40);
}
  }
}


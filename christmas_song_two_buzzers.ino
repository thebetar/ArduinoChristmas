// Simple christmas carol with two buzzers using "ToneLibrary"

#include <Tone.h>

#define REST 0

// Define pins for buzzers
const unsigned int treePin = 2;
const unsigned int ledPin = 13; // The pin number of the led
const unsigned int led2Pin = 11; // The pin number of the led
const unsigned int buttonPin = 12; // The pin number of the button
const unsigned int buzzer1Pin = 7; // The pin number of the first buzzer
const unsigned int buzzer2Pin = 8; // The pin numnber of the second buzzer
const unsigned int buzzer3Pin = 9; // The pin numnber of the third buzzer

// Define melody and durations
int melody[] = {
  NOTE_C5, //1
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,

  NOTE_F5, NOTE_C5, //8 
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5,

  NOTE_F5, NOTE_F5, NOTE_F5,//17
  NOTE_E5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_A5,
  NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_C6, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, //27
  NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5,
  NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_E5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_D5,
  
  NOTE_C5, NOTE_A5,//36
  NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_C6, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, 
  NOTE_E5, NOTE_C5, NOTE_C5,
  
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,//45
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5,
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_C5, NOTE_C5,
  
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5, //53
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, REST
};

int noteDurations[] = {
  4, // 1
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4, 
  4, 8, 8, 8, 8, 
  4, 4, 8, 8, 
  4, 4, 4,
  
  2, 4, // 8
  4, 8, 8, 8, 8,
  4, 4, 4, 
  4, 8, 8, 8, 8, 
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8, 
  4, 4, 4,
  2, 4,
  
  4, 4, 4, // 17
  2, 4,
  4, 4, 4,
  2, 4,
  4, 4, 4,
  4, 4, 8, 8,
  4, 4, 4,
  2, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  
  4, 8, 8, 8, 8, // 27
  4, 4, 4, 
  4, 8, 8, 8, 8, 
  4, 4, 8, 8, 
  4, 4, 4,
  2, 4,
  4, 4, 4,
  2, 4,
  4, 4, 4,
  
  2, 4, // 36
  4, 4, 4,
  4, 4, 8, 8,
  4, 4, 4, 
  2, 4,
  4, 8, 8, 8, 8, 
  4, 4, 4, 
  4, 8, 8, 8, 8,
  4, 4, 4,
  
  4, 8, 8, 8, 8, //45
  4 , 4, 8, 8,
  4, 4, 4,
  2, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  
  4, 8, 8, 8, 8, // 53
  4, 4, 8, 8,
  4, 4, 4,
  2, 4
};

// You can declare the tones as an array
Tone notePlayer[3];

void setup(void)
{
  Serial.begin(9600);
  notePlayer[0].begin(buzzer1Pin);
  notePlayer[1].begin(buzzer2Pin);
  // notePlayer[2].begin(buzzer3Pin);

  // initialize the LED pins as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(treePin, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

unsigned int pinToggle = 0;
unsigned int musicToggle = 0;

void playSong(void) {
  musicToggle = 1;

  const unsigned int melodyCount = sizeof(melody) / sizeof(melody[0]);

  digitalWrite(treePin, HIGH);

  delay(100);

  for (unsigned int currentNote = 0; currentNote < melodyCount; currentNote++) {
    // Check if toggle is on and if no pause in note
    if (pinToggle == 1 && currentNote > 0) {
      // turn LED lights on:
      digitalWrite(ledPin, HIGH);
      digitalWrite(led2Pin, LOW);
      pinToggle = 0;
    } else {
      // turn LED lights off:
      digitalWrite(ledPin, LOW);
      digitalWrite(led2Pin, HIGH);
      pinToggle = 1;
    }

    // Calculate duration
    const unsigned int currentNoteDuration = 1100 / noteDurations[currentNote];

    // Set the frequency for the current note
    const unsigned int noteFreq = melody[currentNote];
    notePlayer[0].play(noteFreq, currentNoteDuration);

    // Set the lower harmony (a simple offset)
    const unsigned int lowHarmonyFreq = (noteFreq == REST) ? 0 : noteFreq - 30;
    notePlayer[1].play(lowHarmonyFreq, currentNoteDuration);

    // Set the higher hamrony (a simple offset)
    // const unsigned int highHarmonyFreq = (noteFreq == REST) ? 0 : noteFreq + 30;
    // notePlayer[2].play(highHarmonyFreq, currentNoteDuration);

    delay(currentNoteDuration);
  }

  // Turn buzzers off
  notePlayer[0].stop();
  notePlayer[1].stop();
  // notePlayer[2].stop();
  
  // Turn LEDs off
  digitalWrite(ledPin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(treePin, LOW);

  // Slight delay for replay
  delay(50);

  // Reset music
  musicToggle = 0;
}

void loop(void)
{
  // Read the state of the pushbutton value:
  unsigned int reading = digitalRead(buttonPin);

  // If button is pressed and music is not already playing
  if (reading == 1 && musicToggle == 0) {
    playSong();
  }
}

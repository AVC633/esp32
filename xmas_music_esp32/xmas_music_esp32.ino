#define buzzer 15     // Buzzer connected to pin 7
#define tempo 140     // Tempo (beats per minute)
//AVC

// Note frequencies
const int notes[] = {
  523, 698, 784, 880, 932, 1047, 1175, 1319, 1480, 1568, 1760, 1976,
  2093, 2349, 2637, 2794, 3136, 3520, 3951, 4186, 4699, 4978
};

// Melody notes (frequency) and durations
const int melody[] = {
  // Notes                         // Durations
  523, 4, 698, 4, 698, 8, 784, 8, 698, 8, 659, 8,
  587, 4, 587, 4, 587, 4,
  784, 4, 784, 8, 880, 8, 784, 8, 698, 8,
  659, 4, 523, 4, 523, 4,
  880, 4, 880, 8, 932, 8, 880, 8, 784, 8,
  698, 4, 587, 4, 523, 8, 523, 8,
  587, 4, 784, 4, 659, 4,
  698, 2, 523, 4,
  698, 4, 698, 8, 784, 8, 698, 8, 659, 8,
  587, 4, 587, 4, 587, 4,
  784, 4, 784, 8, 880, 8, 784, 8, 698, 8,
  659, 4, 523, 4, 523, 4,
  880, 4, 880, 8, 932, 8, 880, 8, 784, 8,
  698, 4, 587, 4, 523, 8, 523, 8,
  587, 4, 784, 4, 659, 4,
  698, 2, 523, 4,
  698, 4, 698, 4, 698, 4,
  659, 2, 659, 4,
  698, 4, 659, 4, 587, 4,
  523, 2, 880, 4,
  932, 4, 880, 4, 784, 4,
  1047, 4, 523, 4, 523, 8, 523, 8,
  587, 4, 784, 4, 659, 4,
  698, 2, 523, 4,
  698, 4, 698, 8, 784, 8, 698, 8, 659, 8,
  587, 4, 587, 4, 587, 4,
  784, 4, 784, 8, 880, 8, 784, 8, 698, 8,
  659, 4, 523, 4, 523, 4,
  880, 4, 880, 8, 932, 8, 880, 8, 784, 8,
  698, 4, 587, 4, 523, 8, 523, 8,
  587, 4, 784, 4, 659, 4,
  698, 2, 523, 4,
  698, 4, 698, 4, 698, 4,
  659, 2, 659, 4,
  698, 4, 659, 4, 587, 4,
  523, 2, 880, 4,
  932, 4, 880, 4, 784, 4,
  1047, 4, 523, 4, 523, 8, 523, 8,
  587, 4, 784, 4, 659, 4,
  698, 2, 0, 4 // REST
};

// Calculate the number of notes
const int numNotes = sizeof(melody) / sizeof(melody[0]) / 2;
// Calculate the duration of a whole note in milliseconds
const int wholenote = (60000 * 4) / tempo;

void playMelody() {
  for (int i = 0; i < numNotes; i++) {
    int note = melody[2 * i];
    int divider = melody[2 * i + 1];
    int duration;

    if (divider == 0) { // REST
      delay(wholenote / 4); // Short pause for REST
      continue;
    } else if (divider < 0) { // Dotted notes
      duration = (wholenote / abs(divider)) * 1.5;
    } else { // Regular notes
      duration = wholenote / divider;
    }

    tone(buzzer, note, duration * 0.9); // Play note
    delay(duration);                    // Wait for the duration
    noTone(buzzer);                     // Stop the note
  }
}

void setup() 
{
pinMode(buzzer,OUTPUT);
}

void loop() 
{
  playMelody();     // Play the melody
  delay(2000);      // Wait for 2 seconds before repeating
}

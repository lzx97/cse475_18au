#include <Adafruit_SSD1306.h>
#include <Adafruit_FeatherOLED.h>

Adafruit_SSD1306 display = Adafruit_SSD1306();


#define VS1053_MIDI Serial1

// See http://www.vlsi.fi/fileadmin/datasheets/vs1053.pdf Pg 31
#define VS1053_BANK_DEFAULT 0x00
#define VS1053_BANK_DRUMS1 0x78
#define VS1053_BANK_DRUMS2 0x7F
#define VS1053_BANK_MELODY 0x79

// See http://www.vlsi.fi/fileadmin/datasheets/vs1053.pdf Pg 32 for more!
#define c0inst 123
#define c1inst 123
#define c2inst 123
#define c3inst 124
#define c4inst 54
#define c5inst 53
#define c6inst 113
#define c7inst 11
#define c8inst 49
#define c9inst 59
#define c10inst 13


#define MIDI_NOTE_ON  0x90
#define MIDI_NOTE_OFF 0x80
#define MIDI_CHAN_MSG 0xB0
#define MIDI_CHAN_BANK 0x00
#define MIDI_CHAN_VOLUME 0x07
#define MIDI_CHAN_PROGRAM 0xC0
long randomDelay;
long totalDelay;
long randomNote;
long randomNote1;
long randomNote2;
void setup() {
  delay(1000);
  
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  Serial.println("VS1053 MIDI test");

  VS1053_MIDI.begin(31250); // MIDI uses a 'strange baud rate'
  
   midiSetChannelBank(0, VS1053_BANK_MELODY);
   midiSetChannelBank(1, VS1053_BANK_MELODY);
   midiSetChannelBank(2, VS1053_BANK_MELODY);
   midiSetChannelBank(3, VS1053_BANK_MELODY);
   midiSetChannelBank(4, VS1053_BANK_MELODY);
   midiSetChannelBank(5, VS1053_BANK_MELODY);
   midiSetChannelBank(6, VS1053_BANK_MELODY);
   midiSetChannelBank(7, VS1053_BANK_MELODY);
   midiSetChannelBank(8, VS1053_BANK_MELODY);
   midiSetChannelBank(9, VS1053_BANK_MELODY);
   midiSetChannelBank(10, VS1053_BANK_MELODY);
   midiSetChannelBank(11, VS1053_BANK_DRUMS1);
   midiSetChannelBank(12, VS1053_BANK_DRUMS1);

  midiSetChannelVolume(0, 127);
  midiSetChannelVolume(1, 127);
  midiSetChannelVolume(2, 127);
  midiSetChannelVolume(3, 127);
  midiSetChannelVolume(4, 127);
  midiSetChannelVolume(5, 127);
  midiSetChannelVolume(6, 127);
  midiSetChannelVolume(7, 127);
  midiSetChannelVolume(8, 127);
  midiSetChannelVolume(9, 127);
  midiSetChannelVolume(10, 127);
  midiSetChannelVolume(11, 127);
  midiSetChannelVolume(12, 127);
  
  midiSetInstrument(0, c0inst);
  midiSetInstrument(1, c1inst);
  midiSetInstrument(2, c2inst);
  midiSetInstrument(3, c3inst);
  midiSetInstrument(4, c4inst);
  midiSetInstrument(5, c5inst);
  midiSetInstrument(6, c6inst);
  midiSetInstrument(7, c7inst);
  midiSetInstrument(8, c8inst);
  midiSetInstrument(9, c9inst);
  midiSetInstrument(10, c10inst);
  midiSetInstrument(11, c9inst);
  midiSetInstrument(12, c9inst);
  
}

void loop() { 
//midiNoteOn(3, 99, 127);delay(10000);
//midiNoteOff(3, 99, 127);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Ambient 1");
  display.setCursor(0, 0);
  display.display();
while(totalDelay<30000){
  randomDelay = random(0, 5000) + 1000;
  
  midiNoteOn(0, 60, 127); delay(randomDelay); totalDelay += randomDelay;randomDelay = random(0, 5000) + 1000;
  midiNoteOn(1, 30, 127); delay(randomDelay); totalDelay += randomDelay;randomDelay = random(0, 5000) + 1000;
  midiNoteOn(2, 99, 127); delay(randomDelay);totalDelay += randomDelay;randomDelay = random(0, 5000) + 1000;

  midiNoteOff(2, 99, 127);delay(randomDelay);totalDelay += randomDelay;randomDelay = random(0, 5000) + 1000;
  midiNoteOff(1, 30, 127);delay(randomDelay);totalDelay += randomDelay;randomDelay = random(0, 5000) + 1000;
  midiNoteOff(0, 60, 127);
  Serial.println(totalDelay);
}
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Ambient 2");
  display.setCursor(0, 0);
  display.display();
while(totalDelay >30000 && totalDelay <60000){
  
  randomNote = random(70, 90);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);totalDelay +=4000;
  midiNoteOff(3, randomNote, 127);
  
  randomNote = random(70, 85);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);
  midiNoteOff(3, randomNote, 127);

  randomNote = random(70, 85);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);
  midiNoteOff(3, randomNote, 127);
  randomNote = random(70, 85);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);
  midiNoteOff(3, randomNote, 127);
  randomNote = random(70, 85);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);
  midiNoteOff(3, randomNote, 127);
  randomNote = random(70, 85);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);
  midiNoteOff(3, randomNote, 127);
  randomNote = random(70, 85);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);
  midiNoteOff(3, randomNote, 127);
  randomNote = random(70, 85);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);
  midiNoteOff(3, randomNote, 127);
  randomNote = random(70, 85);
  midiNoteOn(3, randomNote, 127);delay(random(0, 300) + 50);
  midiNoteOff(3, randomNote, 127);
  
  Serial.println(totalDelay);
}
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Ambient 3");
  display.setCursor(0, 0);
  display.display();
while(totalDelay >60000 && totalDelay<90000){
  randomNote1 = random(50, 60)+2;
  midiNoteOn(4, randomNote1, 127);delay(random(400, 900) + 100);
  randomNote2 = random(60, 70)+4;
  midiNoteOn(5, randomNote2, 127);delay(random(1000, 5000) + 1000);totalDelay +=4000;
  midiNoteOff(4, randomNote1, 10); delay(random(400, 900) + 100);
  midiNoteOff(5, randomNote2, 10);
}

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Active 1");
  display.setCursor(0, 0);
  display.display();
  while(totalDelay > 90000 && totalDelay<120000){
     randomNote = random(40, 50)*2-40;
     midiNoteOn(6, randomNote, 127);delay(random(500, 1000));totalDelay +=1000;
     midiNoteOff(6, randomNote, 10);
  }

 display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Active 2");
  display.setCursor(0, 0);
  display.display();
  while(totalDelay > 120000 && totalDelay<150000){
      randomNote1 = random(70, 80)*2-70;
      randomNote2 = random(60, 70)*2-60;
      midiNoteOn(7, randomNote1, 40);
      midiNoteOn(8, randomNote2, 40);delay(random(2000, 5000));totalDelay +=4000;
      midiNoteOff(7, randomNote1, 10);
      midiNoteOff(8, randomNote2, 10);
  }
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Active 3");
  display.setCursor(0, 0);
  display.display();
  while(totalDelay > 150000 && totalDelay<180000){
      midiNoteOn(10, 50, 127);delay(random(1000, 2500));totalDelay +=4000;
     midiNoteOff(10, 50, 40);
     midiNoteOn(10, 50, 127);delay(random(10,1000));
     midiNoteOff(10, 50, 40);
     midiNoteOn(10, 81, 127);delay(random(1000, 2500));
     midiNoteOff(10, 81, 40);
     midiNoteOn(10, 83, 127);delay(random(10, 5000));
     midiNoteOff(10, 83, 40);

  }
    display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Startle");
  display.setCursor(0, 0);
  display.display();
  while(totalDelay > 180000 && totalDelay<210000){
midiNoteOn(9, 40, 127);delay(150);midiNoteOff(9, 40, 127);midiNoteOn(9, 41, 127);delay(150);midiNoteOff(9, 41, 127);midiNoteOn(9, 42, 127);delay(150);midiNoteOff(9, 42, 127);midiNoteOn(9, 43, 127);delay(150);midiNoteOff(9, 43, 127); totalDelay +=4000;
midiNoteOn(9, 44, 127);delay(400);midiNoteOff(9, 44, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 40, 127);delay(400);midiNoteOff(9, 40, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 44, 127);delay(400);midiNoteOff(9, 44, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 40, 127);delay(200);midiNoteOff(9, 40, 127);midiNoteOn(9, 41, 127);delay(200);midiNoteOff(9, 41, 127);midiNoteOn(9, 43, 127);delay(200);midiNoteOff(9, 43, 127);
midiNoteOn(9, 44, 127);delay(400);midiNoteOff(9, 44, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 40, 127);delay(400);midiNoteOff(9, 40, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 44, 127);delay(400);midiNoteOff(9, 44, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 40, 127);delay(200);midiNoteOff(9, 40, 127);midiNoteOn(9, 41, 127);delay(200);midiNoteOff(9, 41, 127);midiNoteOn(9, 43, 127);delay(200);midiNoteOff(9, 43, 127);
midiNoteOn(9, 44, 127);delay(400);midiNoteOff(9, 44, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 40, 127);delay(400);midiNoteOff(9, 40, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 44, 127);delay(400);midiNoteOff(9, 44, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 40, 127);delay(200);midiNoteOff(9, 40, 127);midiNoteOn(9, 41, 127);delay(200);midiNoteOff(9, 41, 127);midiNoteOn(9, 43, 127);delay(200);midiNoteOff(9, 43, 127);
midiNoteOn(9, 44, 127);delay(400);midiNoteOff(9, 44, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 40, 127);delay(400);midiNoteOff(9, 40, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);
midiNoteOn(9, 44, 127);delay(400);midiNoteOff(9, 44, 127);
midiNoteOn(9, 48, 127);delay(200);midiNoteOff(9, 48, 127);

  }
  
display.print("done!");
delay(1000);
totalDelay = 0;

}


void midiSetInstrument(uint8_t chan, uint8_t inst) {
  if (chan > 15) return;
  inst --; // page 32 has instruments starting with 1 not 0 :(
  if (inst > 127) return;
  
  VS1053_MIDI.write(MIDI_CHAN_PROGRAM | chan);  
  delay(10);
  VS1053_MIDI.write(inst);
  delay(10);
}


void midiSetChannelVolume(uint8_t chan, uint8_t vol) {
  if (chan > 15) return;
  if (vol > 127) return;
  
  VS1053_MIDI.write(MIDI_CHAN_MSG | chan);
  VS1053_MIDI.write(MIDI_CHAN_VOLUME);
  VS1053_MIDI.write(vol);
}

void midiSetChannelBank(uint8_t chan, uint8_t bank) {
  if (chan > 15) return;
  if (bank > 127) return;
  
  VS1053_MIDI.write(MIDI_CHAN_MSG | chan);
  VS1053_MIDI.write((uint8_t)MIDI_CHAN_BANK);
  VS1053_MIDI.write(bank);
}

void midiNoteOn(uint8_t chan, uint8_t n, uint8_t vel) {
  if (chan > 15) return;
  if (n > 127) return;
  if (vel > 127) return;
  
  VS1053_MIDI.write(MIDI_NOTE_ON | chan);
  VS1053_MIDI.write(n);
  VS1053_MIDI.write(vel);
}

void midiNoteOff(uint8_t chan, uint8_t n, uint8_t vel) {
  if (chan > 15) return;
  if (n > 127) return;
  if (vel > 127) return;
  
  VS1053_MIDI.write(MIDI_NOTE_OFF | chan);
  VS1053_MIDI.write(n);
  VS1053_MIDI.write(vel);
}

// Twin Camera shutter sync LED detector
// Arduino Pro Mini ATmega328 5V 16 MHz microcomputer board
// Sparkfun.com DEV-11113
// Written by Andy Modla 2018/07/23
 
const int ledCount = 11;    // the number of LEDs
const int RANGE = 1024;
int counter = 1;
int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13
};   // an array of pin numbers for LEDs from least significant bit
// note pin 13 is onboard LED and is always 0 when RANGE == 1024
//

void setup() {
  // loop over the pin array and set all to output:
  for (int led = 0; led < ledCount; led++) {
    pinMode(ledPins[led], OUTPUT);
  }
  noInterrupts();
}

void loop() {
  for (int led = 0; led < ledCount; led++) {
    if ((counter >> led) & 1) {
      digitalWrite(ledPins[led], HIGH);
    }
    else {
      digitalWrite(ledPins[led], LOW);
    }
  }
  counter++;
  if (counter == RANGE)  // 10 leds for 1024 range
    counter = 1;
  delayMicroseconds(900);
  // 900 us determined from oscilloscope measurement
}

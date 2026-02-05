#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL                                         // Define frequência da CPU para 1MHz para ajustar a função de delay

const int Red = 0;
const int Green = 1;
const int Blue = 2;

volatile uint8_t* Port[] = {&OCR0A, &OCR0B, &OCR1B};

void setup() {
  DDRB  |= (1 << DDB4) | (1 << DDB1) | (1 << DDB0);
  TCCR0A = 3 << COM0A0 | 3 << COM0B0 | 3 << WGM00;
  TCCR0B = 0 << WGM02 | 3 << CS00;
  TCCR1 = 0 << PWM1A | 3 << COM1A0 | 7 << CS10;
  GTCCR = 1 << PWM1B | 3 << COM1B0;
}

void SetColour (int colour, int intensity) {
  *Port[colour] = 0 + intensity;                                // Intensity range is 0 (min) to 255 (max).
}

void loop() {
// Estatic
  SetColour (Red, 255);

// Fade
//  for (int i = 255; i >= 0; i--) {
//
//      SetColour(Red, i);
//
//      _delay_ms(100);
//
//    }
}

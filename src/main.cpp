#include <Arduino.h>
#include "morseutil.hpp"

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

  digitalWrite(LED_BUILTIN, LOW);
  delay(2500);

  unsigned char s[] = "ABCD";

  for (uint8_t i; i <= (uint8_t)((sizeof(s) / sizeof(s[0]) - 1)); i++)
  {

    unsigned char c = s[i];

    MorseSeq *seq = _get_letter_morse_sequence(c);

    for (uint8_t j = 0; j <= (uint8_t)(sizeof(seq) / sizeof(int)); j++)
    {

      int t = *seq[j];

      if (t == 0)
      {
        break;
      }

      digitalWrite(LED_BUILTIN, HIGH);
      delay(*seq[j]);
      digitalWrite(LED_BUILTIN, LOW);
      delay(3 * TIME_UNIT);
    }

    digitalWrite(LED_BUILTIN, LOW);
    delay(2500);
  }

  //   // turn the LED on (HIGH is the voltage level)
  //   digitalWrite(LED_BUILTIN, HIGH);
  //   // wait for a second
  //   delay(__DASH);
  //   // turn the LED off by making the voltage LOW
  //   digitalWrite(LED_BUILTIN, LOW);
  //    // wait for a second
  //   delay(__DASH);
}
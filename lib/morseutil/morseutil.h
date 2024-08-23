
#ifndef MORSEUTIL_H
#define MORSEUTIL_H

#define TIME_UNIT 1000
#define __DOT TIME_UNIT
#define __DASH (3 * TIME_UNIT)
#define __SPACING_SAME_LETTER (TIME_UNIT * -1)
#define __SPACING_BETWEEN_LETTERS (TIME_UNIT * -1)
#define __SPACING_BETWEEN_WORDS (7 * TIME_UNIT * -1)

#define _MORSE_SEQ_SIZE 5
#define _MORSE_SEQ_MAP_SIZE 36 // 26 letters + 10 digits

#define _FIRST_CHAR_NUMBERS '0'
#define _LAST_CHAR_NUMBERS '9'
#define _FIRST_CHAR_LETTERS 'A'

// Morse code sequences for numbers 0-9
#define __M_0 {__DASH, __DASH, __DASH, __DASH, __DASH}
#define __M_1 {__DOT, __DASH, __DASH, __DASH, __DASH}
#define __M_2 {__DOT, __DOT, __DASH, __DASH, __DASH}
#define __M_3 {__DOT, __DOT, __DOT, __DASH, __DASH}
#define __M_4 {__DOT, __DOT, __DOT, __DOT, __DASH}
#define __M_5 {__DOT, __DOT, __DOT, __DOT, __DOT}
#define __M_6 {__DASH, __DOT, __DOT, __DOT, __DOT}
#define __M_7 {__DASH, __DASH, __DOT, __DOT, __DOT}
#define __M_8 {__DASH, __DASH, __DASH, __DOT, __DOT}
#define __M_9 {__DASH, __DASH, __DASH, __DASH, __DOT}

// Morse code sequences for letters A-Z
#define __M_A {__DOT, __DASH, 0, 0, 0}
#define __M_B {__DASH, __DOT, __DOT, __DOT, 0}
#define __M_C {__DASH, __DOT, __DASH, __DOT, 0}
#define __M_D {__DASH, __DOT, __DOT, 0, 0}
#define __M_E {__DOT, 0, 0, 0, 0}
#define __M_F {__DOT, __DOT, __DASH, __DOT, 0}
#define __M_G {__DASH, __DASH, __DOT, 0, 0}
#define __M_H {__DOT, __DOT, __DOT, __DOT, 0}
#define __M_I {__DOT, __DOT, 0, 0, 0}
#define __M_J {__DOT, __DASH, __DASH, __DASH, 0}
#define __M_K {__DASH, __DOT, __DASH, 0, 0}
#define __M_L {__DOT, __DASH, __DOT, __DOT, 0}
#define __M_M {__DASH, __DASH, 0, 0, 0}
#define __M_N {__DASH, __DOT, 0, 0, 0}
#define __M_O {__DASH, __DASH, __DASH, 0, 0}
#define __M_P {__DOT, __DASH, __DASH, __DOT, 0}
#define __M_Q {__DASH, __DASH, __DOT, __DASH, 0}
#define __M_R {__DOT, __DASH, __DOT, 0, 0}
#define __M_S {__DOT, __DOT, __DOT, 0, 0}
#define __M_T {__DASH, 0, 0, 0, 0}
#define __M_U {__DOT, __DOT, __DASH, 0, 0}
#define __M_V {__DOT, __DOT, __DOT, __DASH, 0}
#define __M_W {__DOT, __DASH, __DASH, 0, 0}
#define __M_X {__DASH, __DOT, __DOT, __DASH, 0}
#define __M_Y {__DASH, __DOT, __DASH, __DASH, 0}
#define __M_Z {__DASH, __DASH, __DOT, __DOT, 0}

typedef int MorseSeq[_MORSE_SEQ_SIZE];

typedef MorseSeq MorseSeqMap[_MORSE_SEQ_MAP_SIZE];

extern MorseSeqMap _MORSE_SEQ_MAP;

int _morse_seq_map_hash_func(char c);

MorseSeq *_get_letter_morse_sequence(unsigned char c);

#endif
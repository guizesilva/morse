
#ifndef MORSEUTIL_H
#define MORSEUTIL_H

#define TIME_UNIT 1000
#define __DOT TIME_UNIT
#define __DASH (3 * TIME_UNIT)
#define __SPACING_SAME_LETTER TIME_UNIT
#define __SPACING_BETWEEN_LETTERS TIME_UNIT
#define __SPACING_BETWEEN_WORDS (7 * TIME_UNIT)

#define _MORSE_SEQ_SIZE 5
#define _MORSE_SEQ_MAP_SIZE 36 // 26 letters + 10 digits

#define _FIRST_CHAR_NUMBERS '0'
#define _LAST_CHAR_NUMBERS '9'
#define _FIRST_CHAR_LETTERS 'A'

typedef int MorseSeq[_MORSE_SEQ_SIZE];

typedef MorseSeq MorseSeqMap[_MORSE_SEQ_MAP_SIZE];

extern MorseSeqMap _MORSE_SEQ_MAP;

int _morse_seq_map_hash_func(char c);

MorseSeq *get_morse_sequence(unsigned char c);

#endif
#include "morseutil.h"

MorseSeqMap _MORSE_SEQ_MAP = {

    // Morse code sequences for numbers 0-9
    {__DASH, __DASH, __DASH, __DASH, __DASH},
    {__DOT, __DASH, __DASH, __DASH, __DASH},
    {__DOT, __DOT, __DASH, __DASH, __DASH},
    {__DOT, __DOT, __DOT, __DASH, __DASH},
    {__DOT, __DOT, __DOT, __DOT, __DASH},
    {__DOT, __DOT, __DOT, __DOT, __DOT},
    {__DASH, __DOT, __DOT, __DOT, __DOT},
    {__DASH, __DASH, __DOT, __DOT, __DOT},
    {__DASH, __DASH, __DASH, __DOT, __DOT},
    {__DASH, __DASH, __DASH, __DASH, __DOT},

    // Morse code sequences for letters A-Z
    {__DOT, __DASH, 0, 0, 0},
    {__DASH, __DOT, __DOT, __DOT, 0},
    {__DASH, __DOT, __DASH, __DOT, 0},
    {__DASH, __DOT, __DOT, 0, 0},
    {__DOT, 0, 0, 0, 0},
    {__DOT, __DOT, __DASH, __DOT, 0},
    {__DASH, __DASH, __DOT, 0, 0},
    {__DOT, __DOT, __DOT, __DOT, 0},
    {__DOT, __DOT, 0, 0, 0},
    {__DOT, __DASH, __DASH, __DASH, 0},
    {__DASH, __DOT, __DASH, 0, 0},
    {__DOT, __DASH, __DOT, __DOT, 0},
    {__DASH, __DASH, 0, 0, 0},
    {__DASH, __DOT, 0, 0, 0},
    {__DASH, __DASH, __DASH, 0, 0},
    {__DOT, __DASH, __DASH, __DOT, 0},
    {__DASH, __DASH, __DOT, __DASH, 0},
    {__DOT, __DASH, __DOT, 0, 0},
    {__DOT, __DOT, __DOT, 0, 0},
    {__DASH, 0, 0, 0, 0},
    {__DOT, __DOT, __DASH, 0, 0},
    {__DOT, __DOT, __DOT, __DASH, 0},
    {__DOT, __DASH, __DASH, 0, 0},
    {__DASH, __DOT, __DOT, __DASH, 0},
    {__DASH, __DOT, __DASH, __DASH, 0},
    {__DASH, __DASH, __DOT, __DOT, 0},

};

int _morse_seq_map_hash_func(char c)
{

    if (c > _LAST_CHAR_NUMBERS)
        return (c % _FIRST_CHAR_LETTERS) + (_LAST_CHAR_NUMBERS % _FIRST_CHAR_NUMBERS + 1);
    else
        return c % _FIRST_CHAR_NUMBERS;
}

MorseSeq *get_morse_sequence(unsigned char c)
{
    return &_MORSE_SEQ_MAP[_morse_seq_map_hash_func(c)];
}

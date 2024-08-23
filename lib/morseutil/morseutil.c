#include "morseutil.h"

MorseSeqMap _MORSE_SEQ_MAP = {
    __M_0,
    __M_1,
    __M_2,
    __M_3,
    __M_4,
    __M_5,
    __M_6,
    __M_7,
    __M_8,
    __M_9,
    __M_A,
    __M_B,
    __M_C,
    __M_D,
    __M_E,
    __M_F,
    __M_G,
    __M_H,
    __M_I,
    __M_J,
    __M_K,
    __M_L,
    __M_M,
    __M_N,
    __M_O,
    __M_P,
    __M_Q,
    __M_R,
    __M_S,
    __M_T,
    __M_U,
    __M_V,
    __M_W,
    __M_X,
    __M_Y,
    __M_Z,
};

int _morse_seq_map_hash_func(char c)
{

    if (c > _LAST_CHAR_NUMBERS)
        return (c % _FIRST_CHAR_LETTERS) + (_LAST_CHAR_NUMBERS % _FIRST_CHAR_NUMBERS + 1);
    else
        return c % _FIRST_CHAR_NUMBERS;
}

MorseSeq *_get_letter_morse_sequence(unsigned char c)
{
    return &_MORSE_SEQ_MAP[_morse_seq_map_hash_func(c)];
}

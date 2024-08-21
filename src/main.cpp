#include <Arduino.h>

const int PIN = 9;
const int TIME_UNIT = 1000;
const int DOT = TIME_UNIT;
const int DASH = 3 * TIME_UNIT;
const int SPACING_SAME_LETTER = TIME_UNIT;
const int SPACING_BETWEEN_LETTERS = 3 * TIME_UNIT;
const int SPACING_BETWEEN_WORDS = 7 * TIME_UNIT;

const int M_SEQ_SIZE = 5;

typedef int m_seq[M_SEQ_SIZE];

typedef struct m_letterSeqMap
{
    char letter;
    m_seq seq;
} m_letterSeqMap;

// Morse code sequences for letters A-Z
m_letterSeqMap seqMaps[] = {
    {'A', {DOT, DASH, 0, 0, 0}},
    {'B', {DASH, DOT, DOT, DOT, 0}},
    {'C', {DASH, DOT, DASH, DOT, 0}},
    {'D', {DASH, DOT, DOT, 0, 0}},
    {'E', {DOT, 0, 0, 0, 0}},
    {'F', {DOT, DOT, DASH, DOT, 0}},
    {'G', {DASH, DASH, DOT, 0, 0}},
    {'H', {DOT, DOT, DOT, DOT, 0}},
    {'I', {DOT, DOT, 0, 0, 0}},
    {'J', {DOT, DASH, DASH, DASH, 0}},
    {'K', {DASH, DOT, DASH, 0, 0}},
    {'L', {DOT, DASH, DOT, DOT, 0}},
    {'M', {DASH, DASH, 0, 0, 0}},
    {'N', {DASH, DOT, 0, 0, 0}},
    {'O', {DASH, DASH, DASH, 0, 0}},
    {'P', {DOT, DASH, DASH, DOT, 0}},
    {'Q', {DASH, DASH, DOT, DASH, 0}},
    {'R', {DOT, DASH, DOT, 0, 0}},
    {'S', {DOT, DOT, DOT, 0, 0}},
    {'T', {DASH, 0, 0, 0, 0}},
    {'U', {DOT, DOT, DASH, 0, 0}},
    {'V', {DOT, DOT, DOT, DASH, 0}},
    {'W', {DOT, DASH, DASH, 0, 0}},
    {'X', {DASH, DOT, DOT, DASH, 0}},
    {'Y', {DASH, DOT, DASH, DASH, 0}},
    {'Z', {DASH, DASH, DOT, DOT, 0}},

    // Morse code sequences for numbers 0-9
    {'0', {DASH, DASH, DASH, DASH, DASH}},
    {'1', {DOT, DASH, DASH, DASH, DASH}},
    {'2', {DOT, DOT, DASH, DASH, DASH}},
    {'3', {DOT, DOT, DOT, DASH, DASH}},
    {'4', {DOT, DOT, DOT, DOT, DASH}},
    {'5', {DOT, DOT, DOT, DOT, DOT}},
    {'6', {DASH, DOT, DOT, DOT, DOT}},
    {'7', {DASH, DASH, DOT, DOT, DOT}},
    {'8', {DASH, DASH, DASH, DOT, DOT}},
    {'9', {DASH, DASH, DASH, DASH, DOT}},
};

int main()
{
    char text[] = "CBA123";
    int textLength = strlen(text);

    for (int i = 0; i < textLength; i++)
    {
        char c = toupper(text[i]);

        for (unsigned int j = 0; j < sizeof(seqMaps) / sizeof(seqMaps[0]); j++)
        {
            m_letterSeqMap curr_letterSeqMap = seqMaps[j];
            if (curr_letterSeqMap.letter == c)
            {
                for (int k = 0; k < M_SEQ_SIZE; k++)
                {
                    int curr_seq = curr_letterSeqMap.seq[k];
                    if (curr_seq != 0)
                    {
                        printf("%d ", curr_seq);
                    }
                }
                printf("\n");
                break;
            }
        }
    }

    return 0;
}
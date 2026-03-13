#include <stdio.h>
#include <unity.h>
#include <string.h>

#include "morseutil.hpp"

void setUp(void)
{
}

void tearDown(void)
{
}

void test__morse_seq_map_hash_func()
{

    TEST_ASSERT_EQUAL(0, _morse_seq_map_hash_func('0'));
    TEST_ASSERT_EQUAL(1, _morse_seq_map_hash_func('1'));
    TEST_ASSERT_EQUAL(2, _morse_seq_map_hash_func('2'));
    TEST_ASSERT_EQUAL(3, _morse_seq_map_hash_func('3'));
    TEST_ASSERT_EQUAL(4, _morse_seq_map_hash_func('4'));
    TEST_ASSERT_EQUAL(5, _morse_seq_map_hash_func('5'));
    TEST_ASSERT_EQUAL(6, _morse_seq_map_hash_func('6'));
    TEST_ASSERT_EQUAL(7, _morse_seq_map_hash_func('7'));
    TEST_ASSERT_EQUAL(8, _morse_seq_map_hash_func('8'));
    TEST_ASSERT_EQUAL(9, _morse_seq_map_hash_func('9'));

    TEST_ASSERT_EQUAL(10, _morse_seq_map_hash_func('A'));
    TEST_ASSERT_EQUAL(11, _morse_seq_map_hash_func('B'));
    TEST_ASSERT_EQUAL(12, _morse_seq_map_hash_func('C'));
    TEST_ASSERT_EQUAL(13, _morse_seq_map_hash_func('D'));
    TEST_ASSERT_EQUAL(27, _morse_seq_map_hash_func('R'));
    TEST_ASSERT_EQUAL(35, _morse_seq_map_hash_func('Z'));
}

void test___get_letter_morse_sequence()
{

    MorseSeq zero;
    MorseSeq zero_seq = __M_0;
    memcpy(zero, zero_seq, sizeof(MorseSeq));
    unsigned char zero_char = '0';
    MorseSeq *result_for_zero = _get_letter_morse_sequence(zero_char);

    TEST_ASSERT_EQUAL(0, memcmp(zero, *result_for_zero, sizeof(MorseSeq)));

    MorseSeq four;
    MorseSeq four_seq = __M_4;
    memcpy(four, four_seq, sizeof(MorseSeq));
    unsigned char four_char = '4';
    MorseSeq *result_for_four = _get_letter_morse_sequence(four_char);

    TEST_ASSERT_EQUAL(0, memcmp(four, *result_for_four, sizeof(MorseSeq)));

    MorseSeq R;
    MorseSeq R_seq = __M_R;
    memcpy(R, R_seq, sizeof(MorseSeq));
    unsigned char R_char = 'R';
    MorseSeq *result_for_R = _get_letter_morse_sequence(R_char);

    TEST_ASSERT_EQUAL(0, memcmp(R, *result_for_R, sizeof(MorseSeq)));
}

void test_iterator()
{

    unsigned char text[] = "AB";

    int expected[] = {
        __DOT,
        __SPACING_SAME_LETTER,
        __DASH,
        __SPACING_BETWEEN_LETTERS,
        __DASH,
        __SPACING_SAME_LETTER,
        __DOT,
        __SPACING_SAME_LETTER,
        __DOT,
        __SPACING_SAME_LETTER,
        __DOT,
        __SPACING_SAME_LETTER,
    };

    int i = 0;

    while (true)
    {
        int res = iterator(text);

        if (res == 0)
            break;

        char msg_buffer[16];
        snprintf(msg_buffer, sizeof(msg_buffer), "%d", i + 1);

        TEST_ASSERT_EQUAL_INT_MESSAGE(expected[i], res, msg_buffer);
        i++;
    }
}

int main(int argc, char **argv)
{

    UNITY_BEGIN();

    RUN_TEST(test__morse_seq_map_hash_func);
    RUN_TEST(test___get_letter_morse_sequence);
    RUN_TEST(test_iterator);

    UNITY_END();
}
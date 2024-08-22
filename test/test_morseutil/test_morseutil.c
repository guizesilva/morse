#include <unity.h>
#include <string.h>
#include "morseutil.h"

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

void test_get_morse_sequence()
{

    MorseSeq zero;
    memcpy(zero, _MORSE_SEQ_MAP[0], sizeof(MorseSeq));
    unsigned char zero_char = '0';
    MorseSeq *result_for_zero = get_morse_sequence(zero_char);

    TEST_ASSERT_EQUAL(0, memcmp(zero, *result_for_zero, sizeof(MorseSeq)));

    MorseSeq four;
    memcpy(four, _MORSE_SEQ_MAP[4], sizeof(MorseSeq));
    unsigned char four_char = '4';
    MorseSeq *result_for_four = get_morse_sequence(four_char);

    TEST_ASSERT_EQUAL(0, memcmp(four, *result_for_four, sizeof(MorseSeq)));

    MorseSeq R;
    memcpy(R, _MORSE_SEQ_MAP[27], sizeof(MorseSeq));
    unsigned char R_char = 'R';
    MorseSeq *result_for_R = get_morse_sequence(R_char);

    TEST_ASSERT_EQUAL(0, memcmp(R, *result_for_R, sizeof(MorseSeq)));
}

int main(int argc, char **argv)
{

    UNITY_BEGIN();

    RUN_TEST(test__morse_seq_map_hash_func);
    RUN_TEST(test_get_morse_sequence);

    UNITY_END();
}
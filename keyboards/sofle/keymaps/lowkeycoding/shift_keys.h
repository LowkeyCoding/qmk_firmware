#include "features/custom_shift_keys.h"
const custom_shift_key_t custom_shift_keys[] = {
    {DK_GRV,    DK_TILD},   // Shift ´ is ~
    {DK_2,      DK_AT},     // Shift 1 is @
    {DK_4,      DK_DLR},    // Shift 4 is $
    {DK_6,      DK_CIRC},   // Shift 6 is ^
    {DK_7,      DK_AMPR},   // Shift 7 is &
    {DK_8,      DK_ASTR},   // Shift 8 is *
    {DK_9,      DK_LPRN},   // Shift 9 is (
    {DK_0,      DK_RPRN},   // Shift 0 is )
    {DK_BSLS,   DK_PIPE},   // Shift \ is |
    {DK_QUOT,   DK_DQUO},   // Shift ' is "
    {DK_SCLN,   DK_COLN},   // Shift ; is :
    {DK_COMM,   DK_LABK},   // Shift , is <
    {DK_DOT,    DK_RABK},   // Shift . is >
    {DK_SLSH,   DK_QUES},   // Shift / is ?
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
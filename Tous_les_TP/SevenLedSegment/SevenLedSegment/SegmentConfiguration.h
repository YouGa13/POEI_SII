#ifndef SEGMENT_CONFIGURATION_H
#define SEGMENT_CONFIGURATION_H

#include "STMF100RegisterConfiguration.h"

#define NUM_SEGMENT 8

Pin_t SEGMENTS[NUM_SEGMENT] = {
    {GPIOA,  4}, /* a segment */
    {GPIOB,  0}, /* b segment */
    {GPIOA,  8}, /* c segment */
    {GPIOB, 10}, /* d segment */
    {GPIOB,  5}, /* e segment */
    {GPIOA,  1}, /* f segment */
    {GPIOA,  0}, /* g segment */
    {GPIOA,  7}  /* dp/h segment */
};

uint8_t NUMBERS[11] = {
    0b11111100, /* 0 */
    0b01100000, /* 1 */
    0b11011010, /* 2 */
    0b11110010, /* 3 */
    0b01100110, /* 4 */
    0b10110110, /* 5 */
    0b10111110, /* 6 */
    0b11100000, /* 7 */
    0b11111110, /* 8 */
    0b11110110, /* 9 */
    0b00000001  /* . */
};

void op_segment(uint8_t segment_name, ope_t ope_type);

void display_num(uint8_t num);

void turn_off_segment(Pin_t* segments);

#endif /* SEGMENT_CONFIGURATION_H */
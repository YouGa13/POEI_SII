#include "SegmentConfiguration.h"

void op_segment(uint8_t segment_name, ope_t ope_type) {
    operation_ODR(&SEGMENTS[segment_name - 'a'], ope_type);
}

void display_num(uint8_t num) {
    for (uint8_t i = 0; i < NUM_SEGMENT; ++i) {
        NUMBERS[num] & (1 << i) ? op_segment('h' - i, CLEAR) : op_segment('h' - i, SET);
    }
}

void turn_off_segment(Pin_t* segments) {
    for (unsigned char i = 0; i < NUM_SEGMENT; ++i) {
        operation_BSRR(&segments[i], SET);
    }
}
#include "SegmentConfiguration.h"

void ms_delay(int ms) {
    while (ms-- > 0) {
        volatile int x = 500;
        while (x-- > 0) {
            //__asm("nop");
        }
    }
}

int main(void) {
    for (int i = 0; i < NUM_SEGMENT; ++i) {
        init_GPIO_Pin(*(SEGMENTS + i), WRITE_2MHz);
    }
    turn_off_segment(SEGMENTS);
    Pin_t buttonPC13 = { GPIOC, 13 };
    init_GPIO_Pin(buttonPC13, READ);

    uint32_t PC13_en = GPIOC->IDR & (1 << 13);
    uint32_t i       = 0;
    while (1) {
        uint32_t last = PC13_en;
        PC13_en       = GPIOC->IDR & (1 << 13);
        if (last && !PC13_en) {
            i = (i + 1) % 11;
        }
        display_num(i);
        ms_delay(20);
    }
    return 0;
}
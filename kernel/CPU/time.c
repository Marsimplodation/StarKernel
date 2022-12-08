#include "time.h"
#include "irq.h"
#include "../Graphics/VGADriver.h"
#include "../utils/types.h"
#include "../utils/common.h"


u32 timer = 0;
void sleep(u32 time, Time timeType) {
    timer = time * timeType;
    while (timer != 0) {}
}

void timerCallBack(registers_t r) {
    if(timer != 0) {timer--;}
}

void initTimer(u32 freq) {
    u32 divisor = divisor = 1193182 / freq;
    register_interrupt_handler(0, &timerCallBack);
    outb(0x43, 0x36);
    u8 l = (u8) (divisor) & 0xFF;
    u8 h = (u8) ((divisor>>8) & 0xFF);

    outb(0x40, l);
    outb(0x40, h);
}

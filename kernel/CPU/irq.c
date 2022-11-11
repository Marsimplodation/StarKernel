#include "irq.h"
#include "../Graphics/VGADriver.h"
#include "../utils/types.h"
#include "../utils/common.h"

isr_t interruptHandler[256];
void register_interrupt_handler(u8 n, isr_t handler) {
    interruptHandler[n] = handler;
}

//irq
void irq_handler(registers_t r) {
    if (r.rdi >= 40) {
        outb(0xA0, 0x20); //reset to slave
    }
    outb(0x20, 0x20); //reset to master

    if(interruptHandler[r.rdi - 32] != 0) {
        isr_t handler = interruptHandler[r.rdi - 32];
        handler(r);
    }
}



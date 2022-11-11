#ifndef __IRQ__H__
#define __IRQ__H__
#include "../utils/common.h"

extern void (*irqHanlders[16]);

typedef void (*isr_t)(registers_t r);
void register_interrupt_handler(u8 n, isr_t handler);

#endif  //!__IRQ__H__
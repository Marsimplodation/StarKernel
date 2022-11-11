#ifndef __IDT__H__
#define __IDT__H__
#include "../utils/types.h"

struct idtEntry {
    u16 isr_low;
    u16 kernel_cs;
    u8 ist;
    u8 attributes;
    u16 isr_mid;
    u32 isr_high;
    u32 reserved;
} __attribute__ ((packed));

struct idtptr {
    u16 limit;
    struct idtEntry * base;
} __attribute__ ((packed));

typedef void (*handler) ();
extern void defaultExceptionHandler();
extern void defaultInterruptHandler();
extern void (*exceptionHandlers[32]);
extern void (*irqHanlders[16]);
void idtInit();


#endif  //!__IDT__H__
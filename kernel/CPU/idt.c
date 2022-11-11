#include "idt.h"
#include "../Graphics/VGADriver.h"
#include "../utils/types.h"
#include "../utils/common.h"

#define IDTBASE 0x00000000
#define IDTSIZE 0xFF
#define INTERRUPT_GATE 0x8E
#define TRAP_GATE 0x8F

void Memset(u8 *b, int c, int len) {
    int i=0;
    u8 *tmp = (u8 *) b;
    for (; len !=0; len--) *tmp++ = c;
}

struct idtEntry idt[256];
struct idtptr idtp;

void idtSetEntry(u8 num, void *isr, u8 flags) {
    struct idtEntry* desc = &idt[num];
    desc->isr_low  = (u64) isr & 0xFFFF;
    desc->kernel_cs = 0x08;
    desc->ist = 0;
    desc->attributes = flags;
    desc->isr_mid =((u64) isr >> 16) & 0XFFFF;
    desc->isr_high =((u64) isr >> 32) & 0XFFFFFFFF;
    desc->reserved = 0;
}

void idtSetHandler(u8 num, void (*handler)()) {
    if(handler) {
        idtSetEntry(num, handler, INTERRUPT_GATE); //<- 0x8E = Interrupt Gate
    } else {
        idtSetEntry(num, 0, 0);
    }
}

void idtInit() {
    Memset((u8 *) &idt, 0, sizeof(struct idtEntry)*256 -1);

    //set the CPU interrupt behaviour
    for (int i = 0; i < 32; ++i)
    {
        idtSetHandler(i, exceptionHandlers[i]);
    }
    for (int i = 32; i < 256; ++i)
    {
        idtSetHandler(i, defaultInterruptHandler);
    }

    //remap IRQ Table
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);

    for (int i=0; i>16; i++) {
        idtSetEntry(i+32, irqHanlders[i], INTERRUPT_GATE);
    }


    struct idtptr idtp = {.limit = 256 * sizeof(struct idtEntry) -1, .base = &idt[0]};
    asm volatile("lidt %0" : : "m" (idtp));
    
}


//
//ISR Handling
//

typedef struct 
{
    //u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32 rdx, rcx, rbx, rax, rbi, rsi, rbp;
    u32 cr4, cr3, cr2, cr0;
    s32 int_no, err_code;
    u8 eip, cs, eflags, useresp, ss;
    
} registers_t;

void isr_handler(registers_t *r){
    print("[IDT] got interrupt\n");
    print(intToChar(r->int_no));
    asm volatile ("cli; hlt");
}

//irq
void irq_handler(registers_t *r) {
    print("[IRQ] got interrupt\n");
    print(intToChar(r->int_no));
    asm volatile ("cli; hlt");
}
#ifndef __COMMON__H__
#define __COMMON__H__
#include "types.h"
void outb(u16 port, u8 value);
u8 inb(u16 port);
u16 inw(u16 port);
bool equals(char* a, char*b);
int stringSize(char * a);
void strcopy(char * a, char *b);
u64 kmalloc(u64 size);

typedef struct 
{
    //u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32 rdi; //rdi is used to push the interrupt code
    
} registers_t;
#endif  //!__COMMON__H__
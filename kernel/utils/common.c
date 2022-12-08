#include "common.h"
#include "types.h"

void outb(u16 port, u8 value) {
    asm volatile ("outb %1, %0" : : "dN"(port), "a" (value));
}

u8 inb(u16 port) {
    u8 ret;
    asm volatile("inb %1, %0" : "=a"(ret) :"dN" (port));
    return ret;
}

u16 inw(u16 port) {
    u16 ret;
    asm volatile("inw %1, %0" : "=a"(ret) : "dN" (port));
    return ret;
}

bool equals(char* a, char*b) {
    int i = 0;
    while(a[i] != 0x0) {
        if(a[i] != b[i]) {
            return false;
        }
        i++;
    }
    if(b[i] != 0x0) {
        return false;
    }
    return true;
}

int stringSize(char * a) {
    int ret = 0;
    while(a[ret] != 0x0) {ret++;}
    return ret;
}
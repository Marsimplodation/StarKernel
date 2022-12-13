#include "common.h"
#include "types.h"
#include "../Graphics/VGADriver.h"

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

void strcopy(char * a, char *b) {
    int i = 0;
    while(b[i] != 0x0) {a[i] = b[i]; i++;}
}

extern u64 p5_table;
//u64 currentMem;
u64 * placementAddress = &p5_table;
u64 kmalloc(u64 size) {
  u64 tmp = (u64) placementAddress;
  placementAddress += size;
  if(placementAddress - &p5_table >= 4096) {
    print("all memory on page 5 used up\n");
  }
  return tmp;
}
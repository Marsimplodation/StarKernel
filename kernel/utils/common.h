#ifndef __COMMON__H__
#define __COMMON__H__
#include "types.h"
void outb(u16 port, u8 value);
u8 inb(u16 port);
u16 inw(u16 port);
#endif  //!__COMMON__H__
#ifndef __TIME__H__
#define __TIME__H__
#include "../utils/types.h"
typedef enum {SECONDS=100, MILLISECONDS=1} Time;
void initTimer(u32 freq);
void sleep(u32 time, Time timeType);
#endif  //!__TIME__H__

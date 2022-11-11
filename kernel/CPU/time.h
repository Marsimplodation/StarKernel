#ifndef __TIME__H__
#define __TIME__H__
#include "../utils/types.h"
typedef enum {SECONDS=100, MILLISECONDS=1} Time;
void init_timer();
void sleep(u32 time, Time time_type);
#endif  //!__TIME__H__
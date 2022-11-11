#ifndef __VGADRIVER__H__
#define __VGADRIVER__H__

#include "../dictionary/dictionary.h"
#include "../utils/types.h"

#define COLS 80
#define ROWS 25

typedef unsigned short u16;

void clearScreen ();
void loadBuffer ();
void print (char * word);
void changeColor(colors color);

#endif  //!__VGADRIVER__H__
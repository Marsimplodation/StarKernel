#include "VGADriver.h"
#include "../dictionary/dictionary.h"
#include "../utils/types.h"

u16* memory = (u16*) (0xB8000);
u16 * buffer;
int VGApos = 0;
colors printColor = WHITE;

void changeColor(colors color) {printColor = color;}

//take a u8 char and combine it with a color, to get a u16 short
u16 char2short(char pchar, colors color) {
    return (color << 8) | getAsciVal(pchar);
}

void clearScreen() {
    VGApos = 0;
    //init every bit as ' '
    for (int i = 0; i < ROWS * COLS; i++) {
        memory[i] = 0x20;
        buffer[i] = 0x20;
    }
}


void loadBuffer() {
    for (int i = 0; i < ROWS * COLS; i++) {
        //set every bit in the memory like in the buffer
        memory[i] = buffer[i];

        //move every line one below in the buffer
        if(i > COLS) {
            buffer[i-COLS] = buffer[i];
        }
    }
}


void print (char * word) {
    u16 ch;
    for (int i = 0; i >= 0 ; i++) {
        if(word[i] == 0x0) {break;}
        ch = char2short(word[i], printColor);

        //
        if(VGApos +1 >= COLS * ROWS) {
            loadBuffer();
        }

        //if possible move one line down, if not load buffer
        if(word[i] == '\n') {
            if(VGApos + (COLS - (VGApos % COLS)) <COLS * ROWS) {
                VGApos += (COLS - (VGApos % COLS));
            } else {
                loadBuffer();
            }
        }
        //set char in buffer and in the vga memory
        else {memory[(VGApos++)] = ch;}
        if(VGApos > COLS) {
            buffer[VGApos-COLS] = ch;
        }
    }
}
#include "keyboard.h"
#include "../utils/types.h"
#include "../StarLang/shell.h"
#include "../CPU/idt.h"
#include "../Graphics/VGADriver.h"

char * cmd;
int pos = 0;

void initKeyboard() {
    outb(0xa1, 0xff);
    for (int i = 0; i<10; i++) {
        cmd[i] = 0x0;
    }
    register_interrupt_handler(1, &keyboardGerman);
}

void keyboardGerman() {
    u8 c = inw(0x60);
    char key[2];
    key[0] = 0x0;
    key[1] = 0x0;
    switch (c) {
    case 0x39:
      key[0] =' ';
      break;
    case 0x0E:
      if(pos > 0) {
        pos--;
        cmd[pos] = 0x0;
        deleteChar();
      }
      break;
    case 0x1E:
        key[0] = 'a'; 
        break;
    case 0x1F:
        key[0] = 's';
        break;
    case 0x20:
        key[0] = 'd';
        break;
    case 0x1c:
        print("\n");
        handleCommand(cmd);
        pos = 0;
        for(int i = 0; i<10; i++) {
            cmd[i] = 0x0;
        }
        print("> ");
        break;
    case 0x10:
        key[0] ='q';
        break;
    case 0x11:
        key[0] ='w';
        break;
    case 0x12:
        key[0] = 'e';
        break;
    case 0x13:
        key[0] ='r';
        break;
    case 0x14:
        key[0] ='t';
        break;
    case 0x15:
        key[0] ='z';
        break;
    case 0x16:
        key[0] ='u';
        break;
      case 0x17:
        key[0] ='i';
        break;
    case 0x18:
        key[0] ='o';
        break;
    case 0x19:
        key[0] ='p';
        break;
    case 0x21:
        key[0] ='f';
        break;
    case 0x22:
        key[0] ='g';
        break;
    case 0x23:
        key[0] ='h';
        break;
    case 0x24:
        key[0] ='j';
        break;
    case 0x25:
        key[0] ='k';
        break;
    case 0x26:
        key[0] ='l';
        break;
    case 0x2C:
        key[0] ='y';
        break;
    case 0x2D:
        key[0] ='x';
        break;
    case 0x2E:
        key[0] ='c';
        break;
    case 0x30:
        key[0] ='b';
        break;
    case 0x2F:
        key[0] ='v';
        break;
    case 0x32:
        key[0] ='m';
        break;
    case 0x31:
        key[0] ='n';
        break;
      default:
        break;
    
    }
    if(key[0] != 0x0) {
        print(key);
        cmd[pos++]=key[0];
    }
}
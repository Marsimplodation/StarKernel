#include "commands.h"
#include "shell.h"
#include "../filesystem/filesystem.h"
#include "../utils/types.h"
#include "../utils/common.h"
#include "../Graphics/VGADriver.h"
#include "../CPU/time.h"


command * rootCommand;

void addCommand(char * name, void (*func)(char *)) {
    command * node = rootCommand;
    if(node == 0x0) {
        rootCommand = (command *)kmalloc(sizeof(command));
        node = rootCommand;
    } else {
        while(node->next != 0x0) {
            node = node->next;
        }
        node->next = (command *)kmalloc(sizeof(command));
        node = node->next;
    }
    node->name = (char *)kmalloc(stringSize(name));
    strcopy(node->name, name);
    node->func = func;
    node->next = 0x0;
}

command * getCommand(char * name) {
    command * node = rootCommand;
    while(node != 0x0 && node->name) {
        if(equals(node->name, name)) {
            return node;
        }
        node = node->next;
    }
    return 0x0;
}

void getRest(char * cmd) {
    int j = 0;
    int pos = 0;
    //read the rest of the line
    while (cmd[pos] != ' ' && cmd[pos != 0x0]) {pos++;}
    pos++; //skip the space
    while(cmd[j+pos] != 0x0) {
      cmd[j] = cmd[j+pos];
      j++;
    }
    cmd[j++] = 0x0;
}




void echo(char * cmd) {
    getRest(cmd);
    print(cmd);
    print("\n");
}



void callSleep(char * cmd) {
    getRest(cmd);
    asm volatile("sti");
    sleep(CharToInt(cmd), MILLISECONDS);
}

void initCommands() {
    addCommand("echo", &echo);
    addCommand("clear", &clearScreen);
    addCommand("ls", &listFiles);
    addCommand("cat", &cat);
    //breaks somehow, throws IDT 13
    //addCommand("touch", &touch);
    addCommand("write", &write);
    addCommand("sleep", &callSleep);
}
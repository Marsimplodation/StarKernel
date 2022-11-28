#include "shell.h"
#include "../utils/types.h"
#include "../Graphics/VGADriver.h"
#include "../CPU/time.h"

bool strIn(char* a, char*b) {
    int i = 0;
    while(b[i] != 0x0) {
        if(a[i] != b[i]) {
            return false;
        }
        i++;
    }
    return true;
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

char * tmp;
char * arg1;

typedef struct function {
    char * command;
    struct function * next;
} function;

function test;

void execFunction(function * f) {
    handleCommand(f->command);
    execFunction(f->next);
}

void handleCommand(char * cmd) {
    int i = 0;
    while(cmd[i] != ' ' && cmd[i] != 0x0) {
        tmp[i] = cmd[i];
        i++;
    }
    tmp[i++] = 0x0;
    if(equals(tmp, "echo")) {
        int j = 0;
        while(cmd[i] != ' ' && cmd[i] != 0x0) {
            arg1[j++] = cmd[i++];
        }
        arg1[j++] = '\n';
        arg1[j++] = 0x0;
        print(arg1);
    } else if (equals(tmp, "clear")){
        clearScreen();
    } else {
        print("Command '"); print(tmp); print("' not found\n");
    }
}

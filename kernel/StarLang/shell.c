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

typedef struct file{
  char * name;
  char* content;
}file;

typedef struct folder{
  file * f;
}folder;

file fi={.name="test", .content="echo lol"};
folder root = {&fi};

void handleFile(file * fi) {
  int i = 0;
  int j = 0;
  while(fi->content[i] != 0x0) {
    if(fi->content[i] == '\n') {
      tmp[j++] = 0x0;
      handleCommand(tmp);
      j=0;
      i++;
    } else {
      tmp[j] = fi->content[i];
      i++;
      j++;
    }
  }
  if(j!=0) {
    tmp[j++] = 0x0;
    handleCommand(tmp);
    j=0;
  }
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
    } else if(equals(tmp, "set")) {
      root.f->content = "echo hello\ntest";
    } else if (equals(tmp, "clear")){
        clearScreen();
    } else {
        if(equals(tmp, root.f->name)) {handleFile(root.f);}
        else { print("Command '"); print(tmp); print("' not found\n"); }
    }
}

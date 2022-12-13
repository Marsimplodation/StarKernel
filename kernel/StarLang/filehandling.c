#include "commands.h"
#include "shell.h"
#include "../filesystem/filesystem.h"
#include "../utils/types.h"
#include "../utils/common.h"
#include "../Graphics/VGADriver.h"
#include "../CPU/time.h"

file * fileToWrite;
bool hijack = false;
void (*castInputTo)(char *);

bool hijackInput(char * cmd) {
    if(hijack) {
        castInputTo(cmd);
        return true;
    }
    return false;
}

void printFile(file * f) {
    line * l = f->lines;
    while(l != 0x0) {
        print(l->content);
        l = l->next;
        print("\n");
    }
}

char * tmp2;
void writeToFile(char * cmd) {
    int i = 0;
    while(cmd[i] != ' ' && cmd[i] != 0x0) {
        tmp2[i] = cmd[i];
        i++;
    }
    tmp2[i++] = 0x0;
  //exit
  if(equals(tmp2, "exit")) {
    clearScreen();
    printFile(fileToWrite);
    fileToWrite = 0x0;
    hijack = false;
    print("exit writing file\n");
    return;
  } else if (equals(tmp2, "del")) {
    getRest(cmd);
    delLine(fileToWrite, CharToInt(cmd));
    clearScreen();
    printFile(fileToWrite);
    return;
  }

  addLine(fileToWrite, cmd);
  clearScreen();
  printFile(fileToWrite);
}



void write(char* cmd) {
    getRest(cmd);
    fileToWrite = searchFile(cmd);
      if(fileToWrite == 0x0) {
        print("No file named: ");
        print(cmd);
        print("\n");
        return;}
      clearScreen();
      printFile(fileToWrite);
      castInputTo = &writeToFile;
      hijack = true;
}

void touch(char * cmd) {
    getRest(cmd);
    fileToWrite = searchFile(cmd);
      if(fileToWrite == 0x0) {
    createFile(cmd, "echo New File");
    print("created File : ");
    print(cmd);
    print("\n");
    return;}
}


void cat(char * cmd) {
    getRest(cmd);
      fileToWrite = searchFile(cmd);
      if(fileToWrite == 0x0) {
        print("No file named: ");
        print(cmd);
        print("\n");
        return;}
      printFile(fileToWrite);
}


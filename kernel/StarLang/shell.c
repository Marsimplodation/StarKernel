#include "shell.h"
#include "../utils/types.h"
#include "../utils/common.h"
#include "../Graphics/VGADriver.h"
#include "../CPU/time.h"
#include "../filesystem/filesystem.h"


char * tmp;
char * arg1;

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

bool hijackInput = false;
void (*castInputTo)(char *);
file * fileToWrite = 0x0;

void writeToFile(char * cmd) {
  //exit
  if(equals(cmd, "exit")) {
    clearScreen();
    print(fileToWrite->content);
    fileToWrite = 0x0;
    hijackInput = false;
    print("exit writing file\n");
    return;
  }

  int currentPos = stringSize(fileToWrite->content);
  for (int i = 0; cmd[i] != 0x0; i++) {
    fileToWrite->content[currentPos++] = cmd[i];
  }
  fileToWrite->content[currentPos++] = '\n';
  fileToWrite->content[currentPos++] = 0x0;

  clearScreen();
  print(fileToWrite->content);
}


void executeFile(file * fi) {
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
  if(hijackInput) {
    castInputTo(cmd);
    return;
  } 
  int i = 0;
  while(cmd[i] != ' ' && cmd[i] != 0x0) {
      tmp[i] = cmd[i];
      i++;
  }
  tmp[i++] = 0x0;
  if(equals(tmp, "echo")) {
      int j = 0;
      //read the rest of the line
      while(cmd[i] != 0x0) {
          arg1[j++] = cmd[i++];
      }
      arg1[j++] = '\n';
      arg1[j++] = 0x0;
      print(arg1);
  }
  else if(equals(tmp, "write")) {
    int j = 0;
      //read the rest of the line
      while(cmd[i] != 0x0) {
          arg1[j++] = cmd[i++];
      }
      arg1[j++] = 0x0;
      fileToWrite = searchFile(arg1);
      if(fileToWrite == 0x0) {
        print("No file named: ");
        print(arg1);
        print("\n");
        return;}
      clearScreen();
      print(fileToWrite->content);
      castInputTo = &writeToFile;
      hijackInput = true;
  }

  else if(equals(tmp, "cat")) {
    int j = 0;
      //read the rest of the line
      while(cmd[i] != 0x0) {
          arg1[j++] = cmd[i++];
      }
      arg1[j++] = 0x0;
      fileToWrite = searchFile(arg1);
      if(fileToWrite == 0x0) {
        print("No file named: ");
        print(arg1);
        print("\n");
        return;}
      print(fileToWrite->content);
      print("\n");
  }

  else if(equals(tmp, "touch")) {
    int j = 0;
      //read the rest of the line
      while(cmd[i] != 0x0) {
          arg1[j++] = cmd[i++];
      }
      arg1[j++] = 0x0;
      fileToWrite = searchFile(arg1);
      if(fileToWrite == 0x0) {
        createFile(arg1, "#New File\n");
        print("created File : ");
        print(arg1);
        print("\n");
        return;}
  }

  else if(equals(tmp, "sleep")) {
      int j = 0;
      //read the rest of the line
      while(cmd[i] != 0x0) {
          arg1[j++] = cmd[i++];
      }
      arg1[j++] = '\n';
      arg1[j++] = 0x0;
      asm volatile ("sti");
      sleep(CharToInt(arg1), MILLISECONDS);
  } else if (equals(tmp, "clear")){
      clearScreen();
  }else if (equals(tmp, "ls")){
      listFiles();
  } else {
      file * f = searchFile(tmp);
      //file * f = 0x0;
      if(f != 0x0) {executeFile(f);}
      else { print("Command '"); print(tmp); print("' not found\n"); }
  }
}

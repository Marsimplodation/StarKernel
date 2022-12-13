#include "shell.h"
#include "commands.h"
#include "../utils/types.h"
#include "../utils/common.h"
#include "../Graphics/VGADriver.h"
#include "../CPU/time.h"
#include "../filesystem/filesystem.h"

file * fileToExecute;

char * tmp;

void executeFile(file * fi) {
  line * l = fi->lines;
  while(l != 0x0) {
    handleCommand(l->content);
    l=l->next;
  }
}

void handleCommand(char * cmd) {
  if(hijackInput(cmd)) {return;};
  int i = 0;
  while(cmd[i] != ' ' && cmd[i] != 0x0) {
      tmp[i] = cmd[i];
      i++;
  }
  tmp[i++] = 0x0;
  command * c = getCommand(tmp);
  if(c == 0x0) {
    fileToExecute = searchFile(tmp);
    if (fileToExecute != 0x0) {
      executeFile(fileToExecute);
      return;
    }
    print("Command '");
    print(tmp);
    print("' not found\n"); 
    return;
    }
  c->func(cmd);
}
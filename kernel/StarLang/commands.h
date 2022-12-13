#ifndef __COMMANDS__H__
#define __COMMANDS__H__
#include "../utils/types.h"
#include "../filesystem/filesystem.h"

typedef struct command {
    char * name;
    void (*func)(char *);
    struct command * next;
} command;

void addCommand(char * name, void (*func)(char *));
command * getCommand(char * name);
void initCommands();
bool hijackInput(char * cmd);
void getRest(char * cmd);

//commands
void printFile(file * f);
void writeToFile(char * cmd);
void write(char* cmd);
void touch(char * cmd);
void cat(char * cmd);

#endif  //!__COMMANDS__H__
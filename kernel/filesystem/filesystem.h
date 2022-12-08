#ifndef __FILESYSTEM__H__
#define __FILESYSTEM__H__

typedef struct file{
  char * name;
  char * content;
  struct file * next;
}file;

file * searchFile(char * cmd);
void createFile(char * name, char * content);
void listFiles();

#endif  //!__FILESYSTEM__H__
#ifndef __FILESYSTEM__H__
#define __FILESYSTEM__H__

typedef struct line {
  int index;
  char * content;
  struct line * prev;
  struct line * next;
} line;


typedef struct file{
  char * name;
  //char * content;
  line * lines;
  struct file * next;
}file;

file * searchFile(char * cmd);
void createFile(char * name, char * content);
void listFiles();
void addLine(file * f, char * content);
void delLine(file * f, int num);

#endif  //!__FILESYSTEM__H__
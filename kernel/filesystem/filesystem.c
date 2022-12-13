#include "filesystem.h"
#include "../utils/types.h"
#include "../utils/common.h"
#include "../Graphics/VGADriver.h"
#include "../CPU/time.h"

file * root = 0x0;

//a list is not the most efficient, but I won't have hundreds of files, so O(n) is fine
void createFile(char * name, char * content) {
    file * node = root;
    if(node == 0x0) {
        root = (file *)kmalloc(sizeof(file));
        node = root;
    } else {
        while(node->next != 0x0) {
            node = node->next;
        }
        node->next = (file *)kmalloc(sizeof(file));
        node = node->next;
    }
    node->name = (char *)kmalloc(stringSize(name));
    node->lines = (line *) kmalloc(sizeof(line));
    node->lines->content = (char *)kmalloc(stringSize(content)); 
    node->lines->next = 0x0;
    node->lines->prev = 0x0;
    node->lines->index = 0;

    strcopy(node->name, name);
    strcopy(node->lines->content, content);
    node->next = 0x0;   
}

//double linked list, cause you have a line before and after
void addLine(file * f, char * content) {
    line * l = f->lines;
    while(l->next != 0x0) {
        l = l->next;
    }
    l->next = (line *) kmalloc(sizeof(line));
    l->next->prev = l;
    l=l->next;
    l->content = (char *)kmalloc(stringSize(content));
    strcopy(l->content, content);
    l->index = l->prev->index + 1;
    l->next =  0x0;
}

void delLine(file * f, int num) {
    line * l = f->lines;
    if (num == 0) {
        l = l->next;
    }
    int i = 0;
    while(l != 0x0) {
        
        if (i == num) {
            l->prev->next = l->next;
            l = l->prev;
            return;
        }
        l = l->next;
        i++;
    }
}

file * searchFile(char * cmd) {
    file * node = root;
    while(node != 0x0 && node->name) {
        if(equals(node->name, cmd)) {
            return node;
        }
        node = node->next;
    }
    return 0x0;
}

void listFiles() {
    file * node = root;
    while(node != 0x0 && node->name) {
        
        print(node->name);
        print("\n");
        node = node->next;
    }
}
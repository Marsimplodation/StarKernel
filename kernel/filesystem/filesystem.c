#include "filesystem.h"
#include "../utils/types.h"
#include "../utils/common.h"
#include "../Graphics/VGADriver.h"
#include "../CPU/time.h"




//this is really not how it's supposed to be done
file * root = 0x0;

//a list is not really the most efficient, but should work
void createFile(char * name, char * content) {
    
    if(root == 0x0) {
        root = (file *)kmalloc(sizeof(file));
        root->content = (char *) kmalloc(sizeof(char) * 100);
        root->next = (file *) kmalloc(sizeof(file));
        root->name = (char *) kmalloc(stringSize(name));
        strcopy(root->name, name);
        root->content = content;
        root->next = 0x0;
    }else {
        file * node = root;
        while(node->next != 0x0) {
            node = node->next;
        }
        node->next = (file *)kmalloc(sizeof(file));
        node->next->content = (char *)kmalloc(sizeof(char) * 100);
        node->next->name = (char *)kmalloc(stringSize(name));
        strcopy(node->next->name, name);
        node->next->content = content;
        node->next->next = 0x0;
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

struct line {
    int start;
    int end;
};

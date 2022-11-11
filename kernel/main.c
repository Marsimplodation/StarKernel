#include "dictionary/dictionary.h"
#include "Graphics/VGADriver.h"
#include "CPU/idt.h"
#include "utils/types.h"

void printToDo() {
    changeColor(WHITE);
    print("to do:\n");
    print("  VGA-Driver "); 
    changeColor(GREEN); print("done\n"); 
    changeColor(WHITE); print("  IDT");
    changeColor(GREEN); print(" done, need to re do the isr stub\n");
    changeColor(WHITE); print("  PIT & IRQ");
    changeColor(YELLOW); print(" next\n");
    changeColor(WHITE); print("  Keyboard input");
    changeColor(RED); print(" tbd\n\n");
}

void loadSystemResources() {
    changeColor(WHITE); print("----------------------\nload system ressources\n----------------------\n");
    print("[-] loading IDT\n");
    idtInit();
    print("[+] loaded IDT\n"); 
}

void cstart() {
    //memory[0] = 0x0f48;
    clearScreen();
    changeColor(RED);
    print("Welcome to the StarKernel\n");
    printToDo();
    loadSystemResources();
    
    asm volatile ("int $0x3");
    
    for(;;) {}
}


#include "dictionary/dictionary.h"
#include "Graphics/VGADriver.h"
#include "CPU/idt.h"
#include "CPU/irq.h"
#include "CPU/time.h"
#include "utils/types.h"

u32 ticks = 0;

void printToDo() {
    changeColor(WHITE);
    print("to do:\n");
    print("  VGA-Driver "); 
    changeColor(GREEN); print("done\n"); 
    changeColor(WHITE); print("  IDT");
    changeColor(GREEN); print(" done\n");
    changeColor(WHITE); print("  PIT & IRQ");
    changeColor(GREEN); print(" done\n");
    changeColor(WHITE); print("  Simple timer function");
    changeColor(GREEN); print(" done\n");
    changeColor(WHITE); print("  Keyboard input");
    changeColor(RED); print(" tbd\n\n");
}

void loadSystemResources() {
    changeColor(WHITE); print("----------------------\nload system ressources\n----------------------\n");
    print("[-] loading IDT\n");
    idtInit();
    print("[+] loaded IDT\n"); 
    print("[-] loading timer\n");
    init_timer(100); //init timer to 100hz
    print("[+] loaded timer at 100Hz\n");
}

void cstart() {
    //memory[0] = 0x0f48;
    clearScreen();
    changeColor(RED);
    print("Welcome to the StarKernel\n");
    changeColor(WHITE);
    print("Time passed: ");
    print(intToChar(ticks));
    printToDo();
    loadSystemResources();
    
    //preparing for keyboard stuff
    outb(0xa1, 0xff);
    asm volatile ("sti");

    //pause
    sleep(250, MILLISECONDS);
    
    //just count time up
    for(;;) {
        sleep(1, SECONDS);
        clearScreen();
        changeColor(RED);
        print("Welcome to the StarKernel\n");
        changeColor(WHITE);
        ticks++;
        print("Time passed: ");
        print(intToChar(ticks));
        printToDo();
    }
}


#include "dictionary/dictionary.h"
#include "Graphics/VGADriver.h"
#include "CPU/idt.h"
#include "CPU/irq.h"
#include "CPU/time.h"
#include "utils/types.h"
#include "Keyboard/keyboard.h"

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
    changeColor(GREEN); print(" done\n\n");
}

void loadSystemResources() {
    changeColor(WHITE); print("----------------------\nload system ressources\n----------------------\n");
    print("[-] loading IDT\n");
    idtInit();
    print("[+] loaded IDT\n"); 
    print("[-] loading timer\n");
    init_timer(100); //init timer to 100hz
    print("[+] loaded timer at 100Hz\n");
    print("[-] loading keyboard\n");
    initKeyboard(); //init timer to 100hz
    print("[|] Keyboard configured to DE\n"); 
    print("[+] loaded keyboard\n");
}


void cstart() {
    //memory[0] = 0x0f48;
    clearScreen();
    changeColor(RED);
    print("Welcome to the StarKernel\n");
    changeColor(WHITE);
    print("Time passed: ");
    print(intToChar(ticks));
    //printToDo();
    loadSystemResources();
    changeColor(WHITE); print("----------------------\nShell\n----------------------\n> ");
    
    //preparing for keyboard stuff
    asm volatile ("sti");

    //pause
    sleep(25, MILLISECONDS);
    
    //just count time up
    for(;;) {
        sleep(16, MILLISECONDS);
        //cursor();
        //print("x");
    }
}


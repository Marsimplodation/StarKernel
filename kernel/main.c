#include "dictionary/dictionary.h"
#include "Graphics/VGADriver.h"
#include "CPU/idt.h"
#include "CPU/irq.h"
#include "CPU/time.h"
#include "utils/types.h"
#include "Keyboard/keyboard.h"
#include "filesystem/filesystem.h"
#include "StarLang/commands.h"

u32 ticks = 0;


void loadSystemResources() {
    changeColor(WHITE); print("----------------------\nload system ressources\n----------------------\n");
    print("[-] loading IDT\n");
    idtInit();
    print("[+] loaded IDT\n"); 
    print("[-] loading timer\n");
    initTimer(100); //init timer to 100hz
    asm volatile ("sti");
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
    loadSystemResources();
    print("\n");
    createFile("test1", "echo test");
    createFile("test2", "echo test");
    createFile("test3", "echo test");
    createFile("test4", "echo test");
    initCommands();
    changeColor(WHITE); print("----------------------\nShell\n----------------------\n> ");
    for(;;) {
        
    }
}


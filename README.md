# StarKernel <br>
Just trying to make a 64bit Kernel in regular old C booting with grub <br>
### Image
![alt text](https://raw.githubusercontent.com/Marsimplodation/StarKernel/main/Screenshots/Kernel.png)<br>

### Features and ToDo <br>
Features so far: <br>
    > Working VGA-Driver <br>
    > Working GDT <br>
    > Working IDT <br>
    > Working PIT and IRQ <br>
    > Simple Timer <br>
    > Keyboard Interrupts <br>
    > Simple shell <br>

Next to do: <br>
    > a simple file system <br>
    > more shell functions <br>
    > simple scripting language <br>
    this could take a while

### Shell <br>
`echo {word}` prints the word <br>
`clear` clears the screen <br>

not to stay: <br>
`test` prints "lol" <br>
`set` sets test to print hello and then call it self <br>

### HOW TO RUN <br>
Requirements: <br>
    > make <br>
    > clang <br>
    > nasm <br>
    > qemu <br>
    > xorriso <br>
    > grub <br>
actually running it: <br>
    just type in `make run` or just `make` <br>


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
    > a simple file system, it's crap, but don't judge me <br>

Next to do: <br>
    > more shell functions <br>

### Shell <br>
`echo {word}` prints the word <br>
`clear` clears the screen <br>
`sleep {time}` sleeps time in ms <br>
`ls` list files <br>
`write {file}` write to the file<br>
`cat {file}` show content of file <br>

### Edit files <br>
open `write` <br>
type in what you want <br>
exit with `exit` <br>

### Files <br>
note: Files are limited to 100 charactes content <br>
`test` prints "test" <br>
`loop` prints "loop", waits 16ms, jumps back <br>

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


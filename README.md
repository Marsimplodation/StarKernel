# StarKernel
Just trying to make a 64bit Kernel in regular old C booting with grub
### Features and ToDo
Features so far:
    > Working VGA-Driver 
    > Working GDT
    > Working IDT
Next to do:
    > how ISR Stubs work in 64bit land, haven't found out yet, which registers get used
    > PIT and IRQs, for timers and so on
    > Keyboard Interrupts

### HOW TO RUN
Requirements:
    > make
    > clang
    > nasm
    > qemu
    > xoriso
    > grub
actually running it:
    just type in `make run` or just `make`
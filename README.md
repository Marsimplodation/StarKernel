# StarKernel <br>
Just trying to make a 64bit Kernel in regular old C booting with grub <br>
### Features and ToDo <br>
Features so far: <br>
    > Working VGA-Driver <br>
    > Working GDT <br>
    > Working IDT <br>
Next to do: <br>
    > how ISR Stubs work in 64bit land, haven't found out yet, which registers get used <br>
    > PIT and IRQs, for timers and so on <br>
    > Keyboard Interrupts <br>

### HOW TO RUN <br>
Requirements: <br>
    > make <br>
    > clang <br>
    > nasm <br>
    > qemu <br>
    > xoriso <br>
    > grub <br>
actually running it: <br>
    just type in `make run` or just `make` <br>

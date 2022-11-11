.PHONY: run clean

run: clean
	mkdir objFiles
	nasm -f elf64 bootloader/multiboot_header.asm -o objFiles/multiboot_header.o
	nasm -f elf64 bootloader/entry.asm -o objFiles/boot.o
	nasm -f elf64 bootloader/idt.asm -o objFiles/idt_asm.o
	nasm -f elf64 bootloader/irq.asm -o objFiles/irq_asm.o
	clang -c -O0 -g kernel/main.c -o objFiles/main.o
	clang -c -O0 -g kernel/Graphics/VGADriver.c -o objFiles/VGADriver.o
	clang -c -O0 -g kernel/dictionary/dictionary.c -o objFiles/dictionary.o
	clang -c -O0 -g kernel/CPU/idt.c -o objFiles/idt.o
	clang -c -O0 -g kernel/CPU/irq.c -o objFiles/irq.o
	clang -c -O0 -g kernel/CPU/time.c -o objFiles/time.o
	clang -c -O0 -g kernel/utils/common.c -o objFiles/common.o
	ld --nmagic --output=isofiles/boot/kernel.bin --script=linker.ld objFiles/*.o

	#create iso and boot it
	grub-mkrescue -o os.iso isofiles
	qemu-system-x86_64 -cdrom os.iso -s

clean:
	rm -rf objFiles/ isofiles/boot/kernel.bin os.iso
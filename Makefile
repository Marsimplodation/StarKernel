.PHONY: run clean

run: bootloader/entry.asm bootloader/multiboot_header.asm kernel/main.c
	nasm -f elf64 bootloader/multiboot_header.asm -o multiboot_header.o
	nasm -f elf64 bootloader/entry.asm -o boot.o
	nasm -f elf64 bootloader/idt.asm -o idt_asm.o
	nasm -f elf64 bootloader/irq.asm -o irq_asm.o
	clang -c -O0 -g kernel/main.c
	clang -c -O0 -g kernel/Graphics/VGADriver.c
	clang -c -O0 -g kernel/dictionary/dictionary.c
	clang -c -O0 -g kernel/CPU/idt.c
	clang -c -O0 -g kernel/utils/common.c
	ld --nmagic --output=kernel.bin --script=linker.ld multiboot_header.o boot.o main.o VGADriver.o dictionary.o idt.o idt_asm.o common.o irq_asm.o
	cp kernel.bin isofiles/boot/

	#create iso and boot it
	grub-mkrescue -o os.iso isofiles
	rm -rf *.o kernel.bin
	qemu-system-x86_64 -cdrom os.iso -s

clean:
	rm -rf *.o kernel.bin os.iso
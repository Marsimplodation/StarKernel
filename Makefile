.PHONY: run clean

run: clean
	mkdir objFiles
	nasm -f elf64 bootloader/multiboot_header.asm -o objFiles/multiboot_header.o
	nasm -f elf64 bootloader/entry.asm -o objFiles/boot.o
	nasm -f elf64 bootloader/idt.asm -o objFiles/idt_asm.o
	nasm -f elf64 bootloader/irq.asm -o objFiles/irq_asm.o
	clang -fno-stack-protector -c -O0 -g kernel/main.c -o objFiles/main.o
	clang -fno-stack-protector -c -O0 -g kernel/Graphics/VGADriver.c -o objFiles/VGADriver.o
	clang -fno-stack-protector -c -O0 -g kernel/dictionary/dictionary.c -o objFiles/dictionary.o
	clang -fno-stack-protector -c -O0 -g kernel/CPU/idt.c -o objFiles/idt.o
	clang -fno-stack-protector -c -O0 -g kernel/CPU/irq.c -o objFiles/irq.o
	clang -fno-stack-protector -c -O0 -g kernel/CPU/time.c -o objFiles/time.o
	clang -fno-stack-protector -c -O0 -g kernel/utils/common.c -o objFiles/common.o
	clang -fno-stack-protector -c -O0 -g kernel/StarLang/shell.c -o objFiles/shell.o
	clang -fno-stack-protector -c -O0 -g kernel/StarLang/commands.c -o objFiles/commands.o
	clang -fno-stack-protector -c -O0 -g kernel/StarLang/filehandling.c -o objFiles/filehandling.o
	clang -fno-stack-protector -c -O0 -g kernel/Keyboard/keyboard.c -o objFiles/Keyboard.o
	clang -fno-stack-protector -c -O0 -g kernel/filesystem/filesystem.c -o objFiles/filesystem.o
	ld --nmagic --output=isofiles/boot/kernel.bin --script=linker.ld objFiles/*.o

	#create iso and boot it
	grub-mkrescue -o os.iso isofiles
	qemu-system-x86_64 -cdrom os.iso -s

clean:
	rm -rf objFiles/ isofiles/boot/kernel.bin os.iso

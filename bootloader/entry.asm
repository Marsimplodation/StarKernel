extern cstart
global start

section .text
bits 32

start:
    MOV eax, p3_table
    or eax, 0b11
    mov dword [p4_table + 0], eax

    MOV eax, p2_table
    or eax, 0b11
    mov dword [p3_table + 0], eax
    mov ecx, 0
    
.map_p2_table:
    mov eax, 0x200000
    mul ecx
    or eax, 0b10000011
    mov [p2_table + ecx*8], eax

    inc ecx
    cmp ecx, 512
    jne .map_p2_table

    mov eax, p4_table
    mov cr3, eax ;control register mov has to come from another register

    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    ;-set the long mode
    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr ;write model specific register

    ;-enable paging
    mov eax, cr0
    or eax, 1 << 31
    or eax, 1 << 16
    mov cr0, eax
    mov word [0xb8000], 0x0248; H
    mov word [0xb8000], 0x0248; H
    lgdt [gdt64.pointer] ;load the GDT
    
    mov ax, gdt64.data
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    
    
    ;jmp gdt64.code:long_mode_start
    jmp gdt64.code:cstart



section .bss
align 4096

p4_table:
    resb 4096
p3_table:
    resb 4096
p2_table:
    resb 4096
[GLOBAL p5_table]
p5_table:
    resb 4096

; Access bits
PRESENT        equ 1 << 7
NOT_SYS        equ 1 << 4
EXEC           equ 1 << 3
DC             equ 1 << 2
RW             equ 1 << 1
ACCESSED       equ 1 << 0
 
; Flags bits
GRAN_4K       equ 1 << 7
SZ_32         equ 1 << 6
LONG_MODE     equ 1 << 5

section .rodata
gdt64:
.null: equ $ - gdt64
        dq 0
.code: equ $ - gdt64
        dd 0xFFFF                                   ; Limit & Base (low, bits 0-15)
        db 0                                        ; Base (mid, bits 16-23)
        db PRESENT | NOT_SYS | EXEC | RW            ; Access
        db GRAN_4K | LONG_MODE | 0xF                ; Flags & Limit (high, bits 16-19)
        db 0                                        ; Base (high, bits 24-31)
.data: equ $ - gdt64
        dd 0xFFFF                                   ; Limit & Base (low, bits 0-15)
        db 0                                        ; Base (mid, bits 16-23)
        db PRESENT | NOT_SYS | RW                   ; Access
        db GRAN_4K | SZ_32 | 0xF                    ; Flags & Limit (high, bits 16-19)
        db 0                                        ; Base (high, bits 24-31)
.TSS: equ $ - gdt64
        dd 0x00000068
        dd 0x00CF8900
.pointer:
        dw $ - gdt64 - 1
        dq gdt64


extern isr_handler
section .text

bits 64
[global defaultInterruptHandler]
defaultInterruptHandler:
    IRETQ

[GLOBAL defaultExceptionHandler]
defaultExceptionHandler:
    call isr_handler 
    hlt
    jmp $

%macro ISR_NOERRCODE 1
[GLOBAL isr%1]
isr%1:
    cli
    push byte 0
    push byte %1
    jmp isr_common_stub
%endmacro
%macro ISR_ERRCODE 1
[GLOBAL isr%1]
isr%1:
    cli
    push byte %1
    jmp isr_common_stub
%endmacro
ISR_NOERRCODE 0
ISR_NOERRCODE 1
ISR_NOERRCODE 2
ISR_NOERRCODE 3
ISR_NOERRCODE 4
ISR_NOERRCODE 5
ISR_NOERRCODE 6
ISR_NOERRCODE 7
ISR_NOERRCODE 9
ISR_NOERRCODE 15
ISR_NOERRCODE 16
ISR_NOERRCODE 17
ISR_NOERRCODE 18
ISR_NOERRCODE 19
ISR_NOERRCODE 20
ISR_NOERRCODE 21
ISR_NOERRCODE 22
ISR_NOERRCODE 23
ISR_NOERRCODE 24
ISR_NOERRCODE 25
ISR_NOERRCODE 26
ISR_NOERRCODE 27
ISR_NOERRCODE 28
ISR_NOERRCODE 29
ISR_NOERRCODE 30
ISR_NOERRCODE 31
ISR_ERRCODE 8
ISR_ERRCODE 10
ISR_ERRCODE 11
ISR_ERRCODE 12
ISR_ERRCODE 13
ISR_ERRCODE 14

[GLOBAL exceptionHandlers]
exceptionHandlers:
    dq isr0
    dq isr1
    dq isr2
    dq isr3
    dq isr4
    dq isr5
    dq isr6
    dq isr7
    dq isr8
    dq isr9
    dq isr10
    dq isr11
    dq isr12
    dq isr13
    dq isr14
    dq isr15
    dq isr16
    dq isr17
    dq isr18
    dq isr19
    dq isr20
    dq isr21
    dq isr22
    dq isr23
    dq isr24
    dq isr25
    dq isr26
    dq isr27
    dq isr28
    dq isr29
    dq isr30
    dq isr31

isr_common_stub:
    ;pusha

    push rdx
    push rcx
    push rbx
    push rax
    push rdi
    push rsi
    push rbp

    mov rax, cr4
    mov rax, cr3
    mov rax, cr2
    mov rax, cr0

    call isr_handler
    ;pop eax
    pop rax; cr4
    pop rax; cr3
    pop rax; cr2
    pop rax; cr0
    ;popa
    pop rbp
    pop rsi
    pop rdi
    pop rax
    pop rbx
    pop rcx
    pop rbx
    
    add rsp, 16
    sti
    IRETQ
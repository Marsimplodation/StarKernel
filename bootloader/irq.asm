extern irqHanlder

%macro IRQ 2
[GLOBAL IRQ%1]
IRQ%1:
    cli
    push byte 0
    push byte %2
    jmp irq_common_stub
%endmacro

IRQ 0, 32
IRQ 1, 33
IRQ 2, 34
IRQ 3, 35
IRQ 4, 36
IRQ 5, 37
IRQ 6, 38
IRQ 7, 39
IRQ 8, 40
IRQ 9, 41
IRQ 10, 42
IRQ 11, 43
IRQ 12, 44
IRQ 13, 45
IRQ 14, 46
IRQ 15, 47

[GLOBAL irqHanlders]
irqHanlders:
    dq IRQ0
    dq IRQ1
    dq IRQ2
    dq IRQ3
    dq IRQ4
    dq IRQ5
    dq IRQ6
    dq IRQ7
    dq IRQ8
    dq IRQ9
    dq IRQ10
    dq IRQ11
    dq IRQ12
    dq IRQ13
    dq IRQ14
    dq IRQ15

extern irq_handler
irq_common_stub:
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

    call irq_handler
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
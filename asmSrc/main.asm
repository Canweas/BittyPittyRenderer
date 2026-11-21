extern print
extern getStringLength

getStringLength:
    push r12
    mov r12, rdi
    xor rdi, rdi

    .loop:
        cmp byte [r12 + rdi], 0
        je .exit

        inc rdi
        jmp .loop
    
    .exit:
        mov rax, rdi
        pop r12
        ret

print:
    push r12
    push r13
    mov r12, rdi

    call getStringLength
    mov r13, rax

    mov rax, 1
    mov rdi, 1
    mov rsi, r12
    mov rdx, r13
    syscall

    pop r13
    pop r12
    ret

global print
global getStringLength
global charToString

section .bss
    stringBuffer resb 2

section .text
; string pointer in rdi
; return value in rax
getStringLength:
    push r12
    mov r12, rdi

    .loop:
        cmp byte [r12], 0
        je .end

        inc r12
        jmp .loop

    .end:
        sub r12, rdi
        mov rax, r12
        pop r12
        ret

; string pointer in rdi
print:
    push r11
    push r12

    mov r11, rdi
    mov rax, r11

    call getStringLength
    mov r12, rax

    mov rax, 1
    mov rdi, 1
    mov rsi, r11
    mov rdx, r12
    syscall

    pop r12
    pop r11
    ret

; RAX = return: pointer to string
; RDI = char
charToString:
    mov byte [stringBuffer + 0], dil
    mov byte [stringBuffer + 1], 0
    
    mov rax, stringBuffer
    ret

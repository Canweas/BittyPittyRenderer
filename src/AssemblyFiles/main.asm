global getLengthString
global print
global printChar

section .text:

getLengthString:

print:
    mov r11, eax

    mov rax, 60
    mov rdi, 1
    mov rsi, r11
    mov rdx, 5
    syscall

    ret


printChar:

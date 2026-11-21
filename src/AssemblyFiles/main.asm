global getLengthString
global print
global printChar

section .text:

getLengthString:
    ret

print:
    mov r11, rax

    mov rax, 1
    mov rdi, 1
    mov rsi, r11
    mov rdx, 5
    syscall

    ret

printChar:
    ret

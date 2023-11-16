; This solution is NOT mine

section .data
    ; Define a null-terminated string
    message db "Hello, Holberton", 0xa, 0

    ; Define a format specifier string
    format db "%s", 0

section .text
    ; Declare an external function printf
    extern printf
    global main

main:
    ; Set up the stack frame
    push rbp

    ; Set the first argument (format specifier) for printf
    mov rdi, format

    ; Set the second argument (address of the string) for printf
    mov rsi, message

    ; Call the printf function
    call printf

    ; Restore the stack frame
    pop rbp

    ; Return from the main function
    ret

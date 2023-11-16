; This solution is not mine

section .data
    ; Define a string with newline and null-terminated character
    message db "Hello, Holberton", 0xa, 0

section .text
    ; Declare an external function printf
    extern printf
    global main

main:
    ; Add the message to the registry (edi)
    mov edi, message
    mov eax, 0

    ; Call the printf function
    call printf

%include "asm_io.inc"

SECTION .data
prompt : db "Entrez un nombre : ", 0
bit_0 : db "0", 0
bit_1 : db "1", 0

SECTION .bss
nombre : resd 1

SECTION .text
global main
main : 
    mov eax, prompt
    call print_string
    call read_int
    mov [nombre], eax

    mov ecx, 32
    mov eax, [nombre]

    aff_bit:
        shl eax, 1
        jc print1
        mov ebx, bit_0
        call print_string
        jmp suite

    print1:
        mov ebx, bit_1
        call print_string

    suite:
        loop aff_bit

    call print_nl
    mov ebx, 0
    mov eax, 1
    int 0x80



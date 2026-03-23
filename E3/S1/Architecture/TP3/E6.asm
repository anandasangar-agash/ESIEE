%include "asm_io.inc"

SECTION .data
prompt : db "Entrez un nombre", 0

SECTION .bss
input : resd 1

SECTION .text
global main
main : 
    mov eax, prompt
    call print_string
    read_int
    mov [input], eax
    mov ebx, 0
    while :
        cmp [input], ebx
        je end_while
        mov edx, 0
        mov eax, [input]
        div ebx
        cmp edx, 0
        je else 
        add ebx, 1
        jmp while

        else : 
            mov eax, ebx
            call print_int
            add ebx, 1
            jmp while
    end_while
    call print_nl
    mov ebx, 0
    mov eax, 1
    int 0x80 
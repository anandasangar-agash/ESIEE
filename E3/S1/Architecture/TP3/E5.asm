%include "asm_io.inc"

SECTION .data
prompt1 : db "Entrez un nombre : ", 0
prompt2 : db "Un autre : ", 0
oui : "Oui", 0 
non : "Non", 0 
outmsg : "Le reste vaut : ", 0 

SECTION .bss
input1 : resd 1
input2 : resd 2

SECTION .text
global main
main : 
    mov eax, prompt1
    call print_string
    call read_int
    mov [input1], eax
    mov eax, prompt2
    call print_string
    call read_int
    mov [input2], eax
    mov edx, 0
    mov eax, [input1]
    mov ebx, [input2]
    cdq
    idiv ebx
    cmp edx, 0
    jne else
    mov eax, oui
    call print_string
    jmp fin

    else : 
        mov eax, non
        call print_string
        mov eax, outmsg
        call print_string
        mov eax, edx
        call print_int

    fin :
        call print_nl
        mov ebx, 0
        mov eax, 1
        int 0x80
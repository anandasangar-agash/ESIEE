%include "asm_io.inc"

SECTION .data
prompt1 : db "Entrer un nombre : ", 0
prompt2 : db "Un autre nombre : ", 0
outmsg1 : db "La valeur la plus grande est ", 0

SECTION .bss
input1 : resd 1
input2 : resd 1

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
    mov eax, [input1]
    cmp eax, [input2]
    jl else
    mov ebx, eax
    mov eax, outmsg1
    call print_string
    mov eax, ebx
    call print_int
    else : 
        mov ebx, [input2]
        mov eax, outmsg1
        call print_string
        mov eax, ebx
        call print_int
    call print_nl
    mov ebx, 0
    mov eax, 1
    int 0x80

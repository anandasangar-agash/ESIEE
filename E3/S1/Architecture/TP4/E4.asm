%include "asm_io.inc"

SECTION .data
prompt : db "Entrez un nombre (-1 pour quitter) : ", 0

SECTION .bss

SECTION .text
global main 
main : 
    mov eax, prompt
    call print_string
    mov ebp, esp
    boucle :
        call read_int
        cmp eax, -1
        je aff_suite
        push eax
        jmp boucle

    aff_suite : 
        pop eax
        call print_int
        cmp esp, ebp
        je fin
        jmp aff_suite
    
    fin : 
        call print_nl
        mov ebx, 0
        mov eax, 1
        int 0x80

; Auteurs : ---
; Date de creation : ---
; Objectif : ---

%include "asm_io.inc"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;; Section de donnees ;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SECTION .data
prompt1 : db "Entrer un nombre : ", 0
prompt2 : db "Un autre nombre : ", 0
outmsg1 : db "Oui" , 0
outmsg2 : db "Non ", 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;; Section de reservation ;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SECTION .bss
input1 : resd 1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;; Section de code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SECTION .text
global main
main:
    mov edx, 0
    mov eax, prompt1
    call print_string
    call read_int
    mov [input1], eax
    mov eax, prompt2
    call print_string
    call read_int
    mov ebx, [input1]
    div ebx
    cmp edx, 0
    jne else
        mov eax, outmsg1
        call print_string
        call print_nl
        jmp end_if
    else:
        mov eax, outmsg2
        call print_string
        mov eax, edx
        call print_int
        call print_nl
    end_if:
    mov ebx, 0
    mov eax, 1
    int 0x80




%include "asm_io.inc"

SECTION .data
prompt      db "Entrez les entiers entre 0 et 50 (-1 pour terminer) : ",0
msg_result  db "Entiers manquants : ",0

SECTION .text
global main
main:
    xor ebx, ebx       ; bitmap pour 0..31
    xor ecx, ecx       ; bitmap pour 32..50

    ; afficher prompt
    mov eax, prompt
    call print_string

lecture:
    call read_int
    cmp eax, -1
    je fin_lecture
    cmp eax, 0
    jl lecture
    cmp eax, 50
    jg lecture

    cmp eax, 31
    jle moins32
    ; nombre 32..50
    sub eax, 32
    mov edx, 1
    shl edx, eax
    or ecx, edx
    jmp lecture

moins32:
    ; nombre 0..31
    mov edx, 1
    shl edx, eax
    or ebx, edx
    jmp lecture

fin_lecture:
    ; afficher message
    mov eax, msg_result
    call print_string

    ; afficher nombres manquants 0..50
    mov esi, 0         ; index pour parcourir les nombres

affichage:
    cmp esi, 51
    je fin_programme

    cmp esi, 32
    jl inf32

    ; nombres 32..50
    mov edx, esi
    sub edx, 32
    mov eax, 1
    shl eax, edx
    test ecx, eax
    jnz skip_display
    jmp afficher_num

inf32:
    ; nombres 0..31
    mov eax, 1
    shl eax, esi
    test ebx, eax
    jnz skip_display

afficher_num:
    mov eax, esi
    call print_int
    mov al, ' '
    call print_char

skip_display:
    inc esi
    jmp affichage

fin_programme:
    call print_nl
    mov eax, 1
    mov ebx, 0
    int 0x80

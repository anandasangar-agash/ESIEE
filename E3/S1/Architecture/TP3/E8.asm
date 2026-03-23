%include "asm_io.inc"

SECTION .data
prompt      db "Entrez un entier : ",0
msg_result  db "Nombre de bits à 1 : ",0

SECTION .bss
n           resd 1
compte1     resd 1

SECTION .text
global main
main:
    mov eax, prompt
    call print_string
    call read_int
    mov [n], eax

    mov dword [compte1], 0   ; compteur à 0
    mov ecx, 32              ; 32 bits à tester
    mov eax, [n]             ; EAX = nombre

boucle:
    shr eax, 1               ; Décale à droite : bit faible va dans CF
    jnc suivant              ; CF=0 -> pas de 1, on saute

    inc dword [compte1]      ; Si CF=1, on incrémente compte1

suivant:
    loop boucle              ; ECX--, continue tant que ECX>0

    mov eax, msg_result
    call print_string
    mov eax, [compte1]
    call print_int
    call print_nl

    mov ebx, 0
    mov eax, 1
    int 0x80

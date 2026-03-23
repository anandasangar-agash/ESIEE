SECTION .data
prompt      db "Entrez un entier : ",0
msg_result  db "Nombre de bits à 1 : ",0

SECTION .bss
n           resd 1

SECTION .text
global main
main:
    mov eax, prompt
    call print_string
    call read_int
    mov [n], eax

    mov edx, 0   ; compteur à 0
    mov eax, [n]

boucle:
    cmp eax, 0
    je fin                   ; Si eax = 0, on termine

    add edx, 1      ; incrémente le compteur
    mov ebx, eax
    sub ebx, 1                  ; ebx = eax - 1 (on peut aussi faire dec ebx)
    and eax, ebx             ; eax = eax & (eax - 1)
    jmp boucle

fin:
    mov eax, msg_result
    call print_string
    mov eax, edx
    call print_int
    call print_nl

    mov ebx, 0
    mov eax, 1
    int 0x80

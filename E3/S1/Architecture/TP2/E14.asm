
SECTION .data 
debut:
    db "Le deuxieme TP"

fin:
    db "est presque termine !"

SECTION .text
global main
main:
    mov edx, 14
    mov ecx, debut

    mov ebx, 1
    mov eax, 4
    int 0x80

    mov edx, 21
    mov ecx, fin
    mov ebx, 1
    mov eax, 4
    int 0x80

    mov ebx, 0
    mov eax, 1
    int 0x80
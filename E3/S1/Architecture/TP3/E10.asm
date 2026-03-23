%include "asm_io.inc"

SECTION .data
prompt      db "Entrez les entiers entre 0 et 50 (-1 pour terminer) : ",0
msg_result  db "Entiers manquants : ",0

SECTION .bss
tableau     resb 51      ; 0 à 50 => 51 octets
n           resd 1       ; pour stocker l'entier lu

SECTION .text
global main
main:
    ; Afficher le prompt
    mov eax, prompt
    call print_string

lecture:
    call read_int
    mov [n], eax

    cmp eax, -1        ; -1 → fin de la lecture
    je fin_lecture

    cmp eax, 0
    jl lecture         ; nombre < 0 → ignorer

    cmp eax, 50
    jg lecture         ; nombre > 50 → ignorer

    mov bl, 1
    mov [tableau + eax], bl   ; marque le nombre comme présent
    jmp lecture

fin_lecture:
    ; Affichage du résultat
    mov eax, msg_result
    call print_string

    mov ecx, 0          ; compteur pour parcourir le tableau

affichage:
    cmp ecx, 51
    je fin_programme

    mov al, [tableau + ecx]
    cmp al, 0
    jne skip_display    ; si le nombre est marqué → passer

    mov eax, ecx
    call print_int

skip_display:
    inc ecx
    jmp affichage

fin_programme:
    call print_nl

    mov eax, 1          ; exit syscall
    mov ebx, 0
    int 0x80

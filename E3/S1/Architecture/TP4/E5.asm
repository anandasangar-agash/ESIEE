%include "asm_io.inc"

SECTION .data
prompt  : db "Entrez un nombre (-1 pour quitter) : ", 0

SECTION .bss
array   resd 100       ; tableau pour 100 entiers max
count   resd 1         ; nombre d'éléments saisis

SECTION .text
global main
main:
    mov dword [count], 0        ; initialiser le compteur à 0

lecture:
    mov eax, prompt
    call print_string
    call read_int

    cmp eax, -1
    je tri                        ; si -1, passer au tri

    mov ebx, [count]              ; récupérer le compteur
    mov [array + ebx*4], eax      ; stocker l'entier dans le tableau
    inc dword [count]             ; incrémenter le compteur
    jmp lecture

; ------------------------
; Tri à bulles
tri:
    mov ecx, [count]              ; nombre d'éléments
    dec ecx                        ; ecx = n-1
    cmp ecx, 0
    jle affiche                    ; si 0 ou 1 élément, rien à trier

bubble_outer:
    push ecx                       ; sauvegarder n-1
    mov ecx, [count]
    dec ecx                        ; boucle intérieure : j = 0 .. n-2
    xor esi, esi                   ; esi = 0 -> index dans le tableau

bubble_inner:
    mov eax, [array + esi*4]
    mov ebx, [array + esi*4 + 4]
    cmp eax, ebx
    jle no_swap
    ; échanger
    mov [array + esi*4], ebx
    mov [array + esi*4 + 4], eax
no_swap:
    inc esi
    loop bubble_inner               ; on tourne tant que ecx != 0

    pop ecx                        ; restaurer n-1
    dec ecx
    jg bubble_outer                 ; on tourne tant que ecx > 0

; ------------------------
; Affichage du tableau trié
affiche:
    mov ecx, 0

print_loop:
    cmp ecx, [count]
    jge fin

    mov eax, [array + ecx*4]
    call print_int
    call print_nl

    inc ecx
    jmp print_loop

fin:
    mov eax, 1
    mov ebx, 0
    int 0x80

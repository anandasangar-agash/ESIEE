global occurrence
extern read_int

; int occurrence();
; Lit une suite d'entiers 32 bits terminée par -1
; Puis lit a (32 bits)
; Retourne dans eax le nombre d'occurrences de a.

occurrence:
    push ebp
    mov  ebp, esp

    ; ----------------------------------------------
    ; allouer un tableau local de 1000 entiers (4000 octets)
    ; ----------------------------------------------
    sub esp, 4000         ; tab[i] = (esp + 4*i)

    xor esi, esi          ; compteur d'éléments lus = 0

read_loop:
    call read_int         ; eax = entier lu

    cmp eax, -1
    je read_a

    ; vérifier si on a encore de la place
    cmp esi, 1000
    jge read_loop         ; ignore si trop d'éléments

    ; stocker l'entier dans tab[esi]
    mov edi, esp        ; tab[0]
    mov ebx, esi        ; ebx = index
    shl ebx, 2         ; ebx = index * 4
    add edi, ebx        
    mov [edi], eax      ; tab[edi] = eax

    inc esi               ; nombre d'éléments++
    jmp read_loop

; ----------------------------------------------
; lire a et le comparer à tous les éléments
; ----------------------------------------------
read_a:
    call read_int         ; eax = a
    mov ebx, eax          ; ebx = a
    xor eax, eax          ; eax = compteur = 0

    mov ecx, esi          ; nombre d'éléments lus
    mov edi, esp          ; adresse du tableau

count_loop:
    cmp ecx, 0
    je end_occ

    ; comparer tab[i] avec a
    mov edx, [edi]
    cmp edx, ebx
    jne skip
    inc eax               ; compteur++

skip:
    add edi, 4            ; avancer dans tab
    dec ecx
    jmp count_loop

end_occ:
    add esp, 4000
    pop ebp
    ret

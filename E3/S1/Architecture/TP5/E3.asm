global occurrence
extern read_int

; int occurrence();
; Lit une suite d'entiers 0..100 terminée par -1
; puis lit un entier a (0..100)
; Retour : nombre d'occurrences de a

occurrence:
    push ebp
    mov ebp, esp

    ; -------------------------------------------------
    ; réserver un tableau de 101 dwords = 404 octets
    ; -------------------------------------------------
    sub esp, 404           ; tab[0] = esp

    ; -------------------------------------------------
    ; initialiser le tableau à 0
    ; -------------------------------------------------
    mov edi, esp           ; pointeur sur tab[0]
    mov ecx, 101
init_loop:
    mov dword [edi], 0
    add edi, 4
    loop init_loop

    ; -------------------------------------------------
    ; lecture de la suite
    ; -------------------------------------------------
read_values:
    call read_int          ; eax = entier lu

    cmp eax, -1
    je read_a              ; fin de la suite → lire a

    cmp eax, 0
    jl read_values
    cmp eax, 100
    jg read_values

    ; tab[eax]++
    shl eax, 2             ; eax = index * 4
    mov edi, esp           ; edi = adresse tab[0]
    add edi, eax           ; edi = &tab[index]

    inc dword [edi]        ; tab[index]++

    jmp read_values

    ; -------------------------------------------------
    ; lire a
    ; -------------------------------------------------
read_a:
    call read_int          ; eax = a

    cmp eax, 0
    jl invalid_a
    cmp eax, 100
    jg invalid_a

    ; retourner tab[a]
    shl eax, 2
    mov edi, esp         
    add edi, eax           ; edi = &tab[a]

    mov eax, [edi]         ; eax = occurrence[a]
    jmp end_occurrence

invalid_a:
    mov eax, 0

end_occurrence:
    add esp, 404           ; libération du tableau
    pop ebp
    ret

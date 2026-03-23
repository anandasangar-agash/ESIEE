compte_char:
    push ebp                 ; prologue
    mov ebp, esp
                 


    mov ecx, [esp+8]         ; récupère s
    mov edx,  [esp+12]        ; récupère c

    xor eax, eax             ; compteur = 0
    mov eax, [edx]
loop:
    cmp byte [ecx], 0                ; si fin chaîne
    je fin
    
    cmp byte [ecx], eax              ; si différent
    jnz .skip

    inc eax                  ; compteur++

.skip:
    inc esi
    jmp .loop

fin:
    pop ebp
    ret
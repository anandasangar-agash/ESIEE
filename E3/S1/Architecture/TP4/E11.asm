global longueur

; int longueur(char *str)
; Retourne la longueur de la chaîne (nombre de caractères avant le 0)
longueur:
    push ebp
    mov ebp, esp        ; Prologue standard

    ; Récupérer l'adresse de la chaîne
    mov esi, [ebp + 8]  ; argument str
                         ; [ebp+8] = premier argument sur la pile

    xor eax, eax        ; compteur de longueur = 0

longueur_loop:
    cmp byte [esi + eax], 0  ; comparer le caractère courant à 0
    je longueur_done
    inc eax                  ; incrémenter compteur
    jmp longueur_loop

longueur_done:
    pop ebp
    ret
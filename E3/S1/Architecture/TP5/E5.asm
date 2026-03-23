global longueur

; int longueur(char *str)
; Renvoie la longueur d'une chaîne terminée par 0 dans eax

longueur:
    push ebp
    mov  ebp, esp

    ; récupérer l'argument : str = [ebp+8]
    mov eax, [ebp + 8]

    ; vérifier si la chaîne est vide
    cmp byte [eax], 0
    je base_case

    ; passer au caractère suivant
    inc eax              ; eax = str + 1
    push eax             ; passer str+1 en argument
    call longueur
    add esp, 4           ; nettoyer la pile après l'appel

    ; ajouter 1 au résultat retourné
    inc eax
    jmp end

base_case:
    mov eax, 0           ; longueur = 0

end:
    pop ebp
    ret

; Question 4
; Pas encore répondu
; Noté sur 1,00
; Marquer la question
; Texte de la question

; Écrire une fonction longueur respectant les
; conventions d'appel du C, qui respecte les conventions d'appel du C et qui prend en argument l'adresse
; d'une chaîne de caractères terminée par un octet  
; et calcule sa
; longueur. Le résultat sera renvoyé dans eax.

longueur:
    push ebp
    mov ebp, esp
    
    ; get arg1
    mov ecx, dword [ebp + 8]
    ; ecx now contains the address of the string
    
    mov eax, 0 ; char counter
    .loop:
        cmp byte [ecx], 0
        je .endloop
        inc eax ; increase counter
        inc ecx ; increase address by 1
        jmp .loop
    
    .endloop:
        ; end
    
    pop ebp
    ret
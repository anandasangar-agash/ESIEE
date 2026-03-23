; Question 5
; Pas encore répondu
; Noté sur 1,00
; Marquer la question
; Texte de la question
; 
; Réaliser une fonction fibonacci qui respecte les conventions d'appel du C et qui calcule de manière récursive le nieme élément Fn de la suite de Fibonacci.
; 
; Cette suite est définie par F0:=0, F1:=1 et pour n⩾2, Fn:=Fn−1+Fn−2. Le résultat sera renvoyé dans le registre eax.
; 
; La fonction sera appelé dans un programme qui lit un entier positif n au clavier et affiche la valeur Fn.

fibonacci:
    push ebp
    mov ebp, esp
    
    ; goal value in [ebp + 8]
    
    ; Check case 0
    cmp dword [ebp + 8], 0 ; compare with goal n
    je .case0
    
    ; Check case 1
    cmp dword [ebp + 8], 1 ; compare with goal n
    je .case1
    
    ; Handle calculation for F(n-1)
    ; Get goal n
    mov edx, [ebp + 8]
    sub edx, 1
    push edx
    call fibonacci
    ; result in eax. All other registries have been trashed.
    add esp, 4 ; Remove param1
    push eax ; push F(n-1)
    
    ; Handle calculation for F(n-2)
    ; Get goal n
    mov edx, [ebp + 8]
    sub edx, 2
    push edx
    call fibonacci
    ; result in eax. All other registries have been trashed.
    add esp, 4 ; Remove param1
    
    ; eax is F(n+2). Let's add F(n+1)
    pop edx
    add eax, edx
    
    jmp .end
    
    .case0:
        mov eax, 0
        jmp .end
    
    .case1:
        mov eax, 1
        jmp .end
    
    .end:
        ; end prog
    
    pop ebp
    ret
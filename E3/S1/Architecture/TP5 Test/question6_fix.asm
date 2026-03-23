; Question 6
; Pas encore répondu
; Noté sur 1,00
; Marquer la question
; Texte de la question
; Modifier la fonction et le programme précédent de telle sorte que la fonction prenne deux arguments entiers supplémentaires a
; et b et qui renvoie le n-ième élément   F(a,b) indice n  de la suite définie par  F(a,b) indice 0 = 0 ,  F(a,b) indice 1 = 1   et pour n >= 2 ,   F(a,b) indice n = a * (F(a,b) indice n-1) + b *(F(a,b) indice n-2)
; La nouvelle fonction doit s'appeler suiterecursive.

; Check question6_consigne.png pour la consigne correcte

; Trois arguments: n, a, b
suiterecursive:
    push ebp
    mov ebp, esp
    
    ; goal value in [ebp + 8]
    ; a in [ebp + 12]
    ; b in [ebp + 16]
    
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
    push dword [ebp + 16]; push param3
    push dword [ebp + 12]; push param2
    push edx ; push param1
    call suiterecursive
    ; result in eax. All other registries have been trashed.
    add esp, 12 ; Remove 3 params
    mul dword [ebp + 12]; mult F(n-1) by a
    push eax ; push F(n-1)
    
    ; Handle calculation for F(n-2)
    ; Get goal n
    mov edx, [ebp + 8]
    sub edx, 2
    push dword [ebp + 16]; push param3
    push dword [ebp + 12]; push param2
    push edx ; push param1
    call suiterecursive
    ; result in eax. All other registries have been trashed.
    add esp, 12 ; Remove 3 params
    mul dword [ebp + 16]; mult F(n-2) by b
    
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
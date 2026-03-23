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

; ME SUIS TROMPE C'EST PAS RECURSIF. Check question5_fix.asm

fibonacci:
    push ebp
    mov ebp, esp
    
    ; goal value in [ebp + 8]
    push 1 ; current n value [ebp - 4]
    mov eax, 1 ; fibonacci output (n-1 or n depending on the moment)
    mov ecx, 0 ; fibonacci n-2
    mov edx, 0 ; temp
    
    ; Check case 0
    cmp dword [ebp + 8], 0 ; compare with goal n
    je .case0
    
    ; Check case 1
    cmp dword [ebp + 8], 1 ; compare with goal n
    je .case1
    
    .loop:
        ; compare current n with goal
        mov edx, [ebp - 4]  ; move current n
        cmp edx, [ebp + 8] ; compare with goal n
        je .endloop
        
        mov edx, eax ; backup n-1 to edx (will be n-2 in the next run)
        add eax, ecx ; n = n-1 + n-2 (n-1 in eax is written over) (will be n-1 in the next run)
        mov ecx, edx ; backup n-1 to ecx (will be n-2 in the next run)
        inc dword [ebp - 4] ; increase current n
        jmp .loop
    
    .case0:
        mov eax, 0
        jmp .endloop
    
    .case1:
        mov eax, 1
        jmp .endloop
    
    .endloop:
        ; end prog
        mov esp, ebp ; remove added elements to stack
    
    pop ebp
    ret
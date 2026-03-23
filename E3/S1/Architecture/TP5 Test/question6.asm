; Question 6
; Pas encore répondu
; Noté sur 1,00
; Marquer la question
; Texte de la question
; Modifier la fonction et le programme précédent de telle sorte que la fonction prenne deux arguments entiers supplémentaires a
; et b et qui renvoie le n-ième élément   F(a,b) indice n  de la suite définie par  F(a,b) indice 0 = 0 ,  F(a,b) indice 1 = 1   et pour n >= 2 ,   F(a,b) indice n = a * (F(a,b) indice n-1) + b *(F(a,b) indice n-2)
; La nouvelle fonction doit s'appeler suiterecursive.

; Check question6_consigne.png pour la consigne correcte

; ME SUIS TROMPE C'EST PAS RECURSIF. Check question6_fix.asm

; Trois arguments: n, a, b
suiterecursive:
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
        
        push eax ;  backup n-1 to stack (will be n-2 in the next run)
        
        ; calculate b * F(n-2)
        mov eax, [ebp + 16] ; get b
        mul ecx ; eax*ecx, output in eax. ecx is n-2
        mov ecx, eax ; put b + (n-2) to ecx temporarily
        
        ; calculate a * F(n-1)
        mov eax, [ebp + 12] ; get a
        pop edx ; retrieve n-1 to edx (will be n-2 in the next run)
        push edx ; repush it. don't want to bother with memory offsets
        mul edx ; eax*edx, output in eax. Clears edx.
        
        ; add both
        add eax, ecx ; n = a*(n-1) + b*(n-2) (n-1 in eax is written over)
        
        pop ecx; retrieve n-1 to ecx (will be n-2 in the next run)
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

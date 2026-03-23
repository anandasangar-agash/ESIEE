; Question 2
; Pas encore répondu
; Noté sur 1,00
; Marquer la question
; Texte de la question

; Écrire une fonction occurrence respectant les conventions d'appel du C, et qui lit au clavier :

; -   une suite d'entiers compris entre 0 et 100, terminée par un −1
; -   puis un entier a compris entre 0 et 100.

; La fonction doit renvoyer dans eax le nombre d'occurrences de a dans la suite. Pour mémoriser le nombre d'occurrences de chaque nombre entre 0 et 100, il faut utiliser dans cet exercice un tableau de 101 dword enregistré dans la pile.


occurrence:
    push ebp
    mov ebp, esp
    
    ; push 101x 0 in stack (0 to 100), to count the occurrences of all the numbers
    mov eax, 101
    .loop:
        push dword 0
        dec eax ; decrement eax
        cmp eax, 0
        jg .loop
    
    .loop2:
        call read_int
        ; int in eax
        
        ; Check if -1
        cmp eax, -1
        je .endloop2
        
        ; Check if within bounds (fail if under 0)
        cmp eax, 0
        jl .loop2
        ; Check if within bounds (fail if above 100)
        cmp eax, 100
        jg .loop2
        
        
        ; occ in stack will be [ebp - ((num + 1) * 4)]
        add eax, 1
        mov edx, 4
        mul edx ; mult eax by edx
        mov edx, -1
        mul edx
        add eax, ebp
        inc dword [eax] ; increment occ in stack by 1
        jmp .loop2
    
    .endloop2:
        ; Retrieve a
        call read_int
        
        ; Check if within bounds (fail if under 0)
        cmp eax, 0
        jl .endloop2
        ; Check if within bounds (fail if above 100)
        cmp eax, 100
        jg .endloop2
        
        ; occ in stack will be [ebp - ((num + 1) * 4)]
        add eax, 1
        mov edx, 4
        mul edx ; mult eax by edx, result in eax
        mov edx, -1
        mul edx
        add eax, ebp
        ; retrieve occ count
        mov eax, dword [eax]
        
    ; No need to pop the values, we'll just edit esp
    mov esp, ebp
    
    pop ebp
    ret
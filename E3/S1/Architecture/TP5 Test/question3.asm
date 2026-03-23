; Question 3
; Pas encore répondu
; Noté sur 1,00

; Texte de la question
; Modifier la fonction et le programme précédent afin que
; la fonction occurrence puisse accepter une suite d'entiers non bornés
; (mais bien entendu bornés par la limite de ce qui est représentable sur 32
; bits et raisonnable par rapport à la taille de la pile).

occurrence:
    push ebp
    mov ebp, esp
    
    ; push the numbers in stack individually to allow any number to be entered
    .loop1:
        call read_int
        ; int in eax
        
        ; Check if -1
        cmp eax, -1
        je .endloop1
        
        ; push the numbers in stack individually to allow any number to be entered
        push eax
        ; each num in stack will be [ebp - (amt * 4)]
        jmp .loop1
    
    .endloop1:
        ; Retrieve a
        call read_int
    
    mov ecx, ebp ; store stack address in ecx
    mov edx, 0 ; store occ match amount in edx
        
    .loop2:
        ; loop through nums in stack
        sub ecx, 4
        cmp ecx, esp
        jl .endloop2 ; exit if all stored nums have been iterated through
        
        cmp eax, [ecx]
        je .loop2increment
        jmp .loop2
    
    .loop2increment:
        inc edx ; increment edx
        jmp .loop2
    
    .endloop2:
        ; Program end..
        mov eax, edx ; Put edx in eax
        
    ; No need to pop the values, we'll just edit esp
    mov esp, ebp
    
    pop ebp
    ret
global fibonacci

; int fibonacci(int n)
; Argument : [ebp+8]
; Résultat : eax
fibonacci:
    push ebp
    mov ebp, esp

    mov eax, [ebp + 8]    ; récupérer n

    cmp eax, 0
    je fib_base0           ; si n == 0, return 0

    cmp eax, 1
    je fib_base1           ; si n == 1, return 1

    ; Cas récursif : n >= 2
    ; Calculer fibonacci(n-1)
    mov edx, eax
    dec edx     ; edx = edx - 1 
    push edx
    call fibonacci
    add esp, 4
    push eax        ; sauvegarder fibonacci(n-1) dans ecx

    ; Calculer fibonacci(n-2)
    mov edx, [ebp+8]
    sub edx, 2
    push edx
    call fibonacci
    add esp, 4

    ; eax = fibonacci(n-2) + fibonacci(n-1)
    pop edx
    add eax, edx
    jmp fib_end

fib_base0:
    mov eax, 0
    jmp fib_end

fib_base1:
    mov eax, 1

fib_end:
    pop ebp
    ret

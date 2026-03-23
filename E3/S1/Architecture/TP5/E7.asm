global suiterecursive

suiterecursive:
    push ebp
    mov ebp, esp

    mov eax, [ebp+8]

    cmp eax, 0
    je fib_base0

    cmp eax, 1
    je fib_base1

    mov edx, eax
    dec edx
    push dword [ebp + 16]
    push dword [ebp + 12]
    push edx 
    call suiterecursive
    add esp, 12
    mul dword [ebp + 12]
    push eax

    mov edx, [ebp + 8]
    sub edx, 2
    push dword [ebp + 16]
    push dword [ebp + 12]
    push edx
    call suiterecursive
    add esp, 12
    mul dword [ebp + 16]

    pop edx
    add eax, edx
    jmp end

fib_base0:
    mov eax, 0
    jmp end

fib_base1:
    mov eax, 1
    jmp end

end:
    pop ebp
    ret
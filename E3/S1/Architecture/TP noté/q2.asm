section .text

global addition
addition:
    push ebp
    mov ebp, esp
    
    push ebx

    mov eax, 0
    mov ebx, 0
    mov ecx, [ebp + 8]
    mov edx, [ebp + 12]
    
boucle:
    cmp ebx, ecx
    je end_boucle
    add eax, [edx + 4*ebx]
    inc ebx
    jmp boucle
    
end_boucle:
    pop ebx
    pop ebp
    ret
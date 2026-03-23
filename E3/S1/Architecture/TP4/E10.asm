
global print_string2
print_string2:

    push ebp
    mov ebp, esp

    push eax
    push ebx
    push ecx
    push edx

    mov ebx, 1          ; fd = stdout
    mov ecx, [ebp + 8]  ; adresse de la chaîne (argument)

    ; calculer longueur
    xor edx, edx        ; edx = 0
strlen_loop:
    cmp byte [ecx + edx], 0     ; quand on arrive à 0 on quitte la boucle 
    je strlen_done
    inc edx
    jmp strlen_loop
strlen_done:

    mov eax, 4          ; syscall write
    int 0x80

    pop edx
    pop ecx
    pop ebx
    pop eax

    pop ebp
    ret


global print_string2
extern longueur     ; fonction définie ailleurs

print_string2:
    push ebp
    mov ebp, esp

    push eax
    push ebx
    push ecx
    push edx

    mov ebx, 1            ; fd = stdout
    mov ecx, [ebp + 8]    ; adresse de la chaîne

    ; ------------------------
    ; appel de longueur(str)
    ; ------------------------
    push ecx              ; argument de longueur
    call longueur         ; eax = longueur de la chaîne
    add esp, 4            ; nettoyer la pile après l'appel
    mov edx, eax          ; edx = longueur pour write

    mov eax, 4            ; syscall write
    int 0x80

    pop edx
    pop ecx
    pop ebx
    pop eax

    pop ebp
    ret

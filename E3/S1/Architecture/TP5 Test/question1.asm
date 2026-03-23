; TP 5 - Convention d'appel du C x86 (cdecl)

; Écrire une fonction difference respectant les conventions d'appel du C, prenant deux nombres a  et b  en argument et renvoyant leur différence a - b  dans eax. 

difference:
    push ebp
    mov ebp, esp
    
    mov eax, [ebp + 8]
    push ebx
    mov ebx, [ebp + 12]
    sub eax, ebx
    
    pop ebx
    pop ebp
    ret
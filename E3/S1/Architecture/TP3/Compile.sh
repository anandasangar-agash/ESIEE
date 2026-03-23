#!/bin/sh -e
[ -f asm_io.asm ] && [ -f "$1.asm" ]
echo "Compilation de $1.asm en $1.o"
nasm -f elf32 "$1.asm"
if ! [ -f asm_io.o ]; then
	echo "Compilation de asm_io.asm en asm_io.o"
	nasm -f elf32 asm_io.asm
fi
echo "Edition de lien: $1.o + asm_io.o -> $1"
ld -o "$1" -melf_i386 -e main "$1.o" asm_io.o
chmod +x "$1"
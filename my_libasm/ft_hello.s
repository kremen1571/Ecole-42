%include "stud_io.inc"
global	_start

section	.text
_start:	mov		eax, 3
again:	PRINT	"HELL"
		PUTCHAR	10
		inc		eax
		cmp		eax, 5
		jl		again
		FINISH

/*nasm -f elf ft_hello.s 
ld -m elf_i386 ft_hello.o*/
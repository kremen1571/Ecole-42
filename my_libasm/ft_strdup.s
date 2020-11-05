	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy

	global ft_strdup

section .text

ft_strdup:
			cmp	rdi, 0
			je	er_exit
			push	rdi
			jnz	count

count		call	ft_strlen
			mov	rdi, rax
			jmp		aloc_mem

aloc_mem	inc		rdi
			call	malloc
			cmp		rax, 0
			je		er_exit
			jmp		copystr

copystr		pop		rsi
			mov		rdi, rax
			call	ft_strcpy
			ret

er_exit		mov	rax, 0
			ret
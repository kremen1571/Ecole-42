	global	ft_strlen

section .text

ft_strlen:
			xor	rax, rax				;rax = 0
compare		cmp	byte[rdi + rax], 0
			je	return
			inc	rax
			jmp	compare
return		ret
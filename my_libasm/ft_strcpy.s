global	ft_strcpy

section	.text

ft_strcpy:
			xor	rcx, rcx				;rcx = 0

copy		mov	dl, byte[rsi + rcx]		;temp = src[i]
			cmp	dl, 0					;if (temp == \0)
			je	return					;return
			mov	byte[rdi + rcx], dl		;else dest[i] = temp
			inc rcx						;i++
			jmp copy
return		mov	rax, rdi				;return value = dest
			mov	byte[rax + rcx], dl		;return value[i] = \0
			ret

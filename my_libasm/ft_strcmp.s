global	ft_strcmp

section .text

ft_strcmp:
			xor	rcx, rcx
			xor rax, rax
			xor	rdx, rdx

next		mov	al, byte[rdi + rcx]	;al = next element of s1
			mov	dl, byte[rsi + rcx]	;dl = next element of s2
			cmp	al, 0
			jz	count
			cmp	dl, 0
			jz	count
			inc	rcx
			cmp	al, dl
			jne	count
			je	next

count		movzx	rax, al
			movzx	rdx, dl
			sub		rax, rdx
			ret

al0			cmp	dl, 0
			jz	count
			mov	rax, -1
			ret

dl0			cmp	al, 0
			jz	count
			mov	rax, 1
			ret

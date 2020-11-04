global ft_write
extern error

	section .text

ft_write:
			xor	rax, rax
			mov	rax, 4
			syscall
			ret
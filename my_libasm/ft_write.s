extern __errno_location

	global ft_write

		section .text

ft_write:
			mov		rax, 1
			syscall
			cmp		rax, 0
			jl er
			ret

er			mov		rdx, rax
			call	__errno_location
			neg		rdx
			mov		[rax], rdx
			mov		rax, -1
			ret
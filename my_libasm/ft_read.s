extern __errno_location

	global ft_read

		section .text

ft_read:
			mov		rax, 0
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
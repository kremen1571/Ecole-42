# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_libasm.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klaronda <klaronda@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 03:38:47 by klaronda          #+#    #+#              #
#    Updated: 2020/11/02 03:43:04 by klaronda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .data
    msg db "Hello world!",10      ; 10 is the ASCII code for a new line (LF)

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, 13
    syscall
    
    mov rax, 60
    mov rdi, 0
    syscall

NAME = libasm.a

COMP_NASM = nasm -f elf64
COMP_OBJ = ld

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_strdup.s ft_read.s
OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled libasm.a\033[0m"

.s.o:
	@$(COMP_NASM) $<

clean:
	@rm -f $(OBJ)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@rm -f a.out
	@rm -f write_to.txt
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m All created files deleted.\033[0m"
	

test: re
	@clang main.c -L. -lasm
	@touch write_to.txt
	@./a.out

re:	fclean	all
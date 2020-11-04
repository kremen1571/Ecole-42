NAME = libasm.a

COMP_NASM = nasm -f elf64
COMP_OBJ = ld

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s

OBJ = $(SRC:.s=.o)
#nasm -felf64 helloworld.asm
#ld helloworld.o -o helloworld
#./helloworld


all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	#$(COMP_OBJ) $(OBJ) -o $(NAME)

.s.o:
	$(COMP_NASM) $<

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f a.out
test: re
	gcc main.c $(NAME)
	./a.out

re:	fclean	all
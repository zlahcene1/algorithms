##
## EPITECH PROJECT, 2020
## makefile
## File description:
## push_swap
##

SRC =		src/list/creat_free_list.c	\
		src/list/manage_list.c		\
		src/all_ops.c			\
		src/main.c

OBJ = 		$(SRC:.c=.o)

NAME =		push_swap

CFLAGS += 	-I include/

LIB = 		-L lib -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(LIB) -g3
		rm $(OBJ)
		make clean -C lib/my

clean :
		make clean -C lib/my
		rm -f $(OBJ) *~
		cd src/ && rm -f $(OBJ) *~

fclean :	clean
		make fclean -C lib/my
		rm -f $(NAME)

re :		$(OBJ)
		make re -C lib/my
		gcc -o $(NAME) $(OBJ) $(LIB)

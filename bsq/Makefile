##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC =		src/open_files.c	\
		src/check_errors.c	\
		src/prints.c		\
		src/str_array.c		\
		src/int_array.c		\
		src/algobox.c		\
		src/core_function.c	\
		src/main.c

OBJ = 		$(SRC:.c=.o)

NAME =		bsq

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

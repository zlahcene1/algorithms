##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC =		src/main.c	\
		src/open_file.c	\
		src/project.c

OBJ = 		$(SRC:.c=.o)

NAME =		antman

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

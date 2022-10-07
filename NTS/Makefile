##
## EPITECH PROJECT, 2020
## day10
## File description:
## TASK01
##

SRC	+=	lib/str_to_word_array.cpp
SRC	+=	lib/openFile.cpp
SRC	+=	src/errorTreatment/checkFile.cpp
SRC	+=	src/parsing/parseFile.cpp
SRC	+=	src/parsing/tabToList.cpp
SRC	+=	src/parsing/parseline.cpp
SRC	+=	src/components/createComponent.cpp
SRC	+=	src/circuit/display.cpp
SRC	+=	src/main.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-std=c++20 -g3

CPPFLAGS	+=	-I ./include/
CPPFLAGS	+=	-I ./include/chipsets/
CPPFLAGS	+=	-I ./include/chipsets/pin/

NAME	=	nanotekspice

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(HEADER) $(OBJ)
clean:
		rm -f $(NAME)
		rm -f include/*~
		rm -f *.cpp~

fclean:		clean
		rm -f Makefile~
		rm -f lib/my/*.o

re:	fclean all

##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

SRC				=	src/bsq.c\
					src/find_square.c\
					src/error.c

SRC_M			=	src/main.c

SRC_UT			=	tests/*.c

OBJ				=	$(SRC:.c=.o)

OBJ_M			=	$(SRC_M:.c=.o)

INCLUDE			=	-I./include

NAME			=	bsq

NAME_UT			=	unit_test

CFLAGS			=	-W -Werror -Wall -Wextra -I./include -g

CFLAGS_UT		=	-lcriterion --coverage

LFLAGS			=	-L./lib/ -lmy

RM				=	rm -rf

LINK			=	make -C lib/my/ -s

ALL_LINK		= 	make all -C lib/my/

CLEAN_LINK		=	make clean -C lib/my/

all:		$(NAME)
		$(ALL_LINK)


$(NAME):	$(OBJ_M) $(OBJ)
		$(LINK)
		gcc -o $(NAME) $(OBJ) $(OBJ_M) $(INCLUDE) $(CFLAGS) $(LFLAGS)

tests_run:
		$(LINK)
		gcc -o $(NAME_UT) $(SRC) $(SRC_UT) $(INCLUDE) $(CFLAGS_UT) $(LFLAGS)
		./$(NAME_UT)

clean:
		$(RM) $(OBJ) $(OBJ_UT) $(OBJ_M)
		$(CLEAN_LINK)

fclean:		clean fclean_ut
		$(RM) $(NAME)
		$(RM) *.gcda *.gcno
		$(RM) lib/libmy.a
		$(RM) lib/my/libmy.a

fclean_ut:	clean
		$(RM) $(NAME_UT)
		$(RM) *.gcda *.gcno

re:		fclean all

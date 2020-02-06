##
## EPITECH PROJECT, 2019
## Makefile library
## File description:
## compile lib functions
##

SRC		= 	my_strlen.c\
			my_revstr.c\
			my_str_isnum.c\
			my_putstr.c\
			my_putchar.c\
			practical_function.c\
			my_strdup.c\
			my_put_nbr.c\
			my_getnbr.c	\
			my_compute_power_rec.c\
			my_put_unsigned.c\
			my_nblen.c\


OBJ 	=	$(SRC:.c=.o)

NAME 	=	libmy.a

MY		=	my.h	\
			file_systems.h

LIB_F	=	../

INC_F	=	../../include

CFLAGS	=	-W -Wall -Wextra

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) $(LIB_F)
		cp $(MY) $(INC_F)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(LIB_F)$(NAME)

re:		fclean all
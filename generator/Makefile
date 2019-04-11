##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

SRC 		= 	main.c \
				src/utility.c

OBJ		=	$(SRC:.c=.o)

NAME 		=	generator

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda *.gch

CFLAGS	= 	-pedantic -Wall -Wextra -W -g -O2

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(RM_TRASH)
	cd include && $(RM) $(RM_TRASH)
	cd src && $(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

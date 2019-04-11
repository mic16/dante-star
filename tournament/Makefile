##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

SRC 		= 	main.c \

OBJ		=	$(SRC:.c=.o)

NAME 		=	dante_star

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda *.gch

CFLAGS	= 	-pedantic -Wall -Wextra -W -g -O2

all:
	make -C ../generator && make -C ../solver

clean:
	$(RM) $(RM_TRASH)
	cd include && $(RM) $(RM_TRASH)
	cd src && $(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

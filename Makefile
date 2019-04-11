##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- project
##

NAME_1 		=	solver/solver
NAME_2		=	generator/generator

RM 		=	rm -f

RM_TRASH=	*.o *~ *.gcno *.gcda *.gch

all:
	make -C generator && make -C solver && make -C tournament

clean:
	cd generator/ && $(RM) $(RM_TRASH)
	cd generator/include && $(RM) $(RM_TRASH)
	cd generator/src && $(RM) $(RM_TRASH)
	cd solver/ && $(RM) $(RM_TRASH)
	cd solver/include && $(RM) $(RM_TRASH)
	cd solver/src && $(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(NAME_1)
	$(RM) $(NAME_2)

re: fclean all

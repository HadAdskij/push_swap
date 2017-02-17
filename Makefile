# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 16:00:22 by atytaren          #+#    #+#              #
#    Updated: 2017/01/20 19:41:38 by atytaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
NAME3 = nbr_generator
SRC1 = sources/checker_functions.c sources/functions.c sources/brute_force.c\
		sources/smart_sort.c sources/checker.c sources/functions2.c
SRC2 = sources/checker_functions.c sources/functions.c sources/brute_force.c\
		sources/smart_sort.c sources/push_swap.c sources/functions2.c
SRC3 = sources/nbr_gen.c
LIB = libft.a
LIBPR = libftprintf.a
LIBFOLD = libraries/libft
LIBPRFOLD = libraries/libprintf
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
FLG = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(OBJ1) $(LIB) $(LIBPR)
	clang $(FLG) $(OBJ1) -o $(NAME1) $(LIBFOLD)/$(LIB) $(LIBPRFOLD)/$(LIBPR)

$(NAME2): $(OBJ2) $(LIB) $(LIBPR)
	clang $(FLG) $(OBJ2) -o $(NAME2) $(LIBFOLD)/$(LIB) $(LIBPRFOLD)/$(LIBPR)

$(NAME3): $(OBJ3)
	clang $(FLG) $(OBJ3) -o $(NAME3)

%.o: %.c
	clang $(FLG) -c -o $@ $<

$(LIB):
	make -C $(LIBFOLD)

$(LIBPR):
	make -C $(LIBPRFOLD)

cleanlib:
	make -C $(LIBFOLD) clean
	make -C $(LIBPRFOLD) clean

fcleanlib:
	make -C $(LIBFOLD) fclean
	make -C $(LIBPRFOLD) fclean

clean: cleanlib
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	rm -f $(OBJ3)

fclean: clean fcleanlib
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f $(NAME3)

re: fclean all

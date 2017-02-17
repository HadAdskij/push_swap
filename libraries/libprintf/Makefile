# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 16:00:22 by atytaren          #+#    #+#              #
#    Updated: 2016/12/20 19:58:53 by atytaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBNAME = libftprintf.a
SRC =	ft_printf.c func1.c func2.c
OBJ = $(SRC:.c=.o)
	FLG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(LIBNAME) $(OBJ)

%.o: %.c
	clang $(FLG) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

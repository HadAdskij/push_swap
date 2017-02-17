# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 19:06:47 by atytaren          #+#    #+#              #
#    Updated: 2016/12/15 14:28:59 by atytaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
LIBNAME = libft.a
SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstmap.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_calc_words.c ft_mod.c \
		ft_str_toupper.c ft_create_two_dim_arr.c ft_str_tolower.c \
		ft_sort_int_tab.c ft_print_memory.c ft_print_hex.c ft_swap.c \
		get_next_line.c
OBJ = $(SRC:.c=.o)
FLG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(LIBNAME) $(OBJ)

%.o: %.c
	gcc $(FLG) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

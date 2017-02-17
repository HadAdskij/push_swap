/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:40:52 by atytaren          #+#    #+#             */
/*   Updated: 2017/02/02 14:41:12 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define MORE "al character\n4 - incorrect command\n5 - duplicated numbers\n"
# define ERRORSLIST "1 - malloc error\n2 - number is not integer\n3 - illeg"MORE
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libraries/libft/libft.h"
# include "../libraries/libprintf/ft_printf.h"

enum				e_rrors{
	MALLOC_ERROR = 1,
	NOT_INTEGER_RANGE = 2,
	ILLEGAL_CHARACTER = 3,
	INCORRECT_COMMAND = 4,
	DUPLICATE = 5,
};

typedef struct		s_parameters
{
	int				*a;
	int				*b;
	int				*len;
	int				com_nbr;
	int				*max_com_nbr;
	int				*calls;
	char			**res;
	char			*current;
}					t_par;

typedef struct		s_sort
{
	int				*a;
	int				*b;
	int				*l;
	char			*str;
}					t_sort;

void				catch(int error, int *len);
void				swap(char *command, int *a, int *b, int *len);
void				push(char *command, int *a, int *b, int *len);
void				rotate(char *command, int *a, int *b, int *len);
void				reverse_rotate(char *command, int *a, int *b, int *len);
int					atoi_with_ch(char *str, int *len);
int					is_sorted(int *a, int *len);
char				*brute_force(int *a, int *b, int *len, int com_nbr);
void				copy_parameters(t_par **p);
int					fsjoin(char **a, char *b);
void				put_to_string(char *str, char *s, int l);
int					stupid_sorting(t_par *p, char *command);
void				do_command(int *a, int *b, int *len, char *command);
char				*smart_sort(int *a, int *b, int *len);
int					get_commands_number(char *str);
int					get_numbers(int **a, int **b, char **av, int ac);
int					show_stack(char *command, int *a, int *b, int *len);
void				push_to_a(t_sort *p, int nbr);
void				push_to_b(t_sort *p, int nbr);
void				push_to_a_addition(t_sort *p, int nbr);
void				push_to_b_addition(t_sort *p, int nbr);
int					is_in_array(int nbr, int *arr, int len);
void				sort_3(int *arr, int *b, int *l, char **str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:26:53 by atytaren          #+#    #+#             */
/*   Updated: 2017/02/02 16:12:14 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** atoi that checks if number is integer
*/

int			atoi_with_ch(char *str, int *len)
{
	long int		res;
	int				neg;
	int				fl;

	res = 0;
	neg = 1;
	fl = 1;
	str--;
	while (*(++str) && ((*str <= '9' && *str >= '0') ||
		((*str <= ' ' || *str == '+' || *str == '-') && fl)))
	{
		if (*str <= ' ')
			continue ;
		if (*str == '-')
			neg = -1;
		if (*str <= '9' && *str >= '0')
			res = res * 10 + *str - 48;
		fl = 0;
	}
	if (*str != 0)
		catch(ILLEGAL_CHARACTER, len);
	if (res * neg < -2147483648 || res * neg > 2147483647)
		catch(NOT_INTEGER_RANGE, len);
	return ((int)res * neg);
}

int			is_sorted(int *a, int *len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < len[0] && (j = i) >= 0)
		while (++j < len[0])
			if (a[i] == a[j])
				catch(DUPLICATE, len);
	i = -1;
	while (++i < len[0] - 1)
		if (a[i] > a[i + 1])
			return (0);
	return (1);
}

void		do_command(int *a, int *b, int *len, char *command)
{
	if (command[0] == 's')
		swap(command, a, b, len);
	else if (command[0] == 'p')
		push(command, a, b, len);
	else if (command[0] == 'r' && command[2] == 0)
		rotate(command, a, b, len);
	else if (command[0] == 'r' && command[1] == 'r')
		reverse_rotate(command, a, b, len);
}

/*
**	create new struct t_par, copy everything from existing p, and change pointer
*/

void		copy_parameters(t_par **p)
{
	int		i;
	t_par	*new;

	if ((new = (t_par*)malloc(sizeof(t_par))) == NULL)
		catch(MALLOC_ERROR, (*p)->len);
	new->len = (int*)malloc(sizeof(int) * 3);
	new->a = (int*)malloc(sizeof(int) * ((*p)->len[0] + (*p)->len[1]));
	new->b = (int*)malloc(sizeof(int) * ((*p)->len[0] + (*p)->len[1]));
	if (!new->len || !new->a || !new->b)
		catch(MALLOC_ERROR, (*p)->len);
	new->com_nbr = (*p)->com_nbr;
	new->res = (*p)->res;
	new->calls = (*p)->calls;
	new->max_com_nbr = (*p)->max_com_nbr;
	new->current = ft_strdup((*p)->current);
	i = 3;
	while (--i >= 0)
		new->len[i] = (*p)->len[i];
	while (++i < ((*p)->len[0] + (*p)->len[1]))
		new->a[i] = (*p)->a[i];
	while (--i >= 0)
		new->b[i] = (*p)->b[i];
	*p = new;
}

/*
**	get number array(stack A) from arguments of program
*/

int			get_numbers(int **a, int **b, char **av, int ac)
{
	int		i;
	int		j;
	int		len;
	char	**nbs;
	char	*t;

	j = (av[1][0] == '-' && av[1][1] > '9') ? 1 : 0;
	len = 0;
	while (++j < ac && ++len && (t = av[j]))
		while (*(++t))
			len += *t == ' ' ? 1 : 0;
	if ((*a = (int *)malloc(sizeof(int) * len)) == NULL
		|| (*b = (int *)malloc(sizeof(int) * len)) == NULL)
		catch(MALLOC_ERROR, NULL);
	i = (!(len *= 0) && av[1][0] == '-' && av[1][1] > '9') ? 1 : 0;
	while (++i < ac && (nbs = ft_strsplit(av[i], ' ')) && !(j *= 0))
	{
		while (nbs[j] && !((*b)[len] = 0))
		{
			(*a)[len++] = atoi_with_ch(nbs[j], (av[1][1] == 'd') ? NULL : *b);
			free(nbs[j++]);
		}
		free(nbs);
	}
	return (len);
}

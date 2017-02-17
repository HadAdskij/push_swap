/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:41:58 by atytaren          #+#    #+#             */
/*   Updated: 2017/02/02 14:45:59 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_to_string(char *str, char *s, int l)
{
	while (*s)
		*(str++) = *(s++);
	str--;
	while (*(++str + l))
		*str = *(str + l);
	while (--l)
		*(str++) = 0;
}

char	*check_string(char *str)
{
	char	*res;

	while ((res = ft_strstr(str, "\nrra\nra\n")))
		put_to_string(res, "\n", 7);
	while ((res = ft_strstr(str, "sa\nsb")))
		put_to_string(res, "ss", 3);
	while ((res = ft_strstr(str, "sa\nsb")))
		put_to_string(res, "ss", 3);
	while ((res = ft_strstr(str, "\nrrb\nrb\n")))
		put_to_string(res, "\n", 7);
	while ((res = ft_strstr(str, "\nra\nrra\n")))
		put_to_string(res, "\n", 7);
	while ((res = ft_strstr(str, "\nrb\nrrb\n")))
		put_to_string(res, "\n", 7);
	return (str);
}

char	*smart_sort(int *a, int *b, int *len)
{
	t_sort par;

	par.a = a;
	par.b = b;
	par.l = len;
	par.str = NULL;
	push_to_b(&par, len[0]);
	return (par.str);
}

/*
**	calls "smart" sorting function, that sort stack in some order, and
**	"brute force" sorting function, that sort stack in random order,
**	compare their results and chooses shortest result
*/

char	*sort_stack(int *a, int *b, int *len, char *str2)
{
	int		com_nbr[2];
	char	*str;
	int		*aa;

	com_nbr[0] = -1;
	if ((aa = (int*)malloc(sizeof(int) * len[0])) == NULL)
		catch(MALLOC_ERROR, len);
	while (++com_nbr[0] < len[0])
		aa[com_nbr[0]] = a[com_nbr[0]];
	str = (!is_sorted(a, len)) ? smart_sort(a, b, len) : ft_strnew(1);
	check_string(str);
	com_nbr[0] = get_commands_number(str);
	str2 = len[3] != 's' ? brute_force(aa, b, len, com_nbr[0]) : NULL;
	free(aa);
	if (str2 != NULL)
	{
		com_nbr[1] = get_commands_number(check_string(str2));
		if (com_nbr[1] < com_nbr[0])
		{
			free(str);
			return (str2);
		}
	}
	return (str);
}

int		main(int ac, char **av)
{
	int		*a;
	int		*b;
	int		len[4];
	char	*commandlist;

	if (ac > 1)
	{
		len[2] = 0;
		len[3] = 0;
		if (av[1][0] == '-')
		{
			len[2] = av[1][1];
			len[3] = av[1][2];
		}
		if (ac == 1)
			return (0);
		len[1] = 0;
		len[0] = get_numbers(&a, &b, av, ac);
		commandlist = sort_stack(a, b, len, NULL);
		free(a);
		free(b);
		ft_putstr(commandlist);
		free(commandlist);
	}
	return (0);
}

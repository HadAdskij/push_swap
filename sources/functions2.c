/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:39:33 by atytaren          #+#    #+#             */
/*   Updated: 2017/02/02 14:39:58 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		fsjoin(char **a, char *b)
{
	char	*str;

	if (*a)
		str = ft_strjoin(*a, b);
	else
		str = ft_strdup(b);
	if (*a)
		free(*a);
	if (str == NULL)
		catch(MALLOC_ERROR, NULL);
	*a = str;
	return (1);
}

int		get_commands_number(char *str)
{
	int	com_nbr;

	com_nbr = 0;
	while (*(++str))
		if (*str == '\n')
			com_nbr++;
	return (com_nbr);
}

int		is_in_array(int nbr, int *arr, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (nbr == arr[i])
			return (1);
	return (0);
}

void	sort_3(int *arr, int *b, int *l, char **str)
{
	int		fl;

	fl = 0;
	while (!(arr[0] < arr[1] && arr[1] < arr[2]) || fl)
	{
		if (arr[0] > arr[1] && fsjoin(str, "sa\n"))
			swap("sa", arr, b, l);
		else if (!fl && ((arr[0] < arr[1] && arr[1] > arr[2])
				|| (arr[0] > arr[1] && arr[0] < arr[2]))
				&& fsjoin(str, "ra\n") && ++fl)
			rotate("ra", arr, b, l);
		else if (fl && fsjoin(str, "rra\n"))
			reverse_rotate("rra", arr, b, l + --fl);
	}
}

/*
**	just print stacks at current moment
*/

int		show_stack(char *command, int *a, int *b, int *len)
{
	int	i;

	if (len[2] == 'c' && (i = -1))
	{
		ft_printf("\nCommand: "RED"%s\n", command);
		ft_printf("%35s%35s\n", BLUE"Stack A", YELLOW"Stack B");
		while (++i < len[0] || i < len[1])
		{
			i < len[0] ? ft_printf(BLUE"%30d", a[i]) : ft_printf("%30s", "");
			i < len[1] ? ft_printf(YELLOW"%30d\n", b[i]) : ft_printf("\n");
		}
		ft_printf(RESET"\n");
	}
	else if (len[2] == 'v' && (i = -1))
	{
		ft_printf("\nCommand: %s\n%30s%30s\n", command, "Stack A", "Stack B");
		while (++i < len[0] || i < len[1])
		{
			i < len[0] ? ft_printf("%30d", a[i]) : ft_printf("%30s", " ");
			if (i < len[1])
				ft_printf("%30d", b[i]);
			ft_printf("\n");
		}
	}
	return (1);
}

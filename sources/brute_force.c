/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:45:27 by atytaren          #+#    #+#             */
/*   Updated: 2017/01/20 19:48:57 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	call_stupid_sorting(t_par *p)
{
	if (p->com_nbr + 1 < *(p->max_com_nbr))
	{
		stupid_sorting(p, "sa");
		stupid_sorting(p, "sb");
		stupid_sorting(p, "pa");
		stupid_sorting(p, "pb");
		stupid_sorting(p, "ra");
		stupid_sorting(p, "rb");
		stupid_sorting(p, "rra");
		stupid_sorting(p, "rrb");
	}
}

/*
**	recursive function, that tried to sort stack using backtracking
*/

int		stupid_sorting(t_par *p, char *command)
{
	*(p->calls) += 1;
	if (*(p->calls) > 8000000 || (command[0] != 'p'
		&& (command[1] == 'b' || command[2] == 'b')))
		return (0);
	copy_parameters(&p);
	do_command(p->a, p->b, p->len, command);
	fsjoin(&(p->current), command);
	fsjoin(&(p->current), "\n");
	p->com_nbr++;
	if (is_sorted(p->a, p->len) && !p->len[1])
	{
		*(p->max_com_nbr) = p->com_nbr;
		if (*(p->res))
			free(*(p->res));
		*(p->res) = ft_strdup(p->current);
		return (1);
	}
	call_stupid_sorting(p);
	free(p->a);
	free(p->b);
	free(p->len);
	free(p);
	free(p->current);
	return (1);
}

/*
**	this function just calls previous one
**	and return result string of commands
*/

char	*brute_force(int *a, int *b, int *len, int com_nbr)
{
	t_par	new;
	int		max_com_nbr;
	int		calls_number;
	char	*res;

	new.a = a;
	new.b = b;
	new.len = len;
	res = NULL;
	new.res = &res;
	new.current = "";
	calls_number = 0;
	new.calls = &calls_number;
	max_com_nbr = (com_nbr < 11) ? com_nbr : 10;
	new.max_com_nbr = &max_com_nbr;
	new.com_nbr = 0;
	call_stupid_sorting(&new);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:50:35 by atytaren          #+#    #+#             */
/*   Updated: 2017/02/02 14:51:11 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		*most_part(int *arr, int nbr, int big)
{
	int *res;
	int i;
	int j;
	int hnbr;

	res = (int*)malloc(sizeof(int) * nbr / 2);
	i = -1;
	hnbr = (nbr % 2 == 0 || big) ? nbr / 2 : nbr / 2 + 1;
	while (++i < hnbr)
	{
		res[i] = big ? -2147483647 : 2147483647;
		j = -1;
		while (++j < nbr)
		{
			if (!big && (!i || arr[j] > res[i - 1]) && arr[j] < res[i])
				res[i] = arr[j];
			if (big && (!i || arr[j] < res[i - 1]) && arr[j] > res[i])
				res[i] = arr[j];
		}
	}
	return (res);
}

void	push_to_b_addition(t_sort *p, int nbr)
{
	int *sd;
	int i;
	int fl;
	int hnbr;

	hnbr = (nbr % 2 == 0) ? nbr / 2 : nbr / 2 + 1;
	i = 0;
	fl = 0;
	sd = most_part(p->a, nbr, 0);
	while (i < hnbr)
		if (is_in_array((p->a)[0], sd, hnbr)
			&& fsjoin(&(p->str), "pb\n") && ++i)
			push("pb", p->a, p->b, p->l);
		else if (fsjoin(&(p->str), "ra\n") && ++fl)
			rotate("ra", p->a, p->b, p->l);
	if (fl && fl < (p->l)[0] / 2)
		while (fl-- && fsjoin(&(p->str), "rra\n"))
			reverse_rotate("rra", p->a, p->b, p->l);
	else if (fl && fl >= (p->l)[0] / 2)
		while ((p->l)[0] - fl > 1 && fl++ && fsjoin(&(p->str), "ra\n"))
			rotate("ra", p->a, p->b, p->l);
	push_to_b(p, nbr - hnbr);
	push_to_a(p, hnbr);
	free(sd);
}

void	push_to_b(t_sort *p, int nbr)
{
	if (is_sorted(p->a, &nbr))
		return ;
	if (nbr == 2 && (p->a)[0] > (p->a)[1] && fsjoin(&(p->str), "sa\n"))
		swap("sa", p->a, p->b, p->l);
	else if (nbr == 3)
		sort_3(p->a, p->b, p->l, &(p->str));
	else if (nbr == 4 && (p->a)[3] > (p->a)[0]
			&& (p->a)[3] > (p->a)[1] && (p->a)[3] > (p->a)[2])
		sort_3(p->a, p->b, p->l, &(p->str));
	else if (nbr > 3)
		push_to_b_addition(p, nbr);
}

void	push_to_a_addition(t_sort *p, int nbr)
{
	int *sd;
	int i;
	int fl;

	i = 0;
	fl = 0;
	sd = most_part(p->b, nbr, 1);
	while (i < nbr / 2)
		if (is_in_array((p->b)[0], sd, nbr / 2)
			&& fsjoin(&(p->str), "pa\n") && ++i)
			push("pa", p->a, p->b, p->l);
		else if (fsjoin(&(p->str), "rb\n") && ++fl)
			rotate("rb", p->a, p->b, p->l);
	if (fl && fl < (p->l)[1] / 2)
		while (fl-- && fsjoin(&(p->str), "rrb\n"))
			reverse_rotate("rrb", p->a, p->b, p->l);
	else if (fl && fl >= (p->l)[1] / 2)
		while ((p->l)[1] - fl > 1 && fl++ && fsjoin(&(p->str), "rb\n"))
			rotate("rb", p->a, p->b, p->l);
	push_to_b(p, nbr / 2);
	push_to_a(p, nbr - nbr / 2);
	free(sd);
}

void	push_to_a(t_sort *p, int nbr)
{
	if ((nbr == 2 || nbr == 3)
		&& (p->b)[0] < (p->b)[1] && fsjoin(&(p->str), "sb\n"))
		swap("sb", p->a, p->b, p->l);
	if (nbr > 1)
		push_to_a_addition(p, nbr);
	else if (fsjoin(&(p->str), "pa\n"))
		push("pa", p->a, p->b, p->l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:10:28 by exam              #+#    #+#             */
/*   Updated: 2016/12/15 14:23:03 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	int		buf;
	int		i;
	int		j;

	i = -1;
	while (++i < (int)size)
	{
		j = -1;
		while (++j < (int)size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				buf = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = buf;
			}
		}
	}
}

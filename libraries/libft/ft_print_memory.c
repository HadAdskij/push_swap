/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:36:03 by exam              #+#    #+#             */
/*   Updated: 2017/01/02 19:18:15 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_memory(const void *addr, size_t size)
{
	char		str[16];
	size_t		i;
	int			j;
	char		*a;

	a = (char*)addr;
	i = -1;
	while (++i < size)
	{
		ft_print_hex(a[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		str[i % 16] = (a[i] >= ' ' && a[i] < 127) ? a[i] : '.';
		if (i % 16 == 15 || i == size - 1)
		{
			j = i;
			if (i == size - 1)
				while (i++ % 16 != 15)
					write(1, "   ", i % 2 + 2);
			write(1, str, j % 16 + 1);
			write(1, "\n", 1);
			j = -1;
		}
	}
}

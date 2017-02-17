/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:08:07 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/26 16:03:43 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mod(int i)
{
	if (i < 0)
		return (-1 * i);
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*res;
	int		tn;

	i = 1;
	tn = n;
	if (n < 0)
		i++;
	while ((tn > 9 || tn < -9) && ++i)
		tn /= 10;
	res = (char*)malloc(sizeof(char) * (i + 1));
	if (res)
	{
		res[i] = 0;
		tn = n;
		while (--i >= 0)
		{
			res[i] = mod(tn % 10) + 48;
			tn /= 10;
		}
		if (n < 0)
			res[0] = '-';
	}
	return (res);
}

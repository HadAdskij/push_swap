/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_two_dim_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:09:11 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/30 13:21:43 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create_two_dim_arr(int x, int y, int c)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char**)malloc(sizeof(char*) * (y + 1));
	if (!arr)
		return (NULL);
	arr[y] = NULL;
	j = -1;
	while (++j < y)
	{
		arr[j] = (char*)malloc(sizeof(char) * (x + 1));
		if (!arr[j])
			return (NULL);
		arr[j][x] = 0;
		i = -1;
		while (++i < x)
			arr[j][i] = c;
	}
	return (arr);
}

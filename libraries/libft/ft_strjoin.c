/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:05:36 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/26 15:47:53 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	res = (char*)malloc(sizeof(char) * (i + j + 1));
	if (res)
	{
		res[i + j] = 0;
		while (--j >= 0)
			res[i + j] = s2[j];
		while (--i >= 0)
			res[i] = s1[i];
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:35:05 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/24 18:28:49 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;

	if (!*little)
		return ((char*)big);
	i = -1;
	while (big[++i] && i < (int)len)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < (int)len)
			if (little[(j++) + 1] == 0)
				return ((char*)big + i);
	}
	return (NULL);
}

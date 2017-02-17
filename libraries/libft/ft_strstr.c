/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:20:39 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/24 18:25:21 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	if (!*little)
		return ((char*)big);
	i = -1;
	while (big[++i])
	{
		j = 0;
		while (little[j] == big[i + j])
			if (little[(j++) + 1] == 0)
				return ((char*)big + i);
	}
	return (NULL);
}

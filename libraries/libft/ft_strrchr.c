/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:15:37 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/24 18:06:32 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*temp;

	temp = (char*)s;
	res = NULL;
	while (*temp)
		if (*(temp++) == (char)c)
			res = temp - 1;
	if (c == 0)
		return (temp);
	return (res);
}

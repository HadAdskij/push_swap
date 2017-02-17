/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:38:07 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/26 15:46:24 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	res = (char*)malloc(len + 1);
	if (res && s)
	{
		res[len] = 0;
		while (len)
		{
			res[len - 1] = s[start + len - 1];
			len--;
		}
	}
	return (res);
}

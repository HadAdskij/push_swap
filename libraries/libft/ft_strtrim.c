/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:24:05 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/26 15:52:21 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	char	*ss;
	int		i;

	ss = (char*)s;
	i = 0;
	if (!s)
		return (NULL);
	while (*ss == ' ' || *ss == '\n' || *ss == '\t')
		ss++;
	while (ss[i])
		i++;
	while (i && (ss[i - 1] == ' ' || ss[i - 1] == '\n' || ss[i - 1] == '\t'))
		i--;
	res = (char*)malloc(sizeof(char) * (i + 1));
	if (res)
	{
		res[i] = 0;
		while (--i >= 0)
			res[i] = ss[i];
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:29:31 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/26 15:41:45 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*news;
	unsigned int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		news = (char*)malloc(sizeof(char) * (i + 1));
		if (!news)
			return (NULL);
		news[i] = 0;
		while ((i--) > 0)
			news[i] = f(i, s[i]);
		return (news);
	}
	return (NULL);
}

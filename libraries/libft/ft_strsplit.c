/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:49:25 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/26 19:34:27 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordsnum(const char *s, int *l, char c)
{
	int		words;

	*l = -1;
	words = 0;
	while (s && s[++*l])
		if ((*l == 0 || s[*l - 1] == c) && s[*l] != c)
			words++;
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		words;
	int		l;
	int		tl;

	words = wordsnum(s, &l, c);
	res = (char**)malloc(sizeof(char*) * (words + 1));
	if (res && s)
		res[words] = 0;
	while (s && res && (--l) >= 0)
	{
		if (s[l] == c)
			continue ;
		tl = 0;
		while ((l - tl) >= 0 && s[l - tl] != c)
			tl++;
		l = l - tl + 1;
		res[--words] = (char*)malloc(sizeof(char) * (tl + 1));
		if (!res[words])
			return (NULL);
		res[words][tl] = 0;
		while (--tl >= 0)
			res[words][tl] = s[l + tl];
	}
	return (res);
}

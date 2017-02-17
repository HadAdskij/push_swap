/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:34:40 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/30 15:51:39 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_calc_words(char *s, char c)
{
	int		words;
	int		i;

	i = -1;
	words = 0;
	while (s[++i])
	{
		if (s[i] == c)
			continue ;
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			words++;
	}
	return (words);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:03:43 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/24 20:41:51 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*temp;

	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (res == NULL)
		return (NULL);
	temp = res;
	while (*s1)
		*(temp++) = *(s1++);
	*temp = 0;
	return (res);
}

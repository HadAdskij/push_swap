/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 09:54:01 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/24 13:17:58 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j] && (i + 1) < size)
		dest[i++] = src[j++];
	dest[i] = 0;
	if (!j)
		i = size;
	while (src[j++])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:49:49 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/22 13:25:43 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;

	i = -1;
	while (++i < (int)n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (*((unsigned char*)(dst + i)) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}

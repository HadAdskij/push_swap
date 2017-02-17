/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:34:07 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/26 15:22:00 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t l)
{
	size_t			i;

	i = -1;
	if (dst < src)
		while (++i < l)
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
	if (dst > src)
		while (l--)
			*(unsigned char*)(dst + l) = *(unsigned char*)(src + l);
	return (dst);
}

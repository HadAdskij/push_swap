/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:44:51 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/24 16:49:24 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while ((++i <= (unsigned int)n) && src[i - 1])
	{
		dest[i - 1] = src[i - 1];
	}
	while (i <= (unsigned int)n)
	{
		dest[i - 1] = 0;
		i++;
	}
	return (dest);
}

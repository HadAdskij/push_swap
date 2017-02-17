/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:40:40 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/24 14:41:11 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;

	i = -1;
	while (++i < (int)n)
		if (*((unsigned char*)(s1 + i)) != *((unsigned char*)(s2 + i)))
			return (*((unsigned char*)(s1 + i)) - *((unsigned char*)(s2 + i)));
	return (0);
}

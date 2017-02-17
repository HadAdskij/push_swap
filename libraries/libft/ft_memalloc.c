/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:47:12 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/23 13:36:39 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*result;

	result = (void*)malloc(size);
	if (result)
	{
		while (size > 0)
			*(result + (--size)) = 0;
		return ((void*)result);
	}
	return (NULL);
}

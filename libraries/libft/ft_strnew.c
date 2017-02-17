/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:23:06 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/21 15:48:44 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	size++;
	str = (char*)malloc(size);
	if (str)
	{
		while (size)
		{
			*(str + size - 1) = 0;
			size--;
		}
		return (str);
	}
	return (NULL);
}

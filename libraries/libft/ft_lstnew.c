/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:59:38 by atytaren          #+#    #+#             */
/*   Updated: 2017/01/20 20:59:41 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *con, size_t c)
{
	t_list	*nw;

	nw = (t_list*)malloc(sizeof(t_list));
	if (nw)
	{
		if (con)
		{
			nw->content = malloc(c);
			if (!nw->content)
				return (NULL);
			nw->content_size = c;
			while ((c--) > 0)
				*(unsigned char*)(nw->content) = *(unsigned char*)(con);
		}
		else
		{
			nw->content = NULL;
			nw->content_size = 0;
		}
		nw->next = NULL;
	}
	return (nw);
}

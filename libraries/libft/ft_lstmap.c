/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:36:54 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/30 13:48:00 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nw;
	t_list	*temp;

	if (lst)
	{
		temp = lst->next;
		nw = f(lst);
		nw->next = ft_lstmap(temp, f);
		return (nw);
	}
	return (NULL);
}

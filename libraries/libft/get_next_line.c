/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:20:49 by atytaren          #+#    #+#             */
/*   Updated: 2017/01/20 20:58:49 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	from_list_to_str(t_list *l, char **line, int fl)
{
	t_list		*temp;

	*line = (char*)malloc(fl + 1);
	(*line)[fl] = 0;
	while (l)
	{
		(*line)[--fl] = ((char*)l->content)[0];
		temp = l;
		l = l->next;
		free(temp->content);
		free(temp);
	}
}

int		start(t_crutch *b, t_list **list, int *fl)
{
	*fl = -1;
	*list = NULL;
	if (b->flag != 543354684)
	{
		b->lt = BUFF_SIZE;
		b->buf[BUFF_SIZE - 1] = 0;
		*fl += 1;
		return (1);
	}
	while (++*fl >= 0 && ++b->lt < BUFF_SIZE)
		if (b->buf[b->lt] != '\n' && b->buf[b->lt] != -1)
			ft_lstadd(list, ft_lstnew(b->buf + b->lt, 1));
		else
			break ;
	if (b->lt == BUFF_SIZE)
		b->flag = 0;
	if (b->buf[b->lt] == -1 && b->lt-- >= 0)
		if (*fl == 0)
			return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_crutch		b[47];
	int					l;
	int					fulll;
	t_list				*list;
	t_crutch			*buf;

	buf = (fd < 0) ? NULL : &b[fd % 46];
	if (fd < 0 || line == NULL || (l = start(buf, &list, &fulll)) < 0)
		return (-1);
	while (l && buf->lt == BUFF_SIZE)
	{
		if ((l = read(fd, buf->buf, BUFF_SIZE)) > 0 && l < BUFF_SIZE)
			buf->buf[l] = -1;
		buf->lt = -1;
		while (++buf->lt < l)
			if (buf->buf[buf->lt] == '\n' || buf->buf[buf->lt] == -1)
				break ;
			else
				ft_lstadd(&list, ft_lstnew(buf->buf + buf->lt, 1));
		buf->flag = (buf->lt < l) ? 543354684 : 0;
		fulll += buf->lt;
		l = (!l && fulll > 1) ? 1 : l;
	}
	from_list_to_str(list, line, fulll);
	return ((l > 0) ? 1 : l);
}

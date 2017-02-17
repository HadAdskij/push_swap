/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:36:51 by atytaren          #+#    #+#             */
/*   Updated: 2017/02/02 14:37:16 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	take command from file descriptor and starts corresponding
**	functions
*/

int		check_solving(int len[3], int *a, int *b, int fd)
{
	char	*command;
	int		res;
	int		nbr;

	nbr = 0;
	while (get_next_line(fd, &command) > 0 && ++nbr && !(!fd && !command[0]))
	{
		if (command[0] == 's')
			swap(command, a, b, len);
		else if (command[0] == 'p')
			push(command, a, b, len);
		else if (command[0] == 'r' && command[2] == 0)
			rotate(command, a, b, len);
		else if (command[0] == 'r' && command[1] == 'r')
			reverse_rotate(command, a, b, len);
		else
			catch(INCORRECT_COMMAND, len);
		if (command)
			free(command);
	}
	if (command)
		free(command);
	res = (is_sorted(a, len) && !len[1]) ? 1 : -1;
	res = (nbr) ? res * nbr : res;
	return (res);
}

int		main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	len[3];
	int	fd;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		fd = 0;
	if (ac > 1)
	{
		len[2] = (av[1][0] == '-' && (av[1][1] == 'v' || av[1][1] == 'n'
				|| av[1][1] == 'c' || av[1][1] == 'd')) ? av[1][1] : 0;
		len[1] = 0;
		len[0] = get_numbers(&a, &b, av, ac);
		if (!is_sorted(a, len) || (len[0] == 0))
			len[0] = check_solving(len, a, b, fd);
		write(1, len[0] >= 0 ? "OK\n" : "KO\n", 3);
		free(a);
		free(b);
	}
	if (len[2] == 'c' || len[2] == 'n')
		ft_printf("Commands number: "GREEN"%d\n"RESET, len[0]);
	if (fd)
		close(fd);
	return (0);
}

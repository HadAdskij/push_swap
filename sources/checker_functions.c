/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:00:35 by atytaren          #+#    #+#             */
/*   Updated: 2017/01/20 20:55:47 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	function handle errors
*/

void			catch(int err, int *len)
{
	if (len == NULL || len[2] == 'd')
	{
		ft_printf(RED"Error #%d\n", err);
		ft_printf(BLUE"Errors list:\n"ERRORSLIST);
	}
	else
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/*
**	handle commands "sa", "sb", "ss"
**	this commands swaps first 2 elements in stack
**  "sa" - stack A
**  "sb" - stack B
**  "ss" - both stacks
*/

void			swap(char *command, int *a, int *b, int *len)
{
	int	temp;

	if ((command[1] == 'a' || command[1] == 's') && len[0] > 1)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	if ((command[1] == 'b' || command[1] == 's') && len[1] > 1)
	{
		temp = b[0];
		b[0] = b[1];
		b[1] = temp;
	}
	if (!((command[1] == 'b' || command[1] == 'a'
		|| command[1] == 's') && command[2] == 0))
		catch(INCORRECT_COMMAND, len);
	if (len[2] == 'c' || len[2] == 'v')
		show_stack(command, a, b, len);
}

/*
**	handle commands "pa", "pb"
**	this commands take first element in stack one stack and push it to another
**  "pa" - from stack B to A
**  "pb" - from stack A to B
*/

void			push(char *command, int *a, int *b, int *len)
{
	int	temp;
	int	i;

	temp = (command[1] == 'a') ? b[0] : a[0];
	if (!(i = 0) && command[1] == 'a' && len[1] > 0)
	{
		while (++i < len[1])
			b[i - 1] = b[i];
		i = (len[1]-- >= 0) ? ++len[0] : 0;
		while (--i > 0)
			a[i] = a[i - 1];
		a[0] = temp;
	}
	else if (command[1] == 'b' && len[0] > 0)
	{
		while (++i < len[0])
			a[i - 1] = a[i];
		i = (len[0]-- >= 0) ? ++len[1] : 0;
		while (--i > 0)
			b[i] = b[i - 1];
		b[0] = temp;
	}
	if (!((command[1] == 'b' || command[1] == 'a') && command[2] == 0))
		catch(INCORRECT_COMMAND, len);
	i = (len[2] == 'c' || len[2] == 'v') ? show_stack(command, a, b, len) : 0;
}

/*
**	handle commands "ra", "rb", "rr"
**	this commands move all elements of stack one position top. First
**	elements becomes the last one
**  "ra" - stack A
**  "rb" - stack B
**  "rr" - both stacks
*/

void			rotate(char *command, int *a, int *b, int *len)
{
	int	temp;
	int	i;

	if ((command[1] == 'a' || command[1] == 'r') && len[0] > 1)
	{
		i = 0;
		temp = a[0];
		while (++i < len[0])
			a[i - 1] = a[i];
		a[i - 1] = temp;
	}
	if ((command[1] == 'b' || command[1] == 'r') && len[1] > 1)
	{
		i = 0;
		temp = b[0];
		while (++i < len[1])
			b[i - 1] = b[i];
		b[i - 1] = temp;
	}
	if (!((command[1] == 'b' || command[1] == 'a'
		|| command[1] == 'r') && command[2] == 0))
		catch(INCORRECT_COMMAND, len);
	if (len[2] == 'c' || len[2] == 'v')
		show_stack(command, a, b, len);
}

/*
**	handle commands "rra", "rrb", "rrr"
**	this commands move all elements of stack one position down. Last
**	elements becomes the first one
**  "rra" - stack A
**  "rrb" - stack B
**  "rrr" - both stacks
*/

void			reverse_rotate(char *command, int *a, int *b, int *len)
{
	int	temp;
	int	i;

	if ((command[2] == 'a' || command[2] == 'r') && len[0] > 1)
	{
		i = len[0];
		temp = a[len[0] - 1];
		while (--i > 0)
			a[i] = a[i - 1];
		a[0] = temp;
	}
	if ((command[2] == 'b' || command[2] == 'r') && len[1] > 1)
	{
		i = len[1];
		temp = b[len[1] - 1];
		while (--i > 0)
			b[i] = b[i - 1];
		b[0] = temp;
	}
	if (!((command[2] == 'b' || command[2] == 'a'
		|| command[2] == 'r') && command[3] == 0))
		catch(INCORRECT_COMMAND, len);
	if (len[2] == 'c' || len[2] == 'v')
		show_stack(command, a, b, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:42:23 by atytaren          #+#    #+#             */
/*   Updated: 2017/01/24 14:56:58 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  SIZE 100

int     is_in_array(int *arr, int nbr, int size)
{
	int     i;

	i = -1;
	while (++i < size)
		if (arr[i] == nbr)
			return (0);
	return (1);
}

int main(int ac, char **av)
{
	int		size;
	int     i;
	int     temp;
	int		*nbr;

	if (ac > 1)
		size = atoi(av[1]);
	else
		size = 100;
	nbr = (int*)malloc(sizeof(int) * size);
	i = -1;
	srand(time(NULL));
	while (++i < size)
	{
		temp = rand();
		while (!is_in_array(nbr, temp, size))
			temp = rand() % 100000;
		nbr[i] = temp;
	}
	while (--i >= 0)
		printf("%d ", nbr[i]);
	printf("\n");
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:52:15 by atytaren          #+#    #+#             */
/*   Updated: 2016/11/26 22:16:35 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *strr)
{
	int		res;
	int		neg;
	int		fl;
	char	*str;

	res = 0;
	neg = 1;
	fl = 1;
	str = (char*)(strr - 1);
	while ((*(++str) <= '9' && *str >= '0') || ((*str == '\n'
		|| *str == '\t' || *str == ' ' || *str == '\r' || *str == '\f'
		|| *str == '\v' || *str == '+' || *str == '-') && fl))
	{
		if (*str == '\n' || *str == '\t' || *str == ' ' || *str == '\r'
			|| *str == '\f' || *str == '\v')
			continue ;
		if (*str == '-')
			neg = -1;
		if (*str <= '9' && *str >= '0')
			res = res * 10 + *str - 48;
		fl = 0;
	}
	return (res * neg);
}

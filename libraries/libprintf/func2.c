/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 14:57:54 by atytaren          #+#    #+#             */
/*   Updated: 2016/12/21 20:43:20 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_unsigned(t_param *p, va_list *a, char **s, int *pr)
{
	int							i;
	unsigned long long int		n;

	*pr = (p->w > p->p) ? p->w + 100 : p->p + 100;
	*s = get_empty(*pr * sizeof(char));
	i = *pr;
	if (p->m[0] == 'h' && p->tp == 'u')
		n = (p->m[1] == 'h') ? (unsigned char)va_arg(*a, unsigned int)
			: (S)va_arg(*a, unsigned int);
	else if (p->m[0] == 'l' || p->tp == 'U')
		n = (p->m[1] == 'l') ? va_arg(*a, unsigned long long int)
			: va_arg(*a, unsigned long int);
	else if (p->m[0] == 'L' || p->m[0] == 'j' || p->m[0] == 'z')
		n = (p->m[0] == 'L') ? va_arg(*a, __uint64_t) : va_arg(*a, uintmax_t);
	else
		n = va_arg(*a, unsigned int);
	while (!(!p->p && !n) && (!(*pr - i) || (n /= 10) != 0))
		(*s)[--i] = n % 10 + 48;
	while ((p->p > 0 && p->p > *pr - i) || (p->w > *pr - i && p->fl[0] == 48
		&& p->fl[3] != '-' && (p->p < 0 || p->p > *pr - i)))
		(*s)[--i] = 48;
	return (*pr - i);
}

int		p_to_oct(t_param *p, va_list *a, char **s, int *pr)
{
	int							i;
	unsigned long long int		n;

	*pr = (p->w > p->p) ? p->w + 100 : p->p + 100;
	*s = get_empty(*pr * sizeof(char));
	i = *pr;
	if (p->m[0] == 'l' || p->tp == 'O')
		n = (p->m[1] == 'l') ? va_arg(*a, ZL) : va_arg(*a, unsigned long int);
	else if (p->m[0] == 'h')
		n = (p->m[1] == 'h') ? (unsigned char)va_arg(*a, Z) : (K)va_arg(*a, Z);
	else if (p->m[0] == 'L' || p->m[0] == 'j' || p->m[0] == 'z')
		n = (p->m[0] == 'L') ? va_arg(*a, __uint64_t) : va_arg(*a, uintmax_t);
	else
		n = va_arg(*a, unsigned int);
	while ((p->p || n) && (!(*pr - i) || (n /= 8) > 0))
		(*s)[--i] = n % 8 + 48;
	p->n = *pr + ((p->fl[5] == 35) ? 1 : 0);
	while ((p->p > 0 && p->p > p->n - i) || (p->w > (p->n - i) && p->fl[0] == 48
		&& p->fl[3] != '-' && (p->p < 0 || p->p > p->n - i)))
		(*s)[--i] = 48;
	if (*pr - i > 1 || (*s)[*pr - 1] != '0')
		(*s)[--i] = (p->fl[5] == 35) ? '0' : (*s)[i++];
	return (*pr - i);
}

int		p_to_hex(t_param *p, va_list *a, char **s, int *pr)
{
	int							i;
	unsigned long long int		n;

	*pr = (p->w > p->p) ? p->w + 100 : p->p + 100;
	*s = get_empty(*pr * sizeof(char));
	if ((i = *pr) && p->m[0] == 'h')
		n = (p->m[1] == 'h') ? (unsigned char)va_arg(*a, Z) : (S)va_arg(*a, Z);
	else if (p->m[0] == 'l')
		n = (p->m[1] == 'l') ? va_arg(*a, ZL) : va_arg(*a, unsigned long int);
	else if (p->m[0] == 'L' || p->m[0] == 'j' || p->m[0] == 'z')
		n = (p->m[0] == 'L') ? va_arg(*a, __uint64_t) : va_arg(*a, uintmax_t);
	else
		n = va_arg(*a, unsigned int);
	while (p->p && (!(*pr - i) || (n /= 16) > 0))
		(*s)[--i] = (n % 16 > 9) ? n % 16 + p->tp - 33 : n % 16 + 48;
	p->n = *pr + ((p->fl[5] == 35) ? 2 : 0);
	while ((p->p > 0 && p->p > *pr - i) || (p->w > p->n - i && p->fl[0] == 48
		&& p->fl[3] != '-' && (p->p < 0 || p->p > p->n - i)))
		(*s)[--i] = 48;
	if (p->p && p->fl[5] == 35 && (*pr - i - 1))
	{
		(*s)[--i] = p->tp;
		(*s)[--i] = '0';
	}
	return (*pr - i);
}

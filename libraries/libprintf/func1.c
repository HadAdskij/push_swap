/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:20:37 by atytaren          #+#    #+#             */
/*   Updated: 2016/12/21 19:58:43 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_empty(size_t sz)
{
	char		*s;
	size_t		i;

	i = -1;
	s = (char*)malloc(sz * sizeof(char));
	while (++i < sz)
		s[i] = 0;
	return (s);
}

int		p_string(t_param *p, va_list *arg, char **s, int *pr)
{
	char	*str;
	int		len;
	int		coef;

	len = 0;
	coef = (p->tp == 'S' || p->m[0] == 'l') ? sizeof(wchar_t) : sizeof(char);
	if (p->tp != '%')
		str = va_arg(*arg, char*);
	if (p->tp == '%')
		str = "%";
	if (str == NULL)
		str = (coef == sizeof(char)) ? "(null)" : (char*)L"(null)";
	while (str[len * coef])
		len++;
	len = (p->tp == '%' || p->p < 0 || len < p->p) ? len : p->p;
	*s = get_empty(len * coef + 1);
	if (!len && (*pr = 1))
		return (0);
	*pr = -1;
	while (++(*pr) < len * coef)
		(*s)[*pr] = str[*pr];
	return (len);
}

int		p_pointer(t_param *p, va_list *arg, char **s, int *pr)
{
	long long int		i;
	unsigned long int	num;

	*pr = sizeof(void*) * 2 + 3 + p->p;
	*s = get_empty(*pr * sizeof(char));
	num = va_arg(*arg, long int);
	i = *pr;
	while (p->p && --i && (num || (*pr - i) == 1))
	{
		(*s)[i] = (num % 16 > 9) ? num % 16 + 87 : num % 16 + 48;
		num /= 16;
	}
	while (p->p > -1 && (*pr - i) <= p->p)
		(*s)[i--] = '0';
	while (p->p < 0 && p->w - 2 >= (*pr - i) && p->fl[0] == 48)
		(*s)[i--] = '0';
	(*s)[i--] = 'x';
	(*s)[i] = '0';
	return (*pr - i);
}

int		p_char(t_param *p, va_list *arg, char **s, int *pr)
{
	wchar_t		*wp;

	*pr = (p->m[0] == 'l' || p->tp == 'C') ? 4 : sizeof(char);
	*s = get_empty(*pr * sizeof(char));
	if (p->m[0] != 'l' && p->tp != 'C')
		(*s)[0] = (char)va_arg(*arg, int);
	else
	{
		wp = (wchar_t*)(*s);
		wp[0] = (wchar_t)va_arg(*arg, wint_t);
	}
	return (1);
}

int		p_signed(t_param *p, va_list *a, char **s, int *pr)
{
	int					i;
	long long int		n;

	*pr = (p->w > p->p) ? p->w + 100 : p->p + 100;
	*s = get_empty(*pr * sizeof(char));
	if ((i = *pr) > 0 && (p->m[0] == 'l' || p->tp == 'D'))
		n = (p->m[1] == 'l') ? va_arg(*a, long long int) : va_arg(*a, long int);
	else if (p->m[0] == 'h')
		n = (p->m[1] == 'h') ? (char)va_arg(*a, int) : (S)va_arg(*a, int);
	else if (p->m[0] == 'L' || p->m[0] == 'j' || p->m[0] == 'z')
		n = (p->m[0] == 'L') ? va_arg(*a, __int64_t) : va_arg(*a, intmax_t);
	else
		n = va_arg(*a, int);
	p->n = (n >= 0) ? 1 : -1;
	while (!(!n && !(p->p)) && (!(*pr - i) || (n /= 10) != 0))
		(*s)[--i] = (p->n > 0) ? n % 10 + 48 : -(n % 10) + 48;
	while ((p->p > 0 && p->p > *pr - i) || (p->w > *pr - i + 1
		&& p->fl[0] == 48 && p->fl[3] != '-' && (p->p < 0 || p->p > *pr - i)))
		(*s)[--i] = 48;
	if ((p->n > -1) && (p->fl[2] == 32 || p->fl[1] == 43))
		(*s)[--i] = (p->fl[1] == 43) ? 43 : 32;
	else if ((p->n < 0) || (p->p < 0 && p->w > *pr - i
		&& p->fl[3] != 45 && p->fl[0] == 48))
		(*s)[--i] = (p->n < 0) ? 45 : 48;
	return (*pr - i);
}

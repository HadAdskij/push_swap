/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:53:28 by atytaren          #+#    #+#             */
/*   Updated: 2016/12/21 20:54:54 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		(*g_f[53])(t_param*, va_list*, char**, int*);
int		g_ch;

void	initialize(void)
{
	g_f['s' % 54] = &p_string;
	g_f['%' % 54] = &p_string;
	g_f['S' % 54] = &p_string;
	g_f['p' % 54] = &p_pointer;
	g_f['c' % 54] = &p_char;
	g_f['C' % 54] = &p_char;
	g_f['d' % 54] = &p_signed;
	g_f['i' % 54] = &p_signed;
	g_f['D' % 54] = &p_signed;
	g_f['u' % 54] = &p_unsigned;
	g_f['U' % 54] = &p_unsigned;
	g_f['x' % 54] = &p_to_hex;
	g_f['X' % 54] = &p_to_hex;
	g_f['o' % 54] = &p_to_oct;
	g_f['O' % 54] = &p_to_oct;
}

int		freee(char *s)
{
	free(s);
	return (1);
}

int		print_spaces(t_param *p, va_list *arg, int i, int len)
{
	char	*s;
	int		print;

	len = g_f[p->tp % 54](p, arg, &s, &print);
	if ((p->tp == 'C' || p->tp == 'S' || (p->tp == 's' && p->m[0] == 'l'))
		&& *((Z*)s) > 255 && freee(s))
		return (-1);
	while (p->w > len && p->fl[3] != '-' && ++len)
		if (p->fl[0] == 48 && (p->tp == 's' || p->tp == 'S' || p->tp == '%'
			|| p->tp == 'c' || p->tp == 'C'))
			write(1, "0", 1);
		else
			write(1, " ", 1);
	while (p->tp != 'c' && s[i] == 0 && --print)
		i++;
	if (p->tp == 'S' || p->tp == 'C' || (p->tp == 's' && p->m[0] == 'l'))
		while (print--)
			if (s[i++] != 0)
				write(1, s + i - 1, 1);
	if (print)
		write(1, s + i, print);
	while ((p->w < 0 ? p->w * -1 : p->w) > len && ++len)
		write(1, " ", 1);
	free(s);
	return (len);
}

int		check_and_run(char *s, va_list *a, int sk, int ko)
{
	t_param		p;

	p.w = 0;
	while ((*++s == 45 || *s == 43 || *s == 32 || *s == 35 || *s == 48) && sk++)
		p.fl[*s % 6] = *s;
	while (((*s <= '9' && *s >= '0') || *s == '*') && sk++ && s++)
		p.w = (*(s - 1) != '*') ? p.w * 10 + *(s - 1) - 48 : va_arg(*a, int);
	if (!(p.p = 0) && *s == '.' && s++ && sk++)
		while (((*s <= '9' && *s >= '0') || *s == '*') && sk++)
			p.p = (*(s++) != '*') ? p.p * 10 + *(s - 1) - 48 : va_arg(*a, int);
	else
		p.p = -1;
	while ((*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z' || *s == 76)
		&& *(s - 1) < 104 && sk++ && (p.m[0] = *(s++)))
		if (*s == 'l' || *s == 'h' || *s == 'j')
			p.m[1] = *(s++) + sk++ * 0;
	if (!((*s == 65 || (*s < 69 && *s > 66) || *s == 83 || *s == 88 || *s == 97
		|| (*s > 98 && *s < 101) || *s == 105 || (*s < 113 && *s > 109)
		|| *s == 115 || *s == 117 || *s == 120 || *s == 85 || *s == 79
		|| *s == 37) && (p.tp = *s)))
		return (sk);
	ko = print_spaces(&p, a, 0, 0);
	if ((g_ch += ko) > -4555343 && ko == -1)
		return (-1);
	return (++sk);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		arg;
	int			jump;

	va_start(arg, format);
	initialize();
	g_ch = 0;
	while (*format)
	{
		jump = 0;
		if (*format == '%')
			jump += check_and_run((char*)format, &arg, 1, 0);
		if (jump == -1)
			return (-1);
		format += jump;
		if (jump)
			continue ;
		write(1, format, 1);
		g_ch++;
		format++;
	}
	va_end(arg);
	return (g_ch);
}

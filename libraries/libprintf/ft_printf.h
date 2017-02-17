/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atytaren <atytaren@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:51:07 by atytaren          #+#    #+#             */
/*   Updated: 2016/12/21 20:29:38 by atytaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# define S short int
# define K unsigned short int
# define Z unsigned int
# define ZL unsigned long long int
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

typedef struct		s_param
{
	char			fl[6];
	int				w;
	int				p;
	int				n;
	char			m[2];
	char			tp;
}					t_param;

int					ft_printf(const char *restrict format, ...);
int					p_string(t_param *p, va_list *arg, char **s, int *print);
int					p_pointer(t_param *p, va_list *arg, char **s, int *print);
int					p_char(t_param *p, va_list *arg, char **s, int *print);
int					p_signed(t_param *p, va_list *arg, char **s, int *print);
int					p_unsigned(t_param *p, va_list *arg, char **s, int *print);
int					p_to_hex(t_param *p, va_list *arg, char **s, int *print);
int					p_to_oct(t_param *p, va_list *arg, char **s, int *print);
char				*get_empty(size_t sz);
int					freee(char*s);

#endif

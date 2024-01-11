/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stribuzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:53:35 by stribuzi          #+#    #+#             */
/*   Updated: 2021/02/12 14:56:31 by stribuzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strlen_const(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_printabile	ft_fratm_grande_while_2(t_printabile p, va_list list)
{
	if (p.tipo == 'c')
		p = ft_fratm_char(p, list);
	if (p.tipo == 's')
		p = ft_fratm_string(p, list);
	else if (p.tipo == 'd' || p.tipo == 'i')
		p = ft_fratm_int(p, list);
	else if (p.tipo == 'X' || p.tipo == 'x')
		p = ft_fratm_hex(p, list);
	else if (p.tipo == 'u')
		p = ft_fratm_unsigned(p, list);
	else if (p.tipo == 'p')
		p = ft_fratm_pointer(p, list);
	else if (p.tipo == '%')
		p = ft_fratm_percent(p);
	return (p);
}

t_printabile	ft_fratm_grande_while(t_printabile p,
		const char *s, va_list list)
{
	p = ft_initialize(p);
	if (s[p.i] == '%' && s[p.i + 1] != '%')
	{
		p = ft_find_flags(p, s, p.i, list);
		p.tipo = ft_find_tipo(s, p.i);
		p.i += p.zompa;
		p = ft_fratm_grande_while_2(p, list);
	}
	else if (s[p.i] == '%' && s[p.i + 1] == '%')
		p = ft_fratm_percent(p);
	else
		p = ft_putchar_simple(p, s);
	return (p);
}

int				ft_parser(const char *s, va_list list)
{
	t_printabile	p;

	p.i = 0;
	p.contatore = 0;
	while (p.i < ft_strlen_const(s))
	{
		p = ft_fratm_grande_while(p, s, list);
		p.i++;
	}
	return (p.contatore);
}

int				ft_printf(char const *str, ...)
{
	int		to_return;
	va_list	arguments;

	va_start(arguments, str);
	to_return = ft_parser(str, arguments);
	va_end(arguments);
	return (to_return);
}

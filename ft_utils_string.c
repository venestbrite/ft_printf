/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stribuzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:29:32 by stribuzi          #+#    #+#             */
/*   Updated: 2021/02/10 11:50:30 by stribuzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	ft_fratm_string_handle_null(t_printabile p, int num_of_spaces)
{
	if (p.precision > 0 & p.width == -1)
		p = ft_print_support_until_prec(p, "(null)");
	else if (p.width != -1 && p.precision < 0)
	{
		if (p.minus == -1)
			p = ft_print_width_till_num_of_spaces(p, 6);
		p = putstr_contatore(p, "(null)");
		if (p.minus == 1)
			p = ft_print_width_till_num_of_spaces(p, 6);
	}
	else if (p.width != -1 && p.precision >= 0)
	{
		p.precision >= 6 ? num_of_spaces = 6 : p.precision * 1;
		p.precision < 6 ? num_of_spaces = p.precision : p.precision * 1;
		if (p.minus == -1)
			p = ft_print_width_till_num_of_spaces(p, num_of_spaces);
		p = ft_print_support_until_prec(p, "(null)");
		if (p.minus == 1)
			p = ft_print_width_till_num_of_spaces(p, num_of_spaces);
	}
	else
		p = putstr_contatore(p, "(null)");
	p.i++;
	return (p);
}

t_printabile	ft_fratm_string_support_1(t_printabile p, char *support)
{
	int	diff;

	if (p.width > p.precision && p.precision < ft_strlen(support))
	{
		if (p.minus == -1)
			p = ft_print_width_till_num_of_spaces(p, p.precision);
		p = ft_print_support_until_prec(p, support);
		if (p.minus == 1)
			p = ft_print_width_till_num_of_spaces(p, p.precision);
	}
	else
	{
		if (p.precision > ft_strlen(support))
			diff = p.width - ft_strlen(support);
		else
			diff = p.width - p.precision;
		if (p.minus == -1)
			p = ft_print_until_diff(p, diff, " ");
		p = ft_print_support_until_prec(p, support);
		if (p.minus == 1)
			p = ft_print_until_diff(p, diff, " ");
	}
	p.i++;
	return (p);
}

t_printabile	ft_fratm_string_support_2(t_printabile p, char *support)
{
	if (p.minus == -1)
		p = ft_print_width_till_num_of_spaces(p, ft_strlen(support));
	p = putstr_contatore(p, support);
	if (p.minus == 1)
		p = ft_print_width_till_num_of_spaces(p, ft_strlen(support));
	p.i++;
	return (p);
}

t_printabile	ft_fratm_string(t_printabile p, va_list list)
{
	char	*support;

	support = va_arg(list, char *);
	if (!support)
		return (p = ft_fratm_string_handle_null(p, 0));
	if (p.width != -1 && p.precision < 0)
		return (p = ft_fratm_string_support_2(p, support));
	else if (p.precision > 0 && p.width == -1)
	{
		p = ft_print_support_until_prec(p, support);
		p.i++;
		return (p);
	}
	else if (p.precision != -1 && p.width != -1)
		return (p = ft_fratm_string_support_1(p, support));
	else if (p.precision == 0 && p.width == -1)
		p = ft_print_width_till_num_of_spaces(p, 0);
	else
		p = putstr_contatore(p, support);
	p.i++;
	return (p);
}

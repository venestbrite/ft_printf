/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stribuzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:20:47 by stribuzi          #+#    #+#             */
/*   Updated: 2021/02/10 16:17:09 by stribuzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printabile	ft_hex_handle_zero_support_3(t_printabile p)
{
	p = ft_print_width_till_num_of_spaces(p, 0);
	p.i++;
	return (p);
}

t_printabile	ft_hex_helper_3(t_printabile p, char *support)
{
	int	diff;

	diff = p.width - p.precision;
	if (ft_strlen(support) > p.precision)
		diff = p.width - ft_strlen(support);
	if (p.minus == -1)
		p = ft_print_until_diff(p, diff, " ");
	while (p.precision > ft_strlen(support))
	{
		p = putstr_contatore(p, "0");
		p.precision--;
	}
	if (p.tipo == 'X' && support[0] != '0')
		p = putstr_contatore(p, support);
	else if (p.tipo == 'x' && support[0] != '0')
		p = putstr_contatore(p, ft_str_to_lower(support));
	else
		p = putstr_contatore(p, "0");
	if (p.minus == 1)
		p = ft_print_until_diff(p, diff, " ");
	p.i++;
	return (p);
}

t_printabile	ft_hex_handle_zero_support(t_printabile p)
{
	if (p.precision > 0 && p.width != -1)
	{
		p = ft_hex_helper_3(p, "0");
		p.i++;
		return (p);
	}
	else if (p.precision == 0 && p.width == -1)
	{
		p.i++;
		return (p);
	}
	else if (p.precision == 0 && p.width != -1)
	{
		p = ft_print_width_till_num_of_spaces(p, 0);
		p.i++;
		return (p);
	}
	return (p);
}

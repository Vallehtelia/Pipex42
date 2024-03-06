/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:18:41 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/24 13:18:43 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_format_check(va_list args, char spec, t_ret *ret)
{
	if (spec == 'c')
		ft_print_char(va_arg(args, int), ret);
	else if (spec == 's')
		ft_print_str(va_arg(args, char *), ret);
	else if (spec == 'p')
		ft_print_ptr(va_arg(args, unsigned long long), ret);
	else if (spec == 'd' || spec == 'i')
		ft_print_decimal(va_arg(args, int), ret);
	else if (spec == 'u')
		ft_print_unsigned_decimal(va_arg(args, unsigned int), ret);
	else if (spec == 'x')
		ft_print_hex_lower(va_arg(args, unsigned int), ret);
	else if (spec == 'X')
		ft_print_hex_upper(va_arg(args, unsigned int), ret);
	else if (spec == '%')
		ft_print_char('%', ret);
}

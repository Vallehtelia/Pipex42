/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:32:56 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/22 13:32:59 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	t_ret	ret;

	ret.output_count = 0;
	ret.error_return = 0;
	i = 0;
	va_start(args, s);
	while (s[i] && ret.error_return == 0)
	{
		if (s[i] == '%' && s[i + 1])
		{
			ft_format_check(args, s[i + 1], &ret);
			i++;
		}
		else
			ft_print_char(s[i], &ret);
		i++;
	}
	va_end(args);
	if (ret.error_return < 0)
		return (-1);
	return (ret.output_count);
}

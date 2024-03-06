/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:20:24 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/24 13:20:29 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_hex_lower(unsigned long long ptr, t_ret *ret)
{
	if (ptr > 15)
	{
		ft_print_hex_lower(ptr / 16, ret);
		ft_print_hex_lower(ptr % 16, ret);
	}
	else
	{
		if (ptr < 10)
			ft_print_char(ptr + '0', ret);
		else
			ft_print_char(ptr - 10 + 'a', ret);
	}
}

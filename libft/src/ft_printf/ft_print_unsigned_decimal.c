/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:19:45 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/24 13:19:47 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_unsigned_decimal(unsigned int c, t_ret *ret)
{
	if (c > 9)
	{
		ft_print_unsigned_decimal(c / 10, ret);
		ft_print_unsigned_decimal(c % 10, ret);
	}
	else
		ft_print_char(c + '0', ret);
}

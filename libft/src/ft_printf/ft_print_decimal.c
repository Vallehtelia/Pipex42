/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:21:08 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/24 13:21:10 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_decimal(long long nbr, t_ret *ret)
{
	if (nbr < 0)
	{
		ft_print_char('-', ret);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_print_decimal(nbr / 10, ret);
		ft_print_decimal(nbr % 10, ret);
	}
	else
		ft_print_char(nbr + '0', ret);
}

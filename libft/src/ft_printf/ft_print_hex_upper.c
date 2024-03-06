/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:20:49 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/24 13:20:51 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_hex_upper(unsigned int nbr, t_ret *ret)
{
	if (nbr > 15)
	{
		ft_print_hex_upper(nbr / 16, ret);
		ft_print_hex_upper(nbr % 16, ret);
	}
	else
	{
		if (nbr < 10)
			ft_print_char(nbr + '0', ret);
		else
			ft_print_char(nbr - 10 + 'A', ret);
	}
}

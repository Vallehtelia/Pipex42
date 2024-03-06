/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:20:07 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/24 13:20:08 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_ptr(unsigned long long ptr, t_ret *ret)
{
	ft_print_str("0x", ret);
	if (ptr == 0)
		ft_print_char('0', ret);
	else
		ft_print_hex_lower(ptr, ret);
}

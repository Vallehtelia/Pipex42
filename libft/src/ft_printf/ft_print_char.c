/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:19:05 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/24 13:19:07 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_char(int c, t_ret *ret)
{
	if (ret->error_return < 0)
		return ;
	if (write(1, &c, 1) < 0)
		ret->error_return = -1;
	else
		ret->output_count++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:19:22 by vvaalant          #+#    #+#             */
/*   Updated: 2023/11/24 13:19:24 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_print_str(char *s, t_ret *ret)
{
	if (s == NULL)
		ft_print_str("(null)", ret);
	else
	{
		while (*s)
		{
			ft_print_char(*s, ret);
			s++;
		}
	}
}

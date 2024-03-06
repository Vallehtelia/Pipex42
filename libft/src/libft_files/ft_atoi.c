/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:03:34 by vvaalant          #+#    #+#             */
/*   Updated: 2023/10/24 17:04:45 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../inc/libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int long	num;
	int			neg;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (LONG_MAX / 10) + (str[i] - 48) && num > 0)
			return (-1);
		if (num > (LONG_MAX / 10) + (str[i] - 48) && num < 0)
			return (0);
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

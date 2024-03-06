/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:14:08 by vvaalant          #+#    #+#             */
/*   Updated: 2023/10/31 14:14:21 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			pos;
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	pos = 0;
	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	while (n > pos)
	{
		if (s1ptr[pos] != s2ptr[pos])
		{
			return (s1ptr[pos] - s2ptr[pos]);
		}
		else
		{
			pos++;
		}
	}
	return (0);
}

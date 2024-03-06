/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:56:51 by vvaalant          #+#    #+#             */
/*   Updated: 2023/10/31 13:57:15 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			pos;

	ptr = (unsigned char *)s;
	pos = 0;
	while (n > pos)
	{
		if (ptr[pos] == (unsigned char)c)
		{
			return ((void *)&ptr[pos]);
		}
		pos++;
	}
	return (NULL);
}

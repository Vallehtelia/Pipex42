/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:04 by vvaalant          #+#    #+#             */
/*   Updated: 2023/10/26 12:38:06 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest < source || dest >= (source + len))
	{
		while (len--)
		{
			*dest++ = *source++;
		}
	}
	else
	{
		dest = dest + len;
		source = source + len;
		while (len--)
		{
			*--dest = *--source;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:20:38 by vvaalant          #+#    #+#             */
/*   Updated: 2023/10/26 11:25:45 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n > i)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

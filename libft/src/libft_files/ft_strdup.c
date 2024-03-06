/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:25:02 by vvaalant          #+#    #+#             */
/*   Updated: 2023/10/31 19:25:10 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	char		*cpy;
	int			strlen;

	strlen = 0;
	while (s1[strlen] != '\0')
		strlen++;
	ptr = malloc(strlen + 1);
	if (ptr == NULL)
		return (NULL);
	cpy = ptr;
	while (*s1)
	{
		*cpy = *s1;
		cpy++;
		s1++;
	}
	*cpy = '\0';
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:24:34 by vvaalant          #+#    #+#             */
/*   Updated: 2023/10/31 13:24:37 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		strpos;

	ptr = NULL;
	strpos = 0;
	while (s[strpos])
	{
		if (s[strpos] == (char)c)
		{
			ptr = (char *)&s[strpos];
		}
		strpos++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[strpos]);
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:07:14 by vvaalant          #+#    #+#             */
/*   Updated: 2024/02/21 23:03:30 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
- Joins 2 strings to 1 string and returns pointer to it.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	strlen1;
	size_t	strlen2;

	if (!s1 || !s2)
		return (NULL);
	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	ptr = malloc((strlen1 + strlen2) + 1);
	if (ptr == NULL)
		return (NULL);
	strlen1 = 0;
	strlen2 = 0;
	while (s1[strlen1])
	{
		ptr[strlen1] = s1[strlen1];
		strlen1++;
	}
	while (s2[strlen2])
		ptr[strlen1++] = s2[strlen2++];
	ptr[strlen1] = '\0';
	return (ptr);
}

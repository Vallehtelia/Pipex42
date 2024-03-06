/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:30:29 by vvaalant          #+#    #+#             */
/*   Updated: 2024/01/30 13:27:49 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line_bonus.h"

size_t	strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (!*s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*is_newline(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (buff == NULL)
		return (NULL);
	if (left_str == NULL)
	{
		left_str = (char *)malloc(1);
		if (left_str == NULL)
			return (NULL);
		left_str[0] = '\0';
	}
	str = malloc(sizeof(char) * ((strlen(left_str) + (strlen(buff)) + 1)));
	if (str == NULL)
		return (ft_free(&left_str));
	i = -1;
	j = 0;
	while (left_str && left_str[++i] != '\0')
		str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(left_str);
	return (str);
}

char	*fetch_line(char *left_str)
{
	int		i;
	int		line_l;
	char	*str;

	i = 0;
	if (left_str == NULL)
		return (NULL);
	line_l = line_length(left_str);
	str = (char *)malloc(line_l + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_left_str(char *left_str)
{
	int		remaining_len;
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		return (NULL);
	}
	remaining_len = strlen(left_str) - i;
	str = (char *)malloc(remaining_len + 1);
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	return (str);
}

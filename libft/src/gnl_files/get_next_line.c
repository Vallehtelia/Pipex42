/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:30:07 by vvaalant          #+#    #+#             */
/*   Updated: 2024/01/30 13:28:11 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (ft_free(&left_str));
	left_str = read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = fetch_line(left_str);
	if (!line)
		return (ft_free(&left_str));
	temp = new_left_str(left_str);
	if (left_str != temp)
	{
		free(left_str);
		left_str = NULL;
	}
	left_str = temp;
	return (line);
}

char	*read_to_left_str(int fd, char *left_str)
{
	char	*buf;
	int		rd_bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free(&left_str));
	rd_bytes = 1;
	while (is_newline(left_str) == NULL && rd_bytes != 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		left_str = strjoin(left_str, buf);
	}
	free(buf);
	if (rd_bytes == 0 && (!left_str || !*left_str))
		return (ft_free(&left_str));
	return (left_str);
}

int	line_length(char *left_str)
{
	int	len;

	if (left_str == NULL)
		return (0);
	len = 0;
	while (left_str[len] && left_str[len] != '\n')
		len++;
	if (left_str[len] == '\n')
		return (len + 1);
	else
		return (len);
}

char	*ft_free(char **dump)
{
	free(*dump);
	*dump = NULL;
	return (NULL);
}

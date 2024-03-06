/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:30:46 by vvaalant          #+#    #+#             */
/*   Updated: 2023/12/01 13:30:48 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*read_to_left_str(int fd, char *left_str);
char	*is_newline(const char *s);
char	*strjoin(char *left_str, char *buff);
size_t	strlen(const char *s);
char	*fetch_line(char *left_str);
char	*new_left_str(char *line);
int		line_length(char *left_str);
char	*ft_free(char **dump);

#endif

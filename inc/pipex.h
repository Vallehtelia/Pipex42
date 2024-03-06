/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:54:00 by vvaalant          #+#    #+#             */
/*   Updated: 2024/03/06 22:52:18 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"

# define MAX_ARGS 4

int		main(int ac, char **av, char **envp);

/* runs different process */
void	parent_process(char **av, char **envp, int *fd);
void	child_process(char **av, char **envp, int *fd);
void	read_limited_urandom_data(int output_fd);

char	*find_path(char *cmd, char **envp, int i);
void	execute(char *av, char **envp);
void	error_str(char *av, int n);

char	**parse_command(const char *cmd);

#endif

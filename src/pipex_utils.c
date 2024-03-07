/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:21:26 by vvaalant          #+#    #+#             */
/*   Updated: 2024/03/07 15:25:58 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
- Searches path from environment variables and returns path to given command.
*/
char	*find_path(char *cmd, char **envp, int i)
{
	char	**paths;
	char	*path;
	char	*part_path;

	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free (path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free (paths[i]);
	free(paths);
	return (0);
}

/*
- Splits command to array and finds path for command.
	Then passes command to execve to run first command or program.
*/
void	execute_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = parse_command(av);
	path = find_path(cmd[0], envp, 0);
	if (!path)
	{
		if (access(cmd[0], X_OK) == 0)
			path = cmd[0];
		else
		{
			while (cmd[i])
			{
				free(cmd[i]);
				i++;
			}
			free(cmd);
			error_str(av, 1);
			exit (127);
		}
	}
	if (execve(path, cmd, envp) == -1)
		exit(1);
}

/*
- Prints error for command not found as stderr.
*/
void	error_str(char *av, int n)
{
	if (n == 1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(av, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

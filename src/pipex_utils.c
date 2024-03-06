/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:21:26 by vvaalant          #+#    #+#             */
/*   Updated: 2024/03/05 23:46:19 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
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

void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = parse_command(av);
	path = find_path(cmd[0], envp);
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

static const char	*skip_spaces(const char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

char	**parse_command(const char *cmd)
{
	char		**args;
	char		*arg;
	int			i;
	int			j;
	const char	*start;
	char		quote;

	args = malloc(MAX_ARGS * sizeof(char *));
	i = 0;
	while (*cmd != '\0' && i < MAX_ARGS - 1)
	{
		cmd = skip_spaces(cmd);
		arg = malloc(ft_strlen(cmd) + 1);
		j = 0;
		start = cmd;
		if (*cmd == '\'' || *cmd == '"')
		{
			quote = *cmd++;
			while (*cmd != quote && *cmd != '\0')
				arg[j++] = *cmd++;
			if (*cmd == quote)
				cmd++;
		}
		else
		{
			while (*cmd != ' ' && *cmd != '\0')
				arg[j++] = *cmd++;
		}
		arg[j] = '\0';
		if (j > 0)
			args[i++] = arg;
		else
			free(arg);
		cmd = skip_spaces(cmd);
	}
	args[i] = NULL;
	return (args);
}

void	error_str(char *av, int n)
{
	if (n == 1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(av, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

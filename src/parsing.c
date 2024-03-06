/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:38:13 by vvaalant          #+#    #+#             */
/*   Updated: 2024/03/06 22:52:16 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static const char	*skip_spaces(const char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

static char	*copy_arg(const char *cmd, char **arg_out, int j, char quote)
{
	char		*arg;

	arg = malloc(ft_strlen(cmd) + 1);
	if (!arg)
		return (NULL);
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
		{
			if (*cmd == '\\' && (*(cmd + 1) == '\'' || *(cmd + 1) == '"'))
				cmd++;
			arg[j++] = *cmd++;
		}
	}
	arg[j] = '\0';
	*arg_out = arg;
	return ((char *)cmd);
}

char	**parse_command(const char *cmd)
{
	char		**args;
	char		*arg;
	int			i;
	const char	*next_cmd;

	args = malloc(MAX_ARGS * sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	while (*cmd != '\0' && i < MAX_ARGS - 1)
	{
		cmd = skip_spaces(cmd);
		next_cmd = copy_arg(cmd, &arg, 0, 0);
		if (arg && *arg)
			args[i++] = arg;
		else
			free(arg);
		cmd = next_cmd;
	}
	args[i] = NULL;
	return (args);
}

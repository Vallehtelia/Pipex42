/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:06:12 by vvaalant          #+#    #+#             */
/*   Updated: 2024/03/06 22:52:17 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	read_limited_urandom_data(int output_fd)
{
	int		urandom_fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	urandom_fd = open("/dev/urandom", O_RDONLY);
	if (urandom_fd < 0)
	{
		perror("Failed to open /dev/urandom");
		exit(EXIT_FAILURE);
	}
	bytes_read = read(urandom_fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		perror("Failed to read from /dev/urandom");
		close(urandom_fd);
		exit(EXIT_FAILURE);
	}
	write(output_fd, buffer, bytes_read);
	close(urandom_fd);
}

void	child_process(char **av, char **envp, int *fd)
{
	int	filein;

	if (ft_strncmp(av[1], "/dev/urandom", 13) == 0)
	{
		read_limited_urandom_data(fd[1]);
		close(fd[1]);
	}
	else
	{
		filein = open(av[1], O_RDONLY, 0666);
		if (filein == -1)
		{
			perror("pipex: input");
			exit(0);
		}
		dup2(fd[1], STDOUT_FILENO);
		dup2(filein, STDIN_FILENO);
		close(filein);
	}
	close(fd[0]);
	close(fd[1]);
	execute(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fileout == -1)
		exit(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	close(fd[1]);
	close(fd[0]);
	execute(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int		fd[2];
	char	*default_envp[2];

	default_envp[0] = "PATH=/bin:/usr/bin";
	default_envp[1] = NULL;
	if (envp == NULL || envp[0] == NULL)
		envp = default_envp;
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
		{
			child_process(av, envp, fd);
		}
		parent_process(av, envp, fd);
		waitpid(pid, NULL, 0);
	}
	else
		exit(1);
	return (0);
}

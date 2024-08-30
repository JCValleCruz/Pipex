/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:23:14 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/29 20:44:43 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_childprocess(int fd[2], char **argv, char **envp)
{
	int	infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror("Input file was corrupt.");
		exit(1);
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("Dump from file was wrong.");
		exit(1);
	}
	close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("Dump to file was wrong.");
		exit(1);
	}
	close(fd[1]);
	ft_exec_cmd(argv[2], envp);
}

void	ft_parentprocess(int fd[2], char **argv, char **envp)
{
	int	outfile;

	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Dump from file was wrong.");
		exit(1);
	}
	close(fd[0]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("Output file was corrupt.");
		exit(1);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("Dump to file was wrong.");
		exit(1);
	}
	close(outfile);
	ft_exec_cmd(argv[3], envp);
}

void	ft_exec_cmd(char *argv, char **envp)
{
	char	**cmdwithparams;
	char	*path;

	cmdwithparams = ft_split(argv, ' ');
	if (cmdwithparams == NULL)
	{
		perror("Wrong command.");
		exit(-1);
	}
	path = ft_get_path(cmdwithparams[0], envp);
	if (path == NULL)
	{
		ft_free_split(cmdwithparams);
		perror("Command not found.");
		exit(127);
	}
	if (execve(path, cmdwithparams, envp) == -1)
	{
		free(path);
		ft_free_split(cmdwithparams);
		perror("Execve was wrong.");
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;

	if (argc != 5)
		return (ft_no_enough_args());
	if (pipe(fd) == -1)
	{
		perror("Pipe was not created correctly.");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork was not created correctly.");
		exit(1);
	}
	if (pid == 0)
		ft_childprocess(fd, argv, envp);
	else
		ft_parentprocess(fd, argv, envp);
	wait(NULL);
	return (0);
}

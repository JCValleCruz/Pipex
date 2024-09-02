/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:53:26 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/09/02 19:04:01 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_relative_path(char *cmd, char **envp, char *envp_var)
{
	char	**possible_paths;
	int		i;
	char	*path;
	char	*temp;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], envp_var, ft_strlen(envp_var)) == 0)
			break ;
	}
	possible_paths = ft_split(envp[i] + ft_strlen(envp_var), ':');
	i = -1;
	while (possible_paths[++i])
	{
		temp = ft_strjoin(possible_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	ft_free_split(possible_paths);
	return (path);
}
char	*ft_get_path(char *cmd, char **envp)
{
	char	*full_path;

	full_path = ft_get_relative_path(cmd, envp, "PATH=");
	if (!full_path)
		full_path = ft_get_relative_path(cmd, envp, "PWD=");
	return (full_path);
}
void	ft_free_split(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}
int	ft_no_enough_args(void)
{
	write(1, "The number of args must be 5.", 29);
	exit(1);
}

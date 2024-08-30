/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:21:55 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/29 18:24:33 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "Libft/libft.h"

int		ft_no_enough_args(void);
void	ft_free_split(char **split);
void	ft_childprocess(int *fd, char **argv, char **envp);
void	ft_parentprocess(int *fd, char **argv, char **envp);
char	*ft_get_path(char *cmd, char **envp);
char	*ft_get_relative_path(char *cmd, char **env, char *env_var);
void	ft_exec_cmd(char *argv, char **envp);
#endif

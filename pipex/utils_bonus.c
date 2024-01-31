/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:08:33 by cliew             #+#    #+#             */
/*   Updated: 2024/01/31 19:37:27 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*check_path(char **envp)

{
	while (*envp++ != NULL)
	{
		if (ft_strnstr(*envp, "PATH=", 5) != NULL)
		{
			return (*(envp));
		}
	}
	return (NULL);
}

char	*locate_cmd(char **paths, char *cmd)
{
	char	*_cmd;
	char	*cmd_path;

	if (access(cmd, X_OK) >= 0)
		return (ft_strdup(cmd));
	_cmd = ft_strjoin("/", cmd);
	cmd_path = NULL;
	while (paths && *paths)
	{
		cmd_path = ft_strjoin(*paths, _cmd);
		if (access(cmd_path, X_OK) >= 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		paths++;
	}
	free(_cmd);
	return (cmd_path);
}

char	*find_env_path(char **envp)
{
	while (envp && *envp)
	{
		if (strncmp(*envp, "PATH=", 5) == 0)
		{
			return (ft_strdup(&(*envp)[5]));
		}
		envp++;
	}
	return (NULL);
}

void	free_array(char **v)
{
	char	**p;

	if (!v)
		return ;
	p = v;
	while (*v)
	{
		free(*v);
		v++;
	}
	free(p);
}

char	**find_cmd_paths(char **envp)
{
	char	**paths;
	char	*path;

	path = find_env_path(envp);
	paths = ft_split(path, ':');
	if (path)
		free(path);
	return (paths);
}

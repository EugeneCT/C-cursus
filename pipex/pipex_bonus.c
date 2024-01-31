/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:17:01 by cliew             #+#    #+#             */
/*   Updated: 2024/02/01 07:56:44 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_split_cmd_args(char *s)
{
	int		size;
	char	*p;
	char	**cmd_args;

	if (s == NULL || *s == 0)
		return (NULL);
	p = s;
	while (*p && *p != ' ')
		p++;
	if (*p == 0)
		size = 2;
	else
		size = 3;
	cmd_args = (char **)malloc(size * sizeof(char *));
	cmd_args[size - 1] = 0;
	cmd_args[0] = ft_strndup(s, p - s);
	if (*p && p[1])
		cmd_args[1] = ft_strdup_ignore(p + 1, '"');
	return (cmd_args);
}

int	run_cmd(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_name;
	char	*cmd_path;
	char	**paths;
	int		status;

	paths = find_cmd_paths(envp);
	cmd_args = ft_split_cmd_args(cmd);
	cmd_name = cmd_args[0];
	cmd_path = locate_cmd(paths, cmd_name);
	free_array(paths);
	status = 0;
	if (cmd_path)
	{
		status = execve(cmd_path, cmd_args, envp);
	}
	else
	{
		status = 127;
		return (ft_puterr(ERR_INVALID_CMD, 127));
	}
	free(cmd_path);
	free_array(cmd_args);
	return (status);
}

int	execute_command(int prev_pipe, int pipefd[2], char *cmd, char *envp[])
{
	int		status;
	pid_t	pid;

	status = 0;
	if (pipe(pipefd) < 0)
		return (write(STDOUT_FILENO, "Error creating pipe\n", 20));
	pid = fork();
	if (pid < 0)
		return (write(STDOUT_FILENO, "Error forking\n", 15));
	if (pid == 0)
	{
		if (prev_pipe != STDIN_FILENO)
		{
			dup2(prev_pipe, STDIN_FILENO);
			close(prev_pipe);
		}
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		status = run_cmd(cmd, envp);
		_exit(status);
	}
	close(prev_pipe);
	close(pipefd[1]);
	return (pid);
}

int	pipex(t_in in)
{
	int	status;
	int	i;
	int	prev_pipe;

	status = 0;
	i = 2;
	prev_pipe = in.fin;
	while (i < (in.argc - 2))
	{
		status = execute_command(prev_pipe, in.pipefd, in.argv[i], in.envp);
		prev_pipe = in.pipefd[0];
		i++;
		if (status < 0)
			exit(-1);
	}
	waitpid(0, NULL, WNOHANG | WUNTRACED);
	if (prev_pipe != STDIN_FILENO)
	{
		dup2(prev_pipe, STDIN_FILENO);
		dup2(in.fout, STDOUT_FILENO);
	}
	status = run_cmd(in.argv[i], in.envp);
	close(in.fin);
	close(in.fout);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_in	in;
	int		status;

	if (argc < 5)
		return (ft_puterr(ERR_INVALID_PARAMS, 1));
	in.fin = open(argv[1], O_RDONLY);
	if (in.fin < 0)
	{
		perror("pipex: input file:" );
		return (0);
	}
	in.fout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (in.fout < 0)
	{
		perror("pipex : output file: ");
		return (1);
	}
	in.argv = argv;
	in.envp = envp;
	in.argc = argc;
	status = pipex(in);
	return (status);
}

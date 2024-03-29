/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:17:01 by cliew             #+#    #+#             */
/*   Updated: 2024/03/13 23:00:16 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
char* join_name_and_args(Command* cmd) {
    char* joined_str = strdup(cmd->name); // Duplicate name
    if (joined_str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < cmd->arg_count; ++i) {
        char* temp = ft_strjoin(joined_str," ");
		temp = ft_strjoin(temp, cmd->args[i]);

        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        free(joined_str);
        joined_str = temp;
    }

    return joined_str;
}
int	run_cmd(Command *command, char **envp,t_shell* shell)
{
	char	**cmd_args;
	// char	*cmd_name;
	char	*cmd_path;
	char	**paths;
	int		status;

	paths = find_cmd_paths(envp);
	cmd_path = locate_cmd(paths, command->name);
	free_array(paths);

	cmd_args = ft_split_cmd_args(join_name_and_args(command));
	// cmd_name = cmd_args[0];

	status = 0;

	// ft_printf("Executing command: %s arg count %d\n", command->name, command->arg_count);
    // Example stubs for calling built-in commands
    if (ft_strcmp(command->name, "cd") == 0) {
        // Call built-in cd command
        // Assuming the path is the first argument: command->args[1]
        builtin_cd(shell, command->args, command->arg_count);
    } else if (ft_strcmp(command->name, "pwd") == 0) {
        // Call built-in pwd command
        builtin_pwd();
    } else if (ft_strcmp(command->name, "echo") == 0) {
        // Call built-in echo command
		// ft_printf("Executing builtin_echo\n");
		// ft_printf("%s\n", command->args[0]);
        builtin_echo(shell, command->args, command->arg_count);
    } else if (ft_strcmp(command->name, "unset") == 0) {
		// Call built-in unset command
		// Assuming the variable name is the first argument: command->args[1]
		if (command->arg_count > 1) builtin_unset(command->args[1]);
	} else if (ft_strcmp(command->name, "export") == 0) {
		// Call built-in export command
		// Assuming the variable name is the first argument and the value is the second argument
		if (command->arg_count > 1) builtin_export(command->args[1], command->args[2]);
    } else if (ft_strcmp(command->name, "env") == 0) {
		// Call built-in env command
		builtin_env();
    } else if (ft_strcmp(command->name, "exit") == 0) {
        // Call built-in exit command
        builtin_exit(shell, command->args, command->arg_count);
    } else if (cmd_path)
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

// int	execute_command_pipex(int prev_pipe,int fin,int fout, int pipefd[2], char *cmd, char *envp[])

int	execute_command_pipex(int prev_pipe,Command *cmd, t_in in, t_shell *shell)
{
	int		status;
	pid_t	pid;
	status = 0;
	if (pipe(in.pipefd) < 0)
		return (write(STDOUT_FILENO, "Error creating pipe\n", 20));
	pid = fork();
	if (pid < 0)
		return (write(STDOUT_FILENO, "Error forking\n", 15));
	if (pid == 0)
	{

		if (cmd->fin == -99 && prev_pipe != STDIN_FILENO )
		{
			dup2(prev_pipe, STDIN_FILENO);
			close(prev_pipe);
		}
		if (cmd->fout ==  -99)
			dup2(in.pipefd[1], STDOUT_FILENO);
		close(in.pipefd[0]);
		close(in.pipefd[1]);

		status = run_cmd(cmd, in.envp,shell);

		_exit(status);
	}

	close(prev_pipe);
	close(in.pipefd[1]);
	return (pid);
}

int pipex(t_in in,Command *cmd,t_shell *shell) {
	int status;
	int prev_pipe;
	// char* joined;
	status = 0;
	prev_pipe = cmd->fin;
	while (cmd->next) {
		// joined=ft_strjoin_nconst(cmd->name,cmd->args[0]);
		if (cmd->fin==-99)
		{
			prev_pipe = in.pipefd[0];
			dup2(prev_pipe, STDIN_FILENO);

		}
		
		// status = execute_command_pipex(prev_pipe,cmd.fin,cmd.fout, in.pipefd, joined, in.envp);
		status = execute_command_pipex(prev_pipe,cmd,in ,shell);

		prev_pipe = in.pipefd[0];
		if (status < 0)
			exit(-1);
		waitpid(0, NULL, WUNTRACED);

		*cmd = *(cmd->next);
	}

	waitpid(0, NULL, WNOHANG | WUNTRACED);
	// joined=ft_strjoin_nconst(cmd.name,cmd.args[0]);
	status = run_cmd(cmd, in.envp,shell);
	close(in.fin);
	close(in.fout);

	return status;
}


// Current state of pipes
// Initiialize t_in structure for the following 3
// in.argv = argv;
// 	in.envp = envp;
// 	in.argc = argc;
//  Pass in pointer to the first cmd in cmd table.
// Needed parameter in cmd table 

//     cmd1.name = "echo";
//     cmd1.args = (char*[]){ " hello", NULL}; // Note: args should be an array of strings
//     cmd1.fin = 0;
//     cmd1.fout = -99;
//     
//    fin and fout is the fd_in and fd_out. if 0, means theres no redirection (\n case). if -99, means theres pipe)
//    eg. if cmd1 | cmd2\ncmd3
//    then 
//          cmd1.fin  = 0;
//          cmd1.fout = -99;
//          cmd2.fin  = -99
//          cmd2.fout = 0;
//          cmd3.fin =  0; 
//          cmd3.fout  = 0;



//--------------------------------------------------------------------------
// int	main(int argc, char **argv, char **envp)
// // int	main()x`

// {
// 	t_in	in;
// 	int		status;

// 	Command cmd1;
// 	Command cmd2;
// 	Command cmd3;

//     // Initialize cmd1
//     cmd1.name = "echo";
//     cmd1.args = (char*[]){ " hello", NULL}; // Note: args should be an array of strings
//     cmd1.fin = 0;
//     cmd1.fout = -99;

// 	// cmd1.name = "echo";
//     // cmd1.args = (char*[]){ " hello", NULL}; // Note: args should be an array of strings
//     // cmd1.fin = 0;
//     // cmd1.fout = 0;

//     // // Initialize cmd2
//     // cmd2.name = "echo";
//     // cmd2.args = (char*[]){" world is great", NULL}; // Note: args should be an array of strings
//     // cmd2.fin = 0;
//     // cmd2.fout = -99;

// 	//    // Initialize cmd2
//     cmd2.name = "wc";
//     cmd2.args = (char*[]){"", NULL}; // Note: args should be an array of strings
//     cmd2.fin = -99;
//     cmd2.fout = 0;



// 	// cmd3.name= "wc";
//     // cmd3.args = (char*[]){" ", NULL}; // Note: args should be an array of strings
// 	// cmd3.fin=-99;
// 	// cmd3.fout=0;

// 	cmd3.name= "echo";
//     cmd3.args = (char*[]){" lalala", NULL}; // Note: args should be an array of strings
// 	cmd3.fin=0;
// 	cmd3.fout=0;


// 	// cmd3.name="wc";
// 	// cmd3.args='\0';
// 	// cmd3.fin=-99;
// 	// cmd3.fout=0;

// 	cmd1.next = &cmd2;
//     cmd2.next = &cmd3;
//     cmd3.next = NULL;
	
// 	printf("Command 1: %s %s\n", cmd1.name, cmd1.args[0]);

// 	// if (argc < 5)
// 	// 	return (ft_puterr(ERR_INVALID_PARAMS, 1));


// 	// if (ft_strcmp(argv[1],"no")==0)
// 	// 	in.fin=99;
// 	// else
// 	// 	in.fin = open(argv[1], O_RDONLY);
// 	// if (in.fin < 0)
// 	// {
// 	// 	perror("pipex: input file:" );
// 	// 	return (0);
// 	// }
// 	// if (ft_strcmp(argv[argc-1],"no")==0)
// 	// 	in.fout=99;
// 	// else
// 	// 	in.fout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	// if (in.fout < 0)
// 	// {
// 	// 	perror("pipex : output file: ");
// 	// 	return (1);
// 	// }
// 	in.argv = argv;
// 	in.envp = envp;
// 	in.argc = argc;
// 	status = pipex(in,cmd1);
// 	return (status);
// }


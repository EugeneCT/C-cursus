/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtincommands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:10:58 by vitenner          #+#    #+#             */
/*   Updated: 2024/02/23 14:25:23 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char* get_home_directory()
{
    return getenv("HOME");
}

// Function to change the directory
int change_directory(char* path) {
    return chdir(path);
}

// The main cd function
void builtin_cd(t_shell * shell, char** args, int n_args)
{
    char* path; // Path to change to

    if (n_args == 0)
	{
		// ft_printf("n_args = 0\n");
        // If no arguments, change to the home directory
        path = get_home_directory();
        if (path == NULL) {
            fprintf(stderr, "cd: HOME not set\n");
            return;
        }
    }
	else if (n_args == 1)
	{
        path = args[0];
		// Attempt to change the directory
		if (change_directory(path) != 0)
			// If changing the directory fails, print an error message
			perror("cd");
	}
    else
	{
		perror("bash: cd: too many arguments\n");
		shell->last_exit_status = 1;
	}
        // Use the first argument as the path

}

// Prints the current working directory to stdout.
void builtin_pwd(void)
{
    char *pwd;
    pwd = getcwd(NULL, 0); // Dynamically allocate buffer size
    if (pwd != NULL) {
        ft_printf("%s\n", pwd);
        free(pwd); // Remember to free the memory allocated by getcwd
    } else {
        // Handle error, for example, if getcwd failed
        perror("pwd: error");
    }
}

// Prints the given arguments to stdout, handling the `-n` option to not output the trailing newline.
void builtin_echo(t_shell *shell, char** args, int n_args)
{
	int i = 0;
	int newline = 1;
	// ft_printf("builtin_echo n_args %d\n", n_args);
	// ft_printf("%s\n", args[0]);
	if (n_args > 1 && strcmp(args[0], "-n") == 0)
	{
		// ft_printf("found -n\n");
		newline = 0;
		i++;
	}
	while (i < n_args)
	{
		ft_printf("%s", args[i]);
		if (i < n_args - 1)
			ft_printf(" ");
		i++;
	}
	if (newline)
		ft_printf("\n");
	(void)shell;
    // shell->last_exit_status = 777;
}

// Sets or exports an environment variable with the given name to the given value.
void builtin_export(char* variable, char* value)
{
	if (setenv(variable, value, 1) == -1) {
		perror("export");
	}
}

// Removes the environment variable with the given name from the shell's environment.
void builtin_unset(char* variable)
{
	if (unsetenv(variable) == -1) {
		perror("unset");
	}
}

// Lists all environment variables to stdout.
void builtin_env(void)
{
	extern char** environ;
	for (char** env = environ; *env != NULL; env++)
		ft_printf("%s\n", *env);
}

int adjust_exit_code(int n)
{
    // If n is higher than 255, subtract 256 until it's not
    while (n > 255) {
        n -= 256;
    }

    // If n is lower than 0, add 256 until it's between 0 and 255
    while (n < 0) {
        n += 256;
    }

    return n;
}

int is_valid_number(const char *str)
{
    // Check if the string is empty
    if (!str || *str == '\0') {
        return 0; // Not a valid number
    }

    // Check if the first character is +, -, or a digit
    if (*str != '+' && *str != '-' && !ft_isdigit(*str)) {
        return 0; // Not a valid number
    }

    // Move to the next character
    str++;

    // Check that every other character is a digit
    while (*str != '\0') {
        if (!ft_isdigit(*str)) {
            return 0; // Not a valid number
        }
        str++;
    }

    return 1; // Valid number
}

// Exits the shell.
void builtin_exit(t_shell *shell, char** args, int n_args)
{
	if (n_args >= 2)
	{
		perror("too many arguments ");
		// shell->last_exit_status = 1;
	}
	else if (n_args == 1)
	{

		if (is_valid_number(args[0]) == 0)
			shell->last_exit_status = 2;
		else
			shell->last_exit_status = adjust_exit_code(ft_atoi(args[0]));
	}
	(void)args;
	ft_printf("exit\n");
	ft_printf("builtin_exit last_exit_status %d\n", shell->last_exit_status);

	shexit(shell, 0);
}

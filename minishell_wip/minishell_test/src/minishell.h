/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:00:40 by vitenner          #+#    #+#             */
/*   Updated: 2024/02/26 15:05:30 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
// # include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
#include <errno.h>

/*
** ================== SRUCTURES ==================
*/
/*
** -- MEMORY --
*/
typedef struct MemNode {
	void* ptr;                // Pointer to the allocated memory
	struct MemNode* next;     // Next node in the list
} MemNode;

typedef struct {
	MemNode* head;            // Head of the list of allocated memory blocks
} MemTracker;
/*
** -- PARSING --
*/
typedef struct {
	char* value; // The actual token, e.g., "ls", "-l", ">", etc.
	int type;	// Type of the token (command, argument, redirection, pipe, etc.)
} Token;

typedef struct TokenNode {
	Token token;
	struct TokenNode* next;
} TokenNode;

typedef enum {
	TOKEN_COMMAND,          // 0
	TOKEN_ARG,              // 1
	TOKEN_REDIR_IN, // <       2
	TOKEN_REDIR_OUT,// >       3
	TOKEN_REDIR_APPEND, // >>  4
	TOKEN_REDIR_HEREDOC, // << 5
	TOKEN_PIPE,     // |        6
	TOKEN_ENV_VAR,  // $VAR     7
	TOKEN_EXIT_STATUS, // $?    8
	TOKEN_D_Q,  //              9
	TOKEN_S_Q,  //              10
	TOKEN_S_DOL,//              11
	TOKEN_EOL,//              12
	// Add other necessary token types
} TokenType;
/*
** -- COMMANDS --
*/
typedef enum {
	CMD_BUILTIN,
	CMD_EXTERNAL
} CommandType;

typedef struct Command {
    CommandType type;
    char* name;
    char** args;
    int arg_count;
    char* redirect_in;
    char* redirect_out;
    char* redirect_append;
    char* redirect_heredoc;
    int fd_in;                 // File descriptor for input redirection
    int fd_out;                // File descriptor for output redirection
    int fin;                 // File descriptor for input redirection
    int fout;                // File descriptor for output redirection
    struct Command* next;
} Command;

typedef struct s_params
{
	// int		fin;
	// int		fout;
	int		argc;
	char	**argv;
	char	**envp;
	int		pipefd[2];
}			t_in;



typedef struct {
	Command*    head;             // Head of the list of commands
	int         command_count;         // Number of commands in the table
} CommandTable;

typedef enum {
	REDIRECT_NONE,  	// No redirection
	REDIRECT_INPUT, 	// Input redirection ('<')
	REDIRECT_OUTPUT,	// Output redirection ('>')
	REDIRECT_APPEND 	// Output append redirection ('>>')
} RedirectionType;
/*
** -- ENV --
*/
typedef struct s_env_var {
	char *key;                 // For storing the variable name
	char *value;               // For storing the variable value
	struct s_env_var *next;    // Pointer to the next node in the list
} t_env_var;
/*
** -- MAIN --
*/
typedef struct s_shell {
	t_env_var           *env_head;       // Head of the linked list of environment variables for export
	int                 last_exit_status;  	// Exit status of the last executed command
	struct sigaction    *signals; // Custom signal handlers
	int                 is_interactive;
	MemTracker          mem_tracker;
	TokenNode           *token_head;
} t_shell;
/*
** ================== INITIALIZATION ==================
*/
t_shell     *initialize_shell(char **envp);
void        create_env_var_list(t_shell *shell, char **envp);
/*
** -- SIGNALS --
*/
void        sigint_handler(int sig_num);
void        sigquit_handler(int sig_num);
void        setup_signals(t_shell *shell);

/*
** ================== PARSING ==================
*/
/*
** -- TOKENIZATION --
*/
// void create_tokens(t_shell *shell, const char *s, char c, TokenNode **head);
void        createtokensv2(t_shell *shell, const char *s);
void		create_tokens(t_shell *shell, const char *s);
void		addToken(t_shell *shell, const char *value, int type);
TokenType	get_token_type(const char* token_text);
char		*parse_tokens(t_shell *shell, const char *s);
/*
** -- QUOTES --
*/
void		toggleQuoteState(int *quoteState);
char		*reviewquotes(char *input);
/*
** -- VARIABLE EXPANSION --
*/
char* expandVariables(t_shell *shell, const char *input, t_env_var *envVars);
/*
** -- HEREDOC --
*/
void		parse_heredoc(t_shell *shell);
/*
** ================== COMMANDS ==================
*/
/*
** -- COMMAND TABLE --
*/
CommandTable* create_command_table(t_shell *shell, TokenNode* tokens);
void execute_command_table(t_shell *shell, CommandTable* table,t_in in);
void free_command_table(CommandTable* table);
void execute_ext_command(Command *cmd);
/*
** -- BUILT_IN COMMANDS --
*/
void builtin_cd(t_shell * shell, char** args, int n_args);
void builtin_pwd(void);
void builtin_echo(t_shell *shell, char** args, int n_args);
void builtin_unset(t_shell *shell, char** args, int n_args);
void builtin_env(void);

/*
** :: EXIT ::
*/
void builtin_exit(t_shell *shell, char** args, int n_args);
char	*export_exit_code(t_shell *shell);
int is_valid_number(const char *str);
int adjust_exit_code(int n);

/*
** :: EXPORT ::
*/
void builtin_export(t_shell *shell, char** args, int n_args);
int process_env_arg(t_shell *shell, const char *arg);
int check_duplicates(t_shell *shell, const char *key, int nchar);
void update_var(t_shell *shell, const char *key, const char *value);
void add_new_var(t_shell *shell, const char *key, const char *value);
void decl_new_var(t_shell *shell, const char *key);
void remove_var(t_shell *shell, const char *key, int nchar);
void print_export(t_shell *shell);
/*
** ================== MEMORY ==================
*/
void	shexit(t_shell *shell, int exit_code);
void* shell_malloc(t_shell* shell, size_t size);
void shell_free(t_shell* shell, void* ptr);
void shell_cleanup(t_shell* shell);
char* shell_strdup(t_shell* shell, const char* s);
char* shell_strndup(t_shell* shell, const char* s, size_t n);


/*
** ================== UTILS ==================
*/
const char  *skip_delimiters(const char *s, char c);
int         find_index_char(const char *str, char c);
int intLength(int num);
/*
** -- DEBUG --
*/
void printTokens(TokenNode* head);
void print_command_table(const CommandTable* table);
/*
** -- OLD/TOREMOVE --
*/
void expand_variables(t_shell *shell);


//pipex_and pipex_util
# define ERR_INVALID_CMD "\n pipex: command not found \n"
# define STDIN_FILENO 0
# define STDOUT_FILENO 1

char		*check_path(char **envp);
char		*locate_cmd(char **paths, char *cmd);
char		*find_env_path(char **envp);
void		free_array(char **v);
char	*ft_strdup_ignore(const char *s, char ignore);
int	ft_strchr_count(const char *s, int c);
char	*ft_strjoin_nconst(char *s1, char *s2);
int	ft_puterr(char  *s, int ret);
// int	execute_command_pipex(int prev_pipe,int fin,int fout, int pipefd[2], char *cmd, char *envp[]);
int execute_command_pipex(int prev_pipe,Command *cmd, t_in in, t_shell *shell);
char		**find_cmd_paths(char **envp);
char		**ft_split_cmd_args(char *s);
// int			run_cmd(char *cmd, char **envp);
int	run_cmd(Command* command  , char **envp,t_shell*shell);
// int pipex(t_in in,Command cmd,t_shell *shell);
int pipex(t_in in,Command *cmd,t_shell *shell);
#endif

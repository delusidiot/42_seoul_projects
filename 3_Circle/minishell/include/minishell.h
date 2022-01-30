#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "font_color.h"
# include "libft.h"

# define ENV_HOME "HOME"
# define ENV_USER "USER"
# define ENV_PATH "PATH"
# define ERR_PROMPT "minishell: "
# define SYN_ERR "syntax error near unexpected token "
# define END_SYN_ERR "cannot be at the end"
# define HERE_TEMP "/tmp/.temp"

extern int errno;

typedef enum e_pipe_type
{
	READ = 0,
	WRITE = 1,
}	t_pipe_type;

typedef struct s_user
{
	char	**g_env;
	char	*home_dir;
	char	*pwd;
	char	*username;
	char	*path;
	int		stdin_fd;
	int		stdout_fd;
	int		pipe_in;
	int		pipefd[2];
} t_user;

typedef enum e_ast_type
{
	NONE,
	COMMAND,
	ARGUMENT,
	PIPE,
	REDIRECT,
	FILE_NO,
	OPERATOR,
} t_ast_type;

typedef enum e_redirect_type
{
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_APPEND,
	REDIRECT_HEREDOC
}	t_redirect_type;

typedef enum e_operator_type
{
	OPERATOR_AND,
	OPERATOR_OR
}	t_operator_type;

typedef struct s_source {
	char	*input;
	char	*curpos;
	int		input_size;
}	t_source;

typedef struct s_token {
	t_ast_type	type;
	char		*value;
	int			len;
} t_token;

typedef struct s_AST
{
	t_ast_type type;
	void	*data;
}	t_AST;

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
	int		is_last;
}	t_cmd;

typedef struct s_pipe
{
	t_AST	*left;
	t_AST	*right;
}	t_pipe;

typedef struct s_redirect
{
	t_redirect_type		type;
	t_AST	*ast;
	char	*file;
}	t_redirect;

typedef struct s_operator
{
	t_operator_type	type;
	t_AST	*left;
	t_AST	*right;
}	t_operator;

typedef struct s_exec
{
	int		flag;
	char	*in;
	char	*out;
	char	*append;
	char	*here;
}	t_exec;

/*
 * exceptions
 */

void	exception(void);
void	*malloc_exception(void);
int		syntax_error(char *token_str);

int		put_exec_errno(void);
void	*put_exec_errno_null(void);
int		exec_malloc_exception(void);
int		command_not_found_exception(char *cmd);
int		redirect_not_found_exception(char *file);


/*
 *	parser 
 */
void		skip_whitespaces(t_source *src);
t_source	*create_source(char *input);
t_source	*free_source(t_source *src);
void	print_token(void *content);
void	del_token(void *content);
t_token	*get_static_token(t_token *token, t_source *src);
t_token	*get_token(t_token *token, t_source *src);
t_list	*lexical_analyzer(char *input);

t_AST	*syntax_AST(t_list **token);
t_AST	*syntax_cmd(t_list **token);
t_AST	*syntax_analyzer(t_list *token);
int		analyzer_ast(t_AST *AST);
void	free_AST(void *data);
void	print_ast(t_AST *AST);

/*
 *	executor 
 */

int		is_builtins(t_cmd *cmd);
int		exec_command(t_user *user, t_cmd *cmd);
int		exec_redirect(t_user *user, t_redirect *redirect);
int		exec_pipe(t_user *user, t_pipe *pipe);
int		exec_ast(t_user *user, t_AST *ast);

int		exec_builtins(t_user *user, t_cmd *cmd);
int		is_builtins(t_cmd *cmd);

char	*join_path(char *prev, char *name);
void	get_here_doc(int fd, t_redirect *redirect);
t_list	*create_pipe(void);

void	parent_process(t_user *user, t_cmd *cmd);
void	child_process(t_user *user, t_cmd *cmd);
void	child_process_close(t_user *user, t_cmd *cmd);
char	*get_add_env_path(char *path, t_cmd *cmd);
char	**get_args(t_cmd *cmd);
void	fd_init(t_user *user);
/*
 * signal/signal.c 
 */

void	set_signal(void);
int		status_signal_handler(int status);

/*
* prompt/prompt.c
*/

char	*prompt(t_user *user);
char	*prompt1(t_user *user);
char	*prompt2();

/*
 * startup 
 */

void	startup_shell(t_user *user);
void	init_user(t_user *user);
void	free_user(t_user *user);

/*
*	main.c
*/

#endif
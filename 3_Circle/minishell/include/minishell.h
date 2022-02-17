/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 06:15:42 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 12:53:31 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <dirent.h>
# include "font_color.h"
# include "libft.h"
# include "get_next_line.h"

# define ENV_HOME "HOME"
# define ENV_USER "USER"
# define ENV_PATH "PATH"
# define ERR_PROMPT "minishell: "
# define SYN_ERR_MSG "syntax error near unexpected token "
# define END_SYN_ERR_MSG "cannot be at the end"
# define QUOTE_ERR_MSG "unexpected EOF while looking for matching "
# define LINE_EOF_ERR_MSG "syntax error: unexpected end of file"
# define HERE_TEMP "/tmp/.temp"
# define STDIN_NO 0
# define STDOUT_NO 1
# define STDERR_NO 2

typedef enum e_qtype
{
	NORMAL,
	DOUBLE_QUOTE,
	SINGLE_QUOTE,
}	t_qtype;

typedef enum e_pipe_type
{
	READ = 0,
	WRITE = 1,
}	t_pipe_type;

typedef struct s_env {
	char			*key;
	char			*value;
	int				order;
	struct s_env	*next;
}	t_env;

typedef enum e_ast_type
{
	NONE,
	COMMAND,
	ARGUMENT,
	PIPE,
	REDIRECT,
	FILE_NO,
	OPERATOR,
	LBRACE,
	RBRACE
}	t_ast_type;

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
}	t_source;

typedef struct s_token {
	t_ast_type	type;
	char		*value;
	int			is_last;
	int			cmd_last;
	int			brace_level;
}	t_token;

typedef struct s_ast
{
	t_ast_type	type;
	void		*data;
}	t_ast;

typedef struct s_none
{
	t_ast	*ast;
}	t_none;

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
	int		index;
	int		brace_level;
	int		is_last;
	int		cmd_last;
	pid_t	pid;
}	t_cmd;

typedef struct s_pipe
{
	t_ast	*left;
	t_ast	*right;
}	t_pipe;

typedef struct s_redirect
{
	t_redirect_type	type;
	t_ast			*ast;
	char			*file;
}	t_redirect;

typedef struct s_operator
{
	t_operator_type	type;
	t_ast			*left;
	t_ast			*right;
	int				brace_level;
}	t_operator;

typedef struct s_exec
{
	int		flag;
	char	*in;
	char	*out;
	char	*append;
	char	*here;
}	t_exec;

typedef enum e_ops
{
	S_NONE,
	S_FIRST,
	S_FAIL,
	S_SUCCESS
}	t_ops;

typedef struct s_user {
	t_env	*g_env;
	int		env_size;
	char	*home_dir;
	char	*pwd;
	char	*username;
	int		stdin_fd;
	int		stdout_fd;
	int		cmd_count;
	int		*pipe_in;
	int		*pipe_out;
	int		pipefd[2];
	int		exit_status;
	int		underscore_flag;
	int		brace_level_count;
	t_cmd	*last;
	t_ops	oper_state;
}	t_user;

/*
 * exceptions
 */

void		exception(void);
void		*malloc_exception(void);
int			bool_malloc_exception(void);
int			syntax_error(char *token_str);
int			put_exec_cmd_errno(char *cmd);
int			put_exec_errno(void);
void		*put_exec_errno_null(void);
int			exec_malloc_exception(void);
int			command_not_found_exception(char *cmd);
int			prt_err(char *type, char *content, int flag);

void		*unexpected_end_quote(char *input, t_qtype qtype);
void		*unexpected_end_of_file(void);

/*
 *	parser/lexical_analysis
 */
void		last_command_check(t_list *lst);
t_list		*lexical_analyzer(char *input, t_user *user);
t_list		*get_token(t_source *src, t_user *user);
t_token		*get_pipe_op_token(t_token *token, t_source *src);
char		*get_double_quote(t_source *src, t_user *user);
char		*get_single_quote(t_source *src);
char		*get_common_value(t_source *src, t_user *user, char **wilds);
t_list		*get_wildcard_files(t_token *token, char *wilds, t_user *user);
void		skip_whitespaces(t_source *src);
t_source	*create_source(char *input);
t_source	*free_source(t_source *src);
void		print_token(void *content);
void		del_token(void *content);
int			token_checker(t_list *lst, t_user *user);
int			token_checker_result(t_list *stack, char *msg, int check);
int			redirect_checker(t_list *next, t_list *stack, t_ast_type prev);
int			pipe_checker(t_token *token, t_list *next, \
		t_list *stack, t_ast_type prev);
int			command_checker(t_token *token, t_list *stack, t_ast_type prev);
void		last_brace_checker(t_list *lst);
char		*remove_whitespace(t_source *src, char *value);
char		*mark_wildcard(char *value);
t_list		*add_list(t_list *curr, t_token *token);

/*
 *	parser/syntax_analysis
 */

t_ast		*syntax_ast(t_user *user, t_list **token);
t_ast		*syntax_cmd(t_user *user, t_list **token);
t_ast		*syntax_analyzer(t_user *user, t_list *token);
t_ast		**syntax_PIPE(t_user *user, t_list **token, t_ast **curr);
t_ast		**syntax_operator(t_list **token, t_ast **curr);
int			analyzer_ast(t_ast *ast, t_ast_type prev);
void		free_ast(void *data);
void		print_ast(t_ast *ast);
void		set_cmd(t_cmd *cmd, t_user *user, t_ast *curr);
void		set_redirect_type(t_redirect *redirect, t_list **token);
void		set_token_value(t_token *token, t_source *src, \
		char *value, t_ast_type type);
char		*set_char_value(char *temp, char *value, t_source *src);
int			analyzer_command(t_cmd *command);

/*
 *	executor 
 */

int			is_builtins(t_cmd *cmd);
int			exec_command(t_user *user, t_cmd *cmd);
int			exec_redirect(t_user *user, t_redirect *redirect);
int			exec_pipe(t_user *user, t_pipe *pipe);
int			exec_ast(t_user *user, t_ast *ast);
int			start_command(t_user *user, t_cmd *cmd);

int			exec_builtins(t_user *user, t_cmd *cmd);
int			is_builtins(t_cmd *cmd);

char		*join_path(char *prev, char *name);
void		get_here_doc(int fd, t_redirect *redirect);
t_list		*create_pipe(void);

void		parent_process(t_user *user, t_cmd *cmd);
void		child_process(t_user *user, t_cmd *cmd);
char		**get_args(t_user *user, t_cmd *cmd);
void		fd_init(t_user *user);
/*
 * signal/signal.c 
 */

void		set_command_signal(void);
void		set_exec_signal(void);
int			status_signal_handler(int status);

/*
* prompt/prompt.c
*/

char		*prompt(t_user *user);
char		*prompt1(t_user *user);
char		*prompt2(t_user *user);
t_qtype		is_quotation(char *input);
int			is_nextline(char *input);
char		*add_input(char *input, t_qtype qtype);

/*
 * startup 
 */

void		startup_shell(t_user *user, char **envp);
void		init_user(t_user *user);
void		free_user(t_user *user);

/*
*	wildcard.c
*/

/*
 * builtin commandes
 */

int			ft_env(t_user *user);
int			ft_export(t_user *user, t_list *list);
int			ft_unset(t_user *user, t_list *list);
int			ft_echo(t_list *list);
int			ft_cd(t_user *user, t_list *list);
int			ft_exit(t_user *user, t_list *list);
void		underscore(t_user *user, char *type, t_list *list);

/*
 * env utile
 */

int			set_env_var(t_user *user, char **envp);
char		*get_env(t_env *env, char *key);

/*
 * export utiles
 */

void		set_sort_env(t_env *env);
void		env_order_print(t_user *user);
int			sort_prt(t_user *user);
int			add_export_env(t_user *user, char *tmp_content);

void		env_lst_clear(t_env *env);
void		env_lst_add_back(t_user *user, t_env *new);
t_env		*env_lts_new(char *text);
int			change_value(int flag, char *str, t_env **env, char **key);
int			same_key_find(t_user *user, char *str);

/*
 * export & unset utiles
 */

int			export_unset_err(char *key, int flag);
void		add_export(t_user *user, char *str, char *key);

/*
 * builtin utiles
 */

char		*str_conversion(t_user *user, char *content);

/*
 * utiles
 */

int			end_of_word(char *str);
int			is_white_space(char *str);
void		clear_change_arr(char **arr);
char		**change_lst_to_arr(t_user *user);
char		*err_msg_join(char *type, char *content, char *msg);
int			equal_sign_flag(char *str);
int			not_isalnum_flag(char *content);
int			dollar_sign_flag(char *content);

/*
*	main.c
*/

int			pattern_match(char str[], char pattern[], char *wilds);
void		set_args(t_list **result, char *filename);
void		add_arg_wild(t_user *user, t_cmd *cmd);

#endif

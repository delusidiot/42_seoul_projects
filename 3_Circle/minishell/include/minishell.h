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
# include "font_color.h"
# include "libft.h"

typedef enum e_token_type {
	TYPE_NULL,
	TYPE_WORD,
	TYPE_PIPE,
	TYPE_DOUBLE_QUOTES,
	TYPE_SINGLE_QUOTES,
	TYPE_REDIRECT,
	TYPE_LOGICAL_OPERATION,
	TYPE_WILDCARD,
} t_token_type;

extern int errno;

typedef struct s_user {
	char	**g_env;
	char	*home_dir;
	char	*pwd;
	char	*username;
	int		exit_status;
} t_user;

typedef struct s_token {
	t_token_type type;
	char	*str;
}	t_token;

typedef struct s_token_state{
	t_token *token;
	int length;
	int size;
} t_token_state;
/*
 * signal/signal.c 
 */

void	set_signal(void);

/*
* prompt/prompt.c
*/

char	*prompt(t_user *user);
char	*prompt1(t_user *user);
char	*prompt2(t_user *user);

/*
 * startup 
 */

void	init_user(t_user *user);
void	free_user(t_user *user);

/*
*	main.c
*/

#endif
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

# define ENV_HOME "HOME"
# define ENV_USER "USER"
# define ENV_PATH "PATH"

extern int errno;

typedef struct s_user {
	char	**g_env;
	char	*home_dir;
	char	*pwd;
	char	*username;
	char	*path;
	int		exit_status;
} t_user;

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
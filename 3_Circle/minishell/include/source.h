#ifndef SOURCE_H
# define SOURCE_H

# define ERRCHAR 0
# define INIT_SRC_POS -2

# include "minishell.h"

typedef struct s_source
{
	char	*buf;
	long	bufsize;
	long	curpos;
} t_source;

char	next_char(t_source *src);
void	unget_char(t_source *src);
char	peek_char(t_source *src);
void	skip_white_spaces(t_source *src);


#endif
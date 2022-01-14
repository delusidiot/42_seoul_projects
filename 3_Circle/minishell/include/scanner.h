#ifndef SCANNER_H
# define SCANNER_H

# include "minishell.h"
# include "source.h"

typedef struct s_token
{
	struct s_source *src;
	int		text_len;
	char	*text;
} t_token;

typedef struct s_token_header
{
	char *tok_buf;
	int   tok_bufsize;
	int   tok_bufindex;
} t_token_header;

t_token	*tokenize(t_source *src);
void	free_token(t_token *token);

#endif
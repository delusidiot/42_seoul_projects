#include "minishell.h"

void		skip_whitespaces(t_source *src)
{
    if(!src || !src->input)
        return;
    while(src->curpos && \
		(*src->curpos == ' ' || *src->curpos == '\v' || *src->curpos == '\f' \
		|| *src->curpos == '\r' || *src->curpos == '\n' || *src->curpos == '\t'))
        src->curpos++;
}

t_source	*create_source(char *input)
{
	t_source *src;

	src = malloc(sizeof(t_source));
	if (!src || !input || *input == '\0')
		return (NULL);
	src->input = input;
	src->curpos = input;
	src->input_size = ft_strlen(input);
	return (src);
}

t_source	*free_source(t_source *src)
{
	free(src->input);
	free(src);
	return (NULL);
}
#include "scanner.h"

t_token	*eof_token(void)
{
	t_token *eof;

	eof = malloc(sizeof(t_token));
	if (!eof) //error 처리
		return NULL;
	eof->text_len = 0;
	return (eof);
}

t_token_header *init_header(void)
{
	t_token_header *header;

	header = malloc(sizeof(t_token_header));
	if (!header)
		return NULL;
	header->tok_buf = NULL;
	header->tok_bufsize = 0;
	header->tok_bufindex = -1;
	return (header);
}

void	add_to_buf(t_token_header *header, char c)
{
	char *temp;

	header->tok_buf[header->tok_bufindex++] = c;
	if (header->tok_bufindex >= header->tok_bufsize)
	{
		temp = malloc(header->tok_bufsize * 2);
		if (!temp)
		{
			errno = ENOMEM;
			return ;
		}
		ft_memcpy(temp, header->tok_buf, header->tok_bufsize);
		free(header->tok_buf);
		header->tok_buf = temp;
		header->tok_bufsize *= 2;
	}
}

t_token	*create_token(char *str)
{
	t_token *token = malloc(sizeof(t_token));

	if (!token)
		return NULL;
	ft_memset(token, 0, sizeof(t_token));
	token->text_len = strlen(str);
	char *next_str = malloc(token->text_len + 1);
	if (!next_char)
	{
		free(token);
		return NULL;
	}
	ft_strlcpy(next_str, str, token->text_len);
	token->text = next_str;

	return (token);
}

void free_token(t_token *token)
{
	if (token->text)
		free(token->text);
	free (token);
}

t_token	*tokenize(t_token_header *header, t_source *src)
{
	int	endloop = 0;

	if (!src || !src->buf || !src->bufsize || !header)
	{
		errno = ENODATA;
		return (eof_token());
	}
	if (!header->tok_buf)
	{
		header->tok_bufsize = 1024;
		header->tok_buf = malloc(header->tok_bufsize);
		if (!header->tok_buf)
		{
			errno = ENOMEM;
			return (eof_token());
		}
	}
	header->tok_bufindex = 0;
	header->tok_buf[0] = '\0';

	char nc = next_char(src);

	if (nc == ERRCHAR || nc == EOF)
		return (eof_token());
	nc = next_char(src);
	while (nc != EOF)
	{
		if (nc == ' ' || nc == '\t')
		{
			if (header->tok_bufsize > 0)
				endloop = 1;
		}
		else if (nc == '\n')
		{
			if (header->tok_bufindex > 0)
				unget_char(src);
			else
				add_to_buf(header, nc);
			endloop = 1;
		}
		else
			add_to_buf(header,nc);
		if (endloop)
			break;
		nc = next_char(src);
	}
	if (header->tok_bufindex == 0)
		return (eof_token());
	if (header->tok_bufindex >= header->tok_bufsize)
		header->tok_bufindex--;
	header->tok_buf[header->tok_bufindex] = '\0';

	t_token *token = create_token(header->tok_buf);
	if (!token)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (eof_token());
	}
	token->src = src;
	return (token);
}
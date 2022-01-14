#include "source.h"

void	unget_char(t_source *src)
{
	if (src->curpos < 0)
		return;
	src->curpos--;
}

char	next_char(t_source *src)
{
	char c;

	c  = 0;
	if (!src || !src->buf)
	{
		errno = ENODATA;
		return ERRCHAR;
	}
	if (src->curpos == INIT_SRC_POS)
		src->curpos++;
	else
		c = src->buf[src->curpos];
	if (++src->curpos >= src->bufsize)
	{
		src->curpos = src->bufsize;
		return EOF;
	}
	return src->buf[src->curpos];
}

char	peek_char(t_source *src)
{
	long pos;

	pos = src->curpos;
	if (!src || !src->buf)
	{
		errno = ENODATA;
		return ERRCHAR;
	}
	if (pos == INIT_SRC_POS)
		pos++;
	if (++pos >= src->bufsize)
		return (EOF);
	return src->buf[pos];
}

void	skip_white_spaces(t_source *src)
{
	char	c;
	if (!src || !src->buf)
		return ;
	while (((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
		next_char(src);
}
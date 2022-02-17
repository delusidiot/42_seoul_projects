/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:31:31 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/12 09:31:31 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exception(void)
{
	ft_putstr_fd(strerror(errno), STDERR_NO);
	exit(errno);
}

void	*malloc_exception(void)
{
	ft_putstr_fd(strerror(errno), STDERR_NO);
	ft_putstr_fd("\n", STDERR_NO);
	return (NULL);
}

int	bool_malloc_exception(void)
{
	malloc_exception();
	return (FALSE);
}

void	put_errorno(void)
{
	ft_putstr_fd(ERR_PROMPT, STDERR_NO);
	ft_putstr_fd(strerror(errno), STDERR_NO);
	ft_putstr_fd("\n", STDERR_NO);
}

int	syntax_error(char *token_str)
{
	ft_putstr_fd(ERR_PROMPT, STDERR_NO);
	ft_putstr_fd(SYN_ERR_MSG, STDERR_NO);
	ft_putstr_fd("`", STDERR_NO);
	ft_putstr_fd(token_str, STDERR_NO);
	ft_putstr_fd("\'", STDERR_NO);
	ft_putstr_fd("\n", STDERR_NO);
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:17:58 by jjeon             #+#    #+#             */
/*   Updated: 2021/08/09 18:49:31 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	argv_shift(int argc, char **argv, t_pipex *p)
{
	int	i;

	i = 1;
	while (++i < argc)
		argv[i - 1] = argv[i];
	--argc;
	argv[argc] = NULL;
	p->here_doc = TRUE;
	return (argc);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	init_pipex(&p);
	if (argc > 1 && ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
		argc = argv_shift(argc, argv, &p);
	if (argc < 4 && p.here_doc == TRUE)
		write(2, ERROR_MESSAGE2, ft_strlen(ERROR_MESSAGE2));
	else if (argc < 5)
		write(2, ERROR_MESSAGE, ft_strlen(ERROR_MESSAGE));
	else if (set_param(argc, argv, envp, &p))
		pipex(&p);
	free_pipex(&p);
	return (0);
}

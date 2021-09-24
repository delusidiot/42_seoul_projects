/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:02:53 by jjeon             #+#    #+#             */
/*   Updated: 2021/08/09 18:43:25 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	init_pipex(&p);
	if (argc != 5)
		write(2, ERROR_MESSAGE, ft_strlen(ERROR_MESSAGE));
	else if (set_param(argc, argv, envp, &p))
		pipex(&p);
	free_pipex(&p);
	return (0);
}

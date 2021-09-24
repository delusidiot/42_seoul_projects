/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:39:25 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/29 22:22:54 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_init(t_push *p)
{
	p->a_stack = NULL;
	p->b_stack = NULL;
	p->a_top = -1;
	p->b_top = -1;
}

void	push_free(t_push *p)
{
	if (p->a_stack)
		free(p->a_stack);
	if (p->b_stack)
		free(p->b_stack);
	p->a_stack = NULL;
	p->b_stack = NULL;
}

void	free_command(t_command *comm)
{
	if (comm)
	{
		free(comm->c);
		free(comm);
	}
}

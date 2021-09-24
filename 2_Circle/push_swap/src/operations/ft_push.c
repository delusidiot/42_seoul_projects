/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:40:38 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:42:54 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	push_a(t_push *p)
{
	if (p->b_top < 0)
		return ;
	p->a_top++;
	p->a_stack[p->a_top] = p->b_stack[p->b_top];
	p->b_top--;
}

static void	push_b(t_push *p)
{
	if (p->a_top < 0)
		return ;
	p->b_top++;
	p->b_stack[p->b_top] = p->a_stack[p->a_top];
	p->a_top--;
}

void	ft_push(t_push *p, char c)
{
	if (c == 'a')
		push_a(p);
	else if (c == 'b')
		push_b(p);
	if (p->command_list)
		push_command(p, "p", c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:41:23 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:43:27 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	swap_a(t_push *p)
{
	int	temp;

	if (p->a_top < 1)
		return ;
	temp = p->a_stack[p->a_top];
	p->a_stack[p->a_top] = p->a_stack[p->a_top - 1];
	p->a_stack[p->a_top - 1] = temp;
}

static void	swap_b(t_push *p)
{
	int	temp;

	if (p->b_top < 1)
		return ;
	temp = p->b_stack[p->b_top];
	p->b_stack[p->b_top] = p->b_stack[p->b_top - 1];
	p->b_stack[p->b_top - 1] = temp;
}

void	ft_swap(t_push *p, char c)
{
	if (c == 'a')
		swap_a(p);
	else if (c == 'b')
		swap_b(p);
	else
	{
		swap_a(p);
		swap_b(p);
		c = 's';
	}
	if (p->command_list)
		push_command(p, "s", c);
}

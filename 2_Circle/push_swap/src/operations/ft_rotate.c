/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:41:19 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:43:15 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	rotate_a(t_push *p)
{
	int	temp;
	int	i;

	if (p->a_top < 0)
		return ;
	i = -1;
	temp = p->a_stack[p->a_top];
	while (++i < p->a_top)
		p->a_stack[p->a_top - i] = p->a_stack[p->a_top - i - 1];
	p->a_stack[0] = temp;
}

static void	rotate_b(t_push *p)
{
	int	temp;
	int	i;

	i = -1;
	if (p->b_top < 0)
		return ;
	temp = p->b_stack[p->b_top];
	while (++i < p->b_top)
		p->b_stack[p->b_top - i] = p->b_stack[p->b_top - i - 1];
	p->b_stack[0] = temp;
}

void	ft_rotate(t_push *p, char c)
{
	if (c == 'a')
		rotate_a(p);
	else if (c == 'b')
		rotate_b(p);
	else
	{
		rotate_a(p);
		rotate_b(p);
		c = 'r';
	}
	if (p->command_list)
		push_command(p, "r", c);
}

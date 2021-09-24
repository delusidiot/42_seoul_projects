/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:41:06 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:43:49 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	reverse_rotate_a(t_push *p)
{
	int	temp;
	int	i;

	if (p->a_top < 0)
		return ;
	i = -1;
	temp = p->a_stack[0];
	while (++i < p->a_top)
		p->a_stack[i] = p->a_stack[i + 1];
	p->a_stack[p->a_top] = temp;
}

static void	reverse_rotate_b(t_push *p)
{
	int	temp;
	int	i;

	if (p->b_top < 0)
		return ;
	i = -1;
	temp = p->b_stack[0];
	while (++i < p->b_top)
		p->b_stack[i] = p->b_stack[i + 1];
	p->b_stack[p->b_top] = temp;
}

void	ft_reverse_rotate(t_push *p, char c)
{
	if (c == 'a')
		reverse_rotate_a(p);
	else if (c == 'b')
		reverse_rotate_b(p);
	else
	{
		reverse_rotate_a(p);
		reverse_rotate_b(p);
		c = 'r';
	}
	if (p->command_list)
		push_command(p, "rr", c);
}

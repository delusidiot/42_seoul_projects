/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:21:44 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:54:33 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	search_index(t_push *p, int num, char st)
{
	int	i;
	int	*stack;
	int	top;

	i = -1;
	if (st == 'a')
		stack = p->a_stack;
	else
		stack = p->b_stack;
	if (st == 'a')
		top = p->a_top;
	else
		top = p->b_top;
	while (++i <= top)
	{
		if (stack[i] == num)
			return (i);
	}
	return (i);
}

int	move_b_stack(t_push *p, int idx, char c, int is)
{
	if (c == 'R')
	{
		while (p->b_top > idx)
		{
			ft_reverse_rotate(p, 'b');
			idx--;
			if (idx < 0)
				idx = p->b_top;
		}
	}
	else
	{
		while (p->b_top > idx)
		{
			ft_rotate(p, 'b');
			idx++;
		}
	}
	return (is);
}

int	is_from_to(t_push *p, int from, int to)
{
	int	is;
	int	from_index;
	int	to_index;

	from_index = search_index(p, from, 'b');
	to_index = search_index(p, to, 'b');
	if (from_index > to_index)
	{
		if (p->b_top - from_index <= to_index)
			is = move_b_stack(p, from_index, 'r', 1);
		else
			is = move_b_stack(p, to_index, 'R', 0);
	}
	else
	{
		if (p->b_top - to_index <= from_index)
			is = move_b_stack(p, to_index, 'r', 0);
		else
			is = move_b_stack(p, from_index, 'R', 1);
	}
	return (is);
}

void	from_to_push(t_push *p, int from, int to)
{
	while (to - from >= 0)
	{
		if (is_from_to(p, from, to))
		{
			ft_push(p, 'a');
			ft_rotate(p, 'a');
			from++;
		}
		else
		{
			ft_push(p, 'a');
			to--;
		}
	}
}

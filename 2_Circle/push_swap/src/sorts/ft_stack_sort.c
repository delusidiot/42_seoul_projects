/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 08:48:00 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/20 11:54:55 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	first_divide(t_push *p, int pivot)
{
	int	i;
	int	pivot2;

	pivot2 = pivot / 2;
	i = -1;
	while (is_next_smaller(p, pivot))
	{
		if (p->a_stack[p->a_top] < pivot)
		{
			ft_push(p, 'b');
			if (p->b_stack[p->b_top] > pivot2 && p->b_top > 0)
				ft_rotate(p, 'b');
		}
		else
			ft_rotate(p, 'a');
	}
}

void	first_divide_sort_push(t_push *p, int pivot)
{
	int	from;
	int	to;

	from = 1;
	to = 0;
	while (to < pivot - 1)
	{
		from = to + 1;
		if (pivot - (from - 1 + pivot) / 2 > 5)
			to = (from - 1 + pivot) / 2;
		else
			to = pivot - 1;
		from_to_push(p, from, to);
		if (p->a_stack[p->a_top] == 1)
			ft_rotate(p, 'a');
		while (p->a_stack[0] + 1 == p->a_stack[p->a_top])
			ft_rotate(p, 'a');
	}
}

void	second_divide(t_push *p, int pivot)
{
	while (p->a_stack[p->a_top] != 1)
	{
		ft_push(p, 'b');
		if (p->b_stack[p->b_top] > pivot && p->b_top > 0)
			ft_rotate(p, 'b');
	}
}

void	second_divide_sort_push(t_push *p, int pivot)
{
	int	from;
	int	to;

	from = 1;
	to = pivot - 1;
	while (to < p->len)
	{
		from = to + 1;
		if (p->len - (from + p->len) / 2 > 5)
			to = (from + p->len) / 2;
		else
			to = p->len;
		from_to_push(p, from, to);
		while (p->a_stack[0] + 1 == p->a_stack[p->a_top])
			ft_rotate(p, 'a');
	}
}

void	stack_sort(t_push *p)
{
	int	pivot;
	int	pivot2;

	pivot = p->len / 2 + 1;
	pivot2 = pivot + pivot / 2;
	first_divide(p, pivot);
	first_divide_sort_push(p, pivot);
	second_divide(p, pivot2);
	second_divide_sort_push(p, p->a_stack[0] + 1);
}

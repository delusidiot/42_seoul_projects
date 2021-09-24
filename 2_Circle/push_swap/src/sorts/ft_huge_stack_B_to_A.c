/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_huge_stack_B_to_A.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:52:11 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/23 02:12:55 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	B_to_A_next(t_push *p, int ra, int rb, int pa)
{
	A_to_B(p, pa - ra);
	reverse_rotate_A_B(p, ra, rb);
	A_to_B(p, ra);
	B_to_A(p, rb);
}

void	B_to_A_push(t_push *p, int pivot_s, int pivot_b, int end)
{
	int	ra;
	int	rb;
	int	pa;

	counting_init(&ra, &rb, &pa);
	while (end--)
	{
		if (p->b_stack[p->b_top] < pivot_s)
		{
			ft_rotate(p, 'b');
			rb++;
		}
		else
		{
			ft_push(p, 'a');
			pa++;
			if (p->a_stack[p->a_top] < pivot_b)
			{
				ft_rotate(p, 'a');
				ra++;
			}
		}
	}
	B_to_A_next(p, ra, rb, pa);
}

void	B_to_A(t_push *p, int end)
{
	int	pivot_b;
	int	pivot_s;

	if (end <= 2)
	{
		rest_b_stack(p, end);
		return ;
	}
	pivot_s = get_pivot_s(p->b_stack, p->b_top, end);
	pivot_b = get_pivot_b(p->b_stack, p->b_top, end);
	B_to_A_push(p, pivot_s, pivot_b, end);
}

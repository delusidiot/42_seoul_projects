/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_huge_stack_A_to_B.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:53:29 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/23 02:13:07 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	A_to_B_next(t_push *p, int ra, int rb, int pb)
{
	reverse_rotate_A_B(p, ra, rb);
	A_to_B(p, ra);
	B_to_A(p, rb);
	B_to_A(p, pb - rb);
}

void	A_to_B_push(t_push *p, int pivot_s, int pivot_b, int end)
{
	int	ra;
	int	rb;
	int	pb;

	counting_init(&ra, &rb, &pb);
	while (end--)
	{
		if (p->a_stack[p->a_top] >= pivot_b)
		{
			ft_rotate(p, 'a');
			ra++;
		}
		else
		{
			ft_push(p, 'b');
			pb++;
			if (p->b_stack[p->b_top] >= pivot_s)
			{
				ft_rotate(p, 'b');
				rb++;
			}
		}
	}
	A_to_B_next(p, ra, rb, pb);
}

void	A_to_B(t_push *p, int end)
{
	int	pivot_b;
	int	pivot_s;

	if (end <= 2)
	{
		rest_a_stack(p, end);
		return ;
	}
	pivot_s = get_pivot_s(p->a_stack, p->a_top, end);
	pivot_b = get_pivot_b(p->a_stack, p->a_top, end);
	A_to_B_push(p, pivot_s, pivot_b, end);
}

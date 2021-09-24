/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_huge_stack_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:47:16 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/23 02:11:55 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	counting_init(int *a, int *b, int *p)
{
	*a = 0;
	*b = 0;
	*p = 0;
}

void	rest_a_stack(t_push *p, int end)
{
	if (end == 2 && p->a_stack[p->a_top - 1] < p->a_stack[p->a_top])
		ft_swap(p, 'a');
}

void	rest_b_stack(t_push *p, int end)
{
	int	i;

	if (end == 2 && p->b_stack[p->b_top - 1] > p->b_stack[p->b_top])
		ft_swap(p, 'b');
	i = -1;
	while (++i < end)
		ft_push(p, 'a');
}

void	reverse_rotate_A_B(t_push *p, int ra, int rb)
{
	int	max;
	int	i;

	if (ra > rb)
		max = ra;
	else
		max = rb;
	i = 0;
	while (i < max)
	{
		if (i < ra && i < rb)
			ft_reverse_rotate(p, 'r');
		else if (i < ra)
			ft_reverse_rotate(p, 'a');
		else
			ft_reverse_rotate(p, 'b');
		i++;
	}
}

void	huge_stack_sort(t_push *p)
{
	A_to_B(p, p->len);
}

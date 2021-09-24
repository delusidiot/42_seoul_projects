/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:26:48 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/23 02:31:21 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_sorted(t_push *p)
{
	int	i;

	if (p->a_top < 1)
		return (TRUE);
	i = 0;
	while (++i <= p->a_top)
	{
		if (p->a_stack[i] > p->a_stack[i - 1])
			return (FALSE);
	}
	return (TRUE);
}

void	move_over_three(t_push *p)
{
	int	pivot;

	pivot = p->a_top;
	if (p->a_top > 1)
		pivot = p->a_top - 1;
	while (is_next_smaller(p, pivot))
	{
		if (p->a_stack[p->a_top] < pivot)
			ft_push(p, 'b');
		else
			ft_rotate(p, 'a');
	}
}

void	less_than_seven(t_push *p)
{
	move_over_three(p);
	if (p->a_stack[0] > p->a_stack[1] && p->a_stack[0] < p->a_stack[2])
		ft_rotate(p, 'a');
	else
	{
		while (!is_sorted(p))
		{
			if (p->a_stack[p->a_top] > p->a_stack[p->a_top - 1])
			{
				if (p->b_top > 0 && p->b_stack[p->b_top]
					< p->b_stack[p->b_top - 1])
					ft_swap(p, ' ');
				else
					ft_swap(p, 'a');
			}
			if (is_sorted(p))
				break ;
			ft_reverse_rotate(p, 'a');
		}
	}
	if (p->b_top != -1)
		from_to_push(p, 1, p->len - 3);
	while (p->a_stack[p->a_top] != 1)
		ft_reverse_rotate(p, 'a');
}

void	create_first_command(t_push *p)
{
	p->command_list = malloc(sizeof(t_command));
	p->command_list->c = NULL;
	p->command_list->next = NULL;
	p->last_command = p->command_list;
}

void	sort_stack(t_push *p)
{
	if (p->len < 2 || is_sorted(p))
		return ;
	create_first_command(p);
	if (p->len <= 7)
		less_than_seven(p);
	else if (p->len <= 200)
		stack_sort(p);
	else
		huge_stack_sort(p);
	print_command(p);
}

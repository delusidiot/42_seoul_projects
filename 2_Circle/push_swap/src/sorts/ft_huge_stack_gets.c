/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_huge_stack_gets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:50:43 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/23 01:58:06 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_stack_max(int *stack, int top, int end)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (++i < end)
	{
		if (max < stack[top - i])
			max = stack[top - i];
	}
	return (max);
}

int	get_stack_min(int *stack, int top, int end)
{
	int	i;
	int	min;

	i = -1;
	min = 2147483647;
	while (++i < end)
	{
		if (min > stack[top - i])
			min = stack[top - i];
	}
	return (min);
}

int	get_pivot_s(int *stack, int top, int end)
{
	int	min;
	int	max;

	min = get_stack_min(stack, top, end);
	max = get_stack_max(stack, top, end);
	return ((max - min + 1) / 3 + min);
}

int	get_pivot_b(int *stack, int top, int end)
{
	int	min;
	int	max;

	min = get_stack_min(stack, top, end);
	max = get_stack_max(stack, top, end);
	return ((max - min + 1) / 3 * 2 + min);
}

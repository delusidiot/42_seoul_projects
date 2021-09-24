/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:28:55 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:41:32 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	*create_stack(t_push *p, int size)
{
	p->a_stack = malloc(sizeof(int) * size);
	if (!p->a_stack)
		return (NULL);
	p->b_stack = malloc(sizeof(int) * size);
	if (!p->b_stack)
		return (NULL);
	p->sorted_stack = malloc(sizeof(int) * size);
	if (!p->sorted_stack)
		return (NULL);
	p->a_top = size - 2;
	p->len = size - 1;
	return (p);
}

int	is_duplicate(t_push *p)
{
	int	i;
	int	prev;

	if (p->len < 2)
		return (_SUCCESS);
	i = 0;
	prev = p->sorted_stack[0];
	while (++i < p->len)
	{
		if (prev == p->sorted_stack[i])
			return (_ERROR);
		prev = p->sorted_stack[i];
	}
	return (_SUCCESS);
}

int	push_stack(char *argv, t_push *p, int index)
{
	long	num;

	num = 0;
	if (!is_number(argv))
		return (_ERROR);
	num = ft_atol(argv);
	if (num > 2147483647 || num < -2147483648)
		return (_ERROR);
	p->a_stack[index] = (int)num;
	p->sorted_stack[index] = (int)num;
	return (_SUCCESS);
}

void	argument_to_order(t_push *p)
{
	int	i;
	int	j;

	i = 0;
	while (i <= p->a_top)
	{
		j = 0;
		while (j <= p->a_top)
		{
			if (p->a_stack[i] == p->sorted_stack[p->a_top - j])
				break ;
			j++;
		}
		p->a_stack[i] = j + 1;
		i++;
	}
	sorted_stack_free(p);
}

int	push_args(int argc, char **argv, t_push *p)
{
	int		i;
	int		single;

	i = 0;
	single = 0;
	if (argc == 2)
	{
		argc = word_counter(argv[1], ' ') + 1;
		argv = ft_split(argv[1], ' ');
		i = -1;
		single = -1;
	}
	if (!create_stack(p, argc))
		return (_ERROR);
	while (++i < argc + single)
	{
		if (push_stack(argv[i], p, p->len - i + single) < 0)
			return (_ERROR);
	}
	ft_quick_sort(p->sorted_stack, 0, p->len - 1);
	if (is_duplicate(p) < 0)
		return (_ERROR);
	return (_SUCCESS);
}

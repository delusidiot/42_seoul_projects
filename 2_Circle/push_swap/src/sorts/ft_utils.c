/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 08:33:24 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:55:59 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_next_bigger(t_push *p, int pivot)
{
	int	i;

	i = -1;
	while (++i <= p->a_top)
	{
		if (pivot < p->a_stack[i])
			return (TRUE);
	}
	return (FALSE);
}

int	is_next_smaller(t_push *p, int pivot)
{
	int	i;

	i = -1;
	while (++i <= p->a_top)
	{
		if (pivot > p->a_stack[i])
			return (TRUE);
	}
	return (FALSE);
}

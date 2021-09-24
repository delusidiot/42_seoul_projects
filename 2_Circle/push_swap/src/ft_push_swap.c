/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:31:03 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/23 02:17:13 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_push	p;

	push_init(&p);
	if (push_args(argc, argv, &p) > 0)
	{
		argument_to_order(&p);
		sort_stack(&p);
	}
	else
		write(2, "Error\n", 6);
	push_free(&p);
	return (0);
}

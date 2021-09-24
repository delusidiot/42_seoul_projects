/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:07:40 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:58:13 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_command(t_push *p, char *line)
{
	int	rst;

	rst = 1;
	if (ft_strcmp(line, "ra") || ft_strcmp(line, "rb") || ft_strcmp(line, "rr"))
		ft_rotate(p, line[1]);
	else if (ft_strcmp(line, "rra")
		|| ft_strcmp(line, "rrb") || ft_strcmp(line, "rrr"))
		ft_reverse_rotate(p, line[2]);
	else if (ft_strcmp(line, "sa")
		|| ft_strcmp(line, "sb") || ft_strcmp(line, "ss"))
		ft_swap(p, line[1]);
	else if (ft_strcmp(line, "pa") || ft_strcmp(line, "pb"))
	{
		if (!(line[1] == 'a' && p->b_top == -1)
			&& !(line[1] == 'b' && p->a_top == -1))
			ft_push(p, line[1]);
	}
	else
		rst = 0;
	free(line);
	return (rst);
}

void	checker(t_push *p)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!check_command(p, line))
		{
			write(2, "Error\n", 6);
			return ;
		}
	}
	free(line);
	if (is_sorted(p))
		print_string("OK");
	else
		print_string("KO");
}

int	main(int argc, char **argv)
{
	t_push	p;

	if (argc < 2)
		return (0);
	push_init(&p);
	if (push_args(argc, argv, &p) > 0)
	{
		argument_to_order(&p);
		checker(&p);
	}
	else
		write(2, "Error\n", 6);
	push_free(&p);
	return (0);
}

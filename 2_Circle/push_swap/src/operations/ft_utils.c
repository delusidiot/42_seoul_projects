/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:49:27 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:50:03 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_command(t_push *p, char *s, char c)
{
	int	i;

	i = ft_strlen(s);
	p->last_command->next = malloc(sizeof(t_command));
	p->last_command->next->c = malloc(sizeof(char) * (i + 2));
	p->last_command->next->next = NULL;
	i = -1;
	while (s[++i])
		p->last_command->next->c[i] = s[i];
	p->last_command->next->c[i] = c;
	p->last_command->next->c[i + 1] = '\0';
	p->last_command = p->last_command->next;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	s1_len;
	int	s2_len;

	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len != s2_len)
		return (0);
	while (--s1_len >= 0)
	{
		if (s1[s1_len] != s2[s1_len])
			return (0);
	}
	return (1);
}

void	print_string(char *s)
{
	int	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	write(1, "\n", 1);
}

int	overlap_command(t_command *curr, t_command *next)
{
	if (!curr || !next)
		return (0);
	if ((ft_strcmp(curr->c, "ra") && ft_strcmp(next->c, "rra"))
		|| (ft_strcmp(curr->c, "rra") && ft_strcmp(next->c, "ra"))
		|| (ft_strcmp(curr->c, "rb") && ft_strcmp(next->c, "rrb"))
		|| (ft_strcmp(curr->c, "rrb") && ft_strcmp(next->c, "rb")))
		return (1);
	if (ft_strcmp(curr->c, "rra") && ft_strcmp(next->c, "rrb"))
	{
		print_string("rrr");
		return (1);
	}
	if (ft_strcmp(curr->c, "ra") && ft_strcmp(next->c, "rb"))
	{
		print_string("rr");
		return (1);
	}
	return (0);
}

void	print_command(t_push *p)
{
	t_command	*curr;
	t_command	*next;

	curr = p->command_list;
	next = curr->next;
	while (curr)
	{
		if (curr && next && overlap_command(curr, next))
		{
			free_command(curr);
			if (next->next)
				curr = next->next;
			free_command(next);
			if (curr)
				next = curr->next;
		}
		else
		{
			print_string(curr->c);
			free_command(curr);
			curr = next;
			if (next)
				next = curr->next;
		}
	}
}

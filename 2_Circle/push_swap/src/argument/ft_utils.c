/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 19:53:18 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/15 15:42:13 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sorted_stack_free(t_push *p)
{
	if (p->sorted_stack)
		free(p->sorted_stack);
	p->sorted_stack = NULL;
}

int	is_space(char c)
{
	if (c == ' ' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

int	word_counter(char const *s, char c)
{
	int	size;

	if (!*s)
		return (0);
	size = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			size++;
			while (*s && *s == c)
				s++;
		}
		else
			s++;
	}
	if (*(s - 1) != c)
		size++;
	return (size);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	while (is_space(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

long	ft_atol(char *num)
{
	long	rst;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	rst = 0;
	while (*num && is_space(*num))
		num++;
	if (num[0] == '-')
		sign = -(++i);
	if (num[0] == '+' || num[0] == ' ')
		sign = (++i);
	while (num[i] != '\0')
	{
		rst = (num[i] - '0' + (rst * 10));
		i++;
	}
	return (rst * sign);
}

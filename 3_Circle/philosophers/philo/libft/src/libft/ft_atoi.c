/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:39:38 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/01 14:31:47 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\n' || c == '\t')
		return (true);
	else
		return (false);
}

int	ft_atoi(const char *str)
{
	long	deca;
	int		sign;

	deca = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		deca *= 10;
		deca += (*str - '0');
		str++;
	}
	return (sign * deca);
}

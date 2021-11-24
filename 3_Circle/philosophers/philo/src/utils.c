/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:13:08 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/25 05:13:09 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(char *str)
{
	long	deca;
	int		i;

	i = -1;
	deca = 0;
	while (str[++i])
		deca += (str[i] - '0') + deca * 10;
	if (deca > 2147483647)
		return (_ERROR);
	return ((int)deca);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 06:06:15 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/26 06:06:20 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_atoi(char *str)
{
	long	deca;
	int		i;

	i = -1;
	deca = 0;
	while (str[++i])
		deca = (str[i] - '0') + deca * 10;
	if (deca > 2147483647)
		return (_ERROR);
	return ((int)deca);
}

int	sem_open_check(sem_t **sem, char *name, size_t size)
{
	*sem = sem_open(name, O_CREAT, 0644, size);
	if (*sem == SEM_FAILED)
		return (FALSE);
	sem_unlink(name);
	return (TRUE);
}

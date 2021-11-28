/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:12:41 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/27 08:00:46 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			return (put_error(CHECK_ARG_MINUS_ERROR));
		if (ft_strlen(argv[i]) > 10)
			return (put_error(CHECK_ARG_SIZE_ERROR));
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (put_error(CHECK_ARG_NUMBER_ERROR));
	}
	return (TRUE);
}

static int	parsing_arg(int argc, char **argv, t_info *info)
{
	info->num_of_philo = philo_atoi(argv[1]);
	info->time_to_die = philo_atoi(argv[2]);
	info->time_to_eat = philo_atoi(argv[3]);
	info->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = philo_atoi(argv[5]);
	if (info->num_of_philo == _ERROR || info->time_to_die == _ERROR
		|| info->time_to_eat == _ERROR || info->time_to_sleep == _ERROR
		|| info->must_eat == _ERROR)
		return (put_error(CHECK_ARG_SIZE_ERROR));
	return (TRUE);
}

static int	check_state(int argc, t_info *info)
{
	if (argc == 6 && info->must_eat <= 0)
		return (put_error(MUST_EAT_ERROR));
	if (info->num_of_philo < 0)
		return (put_error(TIME_TO_DIE_ERROR));
	if (info->time_to_die < 0)
		return (put_error(TIME_TO_EAT_ERROR));
	if (info->time_to_eat < 0)
		return (put_error(TIME_TO_SLEEP_ERROR));
	if (info->time_to_sleep < 0)
		return (put_error(MUST_EAT_ERROR));
	return (TRUE);
}

int	init_state(int argc, char **argv, t_info *info)
{
	info->fork = NULL;
	if (!(argc == 5 || argc == 6))
		return (put_error(ARG_NOT_CORRECT_ERROR));
	if (!check_arg(argc, argv))
		return (FALSE);
	if (!parsing_arg(argc, argv, info))
		return (FALSE);
	if (!check_state(argc, info))
		return (FALSE);
	return (TRUE);
}

int	init_thread(t_info *info, t_philo **philo)
{
	int	i;

	i = -1;
	info->fork = ft_calloc(info->num_of_philo, sizeof(t_mutex));
	if (!info->fork)
		return (abnormal_exit(info, *philo, MEMORY_ALLOC_ERROR));
	*philo = ft_calloc(info->num_of_philo, sizeof(t_philo));
	if (!(*philo))
		return (abnormal_exit(info, *philo, MEMORY_ALLOC_ERROR));
	while (++i < info->num_of_philo)
	{
		(*philo)[i].index = i;
		(*philo)[i].info = info;
		(*philo)[i].l = i;
		(*philo)[i].r = (i + 1) % info->num_of_philo;
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (abnormal_exit(info, *philo, MUTEX_INIT_ERROR));
	}
	if (pthread_mutex_init(&info->meal, NULL))
		return (abnormal_exit(info, *philo, MUTEX_INIT_ERROR));
	if (pthread_mutex_init(&info->print, NULL))
		return (abnormal_exit(info, *philo, MUTEX_INIT_ERROR));
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:12:47 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/28 09:30:26 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	philo = NULL;
	if (init_state(argc, argv, &info))
	{
		if (!init_thread(&info, &philo))
			return (0);
		active_philo(&info, philo);
		destroy_mutex(&info, philo);
	}
	else
		usage();
	return (0);
}

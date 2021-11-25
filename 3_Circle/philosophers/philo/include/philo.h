/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:12:31 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/25 05:12:38 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line.h"
# include "libft.h"
# include "color.h"

typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;

/*
** Error messages
*/

# define ARG_NOT_CORRECT_ERROR	"ERROR: THE NUMBER OF ARG IS NOT CORRECT\n"
# define CHECK_ARG_SIZE_ERROR	"ERROR: IT WAS OUT OF RANGE OF ARG VALUES\n"
# define CHECK_ARG_NUMBER_ERROR	"ERROR: THE ARG VALUE IS NOT A NUMBER\n"
# define CHECK_ARG_MINUS_ERROR	"ERROR: THE ARG SHOULD NOT BE NEGATIVE\n"
# define NUM_OF_PHILO_ERROR		"ERROR: NUM_OF_PHILO EXCEPTION\n"
# define TIME_TO_DIE_ERROR		"ERROR: TIME_TO_DIE EXCEPTION\n"
# define TIME_TO_EAT_ERROR		"ERROR: TIME_TO_EAT EXCEPTION\n"
# define TIME_TO_SLEEP_ERROR	"ERROR: TIME_TO_SLEEP EXCEPTION\n"
# define MUST_EAT_ERROR			"ERROR: MUST_EAT EXCEPTION\n"
# define MEMORY_ALLOC_ERROR		"ERROR: MEMORY ALLOCATION FAILURE\n"
# define MUTEX_INIT_ERROR		"ERROR: MUTEX INIT ERROR\n"

/*
** Message
*/
# define COMPLETE_MSG "Dining Philosophers simulation complete!"
# define TAKEN_MSG " has taken a fork"
# define EATING_MSG " is eating"
# define SLEEPING_MSG " is sleeping"
# define THINKING_MSG " is thinking"
# define DIED_MSG " died"

typedef enum s_state
{
	TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	COMPLETE,
}	t_state;

typedef struct s_info
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	int			count;
	t_mutex		*fork;
	t_mutex		print;
	t_mutex		meal;
	long long	start;
}				t_info;

typedef struct s_philo
{
	int			index;
	int			l;
	int			r;
	int			count;
	t_thread	monitor;
	t_thread	routine;
	t_info		*info;
	long long	current;
}	t_philo;

/*
** information update
*/

int		init_state(int argc, char **argv, t_info *info);
int		init_thread(t_info *info, t_philo **philo);
int		philo_atoi(char *str);

/*
** terminate
*/
void	usage(void);
int		put_error(char *str);
void	destroy_mutex(t_info *info, t_philo *philo);
int		abnormal_terminate(t_info *info, t_philo *philo, char *str);

/*
** time
*/
int		timestamp(long long *time);
void	wait_interval(t_philo *philo, long long start, long long interval);

/*
** state
*/
void	take_fork(t_philo *philo);
void	put_fork_down(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
int		print_state(t_state state, t_philo *philo);

/*
** philo
*/

void	active_philo(t_info *info, t_philo *philo);

#endif

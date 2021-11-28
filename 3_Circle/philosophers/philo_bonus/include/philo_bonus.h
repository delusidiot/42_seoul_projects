/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:37:16 by jjeon             #+#    #+#             */
/*   Updated: 2021/11/27 08:37:17 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line.h"
# include "libft.h"
# include "color.h"

typedef pthread_t		t_thread;

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
# define SEMAPHORE_INIT_ERROR	"ERROR: SEMAPHORE INIT ERROR\n"

/*
** Message
*/
# define COMPLETE_MSG "Dining Philosophers simulation complete!"
# define TAKEN_MSG " has taken a fork"
# define EATING_MSG " is eating"
# define SLEEPING_MSG " is sleeping"
# define THINKING_MSG " is thinking"
# define DIED_MSG " died"

/*
** file name
*/

# define PHILO_SEM_FORK "/philo_sem_fork"
# define PHILO_SEM_MEAL "/philo_sem_meal"
# define PHILO_SEM_PRINT "/philo_sem_print"
# define PHILO_SEM_FULL "/philo_sem_full"

typedef enum s_state
{
	TAKEN,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	COMPLETE,
}			t_state;

typedef struct s_philo
{
	int			count;
	t_thread	thread;
	pid_t		pid;
	long long	current;
}	t_philo;

typedef struct s_info
{
	int			index;
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	t_thread	thread;
	sem_t		*sem_fork;
	sem_t		*sem_meal;
	sem_t		*sem_print;
	sem_t		*sem_full;
	t_philo		*philo;
	long long	start;
}				t_info;

/*
** information update
*/
int		init_state(int argc, char **argv, t_info *info);
int		init_sem(t_info *info);
int		sem_open_check(sem_t **sem, char *name, size_t size);

/*
** terminate
*/
void	usage(void);
int		put_error(char *str);
void	kill_process(t_info *info);

/*
** time
*/
int		timestamp(long long *time);
void	wait_interval(t_info *info, long long start, long long interval);

/*
** state
*/
int		print_state(t_state state, t_info *info);
void	take_fork(t_info *info);
void	put_fork(t_info *info);
void	philo_eat(t_info *info);
void	philo_sleep(t_info *info);
void	philo_think(t_info *info);

/*
** philo
*/
void	active_philo(t_info *info);
int		philo_atoi(char *str);
int		sem_open_check(sem_t **sem, char *name, size_t size);

#endif

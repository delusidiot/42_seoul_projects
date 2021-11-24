# include "philo.h"

int main(int argc, char **argv)
{
	t_info info;
	t_philo *philo;

	philo = NULL;
	if (init_state(argc, argv, &info) && init_thread(&info, &philo))
		active_philo(&info, philo);
	else
		usage();
	return (0);
}
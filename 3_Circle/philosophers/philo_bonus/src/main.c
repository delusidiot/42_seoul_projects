# include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (init_state(argc, argv, &info))
	{
		if (!init_sem(&info))
			return (0);
		active_philo(&info);
		kill_process(&info);
	}
	else
		usage();
	return (0);
}
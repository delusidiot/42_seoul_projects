(philo_bonus/philo_bonus 5 410 100 100 > /dev/null)&
	sleep 2
	pgrep -l philo | wc -l
	sleep 2
	pkill philo_bonus

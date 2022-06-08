/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:56:16 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 14:06:21 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_can_eat(t_philosophers *philo)
{
	int	result;

	pthread_mutex_lock(&philo->info->permission_for_eat);
	result = philo->will_be_eat;
	pthread_mutex_unlock(&philo->info->permission_for_eat);
	return (result);
}

static void	start_routine(void *arg)
{
	t_philosophers	*philo;

	philo = arg;
	gettimeofday(&philo->last_eating_time, 0);
	while (philo->eat_count != philo->info->repeat)
	{
		thinking(philo);
		while (!check_philo_can_eat(philo))
		{
			usleep(500);
		}
		eating(philo);
		sleeping(philo);
		if (philo->info->repeat != -1)
			philo->eat_count++;
	}
	pthread_mutex_lock(&philo->info->is_finish_lock);
	philo->info->finished++;
	pthread_mutex_unlock(&philo->info->is_finish_lock);
}

int	run_odd_even_threads(int i, t_philosophers *philosophers)
{
	while (i < philosophers->info->number_of_philo)
	{
		if (pthread_create(&philosophers[i].philo_thread, 0,
				(void *)start_routine, &philosophers[i]))
			return (1);
		pthread_detach(philosophers[i].philo_thread);
		i += 2;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:55:40 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 13:46:24 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_finished(t_philo_info *info)
{
	int		is_finish;

	pthread_mutex_lock(&info->is_finish_lock);
	is_finish = info->finished;
	pthread_mutex_unlock(&info->is_finish_lock);
	return (is_finish == info->number_of_philo);
}

static void	waiting_until_someone_die(t_philosophers *philo)
{
	int		time_difference;

	usleep(philo->info->die_time / 2);
	while (!is_finished(philo->info))
	{
		pthread_mutex_lock(&philo->last_eating_time_lock);
		time_difference = time_diff(&philo->last_eating_time);
		pthread_mutex_unlock(&philo->last_eating_time_lock);
		if (time_difference < philo->info->die_time)
			philo = philo->next;
		else if (philo->eat_count != philo->info->repeat)
		{
			pthread_mutex_lock(&philo->info->permission_for_print);
			ft_message(philo, "\e[0;31mdied\e[1;37m");
			return ;
		}
		usleep(2000);
	}
}

void	main_thread(t_philosophers *philosophers)
{
	gettimeofday(&philosophers->info->starting_time, 0);
	if (run_odd_even_threads(0, philosophers)
		|| run_odd_even_threads(1, philosophers))
	{
		printf("Thread creating error");
		return ;
	}
	waiting_until_someone_die(philosophers);
}

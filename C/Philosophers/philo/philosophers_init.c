/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:24:52 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 11:19:05 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo_with_numbers(t_philosophers *philosopher,
	t_philo_info *info, int index)
{
	philosopher->info = info;
	philosopher->philo_index = index + 1;
	philosopher->will_be_eat = 0;
	if (index % 2 == 0 && (index + 1 != info->number_of_philo
			|| info->number_of_philo == 1))
		philosopher->will_be_eat = 1;
	philosopher->eat_count = 0;
}

t_philosophers	*philosophers_init(t_philo_info *info)
{
	t_philosophers	*philosophers;
	int				i;

	philosophers = malloc(info->number_of_philo * sizeof(t_philosophers));
	if (!philosophers)
	{
		printf("Malloc error\n");
		return (0);
	}
	i = 0;
	while (i < info->number_of_philo)
	{
		fill_philo_with_numbers(&philosophers[i], info, i);
		pthread_mutex_init(&philosophers[i].fork, 0);
		pthread_mutex_init(&philosophers[i].last_eating_time_lock, 0);
		if (i + 1 < info->number_of_philo)
			philosophers[i].next = &philosophers[i + 1];
		if (i != 0)
			philosophers[i].prev = &philosophers[i - 1];
		i++;
	}
	philosophers[0].prev = &philosophers[info->number_of_philo - 1];
	philosophers[info->number_of_philo - 1].next = &philosophers[0];
	return (philosophers);
}

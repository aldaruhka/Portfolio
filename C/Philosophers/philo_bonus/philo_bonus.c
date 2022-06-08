/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:38:14 by dwren             #+#    #+#             */
/*   Updated: 2022/06/06 16:12:54 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	waiting_all_finished_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->number_of_philo)
	{
		waitpid(philo[i].philo_pid, 0, 0);
		i++;
	}
	if (philo->info->sleep_time < 1000)
		usleep(philo->info->sleep_time * 2);
}

int	main(int argc, char *argv[])
{
	t_philo_info	*info;
	t_philo			*philo;

	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	info = philo_info_init(argc, argv);
	if (!info)
		return (0);
	philo = philo_init(info);
	if (!philo)
		return (0);
	create_new_process(philo);
	waiting_all_finished_eat(philo);
	free(philo->info);
	free(philo);
	return (0);
}

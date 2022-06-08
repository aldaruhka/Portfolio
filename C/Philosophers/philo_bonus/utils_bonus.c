/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:14:19 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:05:16 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	time_diff(struct timeval *starting_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return ((current_time.tv_sec - starting_time->tv_sec) * 1000
		+ (current_time.tv_usec - starting_time->tv_usec) / 1000);
}

void	ft_message(t_philo *philo, char *message)
{
	long	time_difference;

	time_difference = time_diff(&philo->info->starting_time);
	printf("\e[1;37m[%ld] %d %s\n", time_difference, philo->philo_index, message);
}

sem_t	*semaphore_open(char *semaphore_name, int start_value)
{
	sem_t	*result;

	sem_unlink(semaphore_name);
	result = sem_open(semaphore_name, O_CREAT | O_EXCL, 00600, start_value);
	if (result == SEM_FAILED)
		printf("Create semaphore error (\"%s\")\n", semaphore_name);
	return (result);
}

void	ft_usleep(int micro_sec)
{
	struct timeval	starting_time;

	gettimeofday(&starting_time, 0);
	while (time_diff(&starting_time) < micro_sec)
	{
		usleep(500);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:56:25 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:36:55 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_diff(struct timeval *starting_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	return ((current_time.tv_sec - starting_time->tv_sec) * 1000
		+ (current_time.tv_usec - starting_time->tv_usec) / 1000);
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

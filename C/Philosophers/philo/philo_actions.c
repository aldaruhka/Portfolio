/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:55:49 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 13:46:34 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(t_philosophers *philo, char *message)
{
	long	time_difference;

	time_difference = time_diff(&philo->info->starting_time);
	printf("\e[1;37m[%ld] %d %s\n", time_difference, philo->philo_index, message);
}

void	eating(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(&philo->info->permission_for_eat);
	philo->next->will_be_eat = 1;
	philo->will_be_eat = 0;
	pthread_mutex_unlock(&philo->info->permission_for_eat);
	pthread_mutex_lock(&philo->info->permission_for_print);
	ft_message(philo, "\e[1;33mhas taken a fork\e[1;37m");
	ft_message(philo, "\e[1;33mhas taken a fork\e[1;37m");
	ft_message(philo, "\e[0;32mis eating\e[1;37m");
	pthread_mutex_unlock(&philo->info->permission_for_print);
	pthread_mutex_lock(&philo->last_eating_time_lock);
	gettimeofday(&philo->last_eating_time, 0);
	pthread_mutex_unlock(&philo->last_eating_time_lock);
	ft_usleep(philo->info->eat_time);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	thinking(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->info->permission_for_print);
	ft_message(philo, "\e[0;35mis thinking\e[1;37m");
	pthread_mutex_unlock(&philo->info->permission_for_print);
}

void	sleeping(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->info->permission_for_print);
	ft_message(philo, "\e[0;34mis sleeping\e[1;37m");
	pthread_mutex_unlock(&philo->info->permission_for_print);
	ft_usleep(philo->info->sleep_time);
}

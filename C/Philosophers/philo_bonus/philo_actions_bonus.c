/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 11:56:38 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:01:26 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->info->permission_to_eat);
	sem_wait(philo->info->all_forks);
	sem_wait(philo->info->all_forks);
	sem_post(philo->info->permission_to_eat);
	sem_wait(philo->die_cheking);
	gettimeofday(&philo->last_eating_time, 0);
	sem_post(philo->die_cheking);
	sem_wait(philo->info->permission_for_printf);
	ft_message(philo, "\e[1;33mhas taken a fork\e[1;37m");
	ft_message(philo, "\e[1;33mhas taken a fork\e[1;37m");
	ft_message(philo, "\e[0;32mis eating\e[1;37m");
	sem_post(philo->info->permission_for_printf);
	ft_usleep(philo->info->eat_time);
	sem_post(philo->info->all_forks);
	sem_post(philo->info->all_forks);
}

void	thinking(t_philo *philo)
{
	sem_wait(philo->info->permission_for_printf);
	ft_message(philo, "\e[0;35mis thinking\e[1;37m");
	sem_post(philo->info->permission_for_printf);
}

void	sleeping(t_philo *philo)
{
	sem_wait(philo->info->permission_for_printf);
	ft_message(philo, "\e[0;34mis sleeping\e[1;37m");
	sem_post(philo->info->permission_for_printf);
	ft_usleep(philo->info->sleep_time);
}

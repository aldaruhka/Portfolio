/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process_actions_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 05:01:26 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:04:56 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	create_cheking_die_semaphore_name(t_philo *philo)
{
	int		count;
	int		i;

	count = 0;
	i = philo->philo_index;
	while (i != 0)
	{
		i = i / 10;
		count++;
	}
	philo->die_cheking_sem_name = malloc(sizeof(char) * (7 + count + 1));
	while (i < 7)
	{
		philo->die_cheking_sem_name[i] = ("/philo ")[i];
		i++;
	}
	philo->die_cheking_sem_name[7 + count] = '\0';
	i = philo->philo_index;
	while (i != 0)
	{
		philo->die_cheking_sem_name[7 + count - 1] = '0' + i % 10;
		count--;
		i /= 10;
	}
}

static void	*start_routine(void *param)
{
	t_philo	*philo;
	int		diff_time;

	philo = param;
	usleep(philo->info->die_time / 2);
	while (1)
	{
		sem_wait(philo->die_cheking);
		diff_time = time_diff(&philo->last_eating_time);
		sem_post(philo->die_cheking);
		if (diff_time >= philo->info->die_time)
		{
			sem_wait(philo->info->permission_for_printf);
			ft_message(philo, "\e[0;31mdied\e[1;37m");
			kill(0, SIGINT);
		}
		usleep(500);
	}
	return (0);
}

static void	run_new_process(t_philo *philo)
{
	pthread_t	check_for_die;

	if (philo->die_cheking == 0)
		exit(0);
	gettimeofday(&philo->last_eating_time, 0);
	pthread_create(&check_for_die, 0, &start_routine, philo);
	while (philo->eat_count != philo->info->repeat)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
		if (philo->info->repeat != -1)
			philo->eat_count++;
	}
	exit(0);
}

int	create_new_process(t_philo *philo)
{
	int	i;

	i = 0;
	gettimeofday(&philo->info->starting_time, 0);
	while (i < philo->info->number_of_philo)
	{
		philo[i].philo_index = i + 1;
		create_cheking_die_semaphore_name(&philo[i]);
		philo[i].die_cheking = semaphore_open(philo[i].die_cheking_sem_name, 1);
		philo[i].philo_pid = fork();
		if (philo[i].philo_pid < 0)
		{
			printf("Process creating error\n");
			kill(0, SIGINT);
		}
		if (!philo[i].philo_pid)
			run_new_process(&philo[i]);
		i++;
	}
	return (0);
}

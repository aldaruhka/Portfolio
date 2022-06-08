/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info_init_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:38:26 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:01:59 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_atoi(char *s)
{
	long	number;

	number = 0;
	while (s && *s == ' ')
		s++;
	if (s && *s == '+')
		s++;
	if (s && (*s < '0' || *s > '9'))
		return (-1);
	while (s && *s >= '0' && *s <= '9')
	{
		number = number * 10 + *s - '0';
		if (number > (long)INT_MAX)
			return (-1);
		s++;
	}
	if (!s || *s)
		return (-1);
	return (number);
}

static void	fill_info_with_numbers(int argc,
	char *argv[], t_philo_info *result)
{
	result->number_of_philo = ft_atoi(argv[1]);
	result->die_time = ft_atoi(argv[2]);
	result->eat_time = ft_atoi(argv[3]);
	result->sleep_time = ft_atoi(argv[4]);
	result->repeat = -1;
	if (argc == 6)
		result->repeat = ft_atoi(argv[5]);
}

static int	semaphore_init(t_philo_info *result)
{
	result->all_forks = semaphore_open(SEMAPHORE_NAME, result->number_of_philo);
	result->permission_for_printf = semaphore_open(PERMISSION_PRINT_NAME, 1);
	result->permission_to_eat = semaphore_open(PERMISSION_EAT_NAME,
			result->number_of_philo / 2);
	if (result->all_forks == SEM_FAILED
		|| result->permission_for_printf == SEM_FAILED
		|| result->permission_to_eat == SEM_FAILED)
		return (1);
	return (0);
}

t_philo_info	*philo_info_init(int argc, char *argv[])
{
	t_philo_info	*result;

	result = malloc(sizeof(t_philo_info));
	if (!result)
	{
		printf("Malloc error\n");
		return (0);
	}
	fill_info_with_numbers(argc, argv, result);
	if (semaphore_init(result))
	{
		free(result);
		return (0);
	}
	if (result->number_of_philo == -1 || result->die_time == -1
		|| result->eat_time == -1 || result->sleep_time == -1
		|| (result->repeat == -1 && argc == 6))
	{
		printf("Wrong arguments\n");
		free(result);
		result = 0;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:47:02 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:51:20 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	fill_info_with_numbers(int argc,
	char *argv[], t_philo_info *result)
{
	result->number_of_philo = ft_atoi(argv[1]);
	result->die_time = ft_atoi(argv[2]);
	result->eat_time = ft_atoi(argv[3]);
	result->sleep_time = ft_atoi(argv[4]);
	result->repeat = -1;
	result->finished = 0;
	if (argc == 6)
		result->repeat = ft_atoi(argv[5]);
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
	pthread_mutex_init(&result->permission_for_eat, 0);
	pthread_mutex_init(&result->is_finish_lock, 0);
	pthread_mutex_init(&result->permission_for_print, 0);
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

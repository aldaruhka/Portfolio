/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:38:30 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:00:57 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*philo_init(t_philo_info *info)
{
	t_philo	*philo;
	int		i;

	philo = malloc(info->number_of_philo * sizeof(t_philo));
	if (!philo)
		return (0);
	i = 0;
	while (i < info->number_of_philo)
	{
		philo[i].info = info;
		philo[i].philo_pid = -1;
		philo[i].philo_index = -1;
		philo[i].eat_count = 0;
		if (i + 1 < info->number_of_philo)
			philo[i].next = &philo[i + 1];
		if (i != 0)
			philo[i].prev = &philo[i - 1];
		i++;
	}
	philo[0].prev = &philo[info->number_of_philo - 1];
	philo[info->number_of_philo - 1].next = &philo[0];
	return (philo);
}

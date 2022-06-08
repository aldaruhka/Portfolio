/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:47:06 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:58:19 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo_info	*info;
	t_philosophers	*phylosophers;

	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	info = philo_info_init(argc, argv);
	if (!info)
		return (0);
	phylosophers = philosophers_init(info);
	if (!phylosophers)
		return (0);
	main_thread(phylosophers);
	free(phylosophers);
	free(info);
	return (0);
}

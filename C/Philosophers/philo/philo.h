/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:47:04 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 13:39:58 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_philo_info
{
	int						number_of_philo;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	int						repeat;
	int						finished;
	struct timeval			starting_time;
	pthread_mutex_t			permission_for_eat;
	pthread_mutex_t			permission_for_print;
	pthread_mutex_t			is_finish_lock;
}t_philo_info;

typedef struct s_philosophers
{
	t_philo_info			*info;
	int						philo_index;
	struct timeval			last_eating_time;
	pthread_mutex_t			fork;
	pthread_mutex_t			last_eating_time_lock;
	int						will_be_eat;
	int						eat_count;
	pthread_t				philo_thread;
	struct s_philosophers	*next;
	struct s_philosophers	*prev;
}t_philosophers;

t_philo_info	*philo_info_init(int argc, char *argv[]);

t_philosophers	*philosophers_init(t_philo_info *info);

void			main_thread(t_philosophers *phylosophers);

int				run_odd_even_threads(int i, t_philosophers *phylosophers);

void			ft_message(t_philosophers *philo, char *message);
void			eating(t_philosophers *philo);
void			thinking(t_philosophers *philo);
void			sleeping(t_philosophers *philo);

long			time_diff(struct timeval *starting_time);
void			ft_usleep(int micro_sec);

void			wait_others_philo_finishing_eat(t_philosophers *philo);
void			change_accept_of_forks(t_philosophers *philo, int value);

#endif
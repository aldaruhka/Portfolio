/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwren <dwren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:38:21 by dwren             #+#    #+#             */
/*   Updated: 2022/06/07 10:03:28 by dwren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h> //нужно в другом процессе?
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <sys/types.h>
# include <signal.h>
# include <semaphore.h>
# include <signal.h>

# define SEMAPHORE_NAME "/all_forks"
# define PERMISSION_PRINT_NAME "/permission_for_printf"
# define PERMISSION_EAT_NAME "/permission_to_eat"

typedef struct s_philo_info
{
	int						number_of_philo;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	int						repeat;
	struct timeval			starting_time;
	sem_t					*all_forks;
	sem_t					*permission_to_eat;
	sem_t					*permission_for_printf;
}t_philo_info;

typedef struct s_philo
{
	t_philo_info			*info;
	int						philo_index;
	int						eat_count;
	struct timeval			last_eating_time;
	pid_t					philo_pid;
	sem_t					*die_cheking;
	char					*die_cheking_sem_name;
	struct s_philo			*next;
	struct s_philo			*prev;
}t_philo;

t_philo_info	*philo_info_init(int argc, char *argv[]);

t_philo			*philo_init(t_philo_info *info);

void			eating(t_philo *philo);
void			thinking(t_philo *philo);
void			sleeping(t_philo *philo);

long			time_diff(struct timeval *starting_time);
void			ft_message(t_philo *philo, char *message);
sem_t			*semaphore_open(char *semaphore_name, int start_value);
void			ft_usleep(int micro_sec);

int				create_new_process(t_philo *philo);

#endif
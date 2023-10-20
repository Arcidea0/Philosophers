/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:38:12 by armgevor          #+#    #+#             */
/*   Updated: 2023/10/09 02:16:37 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include "semaphore.h"
# include <signal.h>
# include <sys/wait.h>

typedef struct s_philob
{
	long			number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			notepme;
	long			eating_count;
	long			last_eating;
	pid_t			pid[200];
	int				id;
	int				is_died;
	int				stop;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*ceat;
	sem_t			*time;

	pthread_t		tphilo;
}t_philob;

void				initb1(t_philob *philo);
void				initb(t_philob *philo, char **v, int c);
void				my_error(char *str);
void				printing(t_philob *philo, char *str);
void				sleeping(t_philob *philo);
void				eating(t_philob *philo);
void				create_philosb(t_philob *philo);
void				*checker_philos(void *struc);
unsigned long long	time_now(void);
void				init_error(void);
void				atol_error(void);
void				is_eating(t_philob *philo);
void				my_usleep(unsigned long long milsec);
int					ft_atol(char *str);
int					ft_strlen(const char *s);
int					ft_strcmp(const char *a, const char *b);
void				my_exit_bonus(t_philob *philo);

#endif
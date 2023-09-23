/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:38:12 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/23 22:47:29 by armgevor         ###   ########.fr       */
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
// # include "../philosophers.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "semaphore.h"

# include <signal.h>

typedef struct s_philob
{
	long	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	notepme;
	long	eating_count;
	long	last_eating;
	pid_t	pid[200];
	int		id;
	sem_t	fork;
	sem_t	print;
}t_philob;

void	initb1(t_philob *philo);
void	initb(t_philob *philo, char **v, int c);
void	my_error(char *str);
void	create_philos(t_philob *philo);
void	printing(t_philob *philo, char *str);
void	sleeping(t_philob *philo);
void	eating(t_philob *philo);





////////////    jnjelu
// void	must_print(t_philob *philo, char *text);
void	init_error(void);
void	atol_error(void);
void	is_eating(t_philob *philo);
// void	my_usleep(unsigned long long milsec);
unsigned long long	time_now(void);
int	ft_atol(char *str);
int	ft_strlen(const char *s);
int	ft_strcmp(const char *a, const char *b);
void	my_usleep(unsigned long long milsec);




#endif

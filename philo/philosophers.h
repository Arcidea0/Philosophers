/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:55:20 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/05 16:55:21 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philolosophers
{
	int				id;
	int				lfork;
	int				rfork;
	int				eating_count;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	long			all_eatings;
	long			last_eating;
	pthread_t		philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*is_dead;
	pthread_mutex_t	*time;
	pthread_mutex_t	*ceat;
}t_philo;

typedef struct s_data
{
	long			number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			notepme;
	pthread_mutex_t	print;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	is_dead;
	pthread_mutex_t	time;
	pthread_mutex_t	ceat;
	t_philo			philo[200];
}t_data;

unsigned long long	time_now(void);
void				atol_error(void);
void				init_error(void);
int					ft_atol(char *str);
void				init1(t_data *data, char **v, int c);
void				init2(t_data *data);
void				ararich(t_data *data);
void				my_usleep(unsigned long long milsec);
void				*sksinq(void *data);
void				must_print(t_philo *philo, char *text);
void				is_eating(t_philo *philo);
void				is_sleeping(t_philo *philo);
int					checker(t_data *data);
int					all_are_eaten(t_data *data);
void				my_exit(t_data *data);
void				unloking(pthread_mutex_t *mutex);
int					ft_strcmp(const char *a, const char *b);
int					ft_strlen(const char *s);
int					verj(t_data *data);

#endif

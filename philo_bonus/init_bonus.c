/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:37:27 by armgevor          #+#    #+#             */
/*   Updated: 2023/10/09 02:11:03 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	initb1(t_philob *philo)
{
	int	i;

	i = -1;
	while (++i < philo->number_of_philosophers)
		philo->pid[i] = -1;
	philo->eating_count = 0;
	philo->last_eating = 0;
	philo->is_died = 0;
	philo->stop = 0;
	sem_unlink("print");
	sem_unlink("forks");
	sem_unlink("ceat");
	sem_unlink("time");
	philo->print = sem_open("print", O_CREAT, 0644, 1);
	philo->forks = sem_open("forks", O_CREAT, 0644,
			philo->number_of_philosophers);
	philo->ceat = sem_open("ceat", O_CREAT, 0644, 1);
	philo->time = sem_open("time", O_CREAT, 0644, 1);
	if (philo->print <= 0 || philo->forks <= 0
		|| philo->ceat <= 0 || philo->time <= 0)
		my_error("Error: semaphore open error");
}

void	initb(t_philob *philo, char **v, int c)
{
	int		i;
	long	tivmy;

	i = 0;
	while (++i < c)
	{
		tivmy = ft_atol(v[i]);
		if ((i == 1 && tivmy < 1) || (i != 1 && tivmy < 0))
			init_error();
		if (i == 1)
			philo->number_of_philosophers = tivmy;
		else if (i == 2)
			philo->time_to_die = tivmy;
		else if (i == 3)
			philo->time_to_eat = tivmy;
		else if (i == 4)
			philo->time_to_sleep = tivmy;
		else if (i == 5)
			philo->notepme = tivmy;
	}
	if (i == 5)
		philo->notepme = -1;
	initb1(philo);
}

void	create_philosb(t_philob *philo)
{
	if (pthread_create(&philo->tphilo,
			NULL, &checker_philos, philo))
		my_error("Error: Failed to create the thread");
	if (philo->id % 2)
		my_usleep(100);
	while (1)
	{
		sem_wait(philo->forks);
		printing(philo, (char *)"has taken a fork");
		sem_wait(philo->forks);
		printing(philo, (char *)"has taken a fork");
		eating(philo);
		sem_post(philo->forks);
		sem_post(philo->forks);
		sleeping(philo);
		printing(philo, (char *)"is thinking");
	}
	if (pthread_join(philo->tphilo, NULL))
		my_error("Error: Failed to join the thread");
}

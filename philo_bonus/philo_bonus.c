/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:37:27 by armgevor          #+#    #+#             */
/*   Updated: 2023/10/09 02:29:59 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	my_error(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	exit(1);
}

int	sax_kerac_en(t_philob *philo)
{
	int	i;

	i = -1;
	while (++i < philo->number_of_philosophers)
	{
		if (philo->eating_count < philo->notepme)
			return (0);
	}
	return (1);
}

int	function(t_philob *philo)
{
	usleep(100);
	sem_wait(philo->time);
	if (time_now() - philo->last_eating
		> (unsigned long long)philo->time_to_die)
	{
		philo->is_died = 1;
		sem_wait(philo->print);
		printf("[%lld] %d %s\n", time_now(), philo->id, "is died");
		philo->stop = 1;
		return (1);
	}
	sem_post(philo->time);
	sem_wait(philo->ceat);
	if (philo->notepme != -1 && sax_kerac_en(philo))
	{
		philo->stop = 1;
		sem_wait(philo->print);
		printf("The simulation is stoped!\n");
		return (1);
	}
	sem_post(philo->ceat);
	return (0);
}

void	*checker_philos(void *struc)
{
	t_philob	*philo;

	philo = (t_philob *)struc;
	while (!philo->stop)
		if (function(philo))
			break ;
	if (philo->is_died)
		exit(41);
	else if (philo->stop)
		exit(42);
	else
		exit(0);
}

int	main(int c, char **v)
{
	t_philob	philov;
	t_philob	*philo;
	int			i;
	int			status;

	status = 0;
	if (c < 5 || c > 6)
		atol_error();
	initb(&philov, v, c);
	philo = &philov;
	i = -1;
	while (++i < philo->number_of_philosophers)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			my_error((char *)"Fork error");
		else if (philo->pid[i] == 0)
		{
			philo->id = i + 1;
			create_philosb(philo);
		}
	}
	my_exit_bonus(philo);
	return (0);
}

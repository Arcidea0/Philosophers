/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:37:27 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/23 22:53:27 by armgevor         ###   ########.fr       */
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

void	my_exit_bonus(t_philob *philo)
{
	// (void)philo;
	kill(philo->pid[philo->id - 1], 0);
	exit(1);
}

int	check_philos(t_philob *philo)
{
	int	i;

	i = -1;
	if (philo->notepme != -1 && sax_kerac_en(philo) == 1)
		my_exit_bonus(philo);
	while (++i < philo->number_of_philosophers)
	{
		if ((time_now() - philo->last_eating
				> (unsigned long long)philo->time_to_die))
		{
			printing(philo, (char *)"is died");
			return (1);
		}
	}
	return (0);
}

void	create_philos(t_philob *philo)
{
	if (philo->id % 2)
		my_usleep(100);
	while(1)
	{
		sem_wait(&philo->fork);
		printing(philo, (char *)"has taken a fork");
		sem_wait(&philo->fork);
		printing(philo, (char *)"has taken a fork");
		eating(philo);
		sem_post(&philo->fork);
		sem_post(&philo->fork);
		printing(philo, (char *)"has sleeping");
		sleeping(philo);
		printing(philo, (char *)"has thinking");
	}
}

int	main(int c, char **v)
{
	t_philob	philov;
	t_philob	*philo;
	int			i;

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
			create_philos(philo);
		}
		if (check_philos(philo))
			my_exit_bonus(philo);
	}
	return (0);
}	
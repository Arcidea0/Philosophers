/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:37:27 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/23 21:59:46 by armgevor         ###   ########.fr       */
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

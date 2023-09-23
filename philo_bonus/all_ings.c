/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_ings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:37:27 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/23 21:57:21 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	printing(t_philob *philo, char *str)
{
	sem_wait(&philo->print);
	printf("[%lld] %d %s\n", time_now(), philo->id, str);
	// if (ft_strcmp(str, (char *)"was died") == 0)
	// 	my_usleep(5);
	sem_post(&philo->print);
}

void	sleeping(t_philob *philo)
{
	printing(philo, (char *)"is sleeping");
	my_usleep(philo->time_to_sleep);
}

void	eating(t_philob *philo)
{
	my_usleep(philo->time_to_eat);
	if (philo->notepme != -1 && philo->eating_count < philo->notepme)
	{
		// sem_wait(philo->ceat);
		philo->eating_count++;
		// sem_post(philo->ceat);
	}
	sem_wait(&philo->print);
	printf("[%lld] %d %s\n", time_now(), philo->id, "is eating");
	sem_post(&philo->print);
	// sem_wait(philo->time);
	philo->last_eating = time_now();
	// sem_post(philo->time);
}

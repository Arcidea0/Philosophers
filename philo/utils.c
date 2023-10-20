/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:55:34 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/20 04:00:54 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atol(char *str)
{
	int		nshan;
	long	tiv;
	int		i;

	nshan = 1;
	tiv = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			nshan = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (tiv > 922337203685477580 || (tiv == 922337203685477580
				&& ((nshan == 1 && (str[i] - '0') > 7)
					|| (nshan == -1 && (str[i] - '0') > 8))))
			atol_error();
		tiv = tiv * 10 + str[i++] - 48;
	}
	if (str[i] != '\0')
		atol_error();
	return (nshan * tiv);
}

unsigned long long	time_now(void)
{
	struct timeval		tval;
	static int			count;
	static long long	start_time;

	gettimeofday(&tval, NULL);
	if (!count)
	{
		count = 1;
		start_time = tval.tv_sec * 1000LL + tval.tv_usec / 1000LL;
	}
	return (tval.tv_sec * 1000LL + tval.tv_usec / 1000LL - start_time);
}

void	my_usleep(unsigned long long milsec)
{
	unsigned long long	time;

	time = time_now();
	while (time_now() - time < milsec)
		;
}

void	is_eating(t_philo *philo)
{
	must_print(philo, (char *)"is eating");
	my_usleep(philo->time_to_eat);
	if (philo->all_eatings != -1 && philo->eating_count < philo->all_eatings)
	{
		pthread_mutex_lock(philo->ceat);
		philo->eating_count++;
		pthread_mutex_unlock(philo->ceat);
	}
	pthread_mutex_lock(philo->time);
	philo->last_eating = time_now();
	pthread_mutex_unlock(philo->time);
}

void	is_sleeping(t_philo *philo)
{
	must_print(philo, (char *)"is sleeping");
	my_usleep(philo->time_to_sleep);
}

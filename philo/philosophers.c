/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:55:13 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/05 16:55:14 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ararich(t_data *data)
{
	int		i;	

	i = -1;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->is_dead, NULL);
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->ceat, NULL);
	while (++i < data->number_of_philosophers)
	{	
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			return ;
		if (pthread_create(&data->philo[i].philo, NULL,
				&sksinq, (void *)&data->philo[i]))
			return ;
	}
	if (checker(data))
	{
		my_exit(data);
		return ;
	}
}

int	checker(t_data *data)
{
	int	i;

	while (1)
	{
		if (data->notepme != -1 && all_are_eaten(data) == 1)
			if (verj(data))
				return (1);
		i = -1;
		while (++i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->time);
			if ((time_now() - data->philo[i].last_eating
					> (unsigned long long)data->time_to_die))
			{
				must_print(&data->philo[i], (char *)"is died");
				return (1);
			}
			pthread_mutex_unlock(&data->time);
		}
	}
	return (0);
}

void	*sksinq(void *philov)
{
	t_philo	*philo;

	philo = (t_philo *)philov;
	if (!(philo->id % 2))
		my_usleep(50);
	while (1)
	{
		pthread_mutex_lock(&philo->fork[philo->rfork]);
		must_print(philo, (char *)"has taken a fork");
		pthread_mutex_lock(&philo->fork[philo->lfork]);
		must_print(philo, (char *)"has taken a fork");
		is_eating(philo);
		pthread_mutex_unlock(&philo->fork[philo->rfork]);
		pthread_mutex_unlock(&philo->fork[philo->lfork]);
		is_sleeping(philo);
		must_print(philo, (char *)"is thinking");
	}
	return (NULL);
}

int	main(int c, char **v)
{
	t_data	data;

	if (c < 5 || c > 6)
		atol_error();
	time_now();
	init1(&data, v, c);
	ararich(&data);
	return (0);
}

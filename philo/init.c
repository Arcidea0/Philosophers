/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:55:07 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/24 18:35:05 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init1(t_data *data, char **v, int c)
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
			data->number_of_philosophers = tivmy;
		else if (i == 2)
			data->time_to_die = tivmy;
		else if (i == 3)
			data->time_to_eat = tivmy;
		else if (i == 4)
			data->time_to_sleep = tivmy;
		else if (i == 5)
			data->notepme = tivmy;
	}
	if (i == 5)
		data->notepme = -1;
	init2(data);
}

void	init2(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philo[i].id = i + 1;
		if (i == 0)
			data->philo[i].lfork = data->number_of_philosophers - 1;
		else
			data->philo[i].lfork = i - 1;
		data->philo[i].rfork = i;
		data->philo[i].eating_count = 0;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].all_eatings = data->notepme;
		data->philo[i].last_eating = 0;
		data->philo[i].fork = data->fork;
		data->philo[i].print = &data->print;
		data->philo[i].is_dead = &data->is_dead;
		data->philo[i].time = &data->time;
		data->philo[i].ceat = &data->ceat;
	}
}

int	all_are_eaten(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->ceat);
		if (data->philo[i].eating_count < data->philo[i].all_eatings)
		{
			pthread_mutex_unlock(&data->ceat);
			return (0);
		}
		else
			pthread_mutex_unlock(&data->ceat);
	}
	return (1);
}

void	must_print(t_philo *philo, char *text)
{
	pthread_mutex_lock(philo->print);
	printf("[%lld] %d %s\n", time_now(), philo->id, text);
	if (ft_strcmp(text, "was died") == 0)
		my_usleep(5);
	pthread_mutex_unlock(philo->print);
}

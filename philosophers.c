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
			verj(data);
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
	int		i;
	t_philo	*philo;

	philo = (t_philo *)philov;
	i = -1;
	if (!(philo->id % 2))
		my_usleep(100);
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

	// system("leaks philo");
	// i = -1;
	// while(++i < data->number_of_philosophers)
	// 	pthread_join(data->philo[i].philo, NULL);
	// checker(data);
	// 
	// int i = -1;
	// while(++i < data.number_of_philosophers)
	// 	printf("[%d] [%d] [%d]\n", data.philo[i].id,
	//		data.philo[i].lfork, data.philo[i].rfork);
	// printf ("[%llu]\n", time_now());
	// while(++i < data.number_of_philosophers)
	// 	printf("%d\n", data.philo[i].id);
	// printf("\n\n%lu\n", data.number_of_philosophers);
	// printf("%lu\n", data.time_to_die);
	// printf("%lu\n", data.time_to_eat);
	// printf("%lu\n", data.time_to_sleep);
	// printf("%lu\n", data.number_of_times_each_philosopher_must_eat);

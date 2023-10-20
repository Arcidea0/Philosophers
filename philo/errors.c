/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:55:01 by armgevor          #+#    #+#             */
/*   Updated: 2023/10/06 15:17:06 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	atol_error(void)
{
	printf("Inputy piti lini hetevyaly\n");
	printf("1) number_of_philosophers\n");
	printf("2) time_to_die\n");
	printf("3) time_to_eat\n");
	printf("4) time_to_sleep\n");
	printf("Ev anhrajeshtutyan depqum\n");
	printf("5) number_of_times_each_philosopher_must_eat\n");
	printf("///Chmoranaq vor arjeqnery piti linen miayn tvayin\\\\\\\n");
}

void	init_error(void)
{
	printf("Bales pilisopaneri tivy piti 1-ic mec lini");
	printf(", isk mnacacy` 60-ic");
}

void	my_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_detach(data->philo[i].philo);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->is_dead);
	pthread_mutex_destroy(&data->time);
	pthread_mutex_destroy(&data->ceat);
}

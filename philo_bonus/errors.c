/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:37:27 by armgevor          #+#    #+#             */
/*   Updated: 2023/10/09 00:43:10 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	exit(1);
}

void	init_error(void)
{
	printf("Bales pilisopaneri tivy piti 1-ic mec lini");
	printf(", isk mnacacy` 60-ic");
	exit(1);
}

void	my_exit_bonus(t_philob *philo)
{
	int	i;
	int	status;

	i = -1;
	waitpid(-1, &status, 0);
	if (status != 0)
	{
		i = -1;
		while (++i < philo->number_of_philosophers && philo->pid[i])
			kill(philo->pid[i], SIGKILL);
	}
	sem_close(philo->print);
	sem_close(philo->forks);
	sem_close(philo->ceat);
	sem_close(philo->time);
	sem_unlink("print");
	sem_unlink("forks");
	sem_unlink("ceat");
	sem_unlink("time");
	exit(1);
}

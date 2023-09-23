/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:55:13 by armgevor          #+#    #+#             */
/*   Updated: 2023/09/23 03:02:26 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *a, const char *b)
{
	int	m;
	int	i;

	if (!a && !b)
		return (0);
	m = ft_strlen(b);
	if (ft_strlen(a) >= ft_strlen(b))
		m = ft_strlen(a);
	i = -1;
	while (++i < m)
		if (a[m] != b[m])
			return (a[i] - b[i]);
	if (i != m)
		return (a[i] - b[i]);
	return (0);
}

void	verj(t_data *data)
{
	pthread_mutex_lock(&data->print);
	printf("The simulation is stoped!\n");
	my_usleep(90);
	my_exit(data);
	exit (0);
}

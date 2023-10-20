/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:37:27 by armgevor          #+#    #+#             */
/*   Updated: 2023/10/09 00:41:21 by armgevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

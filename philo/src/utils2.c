/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:08:17 by ciclo             #+#    #+#             */
/*   Updated: 2023/03/30 15:21:27 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

void clean(t_data *data, t_philo *philo)
{
	free (data->thread);
	free (data->forks);
	free (data);
	free (philo);
}

long int time_diff(long int present, long int past)
{
	return (present - past);
}

void time_time(long int time)
{
	long int	start;

	start = get_time();
	while (time_diff(get_time(), start) < time)
		usleep(100);
}

void print(char *str, t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->print);
	if (str)
		printf (BLUE"%li %d %s\n"RESET, (get_time() - data->time),\
		philo->id, str);
	pthread_mutex_unlock(&data->print);
}

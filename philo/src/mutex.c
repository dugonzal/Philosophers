/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:56:59 by dugonzal          #+#    #+#             */
/*   Updated: 2023/04/01 22:54:32 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

t_data	*mutex_init(t_data *data)
{
	int	i;

	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* data->philo_num);
	if (!data->forks)
		return (NULL);
	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init (&data->forks[i], NULL);
	pthread_mutex_init (&data->print, NULL);
	return (data);
}

void	mutex_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_destroy (&data->forks[i]);
	pthread_mutex_destroy (&data->print);
	pthread_mutex_destroy (&data->dead_mutex);
}

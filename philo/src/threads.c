/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:54:38 by dugonzal          #+#    #+#             */
/*   Updated: 2023/04/03 10:29:54 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

static void	init(t_data *data, t_philo *philo, int i)
{
	while (++i < data->philo_num)
	{
		philo[i].id = i;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->philo_num;
		philo[i].data = data;
		philo[i].last_eat = data->time;
		pthread_create (&data->thread[i], NULL, &philo_rutine, &philo[i]);
	}
}

void	init_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	data->thread = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
	if (!philo || !data->thread)
		free_data(data, RED"Error: malloc failed"RESET);
	memset (philo, 0, sizeof(t_philo) * data->philo_num);
	mutex_init (data);
	data->time = get_time ();
	i = -1;
	init (data, philo, i);
	i = -1;
	while (++i < data->philo_num)
		pthread_detach (data->thread[i]);
	check_dead (philo);
	clean (data, philo);
}

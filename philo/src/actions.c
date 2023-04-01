/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:23:47 by ciclo             #+#    #+#             */
/*   Updated: 2023/04/01 21:24:08 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

int	eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock (&data->forks[philo->left_fork]);
	print_log("has taken a fork", philo, data);
	if (data->dead)
		return (1);
	pthread_mutex_lock (&data->forks[philo->right_fork]);
	print_log("has taken a fork", philo, data);
	time_time(data->time_to_eat);
	print_log("is eating", philo, data);
	philo->last_eat = get_time();
	philo->eat_count++;
	if (philo->eat_count == data->must_eat)
		data->eat_count++;
	if (data->dead)
		return (1);
	pthread_mutex_unlock (&data->forks[philo->left_fork]);
	pthread_mutex_unlock (&data->forks[philo->right_fork]);
	return (0);
}

int	sleep_philo(t_data *data, t_philo *philo)
{
	time_time(data->time_to_sleep);
	print_log("is sleeping", philo, data);
	if (data->dead)
		return (1);
	return (0);
}

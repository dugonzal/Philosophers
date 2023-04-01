/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/04/01 17:55:05 by dugonzal         ###   ########.fr       */
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

void	check_dead(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	while (42)
	{
		if (data->eat_count == data->philo_num)
			break ;
		else if ((get_time() - philo->last_eat) >= data->time_to_die)
		{
			pthread_mutex_lock(&data->dead_mutex);
			data->dead = 1;
			print_log("died", philo, data);
			pthread_mutex_lock(&data->print);
			pthread_mutex_unlock(&data->dead_mutex);
			break ;
		}
		usleep(100);
	}
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
}

/// @brief
/// @param philo
/// @param data
void	philo_life(t_philo *philo, t_data *data)
{
	while (42)
	{
		if (eat(data, philo))
			break ;
		if (sleep_philo(data, philo))
			break ;
		if (data->eat_count == data->philo_num)
			break ;
		print_log("is thinking", philo, data);
	}
}

void	*philo_rutine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	philo_life(philo, data);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	parser(ac, av, &data);
	exit (EXIT_SUCCESS);
}

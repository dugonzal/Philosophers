/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/04/04 11:25:35 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

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
	pthread_mutex_destroy(&data->print);
}

void	philo_life(t_philo *philo, t_data *data)
{
	while (42)
	{
		if (eat(data, philo))
			break ;
		if (sleep_philo(data, philo))
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
	if (philo->id % 2 != 0)
		time_time(data->time_to_die / 10);
	philo_life(philo, data);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_args(av);
	parser(ac, av, &data);
	init_threads(&data);
	exit (EXIT_SUCCESS);
}

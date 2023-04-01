/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:02:23 by dugonzal          #+#    #+#             */
/*   Updated: 2023/04/01 15:02:48 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

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

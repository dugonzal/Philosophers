/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/02/28 14:25:04 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

// teseting programing
// ./filosofers 5 500 300 200 10

/*
philosofers.c:
se trata de implementar una solución para el problema de los filósofos que
intentan comer de un plato y necesitan dos tenedores para hacerlo.

pthread_create -> crea un hilo nuevo para cada filosofo
pthread_join -> espera a que el hilo termine
pthread_mutex_init -> inicializa el mutex
pthread_mutex_lock -> bloquea el mutex
pthread_mutex_unlock -> desbloquea el mutex
*/

void	*filosopher(void *arg)
{
	t_philo	*philo;

	philo =  (t_philo *)arg;
	//while (42)
		printf("filosofo #: -> [%d]\n", philo->id);
	return (NULL);
}

void create_threads(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->philo_num)
	{
		data->philo[i].id = i;
		pthread_create(&data->philo[i].thread, NULL, &filosopher, &data->philo[i]);
	}
	i = -1;
	while (++i < data->philo_num)
		pthread_join(data->philo[i].thread, NULL);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error(RED"Error: malloc failed\n"RESET);
	memset(data, 0, sizeof(t_data));
	parser(ac, av, data);
	create_threads(data);
	exit (EXIT_SUCCESS);
}

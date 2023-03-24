/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/03/03 20:39:01 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

// teseting programing
// ./filosofers 5 500 300 200 10

/*
philosofers.c:
se trata de implementar una solución, para el problema de los filósofos que
intentan comer de un bol de espaguetis necesitan dos tenedores para hacerlo
y cada filosofo solo tiene uno.

pthread_create -> crea un hilo nuevo para cada filosofo
pthread_join -> espera a que el hilo termine
pthread_mutex_init -> inicializa el mutex
pthread_mutex_lock -> bloquea el mutex
pthread_mutex_unlock -> desbloquea el mutex
pthread_mutex_destroy -> destruye el mutex
*/

void	*philo_rutine(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	while (43)
	{
		printf (GREEN"philo exist xd: -> {%d}\n"RESET, philo->id);
		sleep (1);
	}
	return (NULL);
}


void create_threads(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_create(&data->philo[i].thread, NULL, &philo_rutine, &data->philo[i]);
		data->philo[i].id = i;
	}
}

void	monitoring(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->philo_num)
		pthread_join(data->philo[i].thread, NULL);
}


/*
 *inicializacion de los mutex mientras i sea menor o igual que el numero de filosofos
:
 * */
void  mutex_init(t_data *data)
{
  int i;

  i = data->philo_num;
    printf ("%d", i);
  while (i-- <= data->philo_num)
  {
    if (!(pthread_mutex_init(&data->forks[i], NULL)))
      break;
  }
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error(RED"Error: malloc failed\n"RESET);
	memset(data, 0, sizeof(t_data));
	parser(ac, av, data);
	create_threads(data);
  mutex_init (data);
	monitoring (data);
	exit (EXIT_SUCCESS);
}

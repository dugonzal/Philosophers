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
se trata de implementar una solución para el problema de los filósofos que
intentan comer de un bol de espaguetis necesitan dos tenedores para hacerlo
y cada filosofo solo tiene uno.

pthread_create -> crea un hilo nuevo para cada filosofo
pthread_join -> espera a que el hilo termine
pthread_mutex_init -> inicializa el mutex
pthread_mutex_lock -> bloquea el mutex
pthread_mutex_unlock -> desbloquea el mutex
pthread_mutex_destroy -> destruye el mutex
*/

/*

void	*filosopher_rutine(void *arg)
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
		pthread_create(&data->philo[i].thread, NULL, &filosopher_rutine, &data->philo[i]);
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

 *inicializacion de los mutex mientras i sea menor o igual que el numero de filosofos
 , 
 * */
/*
void  mutex_init(t_data *data)
{
  int i;

  i = data->philo_num;
  while (i-- <=  data->philo_num)
  {
    pthread_mutex_init(&data->forks[i], NULL);
  }
}*/

void *philo_rutine(void *args)
{
  t_philo *philo;
  t_data *data;

  printf ("entra");
  philo = (t_philo *)args;
  data = philo->data;
  printf ("philo exits -<[%d] [%d]\n", philo->id, data->philo_num);
  return (NULL);
}
void *init(t_data *data)
{
  t_philo *philo;
  int i;

  i = -1;
  philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
  data->thread = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
  if (!philo || !data->thread || philo->data)
    return (NULL);
  memset (philo, 0, sizeof(t_philo) * data->philo_num);
  while (++i < data->philo_num)
  {
    philo[i].id = i;
    philo[i].data = data;
    pthread_create (&data->thread[i], NULL, &philo_rutine, &philo[i]);
  }
  i = 0;
  while (i < data->philo_num)
  {
    pthread_join (data->thread[i], NULL);
    i++;
  }

  return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	parser(ac, av, &data);
//	create_threads(data);
 // mutex_init (data);
//	monitoring (data);
	exit (EXIT_SUCCESS);
}

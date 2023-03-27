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

void *philo_rutine(void *args)
{
  t_philo *philo;
  t_data *data;

  philo = (t_philo *)args;
  data = philo->data;
  printf ("philo exits -<[%d] [%d] [%d] [%d]\n", philo->id, data->philo_num, data->dead, data->must_eat);
  return (NULL);
}
void *init_threads(t_data *data)
{
  t_philo *philo;
  int i;

  i = 0;
  philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
  data->thread = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
  if (!philo || !data->thread)
    return (NULL);
  memset (philo, 0, sizeof(t_philo) * data->philo_num);
  while (i < data->philo_num)
  {
    philo[i].id = i;
    philo[i].left_fork = i;
    philo[i].data = data;
    pthread_create (&data->thread[i], NULL, &philo_rutine, &philo[i]);
    i++;
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
	exit (EXIT_SUCCESS);
}

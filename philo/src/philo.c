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

void  *philo_rutine(void *args)
{
  t_philo *philo;
  t_data  *data;

  philo = (t_philo *)args;
  data = philo->data;
  (void)data;
//  pthread_mutex_lock (&data->forks[philo->left_fork]);
 // while (42)
  printf ("philo exits -<[%d] -< tenedor i<quierdo -<[%d] tenedor derecho -<[%d]\n", philo->id, philo->left_fork, philo->right_fork);
  //pthread_mutex_unlock (&data->forks[philo->left_fork]);
  return (NULL);
}

void  *mutex_init(t_data *data, t_philo *philo)
{
  int i;

  data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_num);
  if (!data->forks)
   return (NULL);
  i = 0;
  while (i < data->philo_num)
  {
    pthread_mutex_init (&data->forks[i], NULL);
    i++;
  }
  (void)philo;
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
    philo[i].right_fork = (i + 1) % data->philo_num;
    philo[i].data = data;
    pthread_create (&data->thread[i], NULL, &philo_rutine, &philo[i]);
    i++;
    //  break;
  }
  i = 0;
  mutex_init (data, philo);
    while (i < data->philo_num)
    {
      pthread_join (data->thread[i], NULL);
     // break;
      i++;
    }
  return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	parser(ac, av, &data);
  long long i = get_time();
  printf ("[%lld]\n", i);
	exit (EXIT_SUCCESS);
}

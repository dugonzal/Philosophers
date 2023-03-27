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
pthread_mutex_init -> inicializa el mutex
pthread_mutex_lock -> bloquea el mutex
philo_rutine ->  la rutina del filosofo, lo que aun no veo es que nececesita dos mutex para hacer su rutina
pthread_mutex_unlock -> desbloquea el mutex
pthread_join -> espera a que el hilo termine
pthread_mutex_destroy -> destruye el mutex
*/
/*
 * tengo que reservar memoria para los hilos y los mutex es lo que no veia xf
 * */

void *philo_rutine(void *args)
{
  t_philo *philo;

  philo = (t_philo *)args;
  printf ("%d", philo->data->philo_num);
  return (NULL);
}

void init(t_data *data, t_philo *philo)
{
  philo->data = malloc(sizeof(t_data) * data->philo_num); // igual fallaba poorque no reservaba memoria
  if (!philo->data)
    return ;

  // reservar memoria a los hilos xd;
  data->thread = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
  if (!data->thread)
    return ;
  int i = 0;
  while (i++ < data->philo_num)
  {
    //philo->data = data;
    pthread_create (&data->thread[i], NULL, &philo_rutine, &philo[i]);
  }
  int j = 0;
  while (j++ < data->philo_num)
    pthread_join(data->thread[j], NULL);
}
  


int	main(int ac, char **av)
{
	t_data	data;

  parser(ac, av, &data);
  //printf ("[%d]", data.philo_num);
 // monitor (&data);
  //init_mutex (&data);
  //mutex_destroy (&data);
  exit (EXIT_SUCCESS);
}

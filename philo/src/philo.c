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
/*
void  *philo_rutine(void *arg)
{
  t_philo *philo;
  t_data *data;
 
  philo = (t_philo *)arg;
  data = philo->data;
  printf ("%p", &data);
  //ww(data);
  //pthread_mutex_lock ();
// printf ("%d",  data->philo_num);
  printf ("philo exist -<[%d]\n", philo->id);
 //pthread_mutex_unlock (&philo->data->forks[0]);
  return (NULL);
}
void  crear_hilos(t_data *data)
{
  int i;

  i = 0;
  while (i++ < data->philo_num)
  {
   // data->philo[i].id = i;
   // data->philo[i].left_fork = i;
    pthread_create(&data->philo[i].thread, NULL, &philo_rutine, &data->philo[i]);
  }
}
void init_mutex(t_data *data)
{
  int i;

  i = 0;
  data->forks = ()
  while (i++ < data->philo_num)
  {
    pthread_mutex_init(&(data->forks[i]), NULL);
  }
}
void monitor(t_data *data)
{
  int i;

  i = 0;
  while (i++ < data->philo_num)
  {
    pthread_join (data->philo[i].thread, NULL);
  }
}

void  mutex_destroy(t_data *data)
{
  int i;

  i = 0;
  while (i++ < data->philo_num)
  {
    pthread_mutex_destroy (&data->forks[i]);
  }

}
*/


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

void *filo_rutine(void *args)
{
  t_philo *philo; 
  t_data *data;
  
  philo = (t_philo *)args;
  data = philo->data;

  printf ("philo-< [%d] [%p]\n", philo->id, data); 
  return (NULL);
}


void init(t_data *data, t_philo *philo)
{
  data->thread = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);// hago un malloc a los hilos;
  if (!data->thread)
    return ;
  philo->data = malloc(sizeof(philo->data));
  if (!philo->data)
    return;
  int i;
  int j;
  i = 0;
  while (i++ < data->philo_num)
  {
   philo[i].data = data; // nececesitaba guardar la info en la estrcutura del philoso para acceder a ella no se iba almacenar derrepente lol
    pthread_create (&data->thread[i], NULL, &filo_rutine, &philo[i]);
  }
  
  j = 0;
  //sleep (3);
 while (j++ < data->philo_num)
    pthread_join (data->thread[j], NULL);
 // free (philo);
}

/*
 * tengo que reservar memoria para los hilos y los mutex es lo que no veia xf
 * */
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

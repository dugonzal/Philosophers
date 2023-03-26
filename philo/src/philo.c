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
void	*philo_rutine(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
 //pthread_mutex_lock (&philo->data->forks[0]);
  //	while (43)
	{
		printf (GREEN"philo exist xd: -> {%d}\n"RESET, philo->id);
//		sleep (1);
 //pthread_mutex_unlock(&philo->data->forks[0]);
  //	while (43)
	}
	return (NULL);
}


void create_threads(t_data *data)
{
	int i;
  int error;

  i = 0;
  error = 0;
	while (i++ < data->philo_num)
	{
		data->philo[i].id = i;
    data->philo[i].left_fork = i;
		error = pthread_create(&data->philo[i].thread, NULL, &philo_rutine, &data->philo[i]);
	  if (error != 0)
    {
      printf ("error al crear el hilo");
      break;
    }
   // printf ("\ndespues -<%d %d\n", i, error);
  }
}

void	monitoring(t_data *data)
{
	int i;
  int error;

  error = 0;
	i = 0;
	while (i++ < data->philo_num)
  {
    error = pthread_join(data->philo[i].thread, NULL);
    if (error != 0)
    {
      printf ("error al esperar a que los hilos acaben");
      break;
    }
    printf ("[%d]\n", i);
  }
}

 *inicializacion de los mutex mientras i sea menor o igual que el numero de filosofos
:

void  mutex_init(t_data *data)
{
  int i;  

  i = 0;
  int error = 0;
  while (i++ < data->philo_num)
  {
  //  printf ("%d", i);
    (error = pthread_mutex_init(&(data->forks[i]), NULL));
    if (error != 0)
    {
      printf ("algo va mal");
      break;
    }
  }
}

void  mutex_destroy(t_data *data)
{
  int i;
  int error;

  error = 0;
  i = 0;
  while (i++ < data->philo_num)
  {
    if (error != 0)
    error = pthread_mutex_destroy (&data->forks[i]);
    {
      printf ("error al destruir los mutex");
      break;
    }
  }
}
*/

void ww(t_data *data)
{
  int i;

  i = 0;
  while (i++ < data->philo_num)
  {
    printf ("[%d]", i);
  }
}

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

void init(t_data *data)
{
  crear_hilos (data);
  monitor (data);
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

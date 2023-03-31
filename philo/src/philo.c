/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/03/31 10:59:45 by ciclo            ###   ########.fr       */
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
 * los filósofos solo comen piensan y duermen
 * si comen, no piensan ni duermen -> funcion de comer
 * si piensan no comen ni duermen  -> funcion de pensar
 * si duermen no piensan ni comen  -> funcion de dormir
 *
 */
/*
si el philo no empieza a comer en x tiempo desde el inicio del programa
o desde su ultimo bocado, muere
*/

int dead(t_data *data, t_philo *philo)
{
	if ((get_time() - philo->last_eat) >= data->time_to_die)
	{
		print_log("died", philo, data);
		data->dead += 1;
		return (1);
	}
	return (0);
}

void eat_sleep(t_data *data, t_philo *philo)
{
  	pthread_mutex_lock (&data->forks[philo->left_fork]);
		print_log("has taken a fork", philo, data);
		dead (data, philo);
		pthread_mutex_lock (&data->forks[philo->right_fork]);
		print_log("has taken a fork", philo, data);
		time_time(data->time_to_eat);
		philo->last_eat = get_time();
		print_log("is eating", philo, data);
		pthread_mutex_unlock (&data->forks[philo->left_fork]);
		pthread_mutex_unlock (&data->forks[philo->right_fork]);
  	time_time(data->time_to_sleep);
		print_log("is sleeping", philo, data);
		philo->eat_count++;
}

void	philo_life(t_philo *philo, t_data *data)
{
	while (!data->dead)
	{
    eat_sleep(data, philo);
		if (data->must_eat == philo->eat_count)
			break;
			dead (data, philo);
		print_log("is thinking", philo, data);
		dead (data, philo);
	}
}

void  *philo_rutine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data  = philo->data;
	if (philo->id % 2 == 0)
		time_time(2);
	philo_life(philo, data);
	return (NULL);
}

t_data	*mutex_init(t_data *data)
{
	int	i;

	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (NULL);
	i = -1;
	while (++i < data->philo_num )
		pthread_mutex_init (&data->forks[i], NULL);
	pthread_mutex_init (&data->print, NULL); // no hace falta hacer malloc porque es un puntero
	return (data);
}

void 	mutex_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_destroy (&data->forks[i]);
	pthread_mutex_destroy (&data->print);
}

void *philo_dead(void *args)
{
  t_philo *philo;
  t_data *data;

  philo = args;
  data = philo->data;
  return (NULL);
}

void	init_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	data->thread = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
	if (!philo || !data->thread)
		free_data(data, RED"Error: malloc failed"RESET);
	memset (philo, 0, sizeof(t_philo) * data->philo_num);
	mutex_init (data);
	data->time = get_time ();
	i = -1;
	pthread_create (&data->thread_dead, NULL, &philo_dead, &philo);
	while (++i < data->philo_num)
	{
		philo[i].id = i;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->philo_num;
		philo[i].data = data;
		philo[i].last_eat = data->time; // asi todos los filosofos tienen el mismo tiempo
		pthread_create (&data->thread[i], NULL, &philo_rutine, &philo[i]);
	}
	i = -1;
	pthread_join (data->thread_dead, NULL);
	while (++i < data->philo_num)
		pthread_join (data->thread[i], NULL);
	mutex_destroy (data);
	clean (data, philo);
}

int	main(int ac, char **av)
{
	t_data	data;

	parser(ac, av, &data);
	exit (EXIT_SUCCESS);
}

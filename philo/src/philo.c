/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/04/01 14:54:45 by dugonzal         ###   ########.fr       */
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
 * los filósofos solo comen piensan y duermen
 * si comen, no piensan ni duermen -> funcion de comer
 * si piensan no comen ni duermen  -> funcion de pensar
 * si duermen no piensan ni comen  -> funcion de dormir
si el philo no empieza a comer en x tiempo desde el inicio del programa
o desde su ultimo bocado, muere
* si algun filosofo muere, todos los demas deben morir, estoy buscando la forma de implementarlo
* si todos los filosofos han comido al menos N veces, el programa termina
* podria dividir comer, pensar y dormir en funciones diferentes y llamarlas en un bucle
* y en cada iteracion comprobar si algun filosofo ha muerto y si todos han comido N veces
*/

/// @brief
/// @param data
/// @param philo
/// @return
int	eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock (&data->forks[philo->left_fork]);
	print_log("has taken a fork", philo, data);
	if (data->dead)
		return (1);
	pthread_mutex_lock (&data->forks[philo->right_fork]);
	print_log("has taken a fork", philo, data);
	time_time(data->time_to_eat);
	print_log("is eating", philo, data);
	philo->last_eat = get_time();
	philo->eat_count++;
	if (philo->eat_count == data->must_eat)
		data->eat_count++;
	if (data->dead)
		return (1);
	pthread_mutex_unlock (&data->forks[philo->left_fork]);
	pthread_mutex_unlock (&data->forks[philo->right_fork]);
	return (0);
}

/// @brief
/// @param data
/// @param philo
/// @return
int	sleep_philo(t_data *data, t_philo *philo)
{
	time_time(data->time_to_sleep);
	print_log("is sleeping", philo, data);
	if (data->dead)
		return (1);
	return (0);
}

void	check_dead(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	while (42)
	{
		if (data->eat_count == data->philo_num)
			break ;
		else if ((get_time() - philo->last_eat) >= data->time_to_die)
		{
			pthread_mutex_lock(&data->dead_mutex);
			data->dead = 1;
			print_log("died", philo, data);
			pthread_mutex_lock(&data->print);
			pthread_mutex_unlock(&data->dead_mutex);
			break ;
		}
		usleep(100);
	}
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
}

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

int	main(int ac, char **av)
{
	t_data	data;

	parser(ac, av, &data);
	exit (EXIT_SUCCESS);
}

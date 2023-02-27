/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:39 by ciclo             #+#    #+#             */
/*   Updated: 2023/02/27 11:54:08 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
#define PHILOSOFERS_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<pthread.h>

typedef struct s_philo
{
	int			id; // id del filosofo
	pthread_t	thread; // hilo del filosofo
	int			left_fork; // id del tenedor izquierdo
	int			right_fork; // id del tenedor derecho
	int			eat_count; // numero de veces que ha comido
}t_philo;

typedef struct s_data
{
	int			philo_num;	// numero de filosofos
	int			time_to_die; // tiempo que muere
	int			time_to_eat; // tiempo que come
	int			time_to_sleep; // tiempo que duerme
	int			must_eat; // -1 si no se pasa como argumento
	t_philo		*philo;
}	t_data;


int	ft_atoi(const char *str);

#endif

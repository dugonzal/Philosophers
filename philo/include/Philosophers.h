/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:39 by ciclo             #+#    #+#             */
/*   Updated: 2023/02/27 17:57:26 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
#define PHILOSOFERS_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<pthread.h>
#include	<unistd.h>
#include	<sys/time.h>

// colores para la impresion
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"
typedef struct s_philo
{
	int			id; // id del filosofo
	int			left_fork; // id del tenedor izquierdo
	int			right_fork; // id del tenedor derecho
	int			eat_count; // numero de veces que ha comido
}t_philo;

typedef struct s_data
{
	pthread_t	thread; // hilo del filosofo
	int			philo_num;	// numero de filosofos
	int			time_to_die; // tiempo que muere
	int			time_to_eat; // tiempo que come
	int			time_to_sleep; // tiempo que duerme
	int			must_eat; // -1 si no se pasa como argumento
	t_philo		*philo;
}	t_data;


int		ft_atoi(const char *str);
void	parser(int ac, char **av, t_data *data);
void	error(char *s);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif

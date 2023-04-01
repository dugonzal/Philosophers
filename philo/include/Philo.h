/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:39 by ciclo             #+#    #+#             */
/*   Updated: 2023/04/01 10:54:23 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

typedef struct s_data
{
	int 			philo_num;	// numero de filosofos
	int 			time_to_die; // tiempo que muere si no come;
	int 			time_to_eat; // tiempo que come
	int				time_to_sleep; // tiempo que duerme
	int				must_eat; // -1 si no se pasa como argumento
	int				dead; // aqui guradamos si hay algun filsf muerto
	long int		time;
	pthread_t		*thread; // hilo del filosofo
//	pthread_t		thread_dead; // hilo del filosofo
	pthread_mutex_t	*forks; // array de mutex de los tenedores
	pthread_mutex_t	print; // mutex para imprimir
	pthread_mutex_t	dead_mutex; // mutex para imprimir
}	t_data;

typedef struct s_philo
{
	int				id; // id del filosofo
	int				left_fork; // id del (tenedor o mutex) izquierdo
	int				right_fork; // id del (tenedor o mutex) derecho
	int				eat_count; // numero de veces que ha comido
	long int		last_eat; // tiempo en el que ha comido
	int				last_meal_time; // la ultima vez que ha comido
	struct s_data 	*data; // estructura general del programa
}	t_philo;

int			ft_atoi(const char *str, t_data *data);
t_data		*parser(int ac, char **av, t_data *data);
void		error(char *s);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
void		init_threads(t_data *data);
long int	get_time(void);
void		clean(t_data *data, t_philo *philo);
long int	time_diff(long int present, long int past);
void		time_time(long int time);
void		print_log(char *str, t_philo *philo, t_data *data);
void		*free_data(t_data *data, char *s);
void		mutex_destroy(t_data *data);
t_data		*mutex_init(t_data *data);
void		*philo_rutine(void *args);

#endif

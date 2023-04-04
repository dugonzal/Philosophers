/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:15:39 by ciclo             #+#    #+#             */
/*   Updated: 2023/04/04 20:26:23 by dugonzal         ###   ########.fr       */
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
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				dead;
	long int		time;
	pthread_t		*thread;
	int				eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long int		last_eat;
	int				last_meal_time;
	struct s_data	*data;
}	t_philo;

int			ft_atoi(const char *str);
void		parser(int ac, char **av, t_data *data);
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
void		mutex_init(t_data *data);
void		*philo_rutine(void *args);
void		check_dead(t_philo *philo);
int			eat(t_data *data, t_philo *philo);
int			sleep_philo(t_data *data, t_philo *philo);
void		check_args(char **av);
#endif

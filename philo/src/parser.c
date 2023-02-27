/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:26:50 by ciclo             #+#    #+#             */
/*   Updated: 2023/02/27 18:13:20 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philosophers.h"

void	help_msg(void)
{
	printf (BLUE"Philosophers: opcion help -> flag: [--help] [-h]\n\n"RESET);
	printf ("Usage:	 ./philosofers number_of_philosophers time_to_die time_to_eat \
	time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	printf ("Uso:	 ./filosofers numero_de_filosofos tiempo_para_morir \
	tiempo_para_comer tiempo_para_dormir [numero_de_veces_que_cada_filosofo_debe_comer]\n");
	printf ("Example: ./philosofers 5 800 200 200 [5]\n");
	exit (EXIT_SUCCESS);
}

void	parser(int ac, char **av, t_data *data)
{
	if (ft_strcmp(av[1], "-h") == 0 || ft_strcmp(av[1], "--help") == 0)
		help_msg();
	if (ac < 5 || ac > 6)
		error (RED"Error: argumentos invalidos\n"RESET);
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	data->philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philo)
		error(RED"Error: malloc failed\n"RESET);
	memset(data->philo, 0, sizeof(t_philo) * data->philo_num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:26:50 by ciclo             #+#    #+#             */
/*   Updated: 2023/04/04 20:26:12 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

void	help_msg(void)
{
	printf (BLUE"Philosophers: opcion help -> flag: [-h] [--help]\n\n"RESET);
	printf ("Usage:	 ./philo number_of_philosophers time_to_die time_to_eat \
	time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	printf ("Uso:	 ./philo numero_de_filosofos tiempo_antes_de_comer \
	tiempo_para_comer tiempo_para_dormir \
	[numero_de_veces_que_cada_filosofo_debe_comer]\n");
	printf ("Example: ./philosofers 5 800 200 200 [5]\n");
	exit (EXIT_SUCCESS);
}

static int	ft_isdigit(int c)
{
	return (c < 48 || c > 58);
}

void	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j + 1] == '+' || av[i][j + 1] == '-')
					error (RED"Error: -> no es un numero\n"RESET);
				else
					break ;
			}
			else if (ft_isdigit(av[i][j]))
				error (RED"Error: -> no es un numero\n"RESET);
			j++;
		}
		i++;
	}
}

void	parser(int ac, char **av, t_data *data)
{
	memset (data, 0, sizeof(t_data));
	if ((ac > 1 && !ft_strcmp(av[1], "-h")) || \
	(ac > 1 && !ft_strcmp(av[1], "--help")))
		help_msg();
	if (ac < 5 || ac > 6)
		error(RED"Error: -> numero de argumentos \
		invalido\n"RESET);
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
}

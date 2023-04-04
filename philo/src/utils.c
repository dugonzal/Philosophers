/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:57:44 by ciclo             #+#    #+#             */
/*   Updated: 2023/04/04 20:22:56 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philo.h"

int	ft_atoi(const char *str)
{
	unsigned long int	nbr;

	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == 45)
	{
		printf (RED"Error: no puede ser negativo\n"RESET);
		exit (EXIT_FAILURE);
	}
	if (*str == 43)
		str++;
	nbr = 0;
	while (*str && *str > 47 && *str < 58)
		nbr = nbr * 10 + *str++ - 48;
	if (nbr < 1 || nbr > 2147483647)
	{
		printf (RED"Error: no puede ser menor a 1, o mayor a 2147483647\n"RESET);
		exit (EXIT_FAILURE);
	}
	return ((int)nbr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error(char *s)
{
	if (s)
		write(2, s, ft_strlen(s));
	exit (EXIT_FAILURE);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:57:44 by ciclo             #+#    #+#             */
/*   Updated: 2023/03/03 19:27:03 by ciclo            ###   ########.fr       */
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
		exit (-1);
	}
	if (*str ==  43)
		str++;
	nbr = 0;
	while (*str > 47 && *str < 58)
		nbr = nbr * 10 + *str++ - 48;
	if (nbr > 2147483647)
	{
		printf (RED"Error: no puede ser mayor a 2147483647\n"RESET);
		exit (1);
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
	exit (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

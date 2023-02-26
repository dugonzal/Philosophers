/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:57:44 by ciclo             #+#    #+#             */
/*   Updated: 2023/02/26 11:06:01 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Philosophers.h"

int	ft_atoi(const char *str)
{
	int			neg;
	long int	nbr;

	nbr = 0;
	neg = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 32 || *str == 45)
	{
		if (*str == 32)
			neg = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
		nbr = nbr * 10 + *str++ - 48;

	if (nbr > 2147483647 || nbr < -2147483648)
		return (-1);
	return ((int)nbr * neg);
}

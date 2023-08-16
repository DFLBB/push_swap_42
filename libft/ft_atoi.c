/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:05:25 by dlanzas           #+#    #+#             */
/*   Updated: 2023/08/14 14:16:21 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_number(const char *str, int neg)
{
	long int	num;

	num = 0;
	while (*str > 47 && *str < 58)
	{
		num = (num * 10) + (*str - 48);
		if (num > 2147483648 && neg == -1)
			(ft_putstr_fd("Error\n", 2), exit(-1));
		if (num > 2147483647 && neg == 1)
			(ft_putstr_fd("Error\n", 2), exit(-1));
		str++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	size_t	num;
	int		neg;

	neg = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			neg *= -1;
		str++;
	}
	if (*str > 47 && *str < 58)
		num = ft_number(str, neg);
	else
		(ft_putstr_fd("Error\n", 2), exit(-1));
	return (num * neg);
}

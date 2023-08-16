/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:45:19 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/07/27 14:56:35 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[c])
	{
		write(1, &str[c], 1);
		c++;
	}
	return (c);
}

int	ft_print_pointer(unsigned long n)
{
	int		c;
	char	*base;

	c = 0;
	base = "0123456789abcdef";
	if (n < 16)
	{
		c += ft_print_str("0x");
		c += ft_print_char(base[n]);
		return (c);
	}
	c += ft_print_pointer(n / 16);
	c += ft_print_char(base[n % 16]);
	return (c);
}

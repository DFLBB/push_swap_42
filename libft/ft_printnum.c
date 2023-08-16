/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:46:35 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/07/27 14:56:56 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
	{
		c += write (1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		c += write (1, "-", 1);
		c += ft_print_int(n);
	}
	else
	{
		if (n >= 10)
		{
			c += ft_print_int(n / 10);
			c += ft_print_int(n % 10);
		}
		else
			c += ft_print_char("0123456789"[n]);
	}
	return (c);
}

int	ft_print_uint(unsigned int n)
{
	int	c;

	c = 0;
	if (n >= 10)
	{
		c += ft_print_uint(n / 10);
		c += ft_print_uint(n % 10);
	}
	else
		c += ft_print_char("0123456789"[n]);
	return (c);
}

int	ft_print_hex(unsigned int n, char *base)
{
	int		len;

	len = 0;
	if (n == 0)
		len = write (1, "0", 1);
	else
	{
		if (n >= 16)
		{
			len += ft_print_hex(n / 16, base);
			len += ft_print_hex(n % 16, base);
		}
		else
			len += ft_print_char(base[n]);
	}
	return (len);
}

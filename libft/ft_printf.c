/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:33:20 by dlanzas           #+#    #+#             */
/*   Updated: 2023/07/27 14:44:36 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_select(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		c;
	int		len;

	va_start(args, str);
	c = 0;
	len = 0;
	while (str[c])
	{
		if (str[c] != '%')
			len += ft_print_char(str[c]);
		else
		{
			c++;
			len += ft_select(str[c], args);
		}
		c++;
	}
	va_end(args);
	return (len);
}

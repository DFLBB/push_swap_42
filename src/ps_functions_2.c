/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:03:46 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/14 17:47:55 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*get_last_element(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (aux == NULL)
		return (NULL);
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

int	ps_get_max(t_stack *stack)
{
	t_stack	*aux;
	int		max;

	max = -2147483647;
	aux = stack;
	while (aux != NULL)
	{
		if (aux->data > max)
			max = aux->data;
		aux = aux->next;
	}
	return (max);
}

int	ps_get_min(t_stack *stack)
{
	t_stack	*aux;
	int		min;

	min = 2147483646;
	aux = stack;
	while (aux != NULL)
	{
		if (aux->data < min)
			min = aux->data;
		aux = aux->next;
	}
	return (min);
}

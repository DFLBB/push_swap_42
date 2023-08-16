/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:03:46 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/11 14:41:29 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_rotations_up(t_stack *stack, int target)
{
	int		rotations;
	t_stack	*current;

	rotations = 0;
	current = stack;
	while (current && current->data != target)
	{
		rotations++;
		current = current->next;
	}
	if (rotations == stack_size(stack) || rotations == 0)
		return (0);
	return (rotations);
}

int	get_rotations_down(t_stack *stack, int target)
{
	int		rotations;
	t_stack	*current;

	rotations = 0;
	current = stack;
	while (current && current->data != target)
	{
		current = current->next;
	}
	while (current)
	{
		rotations++;
		current = current->next;
	}
	if (rotations == stack_size(stack) || rotations == 0)
		return (0);
	return (rotations);
}

int	get_rot_pos_comp(t_stack *stack, int target)
{
	t_stack	*aux;
	int		rot;
	int		last;
	int		min;

	aux = stack;
	rot = 0;
	while (aux)
	{
		min = ps_get_min(aux);
		last = (get_last_element(aux))->data;
		if ((target > aux->data && (last > target || last == min))
			|| (last == min && target < last))
			return (rot);
		else
		{
			rot++;
			aux = aux->next;
		}
	}
	return (rot);
}

int	direct_rot_pos_comp(t_stack *stack, int target)
{
	t_stack	*aux;
	int		rot;
	int		last;
	int		max_pos;

	aux = stack;
	rot = 0;
	last = (get_last_element(aux))->data;
	while (aux)
	{
		max_pos = ps_get_max(aux);
		if ((target < aux->data && (last < target || last == max_pos))
			|| (last == max_pos && target > last))
			return (rot);
		else
		{
			rot++;
			aux = aux->next;
		}
	}
	return (rot);
}

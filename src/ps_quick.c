/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:45:34 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/14 17:50:26 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	quick_sort_stack2(t_stack **stack_a, t_stack **stack_b)
{
	quick_check_first_move(stack_a, stack_b);
	while (*stack_b)
	{
		quick_calc_moves(stack_a, stack_b);
		quick_check_move(stack_a, stack_b);
		quick_make_move(stack_a, stack_b);
		(pa(stack_a, stack_b), ps_write_move("pa\n"));
	}
}

static int	ps_first_greater(t_stack **stack_a, t_stack **stack_b, int position)
{
	if (position == 0)
		(pb(stack_a, stack_b), ps_write_move("pb\n"));
	else if (position == 1)
		(rb(stack_a, stack_b), pb(stack_a, stack_b), ps_write_move("rb\npb\n"));
	else if (position == -1)
	{
		(rrb(stack_a, stack_b), pb(stack_a, stack_b));
		ps_write_move("rrb\npb\n");
	}
	return (1);
}

static int	ps_first_lower(t_stack **stack_a, t_stack **stack_b, int position)
{
	if (position == 0)
		(rb(stack_a, stack_b), pb(stack_a, stack_b), ps_write_move("rb\npb\n"));
	else if (position == 1)
	{
		(rb(stack_a, stack_b), rb(stack_a, stack_b), pb(stack_a, stack_b));
		ps_write_move("rb\nrb\npb\n");
	}
	else if (position == -1)
		(pb(stack_a, stack_b), ps_write_move("pb\n"));
	return (-1);
}

static void	ps_first(t_stack **stack_a, t_stack **stack_b, int pivot)
{
	int	position;
	int	new_pivot;
	int	groups;

	position = 0;
	new_pivot = 0;
	groups = 90;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->data <= pivot && new_pivot != groups)
			position = ps_first_greater(stack_a, stack_b, position);
		else if ((*stack_a)->data > pivot && new_pivot != groups)
			position = ps_first_lower(stack_a, stack_b, position);
		else
		{
			pivot = (*stack_a)->data;
			new_pivot = 0;
			if (is_sorted(*stack_a))
				quick_sort_stack2(stack_a, stack_b);
		}
		new_pivot++;
	}
}

void	quick_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	rotations_down;
	int	rotations_up;
	int	pivot;
	int	min_a;

	pivot = (*stack_a)->data;
	(pb(stack_a, stack_b), ps_write_move("pb\n"));
	ps_first(stack_a, stack_b, pivot);
	quick_sort_stack2(stack_a, stack_b);
	min_a = ps_get_min(*stack_a);
	rotations_down = get_rotations_down(*stack_a, min_a);
	rotations_up = get_rotations_up(*stack_a, min_a);
	if (rotations_down > rotations_up)
	{
		while (rotations_up-- > 0)
			(ra(stack_a, stack_b), ps_write_move("ra\n"));
	}
	else
	{
		while (rotations_down-- > 0)
			(rra(stack_a, stack_b), ps_write_move("rra\n"));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:03:58 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/14 17:29:11 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_stack2(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
	{
		ps_calc_moves(stack_a, stack_b);
		ps_check_move(stack_a, stack_b);
		ps_make_move(stack_a, stack_b);
		(pb(stack_a, stack_b), ps_write_move("pb\n"));
	}
}

static void	ps_final_order(t_stack **stack_a, t_stack **stack_b)
{
	int	rotations_down;
	int	rotations_up;
	int	max_b;

	max_b = ps_get_max(*stack_b);
	rotations_down = get_rotations_down(*stack_b, max_b);
	rotations_up = get_rotations_up(*stack_b, max_b);
	if (rotations_down > rotations_up)
	{
		while (rotations_up-- > 0)
			(rb(stack_a, stack_b), ps_write_move("rb\n"));
	}
	else
	{
		while (rotations_down-- > 0)
			(rrb(stack_a, stack_b), ps_write_move("rrb\n"));
	}
	while (*stack_b)
		(pa(stack_a, stack_b), ps_write_move("pa\n"));
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->data < (*stack_a)->next->data)
		(pb(stack_a, stack_b), pb(stack_a, stack_b), ps_write_move("pb\npb\n"));
	else
	{
		(sa(stack_a, stack_b), ps_write_move("sa\n"));
		(pb(stack_a, stack_b), pb(stack_a, stack_b), ps_write_move("pb\npb\n"));
	}
	sort_stack2(stack_a, stack_b);
	ps_final_order(stack_a, stack_b);
}

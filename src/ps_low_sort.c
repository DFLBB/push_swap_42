/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_low_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:04:58 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/14 17:18:23 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	else if (is_reverse_sorted(*stack_a))
	{
		(ra(stack_a, stack_b), ps_write_move("ra\n"));
		(sa(stack_a, stack_b), ps_write_move("sa\n"));
	}
	else if (((*stack_a)->data > (*stack_a)->next->data) \
			&& ((*stack_a)->next->next->data > (*stack_a)->data))
		(sa(stack_a, stack_b), ps_write_move("sa\n"));
	else if (((*stack_a)->data < (*stack_a)->next->data) \
			&& ((*stack_a)->next->data) > (*stack_a)->next->next->data \
			&& (*stack_a)->next->next->data != ps_get_min(*stack_a))
	{
		(rra(stack_a, stack_b), ps_write_move("rra\n"));
		(sa(stack_a, stack_b), ps_write_move("sa\n"));
	}
	else if (((*stack_a)->data > (*stack_a)->next->data) \
			&& ((*stack_a)->next->next->data > (*stack_a)->next->data))
		(ra(stack_a, stack_b), ps_write_move("ra\n"));
	else
		(rra(stack_a, stack_b), ps_write_move("rra\n"));
}

static void	ps_final(t_stack **stack_a, t_stack **stack_b)
{
	int	min_a;
	int	rotations_up;
	int	rotations_down;

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

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_a) > 3)
		(pb(stack_a, stack_b), ps_write_move("pb\n"));
	sort_three(stack_a, stack_b);
	while (*stack_b)
	{
		quick_calc_moves(stack_a, stack_b);
		quick_check_move(stack_a, stack_b);
		quick_make_move(stack_a, stack_b);
		(pa(stack_a, stack_b), ps_write_move("pa\n"));
	}
	ps_final(stack_a, stack_b);
}

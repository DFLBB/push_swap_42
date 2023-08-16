/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:45:34 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/11 13:30:59 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	quick_check_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	int		move;
	int		pos;

	(void)stack_a;
	aux = *stack_b;
	move = stack_size(*stack_a) + stack_size(*stack_b);
	while (aux)
	{
		if (aux->cost < move)
		{
			move = aux->cost;
			pos = aux->data;
		}
		aux = aux->next;
	}
	return (pos);
}

void	qps_calc_movs_b(t_stack **aux, t_movs *rp, int len_b)
{
	rp->rpb_up++;
	rp->rpb_down = len_b - rp->rpb_up;
	if (rp->rpb_up > rp->rpb_down)
	{
		(*aux)->movs_b = -1 * rp->rpb_down;
		(*aux)->cost = rp->rpb_down;
	}
	else
	{
		(*aux)->movs_b = rp->rpb_up;
		(*aux)->cost = rp->rpb_up;
	}
}

void	qps_calc_movs_a(t_stack *stack_a, t_stack **aux, t_movs *rp, int len_a)
{
	rp->rpa_up = direct_rot_pos_comp(stack_a, (*aux)->data);
	rp->rpa_down = len_a - rp->rpa_up;
	if (rp->rpa_up > rp->rpa_down)
	{
		(*aux)->movs_a = -1 * rp->rpa_down;
		(*aux)->cost += rp->rpa_down;
	}
	else
	{
		(*aux)->movs_a = rp->rpa_up;
		(*aux)->cost += rp->rpa_up;
	}
}

void	quick_calc_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_movs	rp;
	int		len_a;
	int		len_b;

	len_a = stack_size(*stack_a);
	len_b = stack_size(*stack_b);
	aux = *stack_b;
	rp.rpb_up = -1;
	while (aux)
	{
		qps_calc_movs_b(&aux, &rp, len_b);
		qps_calc_movs_a(*stack_a, &aux, &rp, len_a);
		aux = aux->next;
	}
}

void	quick_check_first_move(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->data < (*stack_b)->next->data)
	{
		(sb(stack_a, stack_b), ps_write_move("sb\n"));
		(pa(stack_a, stack_b), ps_write_move("pa\n"));
		(pa(stack_a, stack_b), ps_write_move("pa\n"));
	}
	else
	{
		(pa(stack_a, stack_b), ps_write_move("pa\n"));
		(pa(stack_a, stack_b), ps_write_move("pa\n"));
	}
}

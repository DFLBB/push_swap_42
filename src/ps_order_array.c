/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_order_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:03:53 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/16 10:47:46 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ps_check_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	int		move;
	int		value;

	aux = *stack_a;
	move = stack_size(*stack_b) + stack_size(*stack_a);
	while (aux)
	{
		if (aux->cost < move)
		{
			move = aux->cost;
			value = aux->data;
		}
		aux = aux->next;
	}
	return (value);
}

void	ps_calc_movs_a(t_stack *aux, t_movs *rp, int len_a)
{
	rp->rpa_up++;
	rp->rpa_down = len_a - rp->rpa_up;
	if (rp->rpa_up > rp->rpa_down)
	{
		aux->movs_a = -1 * rp->rpa_down;
		aux->cost = rp->rpa_down;
	}
	else
	{
		aux->movs_a = rp->rpa_up;
		aux->cost = rp->rpa_up;
	}
}

void	ps_calc_movs_b(t_stack *stack_b, t_stack *aux, t_movs *rp, int len_b)
{
	rp->rpb_up = get_rot_pos_comp(stack_b, aux->data);
	rp->rpb_down = len_b - rp->rpb_up;
	if (rp->rpb_up > rp->rpb_down)
	{
		aux->movs_b = -1 * rp->rpb_down;
		aux->cost += rp->rpb_down;
	}
	else
	{
		aux->movs_b = rp->rpb_up;
		aux->cost += rp->rpb_up;
	}
}

void	ps_calc_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_movs	rp;
	int		len_a;
	int		len_b;

	len_a = stack_size(*stack_a);
	len_b = stack_size(*stack_b);
	aux = *stack_a;
	rp.rpa_up = -1;
	while (aux)
	{
		ps_calc_movs_a(aux, &rp, len_a);
		ps_calc_movs_b(*stack_b, aux, &rp, len_b);
		aux = aux->next;
	}
}

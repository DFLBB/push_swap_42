/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_make_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:17:38 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/16 10:51:59 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_movs_a(t_stack **stack_a, t_stack **stack_b, t_stack *aux)
{
	if (aux->movs_a < 0)
	{
		while (aux->movs_a < 0)
		{
			(rra(stack_a, stack_b), ps_write_move("rra\n"));
			aux->movs_a++;
		}
	}
	else
	{
		while (aux->movs_a > 0)
		{
			(ra(stack_a, stack_b), ps_write_move("ra\n"));
			aux->movs_a--;
		}
	}
}

void	ps_movs_b(t_stack **stack_a, t_stack **stack_b, t_stack *aux)
{
	if (aux->movs_b < 0)
	{
		while (aux->movs_b < 0)
		{
			(rrb(stack_a, stack_b), ps_write_move("rrb\n"));
			aux->movs_b++;
		}
	}
	else
	{
		while (aux->movs_b > 0)
		{
			(rb(stack_a, stack_b), ps_write_move("rb\n"));
			aux->movs_b--;
		}
	}
}

void	ps_mov_syn(t_stack **st_a, t_stack **st_b, t_stack *aux, int syn)
{
	if (syn == 1)
	{
		while (aux->movs_a > 0 && aux->movs_b > 0)
		{
			(rr(st_a, st_b), ps_write_move("rr\n"));
			aux->movs_a--;
			aux->movs_b--;
		}
	}
	else if (syn == -1)
	{
		while (aux->movs_a < 0 && aux->movs_b < 0)
		{
			(rrr(st_a, st_b), ps_write_move("rrr\n"));
			aux->movs_a++;
			aux->movs_b++;
		}
	}
	if (aux->movs_a != 0)
		ps_movs_a(st_a, st_b, aux);
	if (aux->movs_b != 0)
		ps_movs_b(st_a, st_b, aux);
}

int	synergy(t_stack *aux)
{
	if (aux->movs_a < 0 && aux->movs_b < 0)
		return (-1);
	else if (aux->movs_a > 0 && aux->movs_b > 0)
		return (1);
	return (0);
}

void	ps_make_move(t_stack **stack_a, t_stack **stack_b)
{
	int		value;
	t_stack	*aux;
	int		syn;

	aux = *stack_a;
	value = ps_check_move(stack_a, stack_b);
	while (aux->data != value)
		aux = aux->next;
	syn = synergy(aux);
	if (syn == 0)
	{
		ps_movs_a(stack_a, stack_b, aux);
		ps_movs_b(stack_a, stack_b, aux);
	}
	else
		ps_mov_syn(stack_a, stack_b, aux, syn);
}

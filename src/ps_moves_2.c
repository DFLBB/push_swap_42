/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:03:48 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/11 14:48:42 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	(void)stack_a;
	if (stack_size(*stack_b) <= 1)
		return ;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = NULL;
	ps_get(*stack_b, stack_size(*stack_b) - 1)->next = aux;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	aux_a = *stack_a;
	aux_b = *stack_b;
	if (stack_size(*stack_a) <= 1)
		return ;
	*stack_a = (*stack_a)->next;
	aux_a->next = NULL;
	ps_get(*stack_a, stack_size(*stack_a) - 1)->next = aux_a;
	if (stack_size(*stack_b) <= 1)
		return ;
	*stack_b = (*stack_b)->next;
	aux_b->next = NULL;
	ps_get(*stack_b, stack_size(*stack_b) - 1)->next = aux_b;
}

void	rrb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	(void)stack_a;
	if (stack_size(*stack_b) <= 1)
		return ;
	aux = ps_get(*stack_b, stack_size(*stack_b) - 1);
	ps_get(*stack_b, stack_size(*stack_b) - 2)->next = NULL;
	aux->next = *stack_b;
	*stack_b = aux;
}

void	rra(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	(void)stack_b;
	if (stack_size(*stack_a) <= 1)
		return ;
	aux = ps_get(*stack_a, stack_size(*stack_a) - 1);
	ps_get(*stack_a, stack_size(*stack_a) - 2)->next = NULL;
	aux->next = *stack_a;
	*stack_a = aux;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	if (stack_size(*stack_b) <= 1)
		return ;
	aux_a = ps_get(*stack_b, stack_size(*stack_b) - 1);
	ps_get(*stack_b, stack_size(*stack_b) - 2)->next = NULL;
	aux_a->next = *stack_b;
	*stack_b = aux_a;
	if (stack_size(*stack_a) <= 1)
		return ;
	aux_b = ps_get(*stack_a, stack_size(*stack_a) - 1);
	ps_get(*stack_a, stack_size(*stack_a) - 2)->next = NULL;
	aux_b->next = *stack_a;
	*stack_a = aux_b;
}

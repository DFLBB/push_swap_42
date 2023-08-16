/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_make_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:45:34 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/14 17:50:40 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ps_get(t_stack *stack, int pos)
{
	int		i;
	t_stack	*aux;

	aux = stack;
	i = 0;
	while (i < pos)
	{
		i++;
		aux = aux->next;
	}
	return (aux);
}

void	ps_write_move(char	*move)
{
	write(1, move, ft_strlen(move));
}

void	quick_make_move(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;
	t_stack	*aux;
	int		syn;

	aux = *stack_b;
	pos = quick_check_move(stack_a, stack_b);
	while (aux->data != pos)
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

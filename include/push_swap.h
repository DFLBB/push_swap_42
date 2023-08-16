/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:04:11 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/16 10:47:05 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
	int				movs_a;
	int				movs_b;
	int				cost;
}	t_stack;

typedef struct s_movs
{
	int		rpa_up;
	int		rpa_down;
	int		rpb_up;
	int		rpb_down;
}	t_movs;

void	sa(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

t_stack	*parse_arguments(int argc, char **argv);
void	ps_check_list(t_stack **stack_a, t_stack **stack_b);
void	ps_push(t_stack **stack, int data);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	quick_sort_stack(t_stack **stack_a, t_stack **stack_b);
void	ps_calc_moves(t_stack **stack_a, t_stack **stack_b);
void	ps_make_move(t_stack **stack_a, t_stack **stack_b);
int		ps_check_move(t_stack **stack_a, t_stack **stack_b);
void	ps_calc_movs_a(t_stack *aux, t_movs *rp, int len_a);
void	ps_calc_movs_b(t_stack *stack_b, t_stack *aux, t_movs *rp, int len_b);
int		synergy(t_stack *aux);
void	ps_movs_b(t_stack **stack_a, t_stack **stack_b, t_stack *aux);
void	ps_movs_a(t_stack **stack_a, t_stack **stack_b, t_stack *aux);
void	ps_mov_syn(t_stack **stack_a, t_stack **stack_b, t_stack *aux, int syn);
void	quick_sort(int *vect, int len);
void	quick_check_first_move(t_stack **stack_a, t_stack **stack_b);
void	quick_make_move(t_stack **stack_a, t_stack **stack_b);
void	quick_calc_moves(t_stack **stack_a, t_stack **stack_b);
int		quick_check_move(t_stack **stack_a, t_stack **stack_b);
void	qps_calc_movs_a(t_stack *stack_a, t_stack **aux, t_movs *rp, int len_a);
void	qps_calc_movs_b(t_stack **aux, t_movs *rp, int len_b);

void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
void	free_split(char **split);
int		is_valid_number(const char *str);
t_stack	*ps_get(t_stack *stack, int pos);

int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_reverse_sorted(t_stack *stack);
void	ps_write_move(char	*move);
int		ps_get_max(t_stack *stack);
int		ps_get_min(t_stack *stack);
t_stack	*get_last_element(t_stack *stack);
int		ps_get_max_pos(t_stack *stack);
int		ps_get_min_pos(t_stack *stack);

int		get_rotations_down(t_stack *stack, int target);
int		get_rotations_up(t_stack *stack, int target);
int		get_rot_pos_comp(t_stack *stack, int target);
int		direct_rot_pos_comp(t_stack *stack, int target);

#endif

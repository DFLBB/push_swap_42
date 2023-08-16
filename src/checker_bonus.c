/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:08:11 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/14 17:15:04 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	ps_checker_move(t_stack **s_a, t_stack **s_b, char *l, int len)
{
	if (ft_strncmp("sa\n", l, len) == 0)
		sa(s_a, s_b);
	else if (ft_strncmp("sb\n", l, len) == 0)
		sb(s_a, s_b);
	else if (ft_strncmp("ss\n", l, len) == 0)
		ss(s_a, s_b);
	else if (ft_strncmp("pa\n", l, len) == 0)
		pa(s_a, s_b);
	else if (ft_strncmp("pb\n", l, len) == 0)
		pb(s_a, s_b);
	else if (ft_strncmp("ra\n", l, len) == 0)
		ra(s_a, s_b);
	else if (ft_strncmp("rb\n", l, len) == 0)
		rb(s_a, s_b);
	else if (ft_strncmp("rr\n", l, len) == 0)
		rr(s_a, s_b);
	else if (ft_strncmp("rra\n", l, len) == 0)
		rra(s_a, s_b);
	else if (ft_strncmp("rrb\n", l, len) == 0)
		rrb(s_a, s_b);
	else if (ft_strncmp("rrr\n", l, len) == 0)
		rrr(s_a, s_b);
	else
		exit_error(s_a, s_b);
}

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*line;
	unsigned int	len;

	stack_a = parse_arguments(argc, argv);
	stack_b = NULL;
	line = get_next_line(0);
	while (line)
	{
		len = ft_strlen(line);
		ps_checker_move(&stack_a, &stack_b, line, len);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

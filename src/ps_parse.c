/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:03:55 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/08/16 10:47:26 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ps_check_list(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	else if (is_reverse_sorted(*stack_a))
		sort_stack(stack_a, stack_b);
	else if (len == 3)
		sort_three(stack_a, stack_b);
	else if (len <= 5)
		sort_five(stack_a, stack_b);
	else if (len > 250)
		quick_sort_stack(stack_a, stack_b);
	else
		sort_stack(stack_a, stack_b);
}

static int	ps_check_duplicates(t_stack *stack_a, int number)
{
	t_stack	*aux;

	aux = stack_a;
	while (aux)
	{
		if (number == aux->data)
			return (0);
		aux = aux->next;
	}
	return (1);
}

static void	push_argument(t_stack **stack_a, const char *arg)
{
	char	**numbers;
	int		number;
	int		i;

	i = 0;
	numbers = ft_split(arg, ' ');
	if (!numbers)
		exit_error(stack_a, NULL);
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]) || ft_strlen(numbers[i]) == 0)
		{
			free_split(numbers);
			exit_error(stack_a, NULL);
		}
		number = ft_atoi(numbers[i]);
		if (!ps_check_duplicates(*stack_a, number))
		{
			free_split(numbers);
			exit_error(stack_a, NULL);
		}
		ps_push(stack_a, number);
		i++;
	}
	free_split(numbers);
}

static void	parse_multiple_arguments(t_stack **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		push_argument(stack_a, argv[i]);
		i++;
	}
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;
	int		count;

	count = 0;
	stack_a = NULL;
	if (argc == 2)
		push_argument(&stack_a, argv[1]);
	else if (argc > 2)
	{
		while (argv[count])
		{
			if (ft_strlen(argv[count]) == 0 || (ft_strlen(argv[count]) == 1
					&& (argv[count][0] == ' ' || argv[count][0] == '\n')))
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			count++;
		}
		parse_multiple_arguments(&stack_a, argc, argv);
	}
	else
		exit_error(NULL, NULL);
	return (stack_a);
}

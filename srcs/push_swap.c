/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:11:13 by dviegas           #+#    #+#             */
/*   Updated: 2025/07/03 22:49:45 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_invalid(char *arg, t_stack_node *a, long n)
{
	return (error_syntax(arg) || n > INT_MAX || n < INT_MIN
		|| error_duplicate(a, (int)n));
}

void	free_array(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

void	handle_initial_stack_sort(t_stack_node *stack_a, t_stack_node *stack_b)
{
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
}

int	main(int argc, char **argv)
{
    t_stack_node	*stack_a;
    t_stack_node	*stack_b;
    char			**free_splitted;

    stack_a = NULL;
    stack_b = NULL;
    free_splitted = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        free_splitted = argv;
    }
    init_stack_a(&stack_a, argv + 1, free_splitted);
    handle_initial_stack_sort(stack_a, stack_b);
    if (free_splitted)
        free_array(free_splitted);
    while (stack_a && stack_a->prev)
        stack_a = stack_a->prev;
    free_stack(&stack_a);
    return (0);
}

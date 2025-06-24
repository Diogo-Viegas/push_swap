/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:11:13 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/24 17:20:49 by dviegas          ###   ########.fr       */
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

int main (int argc, char **argv)
{
    t_stack_node *stack_a;
    t_stack_node *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    if(argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if(argc == 2)
        argv = ft_split(argv[1],' ');
        
    init_stack_a(&stack_a,argv + 1);

    if(!stack_sorted(stack_a))
    {
        if(stack_len(stack_a) == 2)
            sa(&stack_a,false);
        else if(stack_len(stack_a) == 3)
            sort_three(&stack_a);
        else
            sort_stack(&stack_a,&stack_b);
    }
    free_stack(&stack_a);

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:11:13 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/19 15:18:02 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

    }
    free_stack(&stack_a);
    return (0);
}
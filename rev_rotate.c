/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:19:06 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/23 16:24:59 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack) 
{
	t_stack_node	*last; 

	if (!*stack || !(*stack)->next) 
		return ;
	last = find_last(*stack);
	last->prev->next = NULL; 
	last->next = *stack; 
	last->prev = NULL; 
	*stack = last; 
	last->next->prev = last; 
}

void	rra(t_stack_node **stack_a, bool print)
{
	rev_rotate(stack_a);
	if (!print)
		write(1,"rra\n",4);
}

void	rrb(t_stack_node **stack_b, bool print)
{
	rev_rotate(stack_b);
	if (!print)
		write(1,"rrb\n",4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!print)
		write(1,"rrr\n",4);
}
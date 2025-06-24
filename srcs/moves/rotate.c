/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:50:36 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/24 11:39:58 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next) 
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack; 
	*stack = (*stack)->next; 
	(*stack)->prev = NULL; 
	last_node->next->prev = last_node; 
	last_node->next->next = NULL; 
}		

void	ra(t_stack_node **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		write(1,"ra\n",3);
}

void	rb(t_stack_node **stack_b, bool print) 
{
	rotate(stack_b);
	if (!print)
		write(1,"rb\n",3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		write(1,"rr\n",3);
}


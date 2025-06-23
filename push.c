/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:11:38 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/23 16:13:20 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node; 

	if (!*src) 
		return ;
	push_node = *src; 
	*src = (*src)->next; 
	if (*src) 
		(*src)->prev = NULL; 
	push_node->prev = NULL; 
	if (!*dst) 
	{
		*dst = push_node; 
		push_node->next = NULL;
	}
	else 
	{
		push_node->next = *dst; 
		push_node->next->prev = push_node; 
		*dst = push_node;  
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	push(stack_a, stack_b); 
	if (!print) 
		write(1,"pa\n",3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		write(1,"pb\n",3);
}
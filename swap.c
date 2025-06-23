/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:05:36 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/23 16:09:44 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack_node **head)
{
    if(!head || !(*head)->next)
        return;
    *head = (*head)->next;
    (*head)->prev->prev = *head; 
	(*head)->prev->next = (*head)->next; 
	if ((*head)->next) 
		(*head)->next->prev = (*head)->prev; 
	(*head)->next = (*head)->prev; 
	(*head)->prev = NULL; 

}

void	sa(t_stack_node	**stack_a, bool print) 
{
	swap(stack_a);
	if (!print)
		write(1,"sa\n",3);
}

void	sb(t_stack_node **stack_b, bool print) 
{
	swap(stack_b);
	if (!print)
		write(1,"sb\n",3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		write(1,"ss\n",3);
}
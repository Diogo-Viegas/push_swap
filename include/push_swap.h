/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:11:17 by dviegas           #+#    #+#             */
/*   Updated: 2025/06/25 00:28:46 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

int						ft_isdigit(int c);
// errors
int						error_syntax(char *str_n);
int						error_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a);
// split
char					**ft_split(char *s, char c);
// stack utils
bool					stack_sorted(t_stack_node *stack);
// init a to b
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *stack_a,
							t_stack_node *stack_b);
// init b to a
void					init_nodes_b(t_stack_node *stack_a,
							t_stack_node *stack_b);
// init stack
void					init_stack_a(t_stack_node **a, char **argv);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
t_stack_node			*get_cheapest(t_stack_node *stack);
// rotate
void					ra(t_stack_node **stack_a, bool print);
void					rb(t_stack_node **stack_b, bool print);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b,
							bool print);
// rev rotate
void					rra(t_stack_node **stack_a, bool print);
void					rrb(t_stack_node **stack_b, bool print);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b,
							bool print);
// sort stacks
void					sort_stack(t_stack_node **stack_a,
							t_stack_node **stack_b);

// sort three
void					sort_three(t_stack_node **a);
// stack utils
bool					stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
// swap
void					sa(t_stack_node **stack_a, bool print);
void					sb(t_stack_node **stack_b, bool print);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b,
							bool print);
// push
void					pa(t_stack_node **stack_a, t_stack_node **stack_b,
							bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					free_array(char **splitted);
#endif

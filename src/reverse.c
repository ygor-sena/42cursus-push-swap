/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:17:36 by ygorgsena         #+#    #+#             */
/*   Updated: 2022/10/20 10:02:17 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack **stack);

void	reverse_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	reverse_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*next_to_last;

	last = get_last_nbr(*stack);
	next_to_last = get_penul_nbr(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	next_to_last->next = NULL;
}

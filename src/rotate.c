/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:57:20 by ygorgsena         #+#    #+#             */
/*   Updated: 2022/10/19 18:54:02 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack);

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = get_last_nbr(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

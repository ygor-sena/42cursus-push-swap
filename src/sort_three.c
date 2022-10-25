/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:44:21 by ygorgsena         #+#    #+#             */
/*   Updated: 2022/10/25 11:12:55 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*last_stack;

	last_stack = get_last_nbr(*stack_a);
	if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->index \
		< last_stack->index && (*stack_a)->next->index > last_stack->index)
	{
		reverse_a(stack_a);
		swap_a(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index \
		&& (*stack_a)->index < last_stack->index \
		&& (*stack_a)->next->index < last_stack->index)
		swap_a(stack_a);
	else if ((*stack_a)->index < (*stack_a)->next->index \
		&& (*stack_a)->index > last_stack->index \
		&& (*stack_a)->next->index > last_stack->index)
		reverse_a(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index \
		> last_stack->index && (*stack_a)->next->index > last_stack->index)
	{
		swap_a(stack_a);
		reverse_a(stack_a);
	}
	else
		rotate_a(stack_a);
}

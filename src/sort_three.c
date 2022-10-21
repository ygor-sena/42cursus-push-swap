/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:18:37 by ygorgsena         #+#    #+#             */
/*   Updated: 2022/10/21 17:49:17 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*last_stack;

	last_stack = get_last_nbr(*stack_a);
	if ((*stack_a)->nbr < (*stack_a)->next->nbr \
		&& (*stack_a)->nbr < last_stack->nbr \
		&& (*stack_a)->next->nbr > last_stack->nbr)
	{
		reverse_a(stack_a);
		swap_a(stack_a);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr \
		&& (*stack_a)->nbr < last_stack->nbr)
		swap_a(stack_a);
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr \
		&& (*stack_a)->nbr > last_stack->nbr \
		&& (*stack_a)->next->nbr > last_stack->nbr)
		reverse_a(stack_a);
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr \
        && (*stack_a)->nbr > last_stack->nbr \
		&& (*stack_a)->next->nbr > last_stack->nbr)
	{
		swap_a(stack_a);
		reverse_a(stack_a);
	}
	else
		rotate_a(stack_a);
}

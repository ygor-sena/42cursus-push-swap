/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:37:18 by ygorgsena         #+#    #+#             */
/*   Updated: 2022/10/25 14:47:21 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	get_index(long long number, t_stack *stack);

size_t	get_stack_size(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

size_t	get_smallest_index(t_stack **stack_a)
{
	t_stack	*tmp;
	size_t	smallest;

	smallest = MAX_INT;
	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (smallest > tmp->index)
			smallest = tmp->index;
		tmp = tmp->next;
	}
	return (smallest);
}

t_bool	is_ordered_stack(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->index > stack_a->next->index)
			return (FALSE);
		stack_a = stack_a->next;
	}
	return (TRUE);
}

void	fill_index_stack(t_stack **stack_a)
{
	t_stack	*compare;
	t_stack	*reference;

	compare = *stack_a;
	reference = *stack_a;
	while (compare != NULL)
	{
		compare->index = get_index(compare->nbr, reference);
		compare = compare->next;
	}
}

static size_t	get_index(long long number, t_stack *stack)
{
	size_t	stk_size;
	size_t	index;

	stk_size = get_stack_size(stack);
	index = 1;
	while (stk_size--)
	{
		if (number > stack->nbr)
			index++;
		stack = stack->next;
	}
	return (index);
}
